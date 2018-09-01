// Pumkin.h: interface for the CPumkin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMKIN_H__11C7DC63_2620_478F_A118_9E27FE5D9CEC__INCLUDED_)
#define AFX_PUMKIN_H__11C7DC63_2620_478F_A118_9E27FE5D9CEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ActiveObj.h"
/**
* @class CPunkin
* @brief  窝瓜
*
*
*/
class CPumkin : public CActiveObj
{
public:
	/**
	* @brief Draw
	*
	* 绘图函数
	* @param bg 背景指针
	*
	*/
	void Draw(IplImage* bg);
	/**
	* @brief Timething
	*
	* 时间函数
	* @param 无
	*
	*/
	void Timething();
	CPumkin();
	virtual ~CPumkin();

};

#endif // !defined(AFX_PUMKIN_H__11C7DC63_2620_478F_A118_9E27FE5D9CEC__INCLUDED_)

