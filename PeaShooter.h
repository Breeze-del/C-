// PeaShooter.h: interface for the CPeaShooter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEASHOOTER_H__78339EDC_6472_41D9_968D_4DDF11481EEE__INCLUDED_)
#define AFX_PEASHOOTER_H__78339EDC_6472_41D9_968D_4DDF11481EEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ActiveObj.h"
/**
* @class CPeaShooter
* @brief  豌豆射手
*
*
*/
class CPeaShooter : public CActiveObj
{
public:
	/**
	* @brief Timething
	*
	* 时间函数
	* @param 无
	*
	*/
	void Timething();               //复写时间事件函数.
	CPeaShooter();
	virtual ~CPeaShooter();
};

#endif // !defined(AFX_PEASHOOTER_H__78339EDC_6472_41D9_968D_4DDF11481EEE__INCLUDED_)

