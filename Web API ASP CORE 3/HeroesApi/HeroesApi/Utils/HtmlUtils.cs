﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Threading.Tasks;

namespace HeroesApi
{
    public static class HtmlUtils
    {

        static public string HtmlToString(string URL)
        {
            string htmlCode = string.Empty;
            using (WebClient client = new WebClient())
            {
                htmlCode = client.DownloadString(URL);
            }

            return htmlCode;
        }
    }
}
