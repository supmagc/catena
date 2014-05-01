using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClrGenerator {

    public class InputMethod {

        public readonly bool m_bStatic;
        public readonly bool m_bVirtual;
        public readonly string m_sReturn;
        public readonly string m_sName;
        public readonly InputParameter[] m_aParameters;
        public readonly bool m_bConst;
        public readonly bool m_bEmpty;

        public bool IsConstructor { get { return false; } }

        public InputMethod(bool bStatic, bool bVirtual, string sReturn, string sName, InputParameter[] aParameters, bool bConst, bool bEmpty) {

        }
    }
}
