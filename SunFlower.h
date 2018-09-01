// SunFlower.h: interface for the CSunFlower class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUNFLOWER_H__DF8BBF33_8479_4DD2_AC0C_97AE105F861F__INCLUDED_)
#define AFX_SUNFLOWER_H__DF8BBF33_8479_4DD2_AC0C_97AE105F861F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ActiveObj.h"
/**
* @class CSunFlower
* @brief  向日葵
*  
*
*/
class CSunFlower : public CActiveObj
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
	CSunFlower();
	virtual ~CSunFlower();

};

#endif // !defined(AFX_SUNFLOWER_H__DF8BBF33_8479_4DD2_AC0C_97AE105F861F__INCLUDED_)

