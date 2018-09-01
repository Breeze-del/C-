// StillObj.h: interface for the CStillObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STILLOBJ_H__00D2BFC2_F704_467F_B115_5543DF66BB85__INCLUDED_)
#define AFX_STILLOBJ_H__00D2BFC2_F704_467F_B115_5543DF66BB85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameObject.h"
/**
* @class CStillObj
* @brief  静态组件
*静态组件类
*
*/
class CStillObj : public CGameObject                
{
public:
	CStillObj();
	virtual ~CStillObj();
	/**
	* @brief Timething
	*
	* 时间函数
	* @param 无
	*
	*/
	virtual void Timething();
	//设置坐标，这里是像素坐标.
	/**
	* @brief SetPos
	*
	* 重置位置函数
	* @param x 像素位置x
	* @param y 像素位置y
	*/
	virtual void SetPos(int x, int y);
	/**
	* @brief Draw
	*
	* 打印卡片专用Draw
	* @param bg 背景图指针
	* @param up 为上半部分亮度
	* @param down 为下半部分亮度
	* @param l 为上下部分比例
	* @param tx 位置
	* @param ty 位置
	*/
	virtual void Draw(IplImage* bg, double down, double up = 1, double l = 1, int tx = 0, int ty = 0);
	bool m_isCd;                                   /**< 是否在冷却*/

};

#endif // !defined(AFX_STILLOBJ_H__00D2BFC2_F704_467F_B115_5543DF66BB85__INCLUDED_)

