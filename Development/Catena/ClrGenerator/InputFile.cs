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

        public Configuration Configuration { get; private set; }
        public string Path { get; private set; }

        private int m_nState;
        private Queue<int> m_lStates;
        private Queue<string> m_lNamespaces;
        private List<InputClass> m_lObjects;
        private InputClass m_oCurrentObject;

        public InputFile(Configuration oConfiguration, string sPath, string sOutput) {
            Configuration = oConfiguration;
            Path = sPath;
        }

        public bool Parse() {
            var sFullPath = Configuration.InputBaseDirectory + "/" + Path;
            if(!File.Exists(sFullPath))
                return false;

            m_lStates = new Queue<int>();
            m_lNamespaces = new Queue<string>();
            m_lObjects = new List<InputClass>();
            m_oCurrentObject = null;
            m_lStates.Enqueue(STATE_DEFAULT);
            var aLines = File.ReadAllLines(sFullPath);
            foreach(var sLine in aLines) {
                if(!ParseLine(sLine.Trim()))
                    return false;
            }
            return true;
        }

        private bool ParseLine(string sLine) {
            var nIndex = -1;

            if(m_lStates.Count == 0) {
                Console.WriteLine("E: Invalid structured file");
                return false;
            }

            // Pre check for comment and early return if found
            if((nIndex = sLine.IndexOf("/*")) >= 0) {
                bool bReturn = ParseLine(sLine.Substring(0, nIndex).Trim());
                m_lStates.Enqueue(STATE_COMMENT);
                return bReturn;
            }


            switch(m_lStates.Peek()) {
                case STATE_DEFAULT:
                case STATE_NAMESPACE:
                    if(sLine.StartsWith("namespace")) {
                        var sNamespace = sLine.Substring(sLine.LastIndexOf(" ") + 1);
                        m_lNamespaces.Enqueue(sNamespace);
                        m_lStates.Enqueue(STATE_NAMESPACE);
                    }
                    if((sLine.StartsWith("class") || sLine.StartsWith("struct")) && !sLine.EndsWith(";")) {
                        var oMatch = Regex.Match(sLine, @"^(class|struct)\s+([^\s]+\s+)?([a-z0-9]+)(\s+:\s+[^\s]+)?(\s+{)?$", RegexOptions.IgnoreCase);
                        if(!oMatch.Success) {
                            Console.WriteLine("E: Invalid object declaration: "+sLine);
                            return false;
                        }
                        m_oCurrentObject = new InputClass(m_lNamespaces.ToArray(), oMatch.Groups[1].Value, oMatch.Groups[3].Value);
                        m_lStates.Enqueue(STATE_OBJECT);
                    }
                    break;
                case STATE_COMMENT:
                    if((nIndex = sLine.LastIndexOf("*/")) >= 0) {
                        m_lStates.Dequeue();
                        return ParseLine(sLine.Substring(0, nIndex + 2).Trim());
                    }
                    break;
                case STATE_OBJECT:
                    break;
            }
            return true;
        }
    }
}
