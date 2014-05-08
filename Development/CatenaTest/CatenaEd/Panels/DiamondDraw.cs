using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Catena.Editor.Panels {

    public partial class DiamondDraw : UserControl {

        private Core m_oCore;

        public DiamondDraw() {
            InitializeComponent();

            m_oCore = new Core();
        }
    }
}
