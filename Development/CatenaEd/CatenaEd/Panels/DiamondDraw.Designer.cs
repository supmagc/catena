﻿namespace Catena.Editor.Panels {
    partial class DiamondDraw {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if(disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.components = new System.ComponentModel.Container();
            this.m_oTimer = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // m_oTimer
            // 
            this.m_oTimer.Enabled = true;
            this.m_oTimer.Tick += new System.EventHandler(this.OnTick);
            // 
            // DiamondDraw
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Name = "DiamondDraw";
            this.Size = new System.Drawing.Size(1024, 768);
            this.Resize += new System.EventHandler(this.OnResize);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Timer m_oTimer;
    }
}
