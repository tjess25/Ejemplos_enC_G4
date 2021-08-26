using System;
using System.IO;
using System.Linq;

namespace FastChart
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0) {
                Console.WriteLine("Provide a file name.");
                return;
            }
            if (!File.Exists(args[0])) {
                Console.WriteLine("Data file doesn't exists.");
                return;
            }

            Console.WriteLine("Generating JS...");

            string finalData = "";

            string[] data = File.ReadAllLines(args[0]);
            string js = File.ReadAllText("index_.js");
            string html = File.ReadAllText("index_.html");

            string type = data[0].Contains(',') ? "scatter" : "line";

            switch (type) {
                case "line":
                    string labels = string.Join(',', Enumerable.Range(0, data.Length).Select(x => x).ToArray());
                    finalData = @$"labels: [{labels}],
                                datasets: [{{
                                    label: 'Line Chart',
                                    data: {{{{data}}}},
                                    fill: false,
                                    borderColor: 'rgb(75, 192, 192)',
                                    tension: 0.1
                                }}]";
                    break;
                case "scatter":
                    finalData = @"datasets: [{
                                    label: 'Scatter Chart',
                                    data: {{data}},
                                    backgroundColor: 'rgb(255, 99, 132)'
                                }]";
                    break;
                default:
                    finalData = @"datasets: [{
                                    label: 'Scatter Chart',
                                    data: {{data}},
                                    backgroundColor: 'rgb(255, 99, 132)'
                                }]";
                    break;
            }

            string points = "[";

            foreach (string item in data) {
                if (item.Contains(',')) {
                    points += $@"{{
                            x: {item.Split(',')[0].Trim()},
                            y: {item.Split(',')[1].Trim()}
                        }},";
                } else {
                    points += $"{item},";
                }
            }

            finalData = finalData.Replace("{{data}}", points + "]");

            js = js.Replace("{{type}}", $"'{type}'");
            js = js.Replace("{{data}}", finalData);

            File.WriteAllText($"index{type}.js", js);
            File.WriteAllText($"index{type}.html", html.Replace("{{type}}", type));
        }
    }
}
