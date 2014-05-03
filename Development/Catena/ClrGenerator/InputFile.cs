using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace ClrGenerator {

    public class InputFile {

        const int STATE_DEFAULT = 0;
        const int STATE_NAMESPACE = 1;
        const int STATE_COMMENT = 2;
        const int STATE_OBJECT = 3;
        const int STATE_REGION = 4;

        const string REGEX_NAMESPACE = @"^namespace\s+([a-z0-9]+)\s*\{";
        const string REGEX_OBJECT = @"^(class|struct)\s+([^\s]+\s+)?([a-z0-9]+)?(\s*:\s*[^\s]+)?\s*({|;)";
        const string REGEX_METHOD = @"^((virtual)\s+)?([-a-z0-9_*=&]*)?\s+([a-z0-9]+)\s*\(([^\)]*)\)\s*(const)?\s*(=\s*0)?\s*;";

        public Configuration Configuration { get; private set; }
        public InputClass[] Objects { get { return m_lObjects.ToArray(); } }
        public string Path { get; private set; }

        private Stack<int> m_lStates;
        private Stack<string> m_lNamespaces;
        private List<InputClass> m_lObjects;
        private InputClass m_oCurrentObject;
        private bool m_bPublic;

        public InputFile(Configuration oConfiguration, string sPath, string sOutput) {
            Configuration = oConfiguration;
            Path = sPath;
        }

        public bool Parse() {
            var sFullPath = Configuration.InputBaseDirectory + "/" + Path;
            if(!File.Exists(sFullPath))
                return false;

            m_lStates = new Stack<int>();
            m_lNamespaces = new Stack<string>();
            m_lObjects = new List<InputClass>();
            m_oCurrentObject = null;
            m_lStates.Push(STATE_DEFAULT);
            var sContent = File.ReadAllText(sFullPath).Trim();
            var aLines = File.ReadAllLines(sFullPath);
            while(sContent.Length > 0) {
                var nOffset = ParseContent(ref sContent);
                if(nOffset < 0)
                    return false;
                else if(nOffset > 0)
                    sContent = sContent.Substring(nOffset).Trim();
            }
            return true;
        }

        private int ParseContent(ref string sContent) {
            Match oMatch = null;
            var nIndex = -1;

            if(m_lStates.Count == 0) {
                Console.WriteLine("E: Invalid structured file");
                return -1;
            }

            // Pre check for comment and early return if found
            if(sContent.StartsWith("/*")) {
                m_lStates.Push(STATE_COMMENT);
                return 2;
            }
            if(sContent.StartsWith("//")) {
                return Math.Max(1, sContent.IndexOf("\n") + 1);
            }

            switch(m_lStates.Peek()) {
                case STATE_DEFAULT:
                case STATE_NAMESPACE:
                    if(sContent.StartsWith("namespace ")) {
                        oMatch = DoRegex(ref sContent, REGEX_NAMESPACE);
                        if(!oMatch.Success) {
                            Console.WriteLine("E: Invalid namespace declaration: " + sContent.Substring(0, 20));
                            return -1;
                        }
                        else {
                            m_lNamespaces.Push(oMatch.Groups[1].Value);
                            m_lStates.Push(STATE_NAMESPACE);
                            Console.WriteLine("I: Namespace found: " + m_lNamespaces.Peek());
                            return oMatch.Length;
                        }
                    }
                    if(sContent.StartsWith("class ") || sContent.StartsWith("struct ")) {
                        oMatch = DoRegex(ref sContent, REGEX_OBJECT);
                        if(!oMatch.Success) {
                            Console.WriteLine("E: Invalid object declaration: " + sContent.Substring(0, 20));
                            return -1;
                        }
                        else if(oMatch.Groups[5].Value == "{" && oMatch.Groups[3].Value.ToString().Length > 0) {
                            m_oCurrentObject = new InputClass(m_lNamespaces.ToArray(), oMatch.Groups[1].Value, oMatch.Groups[3].Value);
                            Console.WriteLine("I: Object found: " + m_oCurrentObject.Name);
                            m_bPublic = sContent.StartsWith("struct ");
                            m_lStates.Push(STATE_OBJECT);
                            return oMatch.Length;
                        }
                        else {
                            return oMatch.Length;
                        }
                    }
                    if(sContent.StartsWith("};")) {
                        Console.WriteLine("I: Namespace left");
                        m_lNamespaces.Pop();
                        m_lStates.Pop();
                        return 2;
                    }
                    break;
                case STATE_COMMENT:
                    if((nIndex = sContent.IndexOf("*/")) >= 0) {
                        m_lStates.Pop();
                        return nIndex + 2;
                    }
                    break;
                case STATE_OBJECT:
                    if(sContent.StartsWith("public:")) {
                        m_bPublic = true;
                        return 7;
                    }
                    if(sContent.StartsWith("private:")) {
                        m_bPublic = false;
                        return 8;
                    }
                    if(sContent.StartsWith("protected:")) {
                        m_bPublic = false;
                        return 10;
                    }
                    if(sContent.StartsWith("{")) {
                        Console.WriteLine("I: Region found");
                        m_lStates.Push(STATE_REGION);
                        return 1;
                    }
                    if(sContent.StartsWith("};")) {
                        Console.WriteLine("I: Object left");
                        m_lObjects.Add(m_oCurrentObject);
                        m_oCurrentObject = null;
                        m_lStates.Pop();
                        return 2;
                    }
                    if(m_bPublic) {
                        oMatch = DoRegex(ref sContent, REGEX_METHOD);
                        if(oMatch.Success) {
                            var oMethod = new InputMethod(false,
                                oMatch.Groups[2].Value == "virtual",
                                oMatch.Groups[3].Value,
                                oMatch.Groups[4].Value,
                                new InputParameter[0],
                                oMatch.Groups[6].Value == "const",
                                oMatch.Groups[7].Value.Replace(" ", "") == "=0"
                            );
                            m_oCurrentObject.AddMethod(oMethod);
                            Console.WriteLine("I: Method found: " + oMatch.Groups[0].Value);
                            return oMatch.Length;
                        }
                    }
                    break;
                case STATE_REGION:
                    if(sContent.StartsWith("{")) {
                        Console.WriteLine("I: Region found");
                        m_lStates.Push(STATE_REGION);
                        return 1;
                    }
                    if(sContent.StartsWith("}")) {
                        Console.WriteLine("I: Region left");
                        m_lStates.Pop();
                        return 1;
                    }
                    break;
            }
            return 1;
        }

        private Match DoRegex(ref string sContent, string sRegex) {
            return Regex.Match(sContent, sRegex, RegexOptions.IgnoreCase | RegexOptions.Singleline);
        }
    }
}
