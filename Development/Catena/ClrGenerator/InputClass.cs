using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClrGenerator {
    
    public class InputClass {

        private List<InputMethod> m_lConstructors;
        private List<InputMethod> m_lMethods;
        public string[] Namespaces { get; private set; }
        public string Type { get; private set; }
        public string Name { get; private set; }

        public InputClass(string[] aNamespaces, string sType, string sName) {
            Namespaces = aNamespaces;
            Type = sType;
            Name = sName;
        }

        public void AddMethod(InputMethod oMethod) {
            
        }
    }
}
