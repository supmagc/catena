using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Diamond;

namespace Catena.Editor.Panels {

    public partial class DiamondDraw : UserControl {

        private Core m_oCore;
        private SceneView m_oView;

        public DiamondDraw(Core oCore) {
            InitializeComponent();

            m_oCore = oCore;
            m_oView = m_oCore.Create(this.Handle.ToInt32(), (uint)Size.Width, (uint)Size.Height, false);
        }

        private void OnTick(object sender, EventArgs e) {
            m_oCore.Update();
        }

        private void OnResize(object sender, EventArgs e) {
            m_oView.SetSize((uint)Size.Width, (uint)Size.Height);
        }
    }
}
