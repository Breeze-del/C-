// Card.cpp: implementation of the CCard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"
#include "Card.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCard::CCard()
{

}

CCard::~CCard()
{

}

void CCard::Draw(IplImage *bg, int sunnum)
{
	for (int k = 0; k < 6; k++) {
		if (m_card[k].m_isCd) {
			m_card[k].Draw(bg, 0.7, 0.3, (double)m_card[k].Getm_timer() /(double) m_card[k].Getm_timerate());
		}
		else {
			if (m_cost[k] <= sunnum) {
				m_card[k].Draw(bg, 1);
			}
			else {
				m_card[k].Draw(bg, 0.2);
			}
		}
	}
}

void CCard::Init() //初始化卡片位置、冷却时间、花费.
{
	int start_x = 89;
	int start_y = 8;
	for (int i = 0; i < 6; i++) {
		m_card[i].m_img = CResource::m_cards[i];
		m_card[i].m_isCd = false;
		m_card[i].SetPos(start_x, start_y);
		start_x += 51;
	}
	m_card[0].SetTimer(550);
	m_card[1].SetTimer(500);
	m_card[2].SetTimer(500);
	m_card[3].SetTimer(350);
	m_card[4].SetTimer(450);
	m_card[5].SetTimer(600);
	m_cost[0] = 175;
	m_cost[1] = 50;
	m_cost[2] = 100;
	m_cost[3] = 50;
	m_cost[4] = 50;
	m_cost[5] = 150;
}

int CCard::Getm_cost(int num)
{
	return m_cost[num];
}
