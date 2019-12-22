using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace HeroesApi.Utils
{
    public class StringUtils
    {
        public static string CapitalizarNome(string nome)
        {
            try
            {
                nome = RemoveUnderlines(nome);
                var palavras = new Queue<string>();
                foreach (var palavra in nome.Split(' '))
                {
                    if (!string.IsNullOrEmpty(palavra))
                    {
                        var emMinusculo = palavra.ToLower();
                        var letras = emMinusculo.ToCharArray();
                        letras[0] = char.ToUpper(letras[0]);
                        palavras.Enqueue(new string(letras));
                    }
                }
                return string.Join(" ", palavras);
            }
            catch(Exception e) { return nome;}
            
        }

        public static string RemoveUnderlines(string nome)
        {
            return (nome.Replace("_", " ")).Trim();
        }
    }
}
