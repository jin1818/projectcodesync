// SkinTheme.cpp: implementation of the CSkinTheme class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SkinTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSkinTheme::CSkinTheme(const char * szSkinPath)
{
	LoadSkin(szSkinPath);
}

CSkinTheme::~CSkinTheme()
{

}

bool CSkinTheme::LoadSkin(const char * szSkinPath /* = NULL */)
{
	if(szSkinPath==NULL)
	{
		CImgSkin::Unload();

		return true;
	}

	if(!CImgSkin::Load(szSkinPath, "MenuBar"))
		return false;

	return true;
}

void CSkinTheme::FillCommandBarEntry(CDC* pDC, CXTPCommandBar* pBar)
{
	if(!CImgSkin::IsLoaded())
	{
		CXTPDefaultTheme::FillCommandBarEntry(pDC, pBar);
		return;
	}

	CXTPClientRect rect(pBar);

	Graphics graphics(pDC->GetSafeHdc());

	Rect rc, rc1;

	rc1.X = 0;
	rc1.Y = 0;
	rc1.Width = rect.Width();
	rc1.Height = rect.Height();

	switch(pBar->GetType())
	{
		case xtpBarTypeMenuBar:
		{
			// ±³¾°
			rc = m_mapRect["Background"];
			graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel, NULL, NULL);
			break;
		}
		case xtpBarTypeNormal:
		{
			// pDC->FillSolidRect(rect, RGB(255, 0, 0));
			// GradientFill(pDC, rect, RGB(255,0,0), RGB(0,255,0), FALSE);
			
			// CXTPPenDC pen(*pDC, 0);

			//for (int i = rect.top + 1; i < rect.bottom; i+= 3)
			//{
				//pDC->FillSolidRect(rect.left, i, rect.Width(), 1, XTPDrawHelpers()->BlendColors(RGB(255,0,0), RGB(0,255,0), (float)(1.0 - ((i - rect.top)) / (float)rect.Height())));
			//}
	
			break;
		}
		case xtpBarTypePopup:
		{
			rc = m_mapRect["PopupBack"];

			rc1.X = 0;
			rc1.Y = 0;
			rc1.Width = rc.Width/3;
			rc1.Height = rect.Height();			
			graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

			rc1.X = rc.Width/3;
			rc1.Y = 0;
			rc1.Width = rect.Width()-rc.Width/3*2;
			rc1.Height = rect.Height();			
			graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

			rc1.X = rect.Width()-rc.Width/3;
			rc1.Y = 0;
			rc1.Width = rc.Width/3;
			rc1.Height = rect.Height();			
			graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel);

			// pDC->Draw3dRect(rect, m_mapColor["PopupEdgeLT"], m_mapColor["PopupEdgeRB"]);
			
			break;
		}

		default:
			CXTPDefaultTheme::FillCommandBarEntry(pDC, pBar);
	}
}

CRect CSkinTheme::GetCommandBarBorders(CXTPCommandBar* pBar)
{
	return CXTPDefaultTheme::GetCommandBarBorders(pBar);
	switch(pBar->GetType())
	{
		case xtpBarTypeMenuBar:
		{
			return CRect(10, 10, 10, 10);
		}
		case xtpBarTypePopup:
			return CRect(1, 1, 1, 1);
		case xtpBarTypeNormal: 
			return CRect(0, 5, 0, 5);
		default:
			return CXTPDefaultTheme::GetCommandBarBorders(pBar);
	}
}

CSize CSkinTheme::DrawControlToolBarParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw)
{
	if(!CImgSkin::IsLoaded())
	{
		return CXTPDefaultTheme::DrawControlToolBarParent(pDC, pButton, bDraw);
	}

	CRect rcButton = bDraw? pButton->GetRect(): CXTPEmptyRect();
	XTPControlType controlType = pButton->GetType();

	CSize szIcon = pButton->GetParent()->GetIconSize();
	CSize szButton = CSize(szIcon.cx  + 7, szIcon.cy  + 7);

	BOOL bVert = pButton->GetParent()->GetPosition() == xtpBarRight || pButton->GetParent()->GetPosition() == xtpBarLeft;

	BOOL bPressed = pButton->GetPressed(), 
		bSelected = pButton->GetSelected(), 
		bEnabled = pButton->GetEnabled(), 
		bChecked = pButton->GetChecked(),
		bPopuped = IsPopupControlType(controlType) ;//&& ((CXTPControlPopup*)pButton)->GetPopup();

	COLORREF col;

	if (bDraw)
	{
		CRect rc = pButton->GetRect();
		rc.bottom = m_mapRect["Background"].Height;
		pButton->SetRect(rc);
		col = bPressed?(m_mapColor["Pressed"]):(bSelected? m_mapColor["Selected"]: m_mapColor["Enable"]);
		col = !bEnabled?m_mapColor["Disabled"]: bPressed||bPopuped? m_mapColor["Pressed"]: m_mapColor["Enable"];
		
		pDC->SetTextColor(col);
		pDC->SetBkMode (TRANSPARENT);
		
		return CXTPDefaultTheme::DrawControlToolBarParent(pDC, pButton, bDraw);
	}

	return CXTPDefaultTheme::DrawControlToolBarParent(pDC, pButton, bDraw);
}

void CSkinTheme::DrawControlEntry(CDC* pDC, CRect rect, BOOL bEnabled, BOOL bSelected, BOOL bPressed, BOOL bChecked, BOOL bPopuped, XTPBarPosition barPosition)
{
	if(!CImgSkin::IsLoaded())
	{
//		CXTPDefaultTheme::DrawControlEntry(pDC, rect, bEnabled, bSelected, bPressed, bChecked, bPopuped, barPosition);
		return;
	}

	Graphics graphics(pDC->GetSafeHdc());

	Rect rc, rc1;
	
	if(bSelected && !bPopuped)
		rc = m_mapRect["Selected"];
	else if((bSelected && bPopuped)||bPressed)
		rc = m_mapRect["Pressed"];
	else 
		rc = m_mapRect["Normal"];
	
	rc1.X = rect.left;
	rc1.Y = rect.top;
	rc1.Width = rect.Width();
	rc1.Height = rect.Height();
	graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width, rc.Height, UnitPixel, NULL, NULL);
}

CSize CSkinTheme::DrawControlPopupParent(CDC* pDC, CXTPControl* pButton, BOOL bDraw)
{
	CRect rcButton = pButton->GetRect();
	XTPControlType controlType = pButton->GetType();
	CRect rcText(0, 0, 0, 0), rcShortcut(0, 0, 0, 0);
	BOOL bSelected = pButton->GetSelected(), 
		bEnabled = pButton->GetEnabled(), 
		bChecked = pButton->GetChecked();

	CSize szIcon = pButton->GetParent()->GetIconSize();
	CSize szImage(max(szIcon.cx + 4, m_nTextHeight), max(szIcon.cy + 4, m_nTextHeight));

	XTPButtonStyle buttonStyle = pButton->GetStyle();
	BOOL bDrawImage = (buttonStyle == xtpButtonAutomatic && controlType != xtpControlPopup) ||
		(buttonStyle == xtpButtonIcon) || (buttonStyle == xtpButtonIconAndCaption);

	ASSERT(controlType == xtpControlButton || controlType == xtpControlPopup); // implemented only.

	if (bDraw)
	{
		CRect rcSelection(rcButton.left, rcButton.top, rcButton.right, rcButton.bottom);
		CRect rcImageRect(rcButton.left, rcButton.top, rcButton.left + szImage.cx, rcButton.bottom);
		CRect rcCheck (CPoint(rcImageRect.left + rcImageRect.Width()/2 - 10, rcImageRect.top + rcImageRect.Height()/2 - 10), CSize(20, 20));

		COLORREF clrText = !bEnabled? 0x0099A8AC: bSelected? 0x0060524B: 0x0060524B;
		pDC->SetTextColor(clrText);
		pDC->SetBkMode (TRANSPARENT);

		if (bSelected)
		{
			// µ¯³ö²Ëµ¥
			Graphics graphics(pDC->GetSafeHdc());

			Rect rc, rc1;

			rc1.X = rcSelection.left;
			rc1.Y = rcSelection.top;
			rc1.Width = rcSelection.Width();
			rc1.Height = rcSelection.Height();

			rc = m_mapRect["PopupSeled"];

			rc1.X = rcSelection.left;
			rc1.Y = rcSelection.top;
			rc1.Width = rc.Width/3;
			rc1.Height = rcSelection.Height();			
			graphics.DrawImage(m_pImg, rc1, rc.GetLeft(), rc.GetTop(), rc.Width/3, rc.Height, UnitPixel, NULL, NULL);

			rc1.X = rcSelection.left+rc.Width/3;
			rc1.Y = rcSelection.top+0;
			rc1.Width = rcSelection.Width()-rc.Width/3*2;
			rc1.Height = rcSelection.Height();			
			graphics.DrawImage(m_pImg, rc1, rc.GetLeft()+rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel, NULL, NULL);

			rc1.X = rcSelection.left+rcSelection.Width()-rc.Width/3;
			rc1.Y = rcSelection.top+0;
			rc1.Width = rc.Width/3;
			rc1.Height = rcSelection.Height();			
			graphics.DrawImage(m_pImg, rc1, rc.GetRight()-rc.Width/3, rc.GetTop(), rc.Width/3, rc.Height, UnitPixel, NULL, NULL);


		}

		if (bChecked)
		{
			CRect rcCheck (CPoint(rcButton.left - 2, rcButton.top + rcButton.Height()/2 - 10), CSize(20, 20));
			DrawCheckMark(pDC, rcCheck, clrText);
		}

		CXTPImageManagerIcon* pImage = pButton->GetIconId() != 0 && bDrawImage? pButton->GetImage(szIcon.cx): NULL;
		if (pImage)
		{
			szIcon.cy = pImage->GetHeight() * szIcon.cx / pImage->GetWidth();
			// DrawRectangle(pDC, rcImageRect, bSelected, FALSE, bEnabled, bChecked, FALSE, FALSE);
			CPoint ptImage = CPoint(rcCheck.left + rcCheck.Width()/2 - szIcon.cx/2, rcCheck.top + rcCheck.Height()/2 - szIcon.cy/2);
			DrawImage(pDC, ptImage, szIcon, pImage, bSelected, FALSE, bEnabled, bChecked, FALSE, FALSE);
			rcSelection.left = rcImageRect.right + 1;
		}

		if (controlType == xtpControlPopup)
		{
			CPoint pt = CPoint(rcButton.right - 11, rcButton.CenterPoint().y);
			Triangle(pDC, CPoint(pt.x, pt.y - 3), CPoint(pt.x + 3, pt.y), CPoint(pt.x, pt.y + 3), clrText);
		}

		rcText.SetRect(rcButton.left + 24, rcButton.top, rcButton.right, rcButton.bottom);
		rcShortcut.SetRect(rcButton.left + 16 + 4, rcButton.top, rcButton.right - 19, rcButton.bottom);

	}

	pDC->DrawText(pButton->GetCaption(), &rcText, DT_SINGLELINE | DT_VCENTER | (!bDraw ? DT_CALCRECT : DT_END_ELLIPSIS) );

	if (controlType == xtpControlButton && pButton->GetShortcutText().GetLength() != 0 )
		pDC->DrawText(pButton->GetShortcutText(), &rcShortcut, DT_SINGLELINE | DT_VCENTER | (!bDraw ? DT_CALCRECT : DT_RIGHT) );

	return CSize(16 + 12 + rcText.Width() +  rcShortcut.Width() + 32, max(23, m_nTextHeight - 4));	
}