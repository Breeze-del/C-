// Bg.cpp: implementation of the CBg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"
#include "Bg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBg::CBg()
{
	m_img = CResource::m_bg;
	m_clone = cvCloneImage(m_img);

}
CBg::~CBg()
{

}

void CBg::Draw()
{
	cvShowImage("game", m_img);
	cvCopy(m_clone, m_img);
}

void CBg::Show(IplImage *img)
{
	cvShowImage("game", img);
}
