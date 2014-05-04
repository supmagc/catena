using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ClrGenerator {
    
    public class Configuration {

        private XDocument m_oXml;
        private List<InputFile> m_lFiles = new List<InputFile>();

        public string InputBaseDirectory { get { return m_oXml.Descendants("Input").Descendants("BaseDirectory").Select(e => e.Value).First(); } }
        public int OutputNamespaceRemovalDepth { get { return m_oXml.Descendants("Output").Descendants("NamespaceRemovalDepth").Select(e => (int)e).First(); } }
        public string OutputBaseDirectory { get { return m_oXml.Descendants("Output").Descendants("BaseDirectory").Select(e => e.Value).First(); } }
        public string OutputBaseProject { get { return m_oXml.Descendants("Output").Descendants("BaseProject").Select(e => e.Value).First(); } }
        public string OutputBaseNamespace { get { return m_oXml.Descendants("Output").Descendants("BaseNamespace").Select(e => e.Value).First(); } }
        public string OutputStandardHeader { get { return m_oXml.Descendants("Output").Descendants("StandardHeader").Select(e => e.Value).First(); } }
        public string OutputCombinedHeader { get { return m_oXml.Descendants("Output").Descendants("CombinedHeader").Select(e => e.Value).First(); } }
        public string OutputCombinedHeaderGuard { get { return m_oXml.Descendants("Output").Descendants("CombinedHeaderGuard").Select(e => e.Value).First(); } }
        public string OutputForwardHeader { get { return m_oXml.Descendants("Output").Descendants("ForwardHeader").Select(e => e.Value).First(); } }
        public string OutputForwardHeaderGuard { get { return m_oXml.Descendants("Output").Descendants("ForwardHeaderGuard").Select(e => e.Value).First(); } }
        public string OutputHeaderDirectory { get { return m_oXml.Descendants("Output").Descendants("HeaderDirectory").Select(e => e.Value).First(); } }
        public string OutputHeaderGuardPrefix { get { return m_oXml.Descendants("Output").Descendants("HeaderGuardPrefix").Select(e => e.Value).First(); } }
        public string OutputHeaderPrefix { get { return m_oXml.Descendants("Output").Descendants("HeaderPrefix").Select(e => e.Value).First(); } }
        public string OutputHeaderPrepend { get { return m_oXml.Descendants("Output").Descendants("HeaderPrepend").Select(e => e.Value).First(); } }
        public string OutputHeaderAppend { get { return m_oXml.Descendants("Output").Descendants("HeaderAppend").Select(e => e.Value).First(); } }
        public string OutputSourceDirectory { get { return m_oXml.Descendants("Output").Descendants("SourceDirectory").Select(e => e.Value).First(); } }
        public string OutputSourcePrefix { get { return m_oXml.Descendants("Output").Descendants("SourcePrefix").Select(e => e.Value).First(); } }
        public string OutputSourcePrepend { get { return m_oXml.Descendants("Output").Descendants("SourcePrepend").Select(e => e.Value).First(); } }
        public string OutputSourceAppend { get { return m_oXml.Descendants("Output").Descendants("SourceAppend").Select(e => e.Value).First(); } }
        public InputFile[] Files { get { return m_lFiles.ToArray(); } }

        public Configuration() {
            m_oXml = XDocument.Load("ClrConfig.xml");

            foreach(var oElement in m_oXml.Descendants("File")) {
                m_lFiles.Add(new InputFile(this, oElement.Value, ""));
            }
        }
    }
}
