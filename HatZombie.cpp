// HatZombie.cpp: implementation of the CHatZombie class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HatZombie.h"
#include "Resource.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHatZombie::CHatZombie()
{
	m_isNormal = false;
	m_hp = 250;
	CResource::LoadImg(CResource::m_hatZom_move, m_Move_Img_my, 11);
	CResource::LoadImg(CResource::m_hatZom_attack, m_Attack_Img_my, 6);
	SetAnimType("move");
}

CHatZombie::~CHatZombie()
{

}
