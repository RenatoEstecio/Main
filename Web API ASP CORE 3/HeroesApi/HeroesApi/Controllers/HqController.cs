using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Mime;
using System.Reflection;
using System.Runtime.Serialization.Json;
using System.Text;
using HeroesApi.Utils;
using HtmlAgilityPack;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Net.Http.Headers;
using Newtonsoft.Json;

namespace HeroesApi.Controllers
{

    [Route("api/[controller]")]
   
    [ApiController]
    public class HqController : ControllerBase
    {

        /*
        OKs:

            https://localhost:44374/Api/HQ/wolverine
            https://localhost:44374/Api/HQ/Magneto

        Verificar:

            https://localhost:44374/Api/HQ/Homem_de_Ferro

        */

        //GET: api/Hq/NomeDoPersonagem   
     
        [HttpGet("{Name}")]
        public IEnumerable<Personagem> Get (string Name)
       
        {
            #region Converte URL para String

            string Url = Constantes.URLMAIN + Name;
            string strHtml = HtmlUtils.HtmlToString(Url);

            #endregion

            #region Realiza a busca pela chave

            string realname = RegexUtils.FirstMatch("<b>Nome: </b>(?<Busca>.*?)\\s<", "Busca", strHtml);
            
            #endregion

            #region Faz o processamento dos objetos para um retorno de obj Json

            Personagem p = new Personagem();
            p.RealNome = realname;
            p.Nome = StringUtils.CapitalizarNome(Name);
            return Enumerable.Range(1, 1).Select(index => p);

            #endregion
        }

        /*localhost:44374/Api/HQ/pdf/wolverine*/
        [HttpGet("PDF/{n}")]
        [Route("PDF/{pdf}/{a}")]
        public FileStreamResult Get(string pdf,string n)
        {

            #region Converte URL para String

            string Url = Constantes.URLMAIN + n;
            string strHtml = HtmlUtils.HtmlToString(Url);

            #endregion

            #region Realiza a busca pela chave

            string realname = RegexUtils.FirstMatch("<b>Nome: </b>(?<Busca>.*?)\\s<", "Busca", strHtml);

            #endregion

            #region Faz a conversão para String(outro tipo qualquer)

            Personagem p = new Personagem();
            p.RealNome = realname;
            p.Nome = StringUtils.CapitalizarNome(n);        

            List<List<string>> list = new List<List<string>>();
            List<string> itens = new List<string>();

            PropertyInfo[] propriedades = typeof(Personagem).GetProperties();

            // Percorre a lista, obtendo o nome de cada uma das propriedades
            foreach (PropertyInfo pi in propriedades)                         
                itens.Add(pi.Name);// Obtém o nome da propriedade...

            list.Add(itens);

            itens = new List<string>();
            itens.Add(p.Nome);
            itens.Add(p.RealNome);
            list.Add(itens);
            #endregion

            #region Gerar Arquivo Interno e Realiza Download Cliente                      
            return new FileStreamResult(
                new FileStream(
                    PdfUtils.GerarPDF(list, "Exemplo"), 
                    FileMode.Open), 
                    "application/pdf");
            #endregion
        }

    }
}
