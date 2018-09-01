// DrumZombie.cpp: implementation of the CDrumZombie class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DrumZombie.h"
#include "Resource.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDrumZombie::CDrumZombie()
{
	m_isNormal = false;
	m_hp = 450;
	CResource::LoadImg(CResource::m_drumZom_move, m_Move_Img_my, 6);
	CResource::LoadImg(CResource::m_drumlZom_attack, m_Attack_Img_my, 6);
	SetAnimType("move");
}

CDrumZombie::~CDrumZombie()
{

}
