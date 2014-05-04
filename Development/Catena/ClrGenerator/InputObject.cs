using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClrGenerator {
    
    public class InputObject {

        private List<InputMethod> m_lConstructors = new List<InputMethod>();
        private List<InputMethod> m_lMethods = new List<InputMethod>();
        public string[] Namespaces { get; private set; }
        public string Type { get; private set; }
        public string Name { get; private set; }

        public bool IsRefType { get { return Type == "class"; } }
        public bool IsValType { get { return Type == "struct"; } }
        public string TypeClr { get { return (IsValType ? "value" : "ref") + " " + Type; } }
        public InputMethod[] Constructors { get { return m_lConstructors.ToArray(); } }
        public InputMethod[] Methods { get { return m_lMethods.ToArray(); } }

        public InputObject(string[] aNamespaces, string sType, string sName) {
            Namespaces = aNamespaces;
            Type = sType;
            Name = sName;
        }

        public void AddMethod(InputMethod oMethod) {
            if(oMethod.IsConstructor)
                m_lConstructors.Add(oMethod);
            else
                m_lMethods.Add(oMethod);
        }
    }
}
