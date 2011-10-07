; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "risingui.h"
LastPage=0

ClassCount=5
Class1=CDlgInfo
Class2=CRisingUiApp
Class3=CAboutDlg
Class4=CRisingUiDlg

ResourceCount=5
Resource1=IDD_Info
Resource2=IDD_Link
Resource3=IDD_ABOUTBOX
Resource4=IDD_RISINGUI_DIALOG
Class5=CDlgLink
Resource5=IDR_MENU1

[CLS:CDlgInfo]
Type=0
BaseClass=CSkinDialog
HeaderFile=DlgInfo.h
ImplementationFile=DlgInfo.cpp
LastObject=CDlgInfo

[CLS:CRisingUiApp]
Type=0
BaseClass=CWinApp
HeaderFile=RisingUi.h
ImplementationFile=RisingUi.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CSkinDialog
HeaderFile=RisingUiDlg.cpp
ImplementationFile=RisingUiDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CAboutDlg

[CLS:CRisingUiDlg]
Type=0
BaseClass=CSkinDialog
HeaderFile=RisingUiDlg.h
ImplementationFile=RisingUiDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CRisingUiDlg

[DLG:IDD_Info]
Type=1
Class=CDlgInfo
ControlCount=5
Control1=IDC_TXT_TARGET,static,1342308352
Control2=IDC_SLIDER1,msctls_trackbar32,1342242840
Control3=IDC_BTN_KILL,button,1342243328
Control4=IDC_BTN_UPDATE,button,1342242816
Control5=IDC_BTN_PRO,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_RISINGUI_DIALOG]
Type=1
Class=CRisingUiDlg
ControlCount=2
Control1=IDC_TAB1,SysTabControl32,1342178304
Control2=IDC_RECT_CHILD,static,1073741831

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDM_EXIT
Command2=IDM_ABOUT
CommandCount=2

[DLG:IDD_Link]
Type=1
Class=CDlgLink
ControlCount=0

[CLS:CDlgLink]
Type=0
HeaderFile=DlgLink.h
ImplementationFile=DlgLink.cpp
BaseClass=CSkinDialog
Filter=D
LastObject=CDlgLink
VirtualFilter=dWC

