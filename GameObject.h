// GameObject.h: interface for the CGameObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEOBJECT_H__ED3CFCCE_7C47_46F6_B3BE_B3DB2BB63760__INCLUDED_)
#define AFX_GAMEOBJECT_H__ED3CFCCE_7C47_46F6_B3BE_B3DB2BB63760__INCLUDED_
#include "cv.h"
#include "highgui.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @class CGameObject
* @brief  游戏组件类
*
* 是所有游戏组件的基类
*/
class CGameObject
{
public:

	CGameObject();
	virtual ~CGameObject();
	/**
	* @brief Time
	*
	* 计时器函数
	* @param 无
	*
	*/
	virtual void Time();                          //计时器函数.
	/**
	* @brief Timething
	*
	* 计时器事件
	* @param 无
	*
	*/
	virtual void Timething();                     //计时器事件.
	/**
	* @brief Draw
	*
	* 将组件的图绘画到背景图上
	* @param bg 背景图指针
	*
	*/
	virtual void Draw(IplImage* bg);              //绘制函数.
	/**
	* @brief SetTimer
	*
	* 初化始时间和时间限制变量
	* @param time 时间变量
	*
	*/
	virtual void SetTimer(int time);              //初始化计时变量.
	/**
	* @brief SetPos
	*
	* 初化始位置
	* @param i  位置列数
	* @param j  位置行数
	*
	*/
	virtual void SetPos(int i, int j);           //空.

	IplImage *m_img;                              //主要图片.   /**< 组件自己的图片 */
	/** @brief m_position */
	struct{                                       //位置.
		int i, j; /**< 物体位置结构体 */
		int x, y; /**< 物体位置结构体 */
	}m_Position;
	/**
	* @brief Changem_timer
	*
	* 改变时间变量
	* @param time 改变的值
	*
	*/
	void Changem_timer(int timer);
	/**
	* @brief Getm_timer
	*
	* 获取时间变量的值
	* @param 无
	* @return int 返回时间变量的值
	*/
	int Getm_timer();
	/**
	* @brief Getm_timerate
	*
	* 获取计算机间隔
	* @param 无
	* @return int 计时器间隔的值
	*/
	int Getm_timerate();
protected:
	int m_timer;                                  //计时器.       /**< 计时器 */
	int m_timerate;                               //计时器间隔.    /**< 计时器间隔 */

};

#endif // !defined(AFX_GAMEOBJECT_H__ED3CFCCE_7C47_46F6_B3BE_B3DB2BB63760__INCLUDED_)

