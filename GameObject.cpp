// GameObject.cpp: implementation of the CGameObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "stdio.h"
#include "GameObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGameObject::CGameObject()
{

}

CGameObject::~CGameObject()
{

}

void CGameObject::SetPos(int i, int j)
{

}

void CGameObject::Draw(IplImage *bg)
{
	for (int i = 0; i < m_img->height; i++) {
		for (int j = 0; j < m_img->width; j++) {
			if (i + m_Position.y >= bg->height ||
				j + m_Position.x >= bg->width ||
				i + m_Position.y < 0 ||
				j + m_Position.x < 0
				)continue;  //超过边界的不打印.
			if (CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 0) <= 10 &&
				CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 1) >= 135 &&
				CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 1) <= 155 &&
				CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 2) <= 10
				)continue;//纯色控制

			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 0)
				= CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 0);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 1)
				= CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 1);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 2)
				= CV_IMAGE_ELEM(m_img, uchar, i, j * 3 + 2);
		}
	}
}

void CGameObject::Time()
{
	if (m_timer < m_timerate) {
		m_timer++;
		if (m_timer == m_timerate) {
			Timething();
		}
	}
}

void CGameObject::Timething()
{
}

void CGameObject::SetTimer(int time)
{
	m_timer = m_timerate = time;
}

void CGameObject::Changem_timer(int timer)
{
	m_timer = timer;
}

int CGameObject::Getm_timer()
{
	return m_timer;
}

int CGameObject::Getm_timerate()
{
	return m_timerate;
}
