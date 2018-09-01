// DoorZombie.cpp: implementation of the CDoorZombie class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DoorZombie.h"
#include "Resource.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDoorZombie::CDoorZombie()
{
	m_isNormal = false;
	m_hp = 600;
	CResource::LoadImg(CResource::m_doorZom_move, m_Move_Img_my, 9);
	CResource::LoadImg(CResource::m_doorZom_attack, m_Attack_Img_my, 6);
	SetAnimType("move");
}

CDoorZombie::~CDoorZombie()
{

}
