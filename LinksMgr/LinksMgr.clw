; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyWeb
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LinksMgr.h"

ClassCount=4
Class1=CLinksMgrApp
Class2=CLinksMgrDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LINKSMGR_DIALOG
Class4=CMyWeb
Resource4=IDD_DIALOG1 (English (U.S.))
Resource5=IDD_DIALOG_LINKS

[CLS:CLinksMgrApp]
Type=0
HeaderFile=LinksMgr.h
ImplementationFile=LinksMgr.cpp
Filter=N

[CLS:CLinksMgrDlg]
Type=0
HeaderFile=LinksMgrDlg.h
ImplementationFile=LinksMgrDlg.cpp
Filter=D
LastObject=IDC_TAB_MAIN
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=LinksMgrDlg.h
ImplementationFile=LinksMgrDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LINKSMGR_DIALOG]
Type=1
Class=CLinksMgrDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB_MAIN,SysTabControl32,1350565888
Control4=IDC_RECT,static,1342308352

[DLG:IDD_DIALOG_LINKS]
Type=1
Class=CMyWeb
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631424

[CLS:CMyWeb]
Type=0
HeaderFile=MyWeb.h
ImplementationFile=MyWeb.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DIALOG1 (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

