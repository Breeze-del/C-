// Ball.h: interface for the CBall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALL_H__8F73354A_9D03_465E_92C5_9492E53ADBA2__INCLUDED_)
#define AFX_BALL_H__8F73354A_9D03_465E_92C5_9492E53ADBA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StillObj.h"
#include <string.h>
using namespace std;
/**
* @class CBall
* @brief 子弹类
*
* CBall  是静态游戏组件的派生类 抽象出所有子弹
*/
class CBall : public CStillObj
{
public:
	/**
	* @brief Setspeed
	*
	*初化始速度
	* @param  speed=10；
	* 
	*/
	void Setspeed(int speed = 10);
	/**
	* @brief Move
	*
	*移动函数
	* @param 无
	* 
	*/
	void Move();
	/**
	* @brief SetType
	*
	*改变物体的状态
	* @param  type  状态量
	* 
	*/
	void SetType(string type);
	CBall();
	virtual ~CBall();
	/**
	* @brief Getm_isdead
	*
	*获得死亡状态
	* @param 无
	* @return int  返回死亡状态值
	*/
	int Getm_dead();
	/**
	* @brief Changem_dead
	*
	*改变子弹死亡状态变量
	* @param dead 死亡状态
	* 
	*/
	void Changem_dead(int dead);
	/**
	* @brief Getm_type
	*
	*获得子弹类型
	* @param 无
	* @return int 返回子弹类型 1为普通子弹 2为冰子弹
	*/
	int Getm_type();
private:
	int m_speed;    /**< 子弹速度 */
	int m_dead;     /**< 是否死亡 */
	int m_type;     /**< 子弹类型 1为普通子弹 2为寒冰子弹 */
};

#endif // !defined(AFX_BALL_H__8F73354A_9D03_465E_92C5_9492E53ADBA2__INCLUDED_)

