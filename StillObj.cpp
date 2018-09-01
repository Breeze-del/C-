// StillObj.cpp: implementation of the CStillObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StillObj.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStillObj::CStillObj()
{

}

CStillObj::~CStillObj()
{

}

void CStillObj::Draw(IplImage *bg, double down, double up, double l, int tx, int ty)
{
	double m = (double)l * m_img->height;
	double light;
	for (int i = 0; i < m_img->height; i++) {
		for (int j = 0; j < m_img->width; j++) {
			if (i + m_Position.y + ty >= bg->height ||
				j + m_Position.x + tx >= bg->width ||
				i + m_Position.y + ty< 0 ||
				j + m_Position.x + tx< 0
				)continue;  //超过边界的不打印.
			if (CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 0) <= 10 &&
				CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 1) >= 135 &&
				CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 1) <= 155 &&
				CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 2) <= 10
				)continue;//纯色控制
			if (i > m_img->height - m)
				light = down;
			else
				light = up;
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y + ty, (j + m_Position.x + tx) * 3 + 0)
				= (unsigned char)(CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 0) * light);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y + ty, (j + m_Position.x + tx) * 3 + 1)
				= (unsigned char)(CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 1) * light);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y + ty, (j + m_Position.x + tx) * 3 + 2)
				= (unsigned char)(CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 2) * light);
		}
	}

}

void CStillObj::SetPos(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}



void CStillObj::Timething()
{
	m_isCd = false;
}


