; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "HefengSnapScreen"
#define MyAppVerName "HefengSnapScreen 1.0.0"
#define MyAppPublisher "�ͷ繤����"
#define MyAppURL "http://www.cppentry.com"
#define MyAppExeName "snapscreen.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
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

; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\��ݷ�ʽͳһ������" ; Filename:"{app}\mylinks\MyLinks.exe" ;  Tasks: myLinks
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\��ݷ�ʽͳһ������"; Filename: "{app}\mylinks\MyLinks.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent

[Registry]   
Root: HKLM;Subkey:SOFTWARE\Microsoft\Windows\CurrentVersion\Run;ValueType:string;ValueName:��ݷ�ʽͳһ������;   ValueData: {app}\mylinks\MyLinks.exe;Flags:uninsdeletekeyifempty uninsdeletevalue


