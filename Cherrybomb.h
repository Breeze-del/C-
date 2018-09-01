// Cherrybomb.h: interface for the CCherrybomb class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHERRYBOMB_H__8BBB3DAE_E084_4F62_A3E2_18E1576FBD05__INCLUDED_)
#define AFX_CHERRYBOMB_H__8BBB3DAE_E084_4F62_A3E2_18E1576FBD05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ActiveObj.h"
/**
* @class CCherrybomb
* @brief  樱桃炸弹
*
* 樱桃炸弹类 一种植物 是CActiveObj的派生类 负责绘图判定
*/
class CCherrybomb : public CActiveObj
{
public:
	/**
	* @brief Draw
	*
	*绘图函数绘制炸弹动画
	* @param bg 背景图
	*
	*/
	void Draw(IplImage* bg);
	CCherrybomb();
	virtual ~CCherrybomb();

};

#endif // !defined(AFX_CHERRYBOMB_H__8BBB3DAE_E084_4F62_A3E2_18E1576FBD05__INCLUDED_)

