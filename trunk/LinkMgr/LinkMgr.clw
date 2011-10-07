; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLinkMgrDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "linkmgr.h"
LastPage=0

ClassCount=5
Class1=CLinkMgrApp
Class2=CLinkMgrDlg
Class3=CAboutDlg
Class4=CMainDlg
Class5=CWeatherDlg

ResourceCount=5
Resource1=IDD_DIALOG_WEATHER
Resource2=IDD_MAIN
Resource3=IDD_ABOUTBOX
Resource4=IDD_LINKMGR_DIALOG
Resource5=IDR_RUNMENU

[CLS:CLinkMgrApp]
Type=0
BaseClass=CWinApp
HeaderFile=LinkMgr.h
ImplementationFile=LinkMgr.cpp

[CLS:CLinkMgrDlg]
Type=0
BaseClass=CDialog
HeaderFile=LinkMgrDlg.h
ImplementationFile=LinkMgrDlg.cpp
LastObject=IDC_LIST

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MainDlg.cpp
ImplementationFile=MainDlg.cpp

[CLS:CMainDlg]
Type=0
BaseClass=CDialog
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
LastObject=IDC_CHECK_AUTORUN

[CLS:CWeatherDlg]
Type=0
BaseClass=CDialog
HeaderFile=WeatherDlg.h
ImplementationFile=WeatherDlg.cpp
LastObject=IDC_EXPLORER_WEATHER
Filter=D
VirtualFilter=dWC

[DLG:IDD_LINKMGR_DIALOG]
Type=1
Class=CLinkMgrDlg
ControlCount=2
Control1=IDC_LIST,SysListView32,1350631424
Control2=IDC_IMPORT,button,1342242817

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MAIN]
Type=1
Class=CMainDlg
ControlCount=2
Control1=IDC_CHECK_AUTORUN,button,1342242819
Control2=IDC_HIDE,button,1342242816

[DLG:IDD_DIALOG_WEATHER]
Type=1
Class=CWeatherDlg
ControlCount=1
Control1=IDC_EXPLORER_WEATHER,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816

[MNU:IDR_RUNMENU]
Type=1
Class=?
Command1=ID_RUN
CommandCount=1

