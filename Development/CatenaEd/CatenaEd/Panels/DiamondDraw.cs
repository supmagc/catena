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

        private Diamond.Core m_oCore;

        public DiamondDraw() {
            InitializeComponent();

            m_oCore = new Diamond.Core();
            m_oCore.Create(this.Handle.ToInt32());
        }

        private void OnTick(object sender, EventArgs e) {
            m_oCore.Update();
        }
    }
}
