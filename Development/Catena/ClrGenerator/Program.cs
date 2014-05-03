using System;
using System.Collections.Generic;
using System.Xml.Linq;
using System.Xml;
using System.Linq;
using System.Text;

namespace ClrGenerator {
    class Program {

        static int Main(string[] args) {
            var oConfig = new Configuration();
            Console.WriteLine("Input directory: " + oConfig.InputBaseDirectory);

            List<InputClass> lObjects = new List<InputClass>();
            foreach(var oFile in oConfig.Files) {
                if(oFile.Parse()) {
                    Console.WriteLine("I: Succesfully parsed " + oFile.Path);
                    lObjects.AddRange(oFile.Objects);
                }
                else {
                    Console.WriteLine("E: Unable to parse " + oFile.Path);
                }
            }

            foreach(var oObject in lObjects) {

            }

            Console.ReadKey();
            return 0;
        }
    }
}
