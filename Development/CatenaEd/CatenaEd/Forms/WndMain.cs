using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Catena.Editor.Panels;

namespace Catena.Editor.Forms {
    public partial class WndMain : Form {

        private DiamondDraw m_oDrawT;
        private DiamondDraw m_oDrawR;
        private DiamondDraw m_oDrawL;
        private DiamondDraw m_oDrawP;

        public WndMain() {
            InitializeComponent();

            m_oDrawT = new DiamondDraw();
            m_oDrawT.Location = new Point(0, 0);

            m_oDrawR = new DiamondDraw();
            m_oDrawR.Location = new Point(512, 0);

            m_oDrawL = new DiamondDraw();
            m_oDrawL.Location = new Point(0, 384);

            m_oDrawP = new DiamondDraw();
            m_oDrawP.Location = new Point(512, 384);

            Controls.Add(m_oDrawT);
            Controls.Add(m_oDrawR);
            Controls.Add(m_oDrawL);
            Controls.Add(m_oDrawP);
        }

        private void OnLoad(object sender, EventArgs e) {
        }
    }
}
