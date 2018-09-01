// Pumkin.cpp: implementation of the CPumkin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Pumkin.h"
#include "Resource.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPumkin::CPumkin()
{
	CResource::LoadImg(CResource::m_pumpkin, m_Idle_Img, 4);
	CResource::LoadImg(CResource::m_pumpkin_attack, m_Attack_Img, 4);
	SetAnimType("idle");
	m_isPumkin = true;

}

CPumkin::~CPumkin()
{

}

void CPumkin::Timething()
{

}

void CPumkin::Draw(IplImage *bg)
{
	IplImage* now_img = m_it[m_imgNum / m_animRate];

	m_imgNum = (m_imgNum + 1) % (m_animRate * m_imgSum);

	for (int i = 0; i < now_img->height; i++) {
		for (int j = 0; j < now_img->width; j++) {
			if (i + m_Position.y >= bg->height ||
				j + m_Position.x >= bg->width ||
				i + m_Position.y < 0 ||
				j + m_Position.x < 0
				)continue;
			if (m_isAttack) {
				if (CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0) >= 230 &&
					CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) >= 230 &&
					CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2) >= 230
					)continue;//纯色控制
			}
			else {
				if (CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0) <= 10 &&
					CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) >= 135 &&
					CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) <= 155 &&
					CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2) <= 10
					)continue;//纯色控制
			}
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 0)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 1)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 2)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2);
		}
	}
	if (m_isAttack && m_imgNum == m_Attack_Img.size() * m_animRate - 1) {
		SetAnimType("dead");
	}
}
