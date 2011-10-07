; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "HefengSnapScreen"
#define MyAppVerName "HefengSnapScreen 1.0.0"
#define MyAppPublisher "和风工作室"
#define MyAppURL "http://www.cppentry.com"
#define MyAppExeName "snapscreen.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{51B9BE88-4189-4549-8B45-09BD92D9C05D}
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: checkedonce; OnlyBelowVersion: 0,6.1
Name: "myLinks" ; Description: "Create My Links" ; GroupDescription: "{cm:AdditionalIcons}"; Flags: checkedonce 
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: checkedonce; OnlyBelowVersion: 0,6.1

[Files]
Source: "F:\project\snapscreen\Release\snapscreen.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\project\snapscreen\Release\CatchScreen.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\project\MyLinks\bin\*"; DestDir: "{app}\mylinks"; Flags: ignoreversion recursesubdirs createallsubdirs

; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\快捷方式统一管理器" ; Filename:"{app}\mylinks\MyLinks.exe" ;  Tasks: myLinks
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\快捷方式统一管理器"; Filename: "{app}\mylinks\MyLinks.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent

[Registry]   
Root: HKLM;Subkey:SOFTWARE\Microsoft\Windows\CurrentVersion\Run;ValueType:string;ValueName:快捷方式统一管理器;   ValueData: {app}\mylinks\MyLinks.exe;Flags:uninsdeletekeyifempty uninsdeletevalue


