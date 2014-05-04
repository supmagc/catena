using System;
using System.Collections.Generic;
using System.Xml.Linq;
using System.Xml;
using System.Linq;
using System.Text;
using System.IO;

namespace ClrGenerator {
    class Program {

        static int Main(string[] args) {
            var oConfig = new Configuration();
            Console.WriteLine("Input directory: " + oConfig.InputBaseDirectory);

            List<InputObject> lObjects = new List<InputObject>();
            foreach(var oFile in oConfig.Files) {
                if(oFile.Parse()) {
                    Console.WriteLine("I: Succesfully parsed " + oFile.Path);
                    lObjects.AddRange(oFile.Objects);
                }
                else {
                    Console.WriteLine("E: Unable to parse " + oFile.Path);
                }
            }

            GenerateForwardHeader(oConfig, lObjects);
            GenerateObjectFiles(oConfig, lObjects);

            Console.ReadKey();
            return 0;
        }

        static string GetNamespacesOpening(Configuration oConfig, string[] aNamespaces) {
            string sReturn = "";
            if(oConfig.OutputBaseNamespace.Length > 0)
                sReturn += String.Format("namespace {0} {{", oConfig.OutputBaseNamespace);
            for(int i = oConfig.OutputNamespaceRemovalDepth ; i < aNamespaces.Length ; ++i )
                sReturn += String.Format("namespace {0} {{", aNamespaces[i]);
            return sReturn;
        }

        static string GetNamespacesClosing(Configuration oConfig, string[] aNamespaces) {
            string sReturn = "";
            for(int i = oConfig.OutputNamespaceRemovalDepth ; i < aNamespaces.Length ; ++i)
                sReturn += String.Format("}};");
            if(oConfig.OutputBaseNamespace.Length > 0)
                sReturn += String.Format("}};");
            return sReturn;
        }

        static string GetObjectFullName(InputObject oObject) {
            string sReturn = "";
            foreach(string sNamespace in oObject.Namespaces)
                sReturn += sNamespace + "_";
            return sReturn + oObject.Name;
        }

        static string GetObjectHeaderGuard(Configuration oConfig, InputObject oObject) {
            return oConfig.OutputHeaderGuardPrefix + GetObjectFullName(oObject).ToUpper();
        }

        static string GetObjectHeaderFileName(Configuration oConfig, InputObject oObject) {
            return oConfig.OutputHeaderPrefix + GetObjectFullName(oObject) + ".h";
        }

        static string GetObjectSourceFileName(Configuration oConfig, InputObject oObject) {
            return oConfig.OutputSourcePrefix + GetObjectFullName(oObject) + ".cpp";
        }

        static bool WriteToFile(string sPath, IEnumerable<string> lLines) {
            var oFile = new FileInfo(sPath);
            if(!oFile.Directory.Exists) oFile.Directory.Create();
            File.WriteAllLines(oFile.FullName, lLines);
            return true;
        }

        static bool GenerateForwardHeader(Configuration oConfig, IEnumerable<InputObject> lObjects) {
            List<string> lForwardHeader = new List<string>();
            lForwardHeader.Add(String.Format("#ifndef {0}", oConfig.OutputForwardHeaderGuard));
            lForwardHeader.Add(String.Format("#define {0}", oConfig.OutputForwardHeaderGuard));
            foreach(var oObject in lObjects) {
                lForwardHeader.Add(GetNamespacesOpening(oConfig, oObject.Namespaces));
                lForwardHeader.Add(String.Format("{0} {1};", oObject.TypeClr, oObject.Name));
                lForwardHeader.Add(GetNamespacesClosing(oConfig, oObject.Namespaces));
            }

            lForwardHeader.Add(String.Format("#endif // {0}", oConfig.OutputForwardHeaderGuard));
            WriteToFile(oConfig.OutputBaseDirectory + "/" + oConfig.OutputHeaderDirectory + "/" + oConfig.OutputForwardHeader, lForwardHeader);

            return true;
        }

        static bool GenerateObjectFiles(Configuration oConfig, IEnumerable<InputObject> lObjects) {
            List<string> lCombinedHeader = new List<string>();
            lCombinedHeader.Add(String.Format("#ifndef {0}", oConfig.OutputCombinedHeaderGuard));
            lCombinedHeader.Add(String.Format("#define {0}", oConfig.OutputCombinedHeaderGuard));
            foreach(var oObject in lObjects) {
                if(GenerateObjectHeader(oConfig, oObject) && GenerateObjectSource(oConfig, oObject))
                    lCombinedHeader.Add(String.Format("#include \"{0}\"", GetObjectHeaderFileName(oConfig, oObject)));
            }

            lCombinedHeader.Add(String.Format("#endif // {0}", oConfig.OutputCombinedHeaderGuard));
            WriteToFile(oConfig.OutputBaseDirectory + "/" + oConfig.OutputHeaderDirectory + "/" + oConfig.OutputCombinedHeader, lCombinedHeader);

            return true;
        }

        static bool GenerateObjectHeader(Configuration oConfig, InputObject oObject) {
            List<string> lHeader = new List<string>();
            lHeader.Add(String.Format("#ifndef {0}", GetObjectHeaderGuard(oConfig, oObject)));
            lHeader.Add(String.Format("#define {0}", GetObjectHeaderGuard(oConfig, oObject)));

            lHeader.Add("");
            lHeader.Add(oConfig.OutputHeaderPrepend);
            lHeader.Add("");
            lHeader.Add(String.Format("#include \"{0}\"", oConfig.OutputStandardHeader));
            lHeader.Add(String.Format("#include \"{0}\"", oConfig.OutputForwardHeader));
            lHeader.Add("");
            lHeader.Add(GetNamespacesOpening(oConfig, oObject.Namespaces));
            lHeader.Add("");
            lHeader.Add(String.Format("public {0} {1} {{", oObject.TypeClr, oObject.Name));
            lHeader.Add(String.Format("public:"));
            foreach(var oConstructor in oObject.Constructors) {

            }
            if(oObject.IsRefType) {
                lHeader.Add(String.Format("~{0}();", oObject.Name));
                lHeader.Add(String.Format("!{0}();", oObject.Name));
            }
            foreach(var oMethod in oObject.Methods) {

            }
            lHeader.Add("");
            lHeader.Add(String.Format("private:"));
            string sVariable = "";
            //if(oObject.IsValType) sVariable += "NativeValuePtr<";
            foreach(var sNamespace in oObject.Namespaces)
                sVariable += sNamespace + "::";
            sVariable += oObject.Name;
            //if(oObject.IsValType) sVariable += "> m_oInstance;";
            /*if(oObject.IsRefType)*/ sVariable += "* m_pInstance;";
            lHeader.Add(sVariable);
            lHeader.Add(String.Format("}};"));
            lHeader.Add(GetNamespacesClosing(oConfig, oObject.Namespaces));
            lHeader.Add("");
            lHeader.Add(oConfig.OutputHeaderAppend);
            lHeader.Add("");

            lHeader.Add(String.Format("#endif // {0}", GetObjectHeaderGuard(oConfig, oObject)));
            WriteToFile(oConfig.OutputBaseDirectory + "/" + oConfig.OutputHeaderDirectory + "/" + GetObjectHeaderFileName(oConfig, oObject), lHeader);

            return true;
        }

        static bool GenerateObjectSource(Configuration oConfig, InputObject oObject) {
            List<string> lSource = new List<string>();
            lSource.Add(String.Format("#include \"{0}\"", oConfig.OutputStandardHeader));
            lSource.Add(String.Format("#include \"{0}\"", oConfig.OutputCombinedHeader));
            lSource.Add(String.Format("#include \"{0}\"", GetObjectHeaderFileName(oConfig, oObject)));
            WriteToFile(oConfig.OutputBaseDirectory + "/" + oConfig.OutputSourceDirectory + "/" + GetObjectSourceFileName(oConfig, oObject), lSource);

            return true;
        }
    }
}
