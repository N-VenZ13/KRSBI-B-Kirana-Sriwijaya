<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.label5 = New System.Windows.Forms.Label()
        Me.TBportP = New System.Windows.Forms.TextBox()
        Me.label4 = New System.Windows.Forms.Label()
        Me.TBipP = New System.Windows.Forms.TextBox()
        Me.label3 = New System.Windows.Forms.Label()
        Me.label1 = New System.Windows.Forms.Label()
        Me.TBRobotP = New System.Windows.Forms.TextBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.TBrcvP = New System.Windows.Forms.TextBox()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.label6 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Button17 = New System.Windows.Forms.Button()
        Me.Button16 = New System.Windows.Forms.Button()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.Label14 = New System.Windows.Forms.Label()
        Me.TBrcvD = New System.Windows.Forms.TextBox()
        Me.Label15 = New System.Windows.Forms.Label()
        Me.TBRobotD = New System.Windows.Forms.TextBox()
        Me.TBportD = New System.Windows.Forms.TextBox()
        Me.Label16 = New System.Windows.Forms.Label()
        Me.TBipD = New System.Windows.Forms.TextBox()
        Me.Label17 = New System.Windows.Forms.Label()
        Me.Timer2 = New System.Windows.Forms.Timer(Me.components)
        Me.Timer3 = New System.Windows.Forms.Timer(Me.components)
        Me.Timer4 = New System.Windows.Forms.Timer(Me.components)
        Me.TBs = New System.Windows.Forms.TextBox()
        Me.TBSt = New System.Windows.Forms.TextBox()
        Me.Label26 = New System.Windows.Forms.Label()
        Me.TBDSD = New System.Windows.Forms.TextBox()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.Label38 = New System.Windows.Forms.Label()
        Me.RobotP = New System.Windows.Forms.PictureBox()
        Me.RobotD = New System.Windows.Forms.PictureBox()
        Me.pictureBox1 = New System.Windows.Forms.PictureBox()
        Me.TBDSP = New System.Windows.Forms.TextBox()
        Me.Label45 = New System.Windows.Forms.Label()
        Me.TBDCP = New System.Windows.Forms.TextBox()
        Me.Label46 = New System.Windows.Forms.Label()
        Me.Label23 = New System.Windows.Forms.Label()
        Me.TBDCD = New System.Windows.Forms.TextBox()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.Label29 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.TBA = New System.Windows.Forms.TextBox()
        Me.TextBox4 = New System.Windows.Forms.TextBox()
        Me.TBB = New System.Windows.Forms.TextBox()
        CType(Me.RobotP, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.RobotD, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'label5
        '
        Me.label5.AutoSize = True
        Me.label5.ForeColor = System.Drawing.Color.Red
        Me.label5.Location = New System.Drawing.Point(923, 203)
        Me.label5.Name = "label5"
        Me.label5.Size = New System.Drawing.Size(138, 13)
        Me.label5.TabIndex = 14
        Me.label5.Text = "ROBOT PENYERANG (R1)"
        '
        'TBportP
        '
        Me.TBportP.Location = New System.Drawing.Point(1116, 223)
        Me.TBportP.Name = "TBportP"
        Me.TBportP.Size = New System.Drawing.Size(78, 20)
        Me.TBportP.TabIndex = 13
        Me.TBportP.Text = "28097"
        '
        'label4
        '
        Me.label4.AutoSize = True
        Me.label4.ForeColor = System.Drawing.Color.Lime
        Me.label4.Location = New System.Drawing.Point(1086, 226)
        Me.label4.Name = "label4"
        Me.label4.Size = New System.Drawing.Size(26, 13)
        Me.label4.TabIndex = 12
        Me.label4.Text = "Port"
        '
        'TBipP
        '
        Me.TBipP.Location = New System.Drawing.Point(979, 226)
        Me.TBipP.Name = "TBipP"
        Me.TBipP.Size = New System.Drawing.Size(85, 20)
        Me.TBipP.TabIndex = 11
        Me.TBipP.Text = "192.168.100.29"
        '
        'label3
        '
        Me.label3.AutoSize = True
        Me.label3.ForeColor = System.Drawing.Color.Lime
        Me.label3.Location = New System.Drawing.Point(923, 229)
        Me.label3.Name = "label3"
        Me.label3.Size = New System.Drawing.Size(58, 13)
        Me.label3.TabIndex = 10
        Me.label3.Text = "IP Address"
        '
        'label1
        '
        Me.label1.AutoSize = True
        Me.label1.ForeColor = System.Drawing.Color.Lime
        Me.label1.Location = New System.Drawing.Point(927, 305)
        Me.label1.Name = "label1"
        Me.label1.Size = New System.Drawing.Size(15, 13)
        Me.label1.TabIndex = 17
        Me.label1.Text = "R"
        '
        'TBRobotP
        '
        Me.TBRobotP.Location = New System.Drawing.Point(1040, 302)
        Me.TBRobotP.Multiline = True
        Me.TBRobotP.Name = "TBRobotP"
        Me.TBRobotP.Size = New System.Drawing.Size(26, 22)
        Me.TBRobotP.TabIndex = 15
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.ForeColor = System.Drawing.Color.Lime
        Me.Label2.Location = New System.Drawing.Point(1019, 305)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(14, 13)
        Me.Label2.TabIndex = 19
        Me.Label2.Text = "B"
        '
        'TBrcvP
        '
        Me.TBrcvP.Location = New System.Drawing.Point(979, 302)
        Me.TBrcvP.Multiline = True
        Me.TBrcvP.Name = "TBrcvP"
        Me.TBrcvP.Size = New System.Drawing.Size(33, 22)
        Me.TBrcvP.TabIndex = 18
        '
        'Timer1
        '
        '
        'label6
        '
        Me.label6.AutoSize = True
        Me.label6.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.label6.Location = New System.Drawing.Point(1081, 9)
        Me.label6.Name = "label6"
        Me.label6.Size = New System.Drawing.Size(118, 13)
        Me.label6.TabIndex = 21
        Me.label6.Text = "KRN SRIWIJAYA 2020"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label9.Location = New System.Drawing.Point(1276, 43)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(21, 13)
        Me.Label9.TabIndex = 67
        Me.Label9.Text = "R2"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.ForeColor = System.Drawing.SystemColors.ControlLightLight
        Me.Label7.Location = New System.Drawing.Point(976, 43)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(21, 13)
        Me.Label7.TabIndex = 65
        Me.Label7.Text = "R1"
        '
        'Button17
        '
        Me.Button17.BackColor = System.Drawing.Color.Yellow
        Me.Button17.Location = New System.Drawing.Point(1146, 121)
        Me.Button17.Name = "Button17"
        Me.Button17.Size = New System.Drawing.Size(53, 52)
        Me.Button17.TabIndex = 60
        Me.Button17.Text = "Retry"
        Me.Button17.UseVisualStyleBackColor = False
        '
        'Button16
        '
        Me.Button16.BackColor = System.Drawing.Color.Lime
        Me.Button16.Location = New System.Drawing.Point(1079, 121)
        Me.Button16.Name = "Button16"
        Me.Button16.Size = New System.Drawing.Size(53, 52)
        Me.Button16.TabIndex = 59
        Me.Button16.Text = "Start"
        Me.Button16.UseVisualStyleBackColor = False
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.ForeColor = System.Drawing.Color.Red
        Me.Label11.Location = New System.Drawing.Point(1251, 666)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(108, 13)
        Me.Label11.TabIndex = 94
        Me.Label11.Text = "#KRSBI2020JUARA!"
        '
        'Label12
        '
        Me.Label12.AutoSize = True
        Me.Label12.ForeColor = System.Drawing.Color.Red
        Me.Label12.Location = New System.Drawing.Point(922, 394)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(130, 13)
        Me.Label12.TabIndex = 95
        Me.Label12.Text = "ROBOT DEFENDER (R2)"
        '
        'Label14
        '
        Me.Label14.AutoSize = True
        Me.Label14.ForeColor = System.Drawing.Color.Lime
        Me.Label14.Location = New System.Drawing.Point(1009, 505)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(14, 13)
        Me.Label14.TabIndex = 105
        Me.Label14.Text = "B"
        '
        'TBrcvD
        '
        Me.TBrcvD.Location = New System.Drawing.Point(975, 500)
        Me.TBrcvD.Multiline = True
        Me.TBrcvD.Name = "TBrcvD"
        Me.TBrcvD.Size = New System.Drawing.Size(31, 22)
        Me.TBrcvD.TabIndex = 104
        '
        'Label15
        '
        Me.Label15.AutoSize = True
        Me.Label15.ForeColor = System.Drawing.Color.Lime
        Me.Label15.Location = New System.Drawing.Point(921, 505)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(15, 13)
        Me.Label15.TabIndex = 103
        Me.Label15.Text = "R"
        '
        'TBRobotD
        '
        Me.TBRobotD.Location = New System.Drawing.Point(1024, 500)
        Me.TBRobotD.Multiline = True
        Me.TBRobotD.Name = "TBRobotD"
        Me.TBRobotD.Size = New System.Drawing.Size(37, 22)
        Me.TBRobotD.TabIndex = 101
        '
        'TBportD
        '
        Me.TBportD.Location = New System.Drawing.Point(1116, 422)
        Me.TBportD.Name = "TBportD"
        Me.TBportD.Size = New System.Drawing.Size(73, 20)
        Me.TBportD.TabIndex = 100
        Me.TBportD.Text = "28097"
        '
        'Label16
        '
        Me.Label16.AutoSize = True
        Me.Label16.ForeColor = System.Drawing.Color.Lime
        Me.Label16.Location = New System.Drawing.Point(1084, 427)
        Me.Label16.Name = "Label16"
        Me.Label16.Size = New System.Drawing.Size(26, 13)
        Me.Label16.TabIndex = 99
        Me.Label16.Text = "Port"
        '
        'TBipD
        '
        Me.TBipD.Location = New System.Drawing.Point(975, 422)
        Me.TBipD.Name = "TBipD"
        Me.TBipD.Size = New System.Drawing.Size(86, 20)
        Me.TBipD.TabIndex = 98
        Me.TBipD.Text = "192.168.100.38"
        '
        'Label17
        '
        Me.Label17.AutoSize = True
        Me.Label17.ForeColor = System.Drawing.Color.Lime
        Me.Label17.Location = New System.Drawing.Point(919, 425)
        Me.Label17.Name = "Label17"
        Me.Label17.Size = New System.Drawing.Size(58, 13)
        Me.Label17.TabIndex = 97
        Me.Label17.Text = "IP Address"
        '
        'Timer2
        '
        '
        'TBs
        '
        Me.TBs.Location = New System.Drawing.Point(1033, 138)
        Me.TBs.Multiline = True
        Me.TBs.Name = "TBs"
        Me.TBs.Size = New System.Drawing.Size(25, 23)
        Me.TBs.TabIndex = 115
        Me.TBs.Text = "s"
        '
        'TBSt
        '
        Me.TBSt.Location = New System.Drawing.Point(1207, 138)
        Me.TBSt.Multiline = True
        Me.TBSt.Name = "TBSt"
        Me.TBSt.Size = New System.Drawing.Size(25, 23)
        Me.TBSt.TabIndex = 115
        Me.TBSt.Text = "K"
        '
        'Label26
        '
        Me.Label26.AutoSize = True
        Me.Label26.ForeColor = System.Drawing.Color.Lime
        Me.Label26.Location = New System.Drawing.Point(922, 451)
        Me.Label26.Name = "Label26"
        Me.Label26.Size = New System.Drawing.Size(40, 13)
        Me.Label26.TabIndex = 12
        Me.Label26.Text = "Data S"
        '
        'TBDSD
        '
        Me.TBDSD.Location = New System.Drawing.Point(976, 448)
        Me.TBDSD.Multiline = True
        Me.TBDSD.Name = "TBDSD"
        Me.TBDSD.Size = New System.Drawing.Size(85, 21)
        Me.TBDSD.TabIndex = 15
        '
        'TextBox2
        '
        Me.TextBox2.Location = New System.Drawing.Point(1372, 297)
        Me.TextBox2.Multiline = True
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(25, 23)
        Me.TextBox2.TabIndex = 119
        Me.TextBox2.Text = "p"
        '
        'Label38
        '
        Me.Label38.AutoSize = True
        Me.Label38.ForeColor = System.Drawing.Color.Red
        Me.Label38.Location = New System.Drawing.Point(1664, 598)
        Me.Label38.Name = "Label38"
        Me.Label38.Size = New System.Drawing.Size(108, 13)
        Me.Label38.TabIndex = 94
        Me.Label38.Text = "#KRSBI2020JUARA!"
        '
        'RobotP
        '
        Me.RobotP.Image = CType(resources.GetObject("RobotP.Image"), System.Drawing.Image)
        Me.RobotP.Location = New System.Drawing.Point(599, -1)
        Me.RobotP.Name = "RobotP"
        Me.RobotP.Size = New System.Drawing.Size(50, 50)
        Me.RobotP.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.RobotP.TabIndex = 122
        Me.RobotP.TabStop = False
        '
        'RobotD
        '
        Me.RobotD.Image = CType(resources.GetObject("RobotD.Image"), System.Drawing.Image)
        Me.RobotD.Location = New System.Drawing.Point(599, 549)
        Me.RobotD.Name = "RobotD"
        Me.RobotD.Size = New System.Drawing.Size(50, 50)
        Me.RobotD.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.RobotD.TabIndex = 122
        Me.RobotD.TabStop = False
        '
        'pictureBox1
        '
        Me.pictureBox1.Image = CType(resources.GetObject("pictureBox1.Image"), System.Drawing.Image)
        Me.pictureBox1.Location = New System.Drawing.Point(0, -1)
        Me.pictureBox1.Name = "pictureBox1"
        Me.pictureBox1.Size = New System.Drawing.Size(900, 600)
        Me.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.pictureBox1.TabIndex = 20
        Me.pictureBox1.TabStop = False
        '
        'TBDSP
        '
        Me.TBDSP.Location = New System.Drawing.Point(979, 250)
        Me.TBDSP.Multiline = True
        Me.TBDSP.Name = "TBDSP"
        Me.TBDSP.Size = New System.Drawing.Size(86, 22)
        Me.TBDSP.TabIndex = 15
        '
        'Label45
        '
        Me.Label45.AutoSize = True
        Me.Label45.ForeColor = System.Drawing.Color.Lime
        Me.Label45.Location = New System.Drawing.Point(924, 253)
        Me.Label45.Name = "Label45"
        Me.Label45.Size = New System.Drawing.Size(40, 13)
        Me.Label45.TabIndex = 12
        Me.Label45.Text = "Data S"
        '
        'TBDCP
        '
        Me.TBDCP.Location = New System.Drawing.Point(979, 276)
        Me.TBDCP.Multiline = True
        Me.TBDCP.Name = "TBDCP"
        Me.TBDCP.Size = New System.Drawing.Size(87, 22)
        Me.TBDCP.TabIndex = 15
        '
        'Label46
        '
        Me.Label46.AutoSize = True
        Me.Label46.ForeColor = System.Drawing.Color.Lime
        Me.Label46.Location = New System.Drawing.Point(924, 279)
        Me.Label46.Name = "Label46"
        Me.Label46.Size = New System.Drawing.Size(40, 13)
        Me.Label46.TabIndex = 12
        Me.Label46.Text = "Data C"
        '
        'Label23
        '
        Me.Label23.AutoSize = True
        Me.Label23.ForeColor = System.Drawing.Color.Lime
        Me.Label23.Location = New System.Drawing.Point(922, 478)
        Me.Label23.Name = "Label23"
        Me.Label23.Size = New System.Drawing.Size(40, 13)
        Me.Label23.TabIndex = 12
        Me.Label23.Text = "Data C"
        '
        'TBDCD
        '
        Me.TBDCD.Location = New System.Drawing.Point(976, 473)
        Me.TBDCD.Multiline = True
        Me.TBDCD.Name = "TBDCD"
        Me.TBDCD.Size = New System.Drawing.Size(85, 22)
        Me.TBDCD.TabIndex = 15
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(1124, 305)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(50, 23)
        Me.Button4.TabIndex = 124
        Me.Button4.Text = "Clear"
        Me.Button4.UseVisualStyleBackColor = True
        '
        'Label29
        '
        Me.Label29.AutoSize = True
        Me.Label29.ForeColor = System.Drawing.Color.Lime
        Me.Label29.Location = New System.Drawing.Point(1086, 310)
        Me.Label29.Name = "Label29"
        Me.Label29.Size = New System.Drawing.Size(37, 13)
        Me.Label29.TabIndex = 125
        Me.Label29.Text = "Del All"
        '
        'Button1
        '
        Me.Button1.BackColor = System.Drawing.Color.Black
        Me.Button1.Location = New System.Drawing.Point(1263, 59)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(48, 21)
        Me.Button1.TabIndex = 126
        Me.Button1.Text = "Retry"
        Me.Button1.UseVisualStyleBackColor = False
        '
        'Button2
        '
        Me.Button2.BackColor = System.Drawing.Color.Black
        Me.Button2.Location = New System.Drawing.Point(970, 59)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(42, 21)
        Me.Button2.TabIndex = 127
        Me.Button2.Text = "Retry"
        Me.Button2.UseVisualStyleBackColor = False
        '
        'TBA
        '
        Me.TBA.BackColor = System.Drawing.SystemColors.MenuText
        Me.TBA.Location = New System.Drawing.Point(654, 173)
        Me.TBA.Multiline = True
        Me.TBA.Name = "TBA"
        Me.TBA.Size = New System.Drawing.Size(48, 43)
        Me.TBA.TabIndex = 129
        Me.TBA.Text = "A"
        '
        'TextBox4
        '
        Me.TextBox4.BackColor = System.Drawing.SystemColors.MenuText
        Me.TextBox4.Location = New System.Drawing.Point(846, 271)
        Me.TextBox4.Multiline = True
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(54, 47)
        Me.TextBox4.TabIndex = 132
        '
        'TBB
        '
        Me.TBB.BackColor = System.Drawing.SystemColors.MenuText
        Me.TBB.Location = New System.Drawing.Point(563, 360)
        Me.TBB.Multiline = True
        Me.TBB.Name = "TBB"
        Me.TBB.Size = New System.Drawing.Size(51, 47)
        Me.TBB.TabIndex = 133
        Me.TBB.Text = "B"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.MenuText
        Me.ClientSize = New System.Drawing.Size(1370, 687)
        Me.Controls.Add(Me.TBB)
        Me.Controls.Add(Me.TextBox4)
        Me.Controls.Add(Me.TBA)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label29)
        Me.Controls.Add(Me.Button4)
        Me.Controls.Add(Me.RobotP)
        Me.Controls.Add(Me.RobotD)
        Me.Controls.Add(Me.TextBox2)
        Me.Controls.Add(Me.TBSt)
        Me.Controls.Add(Me.TBs)
        Me.Controls.Add(Me.Label14)
        Me.Controls.Add(Me.TBrcvD)
        Me.Controls.Add(Me.Label15)
        Me.Controls.Add(Me.TBRobotD)
        Me.Controls.Add(Me.TBportD)
        Me.Controls.Add(Me.Label16)
        Me.Controls.Add(Me.TBipD)
        Me.Controls.Add(Me.Label17)
        Me.Controls.Add(Me.Label12)
        Me.Controls.Add(Me.Label38)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Button17)
        Me.Controls.Add(Me.Button16)
        Me.Controls.Add(Me.label6)
        Me.Controls.Add(Me.pictureBox1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.TBrcvP)
        Me.Controls.Add(Me.label1)
        Me.Controls.Add(Me.TBDCD)
        Me.Controls.Add(Me.TBDSD)
        Me.Controls.Add(Me.TBDCP)
        Me.Controls.Add(Me.TBDSP)
        Me.Controls.Add(Me.TBRobotP)
        Me.Controls.Add(Me.label5)
        Me.Controls.Add(Me.TBportP)
        Me.Controls.Add(Me.Label23)
        Me.Controls.Add(Me.Label26)
        Me.Controls.Add(Me.Label46)
        Me.Controls.Add(Me.Label45)
        Me.Controls.Add(Me.label4)
        Me.Controls.Add(Me.TBipP)
        Me.Controls.Add(Me.label3)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.RobotP, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.RobotD, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Private WithEvents label5 As System.Windows.Forms.Label
    Private WithEvents TBportP As System.Windows.Forms.TextBox
    Private WithEvents label4 As System.Windows.Forms.Label
    Private WithEvents TBipP As System.Windows.Forms.TextBox
    Private WithEvents label3 As System.Windows.Forms.Label
    Private WithEvents label1 As System.Windows.Forms.Label
    Private WithEvents TBRobotP As System.Windows.Forms.TextBox
    Private WithEvents Label2 As System.Windows.Forms.Label
    Private WithEvents TBrcvP As System.Windows.Forms.TextBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents label6 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Button17 As System.Windows.Forms.Button
    Friend WithEvents Button16 As System.Windows.Forms.Button
    Private WithEvents Label11 As System.Windows.Forms.Label
    Private WithEvents Label12 As System.Windows.Forms.Label
    Private WithEvents Label14 As System.Windows.Forms.Label
    Private WithEvents TBrcvD As System.Windows.Forms.TextBox
    Private WithEvents Label15 As System.Windows.Forms.Label
    Private WithEvents TBRobotD As System.Windows.Forms.TextBox
    Private WithEvents TBportD As System.Windows.Forms.TextBox
    Private WithEvents Label16 As System.Windows.Forms.Label
    Private WithEvents TBipD As System.Windows.Forms.TextBox
    Private WithEvents Label17 As System.Windows.Forms.Label
    Friend WithEvents Timer2 As System.Windows.Forms.Timer
    Friend WithEvents Timer3 As System.Windows.Forms.Timer
    Friend WithEvents Timer4 As System.Windows.Forms.Timer
    Friend WithEvents TBs As System.Windows.Forms.TextBox
    Friend WithEvents TBSt As System.Windows.Forms.TextBox
    Private WithEvents Label26 As System.Windows.Forms.Label
    Private WithEvents TBDSD As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents RobotD As System.Windows.Forms.PictureBox
    Friend WithEvents RobotP As System.Windows.Forms.PictureBox
    Private WithEvents Label38 As System.Windows.Forms.Label
    Private WithEvents pictureBox1 As System.Windows.Forms.PictureBox
    Private WithEvents TBDSP As System.Windows.Forms.TextBox
    Private WithEvents Label45 As System.Windows.Forms.Label
    Private WithEvents TBDCP As System.Windows.Forms.TextBox
    Private WithEvents Label46 As System.Windows.Forms.Label
    Private WithEvents Label23 As System.Windows.Forms.Label
    Private WithEvents TBDCD As System.Windows.Forms.TextBox
    Private WithEvents Button4 As System.Windows.Forms.Button
    Private WithEvents Label29 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents TBA As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents TBB As System.Windows.Forms.TextBox

End Class
