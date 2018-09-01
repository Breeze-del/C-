// Scoop.h: interface for the CScoop class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCOOP_H__3376BC17_7986_4F23_953A_323BA773180A__INCLUDED_)
#define AFX_SCOOP_H__3376BC17_7986_4F23_953A_323BA773180A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StillObj.h"
/**
* @class CScoop
* @brief  铲子
*铲子类
*
*/
class CScoop : public CStillObj
{
public:
	/**
	* @brief Init
	*
	* 初化始铲子 加载图片
	*/
	void Init();
	CScoop();
	virtual ~CScoop();
	bool m_isMove;                    /**< 是否移动 */

};

#endif // !defined(AFX_SCOOP_H__3376BC17_7986_4F23_953A_323BA773180A__INCLUDED_)

