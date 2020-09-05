'Written by Myhrginoc 4/7/02
'Updated by Myhrginoc 3/1/03
'This script will restore Blizzard's settings and files after a crash.
'  
'Create a shell object
Set Shell = WScript.CreateObject("WScript.Shell")
'Create a file system object
Set FSO = WScript.CreateObject("Scripting.FileSystemObject")
'Get path to Diablo II EXE from registry
Reg1 = "HKCU\Software\Blizzard Entertainment\Diablo II"
Reg2 = "HKLM\Software\Blizzard Entertainment\Diablo II"
Reg1Use = True
Reg2Use = True
D2Path = Shell.RegRead(Reg1 & "\InstallPath")& "\"
If (FSO.FileExists(D2Path & "game.exe") = 0) Then
  Reg1Use = False
End If
VanillaSave1 = D2Path & "Save"
D2Path = Shell.RegRead(Reg2 & "\InstallPath")& "\"
If (FSO.FileExists(D2Path & "game.exe") = 0) Then
  Reg2Use = False
End If
VanillaSave2 = D2Path & "Save"
If Reg1Use = False Then
  If Reg2Use = False Then
    D2Alert = "The Diablo II installation could not be found.  Please try re-installing Diablo II"
    D2Choose = MsgBox (D2Alert,16,"Restore Failure")
    WScript.Quit(1)
  End If
End If
If Reg1Use Then
  VanillaKey = Reg1 & "\Save Path\"
  Shell.RegWrite VanillaKey, VanillaSave1, "REG_SZ"
End If
If Reg2Use Then
  VanillaKey = Reg2 & "\Save Path\"
  Shell.RegWrite VanillaKey, VanillaSave2, "REG_SZ"
End If
On Error Resume Next
ErrorFlag = 0
'Check for Bnclient.dll or Bnclient.baq in the Diablo directory
Set BnclientDLL = FSO.GetFile(D2Path & "Bnclient.dll")
If Err.Number > 0 Then
  Err.Clear
  Set BnclientDLL = FSO.GetFile(D2Path & "Bnclient.baq")
  If Err.Number = 0 Then
    BnclientDLL.Move (D2Path & "Bnclient.dll")
    D2Alert = "BNClient.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace BNClient.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Client.dll or D2Client.baq in the Diablo directory
Set D2ClientDLL = FSO.GetFile(D2Path & "D2Client.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2ClientDLL = FSO.GetFile(D2Path & "D2Client.baq")
  If Err.Number = 0 Then
    D2ClientDLL.Move (D2Path & "D2Client.dll")
    D2Alert = "D2Client.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Client.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2CMP.dll or D2CMP.baq in the Diablo directory
Set D2CMPDLL = FSO.GetFile(D2Path & "D2CMP.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2CMPDLL = FSO.GetFile(D2Path & "D2CMP.baq")
  If Err.Number = 0 Then
    D2CMPDLL.Move (D2Path & "D2CMP.dll")
    D2Alert = "D2CMP.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2CMP.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Common.dll or D2Common.baq in the Diablo directory
Set D2CommonDLL = FSO.GetFile(D2Path & "D2Common.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2CommonDLL = FSO.GetFile(D2Path & "D2Common.baq")
  If Err.Number = 0 Then
    D2CommonDLL.Move (D2Path & "D2Common.dll")
    D2Alert = "D2Common.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Common.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Direct3D.dll or D2Direct3D.baq in the Diablo directory
Set D2Direct3DDLL = FSO.GetFile(D2Path & "D2Direct3D.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2Direct3DDLL = FSO.GetFile(D2Path & "D2Direct3D.baq")
  If Err.Number = 0 Then
    D2Direct3DDLL.Move (D2Path & "D2Direct3D.dll")
    D2Alert = "D2Direct3D.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Direct3D.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2DDraw.dll or D2DDraw.baq in the Diablo directory
Set D2DDrawDLL = FSO.GetFile(D2Path & "D2DDraw.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2DDrawDLL = FSO.GetFile(D2Path & "D2DDraw.baq")
  If Err.Number = 0 Then
    D2DDrawDLL.Move (D2Path & "D2DDraw.dll")
    D2Alert = "D2DDraw.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2DDraw.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Game.dll or D2Game.baq in the Diablo directory
Set D2GameDLL = FSO.GetFile(D2Path & "D2Game.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2GameDLL = FSO.GetFile(D2Path & "D2Game.baq")
  If Err.Number = 0 Then
    D2GameDLL.Move (D2Path & "D2Game.dll")
    D2Alert = "D2Game.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Game.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Gdi.dll or D2Gdi.baq in the Diablo directory
Set D2GdiDLL = FSO.GetFile(D2Path & "D2Gdi.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2GdiDLL = FSO.GetFile(D2Path & "D2Gdi.baq")
  If Err.Number = 0 Then
    D2GdiDLL.Move (D2Path & "D2Gdi.dll")
    D2Alert = "D2Gdi.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Gdi.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Gfx.dll or D2Gfx.baq in the Diablo directory
Set D2GfxDLL = FSO.GetFile(D2Path & "D2Gfx.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2GfxDLL = FSO.GetFile(D2Path & "D2Gfx.baq")
  If Err.Number = 0 Then
    D2GfxDLL.Move (D2Path & "D2Gfx.dll")
    D2Alert = "D2Gfx.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Gfx.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Glide.dll or D2Glide.baq in the Diablo directory
Set D2GlideDLL = FSO.GetFile(D2Path & "D2Glide.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2GlideDLL = FSO.GetFile(D2Path & "D2Glide.baq")
  If Err.Number = 0 Then
    D2GlideDLL.Move (D2Path & "D2Glide.dll")
    D2Alert = "D2Glide.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Glide.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Lang.dll or D2Lang.baq in the Diablo directory
Set D2LangDLL = FSO.GetFile(D2Path & "D2Lang.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2LangDLL = FSO.GetFile(D2Path & "D2Lang.baq")
  If Err.Number = 0 Then
    D2LangDLL.Move (D2Path & "D2Lang.dll")
    D2Alert = "D2Lang.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Lang.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Launch.dll or D2Launch.baq in the Diablo directory
Set D2LaunchDLL = FSO.GetFile(D2Path & "D2Launch.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2LaunchDLL = FSO.GetFile(D2Path & "D2Launch.baq")
  If Err.Number = 0 Then
    D2LaunchDLL.Move (D2Path & "D2Launch.dll")
    D2Alert = "D2Launch.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Launch.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2MCPClient.dll or D2MCPClient.baq in the Diablo directory
Set D2MCPClientDLL = FSO.GetFile(D2Path & "D2MCPClient.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2MCPClientDLL = FSO.GetFile(D2Path & "D2MCPClient.baq")
  If Err.Number = 0 Then
    D2MCPClientDLL.Move (D2Path & "D2MCPClient.dll")
    D2Alert = "D2MCPClient.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2MCPClient.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Multi.dll or D2Multi.baq in the Diablo directory
Set D2MultiDLL = FSO.GetFile(D2Path & "D2Multi.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2MultiDLL = FSO.GetFile(D2Path & "D2Multi.baq")
  If Err.Number = 0 Then
    D2MultiDLL.Move (D2Path & "D2Multi.dll")
    D2Alert = "D2Multi.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Multi.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Net.dll or D2Net.baq in the Diablo directory
Set D2NetDLL = FSO.GetFile(D2Path & "D2Net.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2NetDLL = FSO.GetFile(D2Path & "D2Net.baq")
  If Err.Number = 0 Then
    D2NetDLL.Move (D2Path & "D2Net.dll")
    D2Alert = "D2Net.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Net.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Sound.dll or D2Sound.baq in the Diablo directory
Set D2SoundDLL = FSO.GetFile(D2Path & "D2Sound.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2SoundDLL = FSO.GetFile(D2Path & "D2Sound.baq")
  If Err.Number = 0 Then
    D2SoundDLL.Move (D2Path & "D2Sound.dll")
    D2Alert = "D2Sound.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Sound.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for D2Win.dll or D2Win.baq in the Diablo directory
Set D2WinDLL = FSO.GetFile(D2Path & "D2Win.dll")
If Err.Number > 0 Then
  Err.Clear
  Set D2WinDLL = FSO.GetFile(D2Path & "D2Win.baq")
  If Err.Number = 0 Then
    D2WinDLL.Move (D2Path & "D2Win.dll")
    D2Alert = "D2Win.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace D2Win.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for Fog.dll or Fog.baq in the Diablo directory
Set FogDLL = FSO.GetFile(D2Path & "Fog.dll")
If Err.Number > 0 Then
  Err.Clear
  Set FogDLL = FSO.GetFile(D2Path & "Fog.baq")
  If Err.Number = 0 Then
    FogDLL.Move (D2Path & "Fog.dll")
    D2Alert = "Fog.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace Fog.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
'Check for Storm.dll or Storm.baq in the Diablo directory
Set StormDLL = FSO.GetFile(D2Path & "Storm.dll")
If Err.Number > 0 Then
  Err.Clear
  Set StormDLL = FSO.GetFile(D2Path & "Storm.baq")
  If Err.Number = 0 Then
    StormDLL.Move (D2Path & "Storm.dll")
    D2Alert = "Storm.dll was successfully restored"
    D2Choose = MsgBox (D2Alert,48,"Recovered DLL")
  Else
    D2Alert = "Unable to find .dll or .baq extension." & chr(13) & chr(10) & "You need to find or replace Storm.dll"
    D2Choose = MsgBox (D2Alert,16,"Missing DLL")
    ErrorFlag = ErrorFlag + 1
  End If
  Err.Clear
End If
On Error GoTo 0
If ErrorFlag > 0 Then
  D2Alert = "One or more crash conditions could not be corrected." & chr(13) & chr(10) & "Check your Diablo II installation, including file locations   " & chr(13) & chr(10) & "and the Windows Registry settings."
  D2Choose = MsgBox (D2Alert,16,"Restore Failed")
  WScript.Quit(2)
Else
  D2Alert = "Restoration activities have completed successfully."
  D2Choose = MsgBox (D2Alert,48,"Restore Complete")
  WScript.Quit(0)
End If