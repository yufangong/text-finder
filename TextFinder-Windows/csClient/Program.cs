using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("  ==============================================================");
            Console.WriteLine("     Text Finder Service Start");
            Console.WriteLine("  ==============================================================\n");

            if (args.Length < 3)
            {
                Console.Write("\n This Application only provide search service.\n");
                Console.Write("\n CommandLine format:Command(search) path keywords(use space to separate) option");
                Console.Write("\n For example: search ../ keyword1 keyword2 /O");
                return;
            }
            String command = args[0];
            if (command != "search")
            {
                Console.Write("\n This Application only provide search service.\n");
                Console.Write("\n CommandLine format:Command(search) path keywords(use space to separate) option");
                Console.Write("\n For example: search ../ keyword1 keyword2 /O");
                return;
            }
            String path = args[1];
            int keywordEnd;
            Boolean searchAll;
            String temp = args[args.Length - 1];
            if (temp == "/o" || temp == "/O")
            {
                searchAll = false;
                keywordEnd = args.Length - 1;
            }
            else
            {
                searchAll = true;
                keywordEnd = args.Length;
            }
            List<String> keywords = new List<string>();
            for (int i = 2; i < keywordEnd; i++)
            {
                keywords.Add(args[i]);
            }

            Console.WriteLine("  Set Search Path: {0}", path);
            Console.Write("  Set Search KeyWords: ");
            foreach (String keyword in keywords)
                Console.Write("{0}  ", keyword);
            Console.Write("\n  Set Search Option: ");
            if (searchAll)
                Console.Write("files contain all keywords\n\n");
            else
                Console.Write("files contain any keyword\n\n");
            Array k = keywords.ToArray();

            try
            {
                DateTime start = DateTime.Now;
                TextSearchComptLib.ITextSearch searchService = new TextSearchComptLib.TextSearch();
                searchService.SetSearchPath(path);
                searchService.SetSearchOption(searchAll);
                searchService.SetSearchKeywords(k);

                Array files;
                searchService.GetResults(out files);

                DateTime end = DateTime.Now;
                Console.WriteLine("\n  ====Execution time : {0} Milliseconds ====\n", (end - start).Milliseconds);
                Console.WriteLine("  *****************");
                Console.WriteLine("  *Search Result: *");
                Console.WriteLine("  *****************");

                foreach (String file in files)
                {
                    Console.WriteLine("  {0}", file);
                }
                Console.Write("\n\n");
            }
            catch (Exception ex)
            {
                Console.Write("\n  error: {0}\n", ex.Message);
                return;
            }
        }
    }
}
