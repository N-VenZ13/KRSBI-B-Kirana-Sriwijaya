Imports System.Net
Imports System.IO
Imports System.Text.Encoding
Imports System.Net.Sockets
Imports System.Threading.Tasks

Public Class Form1

    Dim speed As Integer = 5 'Kecepatan gerak robot
    Dim direction As String = "" 'Arah gerakan

    Dim publisher As New Sockets.UdpClient(0)
    Dim subscriber As New Sockets.UdpClient(28097)
    Dim TCPClientz As Sockets.TcpClient
    Dim TCPClientStream As Sockets.NetworkStream

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load, pictureBox1.Click
        subscriber.Client.ReceiveTimeout = 100
        subscriber.Client.Blocking = False
    End Sub

    'Basestation mengirim data ke Robot Penyerang'

    Private Sub TBRobotP_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TBRobotP.TextChanged
        publisher.Connect(TBipP.Text, TBportP.Text)
        Dim sendbytes() As Byte = ASCII.GetBytes(TBRobotP.Text)
        publisher.Send(sendbytes, sendbytes.Length)
        Timer1.Start()
    End Sub

    'Connect Robot Penyerang'

    '  Private Sub CheckBox1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CheckBox1.CheckedChanged

    'Try
    '   If (CheckBox1.Checked = True) Then


    '            Label39.Text = "Connected"

    '       Else

    '            Label39.Text = "Disconnected"
    '       End If
    '  Catch

    '    End Try


    'End Sub

    'Basestation Menerima Data dari Robot Penyerang ' 

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick



        Try
            Dim ep As IPEndPoint = New IPEndPoint(IPAddress.Any, 0)
            Dim rcvbytes() As Byte = subscriber.Receive(ep)
            TBDSP.Text = ASCII.GetString(rcvbytes)
            If TBDSP.Text.StartsWith("<") Then
                TBDCP.Text = ASCII.GetString(rcvbytes)
            End If
        Catch ex As Exception

        End Try



    End Sub

    'Data yang di pisah untuk di kirim ke R'

    Private Sub TBDCP_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TBDCP.TextChanged
        Dim text() As String
        text = Split(TBDCP.Text, ":")
        TBrcvP.Text = text(1)
        TBRobotD.Text = text(1)
        TBRobotP.Text = text(1)
    End Sub
    'Basestation Mengirim Data ke Robot Defender'

    Private Sub TBRobotD_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TBRobotD.TextChanged
        publisher.Connect(TBipD.Text, TBportD.Text)
        Dim sendbytes() As Byte = ASCII.GetBytes(TBRobotD.Text)
        publisher.Send(sendbytes, sendbytes.Length)
        Timer2.Start()
    End Sub

    'Basestation Menerima Data dari Robot Defender'

    Private Sub Timer2_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer2.Tick
        Try

            Dim ep As IPEndPoint = New IPEndPoint(IPAddress.Any, 0)
            Dim rcvbytes() As Byte = subscriber.Receive(ep)
            TBDSD.Text = ASCII.GetString(rcvbytes)
            If TBDSD.Text.StartsWith("<") Then
                TBDCD.Text = ASCII.GetString(rcvbytes)
            End If
        Catch ex As Exception

        End Try

    End Sub

    'Data yang di pisah untuk di kirim ke R

    Private Sub TBDCD_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TBDCD.TextChanged
        Dim text() As String
        text = Split(TBDCD.Text, ":")
        TBrcvD.Text = text(1)
        TBRobotP.Text = text(1)
        TBRobotD.Text = text(1)

    End Sub
    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click

        ' ' Gerakan ke bawah selama 5 detik
        'For i As Integer = 1 To (3400 \ 100) ' 5000ms / 100ms per loop
        '    RobotP.Top += speed
        '    RobotD.Top += speed
        '    Await Task.Delay(100) ' Delay setiap 100ms agar gerakan lebih halus
        'Next

        ' 'Gerakan ke kiri selama 3 detik
        'For i As Integer = 1 To (3000 \ 100)
        '    RobotP.Left -= speed
        '    RobotD.Left += speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (4900 \ 100)
        '    RobotD.Left += speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (3200 \ 100)
        '    ball.Left += speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (2000 \ 100)
        '    RobotP.Top -= speed
        '    RobotD.Top -= speed
        '    RobotD.Left -= speed
        '    ball.Top -= speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (3000 \ 100)
        '    RobotD.Left -= speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (500 \ 100)

        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (8000 \ 100)

        '    ball.Left -= speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (1500 \ 100)
        '    RobotP.Top -= speed
        '    RobotD.Top -= speed

        '    ball.Top -= speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (2500 \ 100)
        '    RobotP.Top -= speed

        '    Await Task.Delay(100)
        'Next
        'For i As Integer = 1 To (1000 \ 100)
        '    RobotP.Left += speed

        '    Await Task.Delay(100)
        'Next
        'For i As Integer = 1 To (2000 \ 100)
        '    RobotP.Top -= speed

        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (4700 \ 100)
        '    ball.Left += speed
        '    ball.Top -= speed
        '    ball.Left += speed
        '    Await Task.Delay(100)
        'Next

        'For i As Integer = 1 To (2200 \ 100)
        '    ball.Left -= speed
        '    ball.Top -= speed
        '    ball.Left -= speed
        '    ball.Left -= speed
        '    Await Task.Delay(100)
        'Next



        TBRobotP.Text = TBs.Text
        TBRobotD.Text = TBs.Text
        If TBs.Text = "S1" Then
            TBs.Text = "s1"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBs.Text = "s1" Then
            TBs.Text = "S1"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        End If
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        TBRobotP.Text = Tbm1.Text
        TBRobotD.Text = Tbm1.Text
        If Tbm1.Text = "M1" Then
            Tbm1.Text = "m1"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf Tbm1.Text = "m1" Then
            Tbm1.Text = "M1"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        End If
    End Sub


    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        TBRobotP.Text = TBSt.Text
        TBRobotD.Text = TBSt.Text

        If TBSt.Text = "R12" Then
            TBSt.Text = "r12"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBSt.Text = "r12" Then
            TBSt.Text = "R12"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub


    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        TBRobotP.Text = TBma.Text
        TBRobotD.Text = TBma.Text
        If TBma.Text = "S2" Then
            TBma.Text = "s2"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBma.Text = "s2" Then
            TBma.Text = "S2"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        End If
    End Sub


    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        TBRobotP.Text = Tbm2.Text
        TBRobotD.Text = Tbm2.Text
        If Tbm2.Text = "M2" Then
            Tbm2.Text = "m2"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf Tbm2.Text = "m2" Then
            Tbm2.Text = "M2"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        End If
    End Sub


    Private Sub TBRe1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TBRe1.Click
        TBRobotP.Text = Tbr2.Text
        TBRobotD.Text = Tbr2.Text

        If Tbr2.Text = "S5" Then
            Tbr2.Text = "s5"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf Tbr2.Text = "s5" Then
            Tbr2.Text = "S5"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        TBRobotP.Text = TBcy.Text
        TBRobotD.Text = TBcy.Text
        If TBcy.Text = "S4" Then
            TBcy.Text = "s4"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBcy.Text = "s4" Then
            TBcy.Text = "S4"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        End If
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        TBRobotP.Text = Tbm3.Text
        TBRobotD.Text = Tbm3.Text
        If Tbm3.Text = "M4" Then
            Tbm3.Text = "m4"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf Tbm3.Text = "m4" Then
            Tbm3.Text = "M4"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        End If
    End Sub

    Private Sub TBRe2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TBRe2.Click
        TBRobotP.Text = Tbr3.Text
        TBRobotD.Text = Tbr3.Text

        If Tbr3.Text = "R5" Then
            Tbr3.Text = "r5"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf Tbr3.Text = "r5" Then
            Tbr3.Text = "R5"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub


    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        TBRobotP.Text = TBRR.Text
        TBRobotD.Text = TBRR.Text

        If TBRR.Text = "RR" Then
            TBRR.Text = "rr"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBRR.Text = "rr" Then
            TBRR.Text = "RR"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        TBRobotP.Text = TBRS.Text
        TBRobotD.Text = TBRS.Text

        If TBRS.Text = "RS" Then
            TBRS.Text = "rs"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBRS.Text = "rs" Then
            TBRS.Text = "RS"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub


    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        TBRobotP.Text = TBB.Text
        TBRobotD.Text = TBB.Text
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        TBRobotP.Text = " "
        TBRobotD.Text = " "
        TBrcvP.Text = " "
        TBrcvD.Text = " "
        TBDCP.Text = "<: "
        TBDSP.Text = "<: "
        TBDCD.Text = "<: "
        TBDSD.Text = "<: "
    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        TBRobotP.Text = TBMV.Text
        TBRobotD.Text = TBMV.Text

        If TBMV.Text = "M3" Then
            TBMV.Text = "m3"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBMV.Text = "m3" Then
            TBMV.Text = "M3"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        TBRobotP.Text = TBSM.Text
        TBRobotD.Text = TBSM.Text

        If TBSM.Text = "S3" Then
            TBSM.Text = "s3"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBSM.Text = "s3" Then
            TBSM.Text = "S3"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        TBRobotP.Text = TBRM.Text
        TBRobotD.Text = TBRM.Text

        If TBRM.Text = "R34" Then
            TBRM.Text = "r34"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBRM.Text = "r34" Then
            TBRM.Text = "R34"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If
    End Sub


    Private Sub Button14_Click(sender As Object, e As EventArgs) Handles Button14.Click
        TBRobotP.Text = TBMB.Text
        TBRobotD.Text = TBMB.Text

        If TBMB.Text = "M5" Then
            TBMB.Text = "m5"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "

        ElseIf TBMB.Text = "m5" Then
            TBMB.Text = "M5"
            TBRobotP.Text = " "
            TBRobotD.Text = " "
            TBrcvP.Text = " "
            TBrcvD.Text = " "
            TBDCP.Text = "<: "
            TBDSP.Text = "<: "
            TBDCD.Text = "<: "
            TBDSD.Text = "<: "
        End If

    End Sub

    Private Sub Button15_Click(sender As Object, e As EventArgs)

    End Sub

    Private Sub RobotP_Click(sender As Object, e As EventArgs) Handles RobotP.Click

    End Sub

    Private Sub TBportP_TextChanged(sender As Object, e As EventArgs) Handles TBportP.TextChanged

    End Sub

    Private Sub label4_Click(sender As Object, e As EventArgs) Handles label4.Click

    End Sub

    Private Sub TBipP_TextChanged(sender As Object, e As EventArgs) Handles TBipP.TextChanged

    End Sub

    Private Sub label3_Click(sender As Object, e As EventArgs) Handles label3.Click

    End Sub

    Private Sub label1_Click(sender As Object, e As EventArgs) Handles label1.Click

    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub

    Private Sub TBrcvP_TextChanged(sender As Object, e As EventArgs) Handles TBrcvP.TextChanged

    End Sub

    Private Sub label6_Click(sender As Object, e As EventArgs) Handles label6.Click

    End Sub

    Private Sub Label9_Click(sender As Object, e As EventArgs) Handles Label9.Click

    End Sub

    Private Sub Label7_Click(sender As Object, e As EventArgs) Handles Label7.Click

    End Sub

    Private Sub Label11_Click(sender As Object, e As EventArgs) Handles Label11.Click

    End Sub

    Private Sub TBs_TextChanged(sender As Object, e As EventArgs) Handles TBs.TextChanged

    End Sub

    Private Sub TBSt_TextChanged(sender As Object, e As EventArgs) Handles TBSt.TextChanged

    End Sub

    Private Sub TextBox2_TextChanged(sender As Object, e As EventArgs) Handles TextBox2.TextChanged

    End Sub

    Private Sub Label38_Click(sender As Object, e As EventArgs) Handles Label38.Click

    End Sub

    Private Sub TBDSP_TextChanged(sender As Object, e As EventArgs) Handles TBDSP.TextChanged

    End Sub

    Private Sub Label45_Click(sender As Object, e As EventArgs) Handles Label45.Click

    End Sub

    Private Sub Label46_Click(sender As Object, e As EventArgs) Handles Label46.Click

    End Sub

    Private Sub Label29_Click(sender As Object, e As EventArgs) Handles Label29.Click

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

    End Sub

    Private Sub TBma_TextChanged(sender As Object, e As EventArgs) Handles TBma.TextChanged

    End Sub

    Private Sub TBcy_TextChanged(sender As Object, e As EventArgs) Handles TBcy.TextChanged

    End Sub

    Private Sub Tbm1_TextChanged(sender As Object, e As EventArgs) Handles Tbm1.TextChanged

    End Sub

    Private Sub Tbm2_TextChanged(sender As Object, e As EventArgs) Handles Tbm2.TextChanged

    End Sub

    Private Sub Tbm3_TextChanged(sender As Object, e As EventArgs) Handles Tbm3.TextChanged

    End Sub

    Private Sub Tbr2_TextChanged(sender As Object, e As EventArgs) Handles Tbr2.TextChanged

    End Sub

    Private Sub Tbr3_TextChanged(sender As Object, e As EventArgs) Handles Tbr3.TextChanged

    End Sub

    Private Sub TBRR_TextChanged(sender As Object, e As EventArgs) Handles TBRR.TextChanged

    End Sub

    Private Sub TBRS_TextChanged(sender As Object, e As EventArgs) Handles TBRS.TextChanged

    End Sub

    Private Sub TBRM_TextChanged(sender As Object, e As EventArgs) Handles TBRM.TextChanged

    End Sub

    Private Sub TBMV_TextChanged(sender As Object, e As EventArgs) Handles TBMV.TextChanged

    End Sub

    Private Sub TBSM_TextChanged(sender As Object, e As EventArgs) Handles TBSM.TextChanged

    End Sub

    Private Sub TBMB_TextChanged(sender As Object, e As EventArgs) Handles TBMB.TextChanged

    End Sub

    Private Sub label5_Click(sender As Object, e As EventArgs) Handles label5.Click

    End Sub

    Private Sub RobotD_Click(sender As Object, e As EventArgs) Handles RobotD.Click

    End Sub

    Private Sub TBB_TextChanged(sender As Object, e As EventArgs) Handles TBB.TextChanged

    End Sub
End Class
