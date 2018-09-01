// DoorZombie.h: interface for the CDoorZombie class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOORZOMBIE_H__C8446855_DB12_468C_8EAA_68ABC1CDD2F9__INCLUDED_)
#define AFX_DOORZOMBIE_H__C8446855_DB12_468C_8EAA_68ABC1CDD2F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Zombies.h"
/**
* @class DoorZombies
* @brief  铁门僵尸
*
* 铁门僵尸 CZombies派生类 初化始状态变量
*/
class CDoorZombie : public CZombies
{
public:
	CDoorZombie();
	virtual ~CDoorZombie();

};

#endif // !defined(AFX_DOORZOMBIE_H__C8446855_DB12_468C_8EAA_68ABC1CDD2F9__INCLUDED_)

