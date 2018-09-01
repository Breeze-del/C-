// DrumZombie.h: interface for the CDrumZombie class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRUMZOMBIE_H__7218FDC2_9E09_4F56_8DCF_0CA45B824323__INCLUDED_)
#define AFX_DRUMZOMBIE_H__7218FDC2_9E09_4F56_8DCF_0CA45B824323__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Zombies.h"
/**
* @class CDrumZombie
* @brief  铁帽僵尸
*
* 铁帽僵尸类 CZombies派生类 初化始状态变量
*/
class CDrumZombie : public CZombies
{
public:
	CDrumZombie();
	virtual ~CDrumZombie();

};

#endif // !defined(AFX_DRUMZOMBIE_H__7218FDC2_9E09_4F56_8DCF_0CA45B824323__INCLUDED_)

