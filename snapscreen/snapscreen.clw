; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=TimerSnapSet
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "snapscreen.h"
LastPage=0

ClassCount=6
Class1=SetHotKey
Class2=CSnapscreenApp
Class3=CAboutDlg
Class4=CSnapscreenDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDD_DIALOG_REGISTER
Resource3=IDD_SNAPSCREEN_DIALOG
Resource4=IDD_ABOUTBOX
Class5=Register
Class6=TimerSnapSet
Resource5=IDD_DIALOG_TIMERSNAP_SET

[CLS:SetHotKey]
Type=0
BaseClass=CDialog
HeaderFile=SetHotKey.h
ImplementationFile=SetHotKey.cpp

[CLS:CSnapscreenApp]
Type=0
BaseClass=CWinApp
HeaderFile=snapscreen.h
ImplementationFile=snapscreen.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=snapscreenDlg.cpp
ImplementationFile=snapscreenDlg.cpp

[CLS:CSnapscreenDlg]
Type=0
BaseClass=CDialog
HeaderFile=snapscreenDlg.h
ImplementationFile=snapscreenDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CSnapscreenDlg

[DLG:IDD_DIALOG1]
Type=1
Class=SetHotKey
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SNAPSCREEN_DIALOG]
Type=1
Class=CSnapscreenDlg
ControlCount=20
Control1=ID_MINIZE,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC_HOTKEY,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CHECK1,button,1476460547
Control10=IDC_CHECK2,button,1342242819
Control11=IDC_STATIC,static,1342308352
Control12=IDC_WEB_URL,button,1342242816
Control13=ID_SNAP,button,1342242817
Control14=ID_SET_HOTKEY,button,1342242817
Control15=IDC_STATIC,button,1342177287
Control16=IDC_BUTTON_TIMERSNAP,button,1342242816
Control17=IDC_BUTTON_CONTINUESNAP,button,1342242816
Control18=IDC_BUTTON_MAINREGISTER,button,1342242816
Control19=IDC_STATIC,button,1342177287
Control20=IDC_BUTTON_WHOLESCREEN,button,1342242816

[DLG:IDD_DIALOG_REGISTER]
Type=1
Class=Register
ControlCount=12
Control1=IDC_EDIT_SRC,edit,1342246017
Control2=IDC_EDIT_DST,edit,1350631552
Control3=IDC_BUTTON_GOREGISTER,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON_PAY,button,1342242816
Control11=IDC_EDIT_QQ,edit,1342244992
Control12=IDC_BUTTON_CALLME,button,1342242816

[CLS:Register]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_CALLME

[DLG:IDD_DIALOG_TIMERSNAP_SET]
Type=1
Class=TimerSnapSet
ControlCount=12
Control1=IDC_COMBO_PINGLV,combobox,1344340226
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DATETIMEPICKER_TIME,SysDateTimePick32,1342242857
Control4=IDC_STATIC,button,1342177287
Control5=IDC_CHECK_SPTIME,button,1342242819
Control6=IDC_CHECK_START,button,1342242819
Control7=IDC_CHECK_AUTORUN,button,1342242819
Control8=IDC_EDIT_PATH,edit,1350631552
Control9=IDC_BUTTON_GETPATH,button,1342242816
Control10=IDOK,button,1342242816
Control11=IDCANCEL,button,1342242816
Control12=IDC_STATIC,static,1342308352

[CLS:TimerSnapSet]
Type=0
HeaderFile=TimerSnapSet.h
ImplementationFile=TimerSnapSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

