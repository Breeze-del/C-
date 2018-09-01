// MouseThing.h: interface for the CMouseThing class.
//
//////////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include "Scoop.h"
#include "Card.h"
#if !defined(AFX_MOUSETHING_H__55B922DB_D501_4A26_B60A_CA003D5AFBC0__INCLUDED_)
#define AFX_MOUSETHING_H__55B922DB_D501_4A26_B60A_CA003D5AFBC0__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CGame;
/**
* @class CMouseThing
* @brief  鼠标点击事件
*管理鼠标所有操作并触发相应时间改变状态量
*
*/
class CMouseThing
{
public:
	/**
	* @brief CheckPos
	*
	* 检查是否越界 
	* @param 无
	*
	*/
	void CheckPos();
	/**
	* @brief ChnageImg
	*
	* 改变图片
	* @param 无
	*
	*/
	void ChangeImg();
	CMouseThing();
	virtual ~CMouseThing();

	/**
	* @brief MouseOn
	*
	* 点击事件函数
	* @param event 事件变量
	* @param x 鼠标位置x
	* @param y 鼠标位置y
	* @param flags 键盘事件变量
	* @param param 空的指针
	*/
	static void MouseOn(int event, int x, int y, int flags, void* param);
	/**
	* @brief MouseComeOn
	*
	* 初化始鼠标点击时间系统
	* @param game CGame的指针
	*
	*/
	void MouseComeOn(CGame* game);                 //初始化
	/**
	* @brief PosIJtoXY
	*
	* ij坐标转换为XY坐标
	* @param i i坐标
	* @param j j坐标
	*/
	virtual CvPoint PosIJtoXY(int i, int j);      //ij坐标转换为xy坐标.
	/**
	* @brief PosXYtoIJ
	*
	* xy坐标转换为ij坐标
	* @param x 像素坐标x
	* @param y 像素坐标y
	*/
	virtual CvPoint PosXYtoIJ(int x, int y);        //xy坐标转换为ij坐标.
	/**
	* @brief CheckMouseCard
	*
	* 检查是否可以种植 种植状态的转换 切换植物图片
	* @param x 像素位置x
	* @param y 像素位置y
	* @return bool true切换 false没切换
	*/
	bool CheckMouseCard(int x, int y);                //种植状态转换函数.
	CGame* m_game;                                    /**< 游戏引擎指针 */
	CScoop* m_scoop;                                  /**< 铲子指针 */
	CCard* m_cards;                                   /**< 卡牌指针 */
	/**
	* @brief Getm_isplant
	*
	* 获得是否在种植状态
	* @param 无
	* @return bool true在种植状态 false不在种植状态
	*/
	bool Getm_isplant();
private:
	bool m_isplant;                                  //是否在种植状态. /**< 是否在种植状态 */
	int m_planttype;                                 //种植的植物种类. /**< 种植的植物种类 */
};


#endif // !defined(AFX_MOUSETHING_H__55B922DB_D501_4A26_B60A_CA003D5AFBC0__INCLUDED_)

