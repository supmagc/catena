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
        public WndMain() {
            InitializeComponent();
        }

        private void Form_OnLoad(object sender, EventArgs e) {

            components.Add(new DiamondDraw());
        }
    }
}
