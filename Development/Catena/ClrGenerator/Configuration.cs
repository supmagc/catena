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
        public string OutputBaseDirectory { get { return m_oXml.Descendants("Output").Descendants("BaseDirectory").Select(e => e.Value).First(); } }
        public string OutputHeaderDirectory { get { return m_oXml.Descendants("Output").Descendants("HeaderDirectory").Select(e => e.Value).First(); } }
        public string OutputSourceDirectory { get { return m_oXml.Descendants("Output").Descendants("SourceDirectory").Select(e => e.Value).First(); } }
        public string OutputBaseNamespace { get { return m_oXml.Descendants("Output").Descendants("BaseNamespace").Select(e => e.Value).First(); } }
        public InputFile[] Files { get { return m_lFiles.ToArray(); } }

        public Configuration() {
            m_oXml = XDocument.Load("ClrConfig.xml");

            foreach(var oElement in m_oXml.Descendants("File")) {
                m_lFiles.Add(new InputFile(this, oElement.Value, ""));
            }
        }
    }
}
