using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClrGenerator {
    
    public class InputClass {

        private List<InputMethod> m_lConstructors;
        private List<InputMethod> m_lMethods;
        private string[] m_aNamespaces;
        private string m_sType;
        private string m_sName;

        public string Name { get { return m_sName; } }

        public InputClass(string[] aNamespaces, string sType, string sName) {
            m_aNamespaces = aNamespaces;
            m_sType = sType;
            m_sName = sName;
        }

        public void AddMethod(InputMethod oMethod) {
            
        }
    }
}
