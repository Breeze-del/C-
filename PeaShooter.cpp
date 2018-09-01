// PeaShooter.cpp: implementation of the CPeaShooter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PeaShooter.h"
#include "Resource.h"
#include "stdio.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPeaShooter::CPeaShooter()
{
	CResource::LoadImg(CResource::m_peashooter, m_Idle_Img, 4);
	SetTimer(32);
	m_timer = 24;
	SetAnimType("idle");
	m_balltype = 0;
}

CPeaShooter::~CPeaShooter()
{

}

void CPeaShooter::Timething()
{
	//´´½¨×Óµ¯.
	m_isBullet = true;
	m_timer = 0;
}
