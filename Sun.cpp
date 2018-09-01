// Sun.cpp: implementation of the CSun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"
#include "Sun.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSun::CSun()
{
	m_img = CResource::m_sun;
	SetTimer(200);
	m_timer = 0;
	m_isGet = false;
	m_isEnd = false;
}

CSun::~CSun()
{

}

void CSun::Move()
{
	if (m_isGet) {
		m_Position.x += m_speedx;
		m_Position.y += m_speedy;
		if (m_Position.x <= 10)  //Ä¿±êµã(10,0)
			m_Position.x = 10;
		if (m_Position.y <= 0)
			m_Position.y = 0;
		if (m_Position.x == 10 && m_Position.y == 0) {
			m_isEnd = true;
		}
		return;
	}
	if (m_isMove && m_Position.y < m_aimy)
		m_Position.y += 5;
}

void CSun::Changem_isGet(bool isGet)
{
	m_isGet = isGet;
}

void CSun::Changem_speedx(int speedx)
{
	m_speedx = speedx;
}

void CSun::Changem_speedy(int speedy)
{
	m_speedy = speedy;
}

bool CSun::Getm_isEnd()
{
	return m_isGet;
}

void CSun::Changem_isMove(bool isMove)
{
	m_isMove = isMove;
}

void CSun::Changem_aimy(int aimy)
{
	m_aimy = aimy;
}
