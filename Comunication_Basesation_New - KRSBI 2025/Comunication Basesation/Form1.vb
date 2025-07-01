Imports System.Net
Imports System.IO
Imports System.Text.Encoding
Imports System.Net.Sockets

Public Class Form1
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
        TBRobotP.Text = TBs.Text
        TBRobotD.Text = TBs.Text
    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        TBRobotP.Text = TBSt.Text
        TBRobotD.Text = TBSt.Text
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

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        TBRobotP.Text = TBA.Text
        TBRobotD.Text = TBA.Text
    End Sub

End Class


