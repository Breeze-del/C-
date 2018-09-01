// SunFlower.cpp: implementation of the CSunFlower class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SunFlower.h"
#include "Resource.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSunFlower::CSunFlower()
{
	CResource::LoadImg(CResource::m_sunflower, m_Idle_Img, 3);
	SetTimer(400);
	m_animRate = 10;
	m_timer = 0;
	SetAnimType("idle");
}

CSunFlower::~CSunFlower()
{

}

void CSunFlower::Timething()
{
	m_isCreatsun = true;
	m_timer = 0;
}
