'Bonescythe's MOD LAUNCHER Script
'Enhanced by Myhrginoc 4/7/02
'Slightly Enhanced by FoxBat 8/26/02
'Consolidated modes in one script by Myhrginoc 3/1/03
'Added the remaining DLLs by Myhrginoc 5/20/03
'This script will launch a mod in a Diablo II subdirectory.
'  
Dim ErrorFlag
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
VanillaSave1 = D2Path & "Save\"
D2Path = Shell.RegRead(Reg2 & "\InstallPath")& "\"
If (FSO.FileExists(D2Path & "game.exe") = 0) Then
  Reg2Use = False
End If
VanillaSave2 = D2Path & "Save\"
If Reg1Use = False Then
  If Reg2Use = False Then
    D2Alert = "The Diablo II installation could not be found.  Please try re-installing Diablo II"
    D2Choose = MsgBox (D2Alert,16,"Launch Failure")
    WScript.Quit(1)
  End If
End If
'Get the current directory folder object
Set Folder = FSO.GetFolder(".")
'Ensure script gets to clean up if setting up and launching the mod fails
On Error Resume Next
'Check for proper installation of Blizzard DLLs in Diablo installation directory
  ErrorFlag = 0
  Set BNClientDLL = FSO.GetFile(D2Path & "Bnclient.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set ClientDLL = FSO.GetFile(D2Path & "D2Client.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set CmpDLL = FSO.GetFile(D2Path & "D2CMP.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set CommonDLL = FSO.GetFile(D2Path & "D2Common.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set Direct3dDLL = FSO.GetFile(D2Path & "D2Direct3D.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set DDRawDLL = FSO.GetFile(D2Path & "D2DDraw.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set GameDLL = FSO.GetFile(D2Path & "D2Game.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set GdiDLL = FSO.GetFile(D2Path & "D2Gdi.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set GfxDLL = FSO.GetFile(D2Path & "D2Gfx.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set GlideDLL = FSO.GetFile(D2Path & "D2Glide.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set LangDLL = FSO.GetFile(D2Path & "D2Lang.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set LaunchDLL = FSO.GetFile(D2Path & "D2Launch.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set MCPClientDLL = FSO.GetFile(D2Path & "D2MCPClient.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set MultiDLL = FSO.GetFile(D2Path & "D2Multi.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set NetDLL = FSO.GetFile(D2Path & "D2Net.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set SoundDLL = FSO.GetFile(D2Path & "D2Sound.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set WinDLL = FSO.GetFile(D2Path & "D2Win.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set FogDLL = FSO.GetFile(D2Path & "Fog.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  Set StormDLL = FSO.GetFile(D2Path & "Storm.dll")
  If Err.Number > 0 Then
    ErrorFlag = ErrorFlag + 1
    Err.Clear
  End If
  If ErrorFlag > 0 Then
    D2Alert = "One or more required DLLs is either not present or has a corrupted name in the Diablo II installation directory.  Run RecoverFromCrash.VBS and try again."
    D2Choose = MsgBox (D2Alert,16,"Launch Failure")
    WScript.Quit(2)
  End If
'If Diablo path is not the current directory run MOD otherwise just fix up
If Folder.Path & "\" <> D2Path Then
  'Get full pathname of current directory and append save dir name
  Dir = Folder.Path & "\Save\"
  'Make new save dir if necessary
  If (FSO.FolderExists(Dir) = False) then
    Set f = FSO.CreateFolder(Dir)
    If Err.Number > 0 Then
      D2Alert = "Unable to create a new Save directory.  Create manually and try again."
      D2Choose = MsgBox (D2Alert,16,"Launch Failure")
      WScript.Quit(3)
    End If
  End If
  'Determine game running mode
  RunTxt = False
  RunWindowed = False
  D2CmdLine = chr(34) & D2Path & "game.exe" & chr(34) & "-direct"
  D2Alert = "Do you need to generate bin files?" & chr(13) & chr(10) & chr(10) & "Warning!  Generating bin files may cause problems if the txt files in the mpq   " & chr(13) & chr(10) & "are not the same version as the current mod or are missing from the mpq."
  D2Choose = MsgBox(D2Alert,308,"-Txt Mode") 
  If D2Choose = 6 Then
    'Be sure there is a place to receive bin files
    Dir2 = Folder.Path & "\data\global\excel"
    If (FSO.FolderExists(Dir2) = False) Then
      ErrorFlag = 0
      Dir2 = Folder.Path & "\data"
      Set f = FSO.CreateFolder(Dir2)
      If Err.Number > 0 Then
        ErrorFlag = ErrorFlag + 1
        Err.Clear
      End If
      Dir2 = Dir2 & "\global"
      Set f = FSO.CreateFolder(Dir2)
      If Err.Number > 0 Then
        ErrorFlag = ErrorFlag + 1
        Err.Clear
      End If
      Dir2 = Dir2 & "\excel"
      Set f = FSO.CreateFolder(Dir2)
      If Err.Number > 0 Then
        ErrorFlag = ErrorFlag + 1
        Err.Clear
      End If
      If ErrorFlag > 0 Then
	D2Alert = "Unable to find or create a new data\global\excel directory to receive new bin files.  Create manually and try again."
        D2Choose = MsgBox (D2Alert,16,"Launch Failure")
        WScript.Quit(4)
      End If
    Else
      BinFiles = Dir2 & "\*.bin"
      FSO.DeleteFile(BinFiles)
    End If
    D2CmdLine = D2CmdLine & " -txt"
  End If 
  'Hide Blizzard DLLs!
  'Check if BNClient.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\BNClient.dll") Then
    BNClientDLL.Move (D2Path & "BNClient.baq")
  End If
  'Check if D2Client.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Client.dll") Then
    ClientDLL.Move (D2Path & "D2Client.baq")
  End If
  'Check if D2CMP.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2CMP.dll") Then
    CmpDLL.Move (D2Path & "D2CMP.baq")
  End If
  'Check if D2Common.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Common.dll") Then
    CommonDLL.Move (D2Path & "D2Common.baq")
  End If
  'Check if D2Direct3D.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Direct3D.dll") Then
    Direct3dDLL.Move (D2Path & "D2Direct3D.baq")
  End If
  'Check if D2DDraw.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2DDraw.dll") Then
    DDrawDLL.Move (D2Path & "D2DDraw.baq")
  End If
  'Check if D2Game.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Game.dll") Then
    GameDLL.Move (D2Path & "D2Game.baq")
  End If
  'Check if D2Gdi.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Gdi.dll") Then
    GdiDLL.Move (D2Path & "D2Gdi.baq")
  End If
  'Check if D2Gfx.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Gfx.dll") Then
    GfxDLL.Move (D2Path & "D2Gfx.baq")
  End If
  'Check if D2Glide.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Glide.dll") Then
    GlideDLL.Move (D2Path & "D2Glide.baq")
  End If
  'Check if D2Lang.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Lang.dll") Then
    LangDLL.Move (D2Path & "D2Lang.baq")
  End If
  'Check if D2Launch.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Launch.dll") Then
    LaunchDLL.Move (D2Path & "D2Launch.baq")
  End If
  'Check if D2MCPClient.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2MCPClient.dll") Then
    MCPClientDLL.Move (D2Path & "D2MCPClient.baq")
  End If
  'Check if D2Multi.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Multi.dll") Then
    MultiDLL.Move (D2Path & "D2Multi.baq")
  End If
  'Check if D2Net.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Net.dll") Then
    NetDLL.Move (D2Path & "D2Net.baq")
  End If
  'Check if D2Sound.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Sound.dll") Then
    SoundDLL.Move (D2Path & "D2Sound.baq")
  End If
  'Check if D2Win.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\D2Win.dll") Then
    WinDLL.Move (D2Path & "D2Win.baq")
  End If
  'Check if Fog.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\Fog.dll") Then
    FogDLL.Move (D2Path & "Fog.baq")
  End If
  'Check if Storm.dll exists in the current directory
  If FSO.FileExists(Folder.Path & "\Storm.dll") Then
    StormDLL.Move (D2Path & "Storm.baq")
  End If
  D2Alert = "Run game in windowed mode?" & chr(13) & chr(10) & chr(10) & "Windowed mode is primarily used for debugging.   "
  D2Choose = MsgBox(D2Alert,292,"Windowed Mode") 
  If D2Choose = 6 Then
    D2CmdLine = D2CmdLine & " -w"
  End If
  'Get mod save folder and write new save path to the Registry
  If Reg1Use Then
    RegSave = Reg1 & "\Save Path"
    Shell.RegWrite RegSave, Dir, "REG_SZ"
  End If
  If Reg2Use Then
    RegSave = Reg2 & "\Save Path"
    Shell.RegWrite RegSave, Dir, "REG_SZ"
  End If
  'Launch Diablo II normally and wait for it to finish
  Result = Shell.Run(D2CmdLine, 1, TRUE)
  'Restore name to Blizzard's BNClient.dll
  If BNClientDLL.Name = "BNClient.baq" Then
    BNClientDLL.Move (D2Path & "BNClient.dll")
  End If
  'Restore name to Blizzard's D2Client.dll
  If ClientDLL.Name = "D2Client.baq" Then
    ClientDLL.Move (D2Path & "D2Client.dll")
  End If
  'Restore name to Blizzard's D2CMP.dll
  If CmpDLL.Name = "D2CMP.baq" Then
    CmpDLL.Move (D2Path & "D2CMP.dll")
  End If
  'Restore name to Blizzard's D2Common.dll
  If CommonDLL.Name = "D2Common.baq" Then
    CommonDLL.Move (D2Path & "D2Common.dll")
  End If
  'Restore name to Blizzard's D2Direct3D.dll
  If Direct3dDLL.Name = "D2Direct3D.baq" Then
    Direct3dDLL.Move (D2Path & "D2Direct3D.dll")
  End If
  'Restore name to Blizzard's D2DDraw.dll
  If DDrawDLL.Name = "D2DDraw.baq" Then
    DDrawDLL.Move (D2Path & "D2DDraw.dll")
  End If
  'Restore name to Blizzard's D2Game.dll
  If GameDLL.Name = "D2Game.baq" Then
    GameDLL.Move (D2Path & "D2Game.dll")
  End If
  'Restore name to Blizzard's D2Gdi.dll
  If GdiDLL.Name = "D2Gdi.baq" Then
    GdiDLL.Move (D2Path & "D2Gdi.dll")
  End If
  'Restore name to Blizzard's D2Gfx.dll
  If GfxDLL.Name = "D2Gfx.baq" Then
    GfxDLL.Move (D2Path & "D2Gfx.dll")
  End If
  'Restore name to Blizzard's D2Glide.dll
  If GlideDLL.Name = "D2Glide.baq" Then
    GlideDLL.Move (D2Path & "D2Glide.dll")
  End If
  'Restore name to Blizzard's D2Lang.dll
  If LangDLL.Name = "D2Lang.baq" Then
    LangDLL.Move (D2Path & "D2Lang.dll")
  End If
  'Restore name to Blizzard's D2Launch.dll
  If LaunchDLL.Name = "D2Launch.baq" Then
    LaunchDLL.Move (D2Path & "D2Launch.dll")
  End If
  'Restore name to Blizzard's D2MCPClient.dll
  If MCPClientDLL.Name = "D2MCPClient.baq" Then
    MCPClientDLL.Move (D2Path & "D2MCPClient.dll")
  End If
  'Restore name to Blizzard's D2Multi.dll
  If MultiDLL.Name = "D2Multi.baq" Then
    MultiDLL.Move (D2Path & "D2Multi.dll")
  End If
  'Restore name to Blizzard's D2Net.dll
  If NetDLL.Name = "D2Net.baq" Then
    NetDLL.Move (D2Path & "D2Net.dll")
  End If
  'Restore name to Blizzard's D2Sound.dll
  If SoundDLL.Name = "D2Sound.baq" Then
    SoundDLL.Move (D2Path & "D2Sound.dll")
  End If
  'Restore name to Blizzard's D2Win.dll
  If WinDLL.Name = "D2Win.baq" Then
    WinDLL.Move (D2Path & "D2Win.dll")
  End If
  'Restore name to Blizzard's Fog.dll
  If FogDLL.Name = "Fog.baq" Then
    FogDLL.Move (D2Path & "Fog.dll")
  End If
  'Restore name to Blizzard's Storm.dll
  If StormDLL.Name = "Storm.baq" Then
    StormDLL.Move (D2Path & "Storm.dll")
  End If
  'Restore previous save directory setting in registry
  If Reg1Use Then
    RegSave = Reg1 & "\Save Path"
    Shell.RegWrite RegSave, VanillaSave1, "REG_SZ"
  End If
  If Reg2Use Then
    RegSave = Reg2 & "\Save Path"
    Shell.RegWrite RegSave, VanillaSave2, "REG_SZ"
  End If
Else
  D2Alert = "This script cannot be used in the Blizzard D2 installation directory" & chr(13) & chr(10) & chr(10) & "If the script is in a mod directory and you get this error,  " & chr(13) & chr(10) & chr(10) & "you need to run RecoverFromCrash.vbs first.  Your Registry setting   " & chr(13) & chr(10) & chr(10) & "for Diablo II installation location has become invalid."
  D2Choose = MsgBox (D2Alert,16,"Launch Failure")
  WScript.Quit(5)
End If
On Error GoTo 0
WScript.Quit(0)