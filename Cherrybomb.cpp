// Cherrybomb.cpp: implementation of the CCherrybomb class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cherrybomb.h"
#include "Resource.h"
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#pragma   comment(linker,   "/subsystem:\"windows\"   /entry:\"mainCRTStartup\""   )
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
DWORD WINAPI Bomb(LPVOID pM)             //’®µØ…˘“Ù
{
	mciSendString("play .\\music\\bomb.mp3", NULL, 0, NULL);
	return 0;
}

CCherrybomb::CCherrybomb()
{
	CResource::LoadImg(CResource::m_cherrybomb, m_Idle_Img, 6);
	m_animRate = 8;
	SetAnimType("idle");
}

CCherrybomb::~CCherrybomb()
{

}

void CCherrybomb::Draw(IplImage *bg)
{
	IplImage *now_img = m_it[m_imgNum / m_animRate];
	int now_i, now_j;
	if (m_imgNum == 4 * m_animRate) {
		now_i = 0;
		now_j = 0;
		m_bomb = true;
		CreateThread(NULL, 0, Bomb, NULL, 0, NULL);
	}
	else if (m_imgNum / m_animRate == 5) {
		now_j = -35;
		now_i = -20;
		m_isDead = true;
	}
	else {
		now_i = 0;
		now_j = 0;
	}
	m_imgNum = (m_imgNum + 1) % (m_animRate * m_imgSum);
	for (int i = 0; i < now_img->height; i++) {
		for (int j = 0; j < now_img->width; j++) {
			if (i + m_Position.y > bg->height ||
				j + m_Position.y > bg->width ||
				i + m_Position.y < 0 ||
				j + m_Position.x < 0
				)continue;
			if (CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0) <= 10 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) >= 135 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) <= 155 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2) <= 10
				)continue;//¥ø…´øÿ÷∆
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y + now_i, (j + m_Position.x + now_j) * 3 + 0)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y + now_i, (j + m_Position.x + now_j) * 3 + 1)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y + now_i, (j + m_Position.x + now_j) * 3 + 2)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2);
		}
	}
}
