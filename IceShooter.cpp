// IceShooter.cpp: implementation of the CIceShooter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IceShooter.h"
#include "Resource.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIceShooter::CIceShooter()
{
	CResource::LoadImg(CResource::m_iceshooter, m_Idle_Img, 3);
	SetTimer(48);
	m_timer = 16;
	SetAnimType("idle");
	m_balltype = 1;
}

CIceShooter::~CIceShooter()
{

}
void CIceShooter::Timething()
{
	//´´½¨×Óµ¯
	m_isBullet = true;
	m_timer = 0;
}
