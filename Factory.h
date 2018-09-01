// Factory.h: interface for the CFactory class.
//
//////////////////////////////////////////////////////////////////////
#include "ActiveObj.h"
#include "PeaShooter.h"
#include "IceShooter.h"
#include "SunFlower.h"
#include "Pumkin.h"
#include "Cherrybomb.h"
#include "Zombies.h"
#include "HatZombie.h"
#include "DoorZombie.h"
#include "DrumZombie.h"
#include "Nut.h"
#include "string"
#include"Chomper.h"
using namespace std;

#if !defined(AFX_FACTORY_H__E848F3C0_E4B8_47E4_83E1_D160BE3E690A__INCLUDED_)
#define AFX_FACTORY_H__E848F3C0_E4B8_47E4_83E1_D160BE3E690A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @class CFactory
* @brief  工厂类
*
* 工厂类 根据时间产生僵尸和负责根据点击事件产生植物
*/
class CFactory
{
public:
	/**
	* @brief Init
	*
	* 初化始工厂 重置时间变量
	* @param 无
	*
	*/
	void Init();
	/**
	* @brief Spawn
	*
	* 产生僵尸的算法，根据时间算法产生僵尸
	* @param 无
	* @return CActiveObj 返回产生对象的指针
	*/
	CActiveObj* Spawn();
	/**
	* @brief Creat
	*
	* 产生植物类的对象
	* @param num 植物编号
	* @param i 列数
	* @param j 行数
	* @return CActiveObj 返回生成植物对象的指针
	*/
	CActiveObj* Creat(int num, int i, int j);
	CFactory();
	virtual ~CFactory();
	/**
	* @brief Getm_spawntime
	*
	* 获得时间变量
	* @param 无
	* @return int 返回时间变量的值
	*/
	int Getm_spawntime();
private:
	bool m_isp;         /**< 工厂初化始状态 true初化始 */
	int m_spawntime;    /**< 工厂时间变量 */ 
	int m_spawnrate;    /**< 工厂时间变量上限 */
	IplImage* m_warnimg;/**< 警告动画图片 */
	IplImage* m_prepare;/**< 准备动画图片 */
};

#endif // !defined(AFX_FACTORY_H__E848F3C0_E4B8_47E4_83E1_D160BE3E690A__INCLUDED_)

