// Nut.h: interface for the CNut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NUT_H__10EE19C0_DD2B_409B_9B2E_2167E45FA220__INCLUDED_)
#define AFX_NUT_H__10EE19C0_DD2B_409B_9B2E_2167E45FA220__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ActiveObj.h"
/**
* @class CNut
* @brief  坚果
*
*
*/
class CNut : public CActiveObj
{
public:
	/**
	* @brief Timething
	*
	* 时间函数
	* @param 无
	*
	*/
	void Timething();
	CNut();
	virtual ~CNut();

};

#endif // !defined(AFX_NUT_H__10EE19C0_DD2B_409B_9B2E_2167E45FA220__INCLUDED_)

