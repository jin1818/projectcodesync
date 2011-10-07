; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFindWordDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FindWord.h"

ClassCount=3
Class1=CFindWordApp
Class2=CFindWordDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FINDWORD_DIALOG

[CLS:CFindWordApp]
Type=0
HeaderFile=FindWord.h
ImplementationFile=FindWord.cpp
Filter=N

[CLS:CFindWordDlg]
Type=0
HeaderFile=FindWordDlg.h
ImplementationFile=FindWordDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFindWordDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FindWordDlg.h
ImplementationFile=FindWordDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FINDWORD_DIALOG]
Type=1
Class=CFindWordDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BROWSE,button,1342242816
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_SEARCH_STRING,static,1342308352
Control7=IDC_SEARCH,button,1342242816
Control8=IDC_LIST2,SysListView32,1350631429
Control9=IDC_NO_CASE,button,1342242819
Control10=IDC_COMBO1,combobox,1344340226
Control11=IDC_STATIC_SEARCH,static,1342308352
Control12=IDC_SELECT_EXT,static,1342308352
Control13=IDC_LOG_FILE,button,1342242819

