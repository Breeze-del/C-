// Zombies.h: interface for the CZombies class.
//
//////////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include "vector"
using namespace std;

#if !defined(AFX_ZOMBIES_H__EFA90B53_8AEE_4F68_B5ED_04BC69DFC408__INCLUDED_)
#define AFX_ZOMBIES_H__EFA90B53_8AEE_4F68_B5ED_04BC69DFC408__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ActiveObj.h"
/**
* @class CZombies
* @brief  僵尸类
*
*
*/
class CZombies : public CActiveObj
{
public:
	/**
	* @brief TakeDamage
	*
	* 伤害函数
	* @param damage 伤害值
	*
	*/
	virtual void TakeDamage(int damage);
	/**
	* @brief SetAttack
	*
	* 是状态变为攻击
	* @param 无
	*
	*/
	void SetAttack();
	/**
	* @brief SetAnimType
	*
	* 改变组件状态
	* @param str 组件的状态
	*
	*/
	virtual void SetAnimType(string str);
	/**
	* @brief Draw
	*
	* 绘图僵尸
	* @param bg 背景图指针
	*
	*/
	virtual void Draw(IplImage* bg);
	CZombies();
	virtual ~CZombies();
	vector <IplImage* > m_Move_Img_my;        /**< 僵尸的行走动画.(特别的) */
	vector <IplImage* > m_Attack_Img_my;      /**< 僵尸的攻击动画.(特别的 */
	vector <IplImage* > m_Bomb_Img;            /**< 僵尸的爆炸死亡动画 */
};

#endif // !defined(AFX_ZOMBIES_H__EFA90B53_8AEE_4F68_B5ED_04BC69DFC408__INCLUDED_)

