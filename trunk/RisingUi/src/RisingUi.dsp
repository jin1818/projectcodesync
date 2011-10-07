# Microsoft Developer Studio Project File - Name="RisingUi" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=RisingUi - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RisingUi.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RisingUi.mak" CFG="RisingUi - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RisingUi - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "RisingUi - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RisingUi - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"../bin/RisingUi.exe"

!ELSEIF  "$(CFG)" == "RisingUi - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /Zm256 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"../bin/RisingUi_d.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "RisingUi - Win32 Release"
# Name "RisingUi - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\skin\CSLock.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\CxStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLink.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\ImgSkin.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\Registry.cpp
# End Source File
# Begin Source File

SOURCE=.\RisingUi.cpp
# End Source File
# Begin Source File

SOURCE=.\RisingUi.rc
# End Source File
# Begin Source File

SOURCE=.\RisingUiDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinButton.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinCfg.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinMenuBar.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinSlider.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinTheme.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\SkinWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\skin\tinyxml\tinystr.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\tinyxml\tinyxml.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\tinyxml\tinyxmlerror.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\tinyxml\tinyxmlparser.cpp
# End Source File
# Begin Source File

SOURCE=.\skin\ZvLib.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgInfo.h
# End Source File
# Begin Source File

SOURCE=.\DlgLink.h
# End Source File
# Begin Source File

SOURCE=.\skin\ImgSkin.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RisingUi.h
# End Source File
# Begin Source File

SOURCE=.\RisingUiDlg.h
# End Source File
# Begin Source File

SOURCE=.\skin\SkinButton.h
# End Source File
# Begin Source File

SOURCE=.\skin\SkinDialog.h
# End Source File
# Begin Source File

SOURCE=.\skin\SkinMenuBar.h
# End Source File
# Begin Source File

SOURCE=.\skin\SkinSlider.h
# End Source File
# Begin Source File

SOURCE=.\skin\SkinTabCtrl.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\skin\ZvLib.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\RisingUi.ico
# End Source File
# Begin Source File

SOURCE=.\res\RisingUi.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\skin\GDIPlus\Lib\GdiPlus.lib
# End Source File
# End Target
# End Project
