// ActiveObj.h: interface for the CActiveObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTIVEOBJ_H__6CD6E9AB_4AE9_41B4_9483_91B734C60195__INCLUDED_)
#define AFX_ACTIVEOBJ_H__6CD6E9AB_4AE9_41B4_9483_91B734C60195__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameObject.h"
#include "cv.h"
#include "highgui.h"
#include <vector>
#include <string.h>
using namespace std;
/**
* @class CActiveObj
* @brief 动态游戏组件
*
* CActiveObj  动态游戏组件 是游戏中其他的动态物体的基类
*/
class CActiveObj : public CGameObject      //有动画的gameobj
{
public:
	/**
	* @brief SetAttack
	*
	*改变物体的状态函数 虚函数
	* @param 无
	* @return void  不返回值
	*/
	virtual void SetAttack();
	/**
	* @brief Timething
	*
	* 时间函数
	* @param 无
	* 
	*/
	virtual void Timething();
	CActiveObj();
	virtual ~CActiveObj();
	/**
	* @brief Draw
	*
	* 绘图函数
	* @param bg 背景图地址
	* 
	*/
	virtual void Draw(IplImage* bg);
	void SetPos(int i, int j);            //设置坐标函数, i 表示行, j 表示列.
	bool CheckDead();                      //检测是否该被清除.
	/**
	 * @brief TakeDamage 
	 * 
	 * 判断物体收到伤害
	 * @param damage 对物体的伤害值
	 * 
	 */
	virtual void TakeDamage(int damege);   //受伤害函数.
	/**
	 * @brief SetAnimType 
	 * 
	 * 改变组件的状态 有move attack ilde dead
	 * @param srr 代表组件状态的字符串
	 * 
	 */
	virtual void SetAnimType(string str);  //改变actobj状态.
	/**
	* @brief Move
	*
	*移动
	* @param 无
	* 
	*/
	virtual void Move();                   //移动.
	vector <IplImage* >::iterator m_it;  //actobj的图片类型.       /**< actobj的图片类型 */
	vector <IplImage* > m_Idle_Img;         //actobj的闲置动画.    /**< actobj的闲置动画 */
	vector <IplImage* > m_Move_Img;         //actobj的行走动画.    /**< actobj移动动画 */
	vector <IplImage* > m_Attack_Img;       //actobj的攻击动画.    /**< actobj的攻击动画 */
	vector <IplImage* > m_Dead_Img;         //actobj的死亡动画.   /**< actobj的死亡类型 */
	/**
	 * @brief Getobjtype 
	 * 
	 * 获得组件的的类别 0植物 1僵尸
	 * @param 无
	 * @return int 返回组件类别
	 */
	int Getobjtype();
	/**
	* @brief Getm_isbullet
	*
	* 获得是否可以发射子弹
	* @param 无
	* @return int 返回是否可以发射子弹
	*/
	bool Getm_isbullet();
	/**
	* @brief Chnagem_isbullet
	*
	* 改变状态
	* @param 无
	* 
	*/
	void Changem_isbullet(bool isbullet);
	/**
	* @brief	Getballtype
	*
	* 获得子弹类型
	* @param 无
	* @return int 返回子弹类型
	*/
	int Getballtype();
	/**
	* @brief Getm_iscreatsun
	*
	* 是否可以产生阳光
	* @param 无
	* @return bool 返回判断
	*/
	bool Getm_iscreatsun();
	/**
	* @brief Changem_iscreatsun
	*
	* 改变 变量是否产生阳光
	* @param bool iscreatsun 是否能产生阳光状态量
	* 
	*/
	void Changem_iscreatsun(bool iscreatsun);
	/**
	* @brief Changem_ismove
	*
	* 改变移动状态
	* @param bool ismove
	* 
	*/
	void Changem_ismove(bool ismove);
	/**
	* @brief Getm_ismove
	*
	* 获得移动状态
	* @param 无
	* @return bool 返回移动状态
	*/
	bool Getm_ismove();
	/**
	* @brief Getm_attack
	*
	* 获得攻击状态
	* @param 无
	* @return bool 返回攻击状态
	*/
	bool Getm_attack();
	/**
	* @brief Getm_bomb
	*
	* 获得爆炸状态
	* @param 无
	* @return bool 返回爆炸状态
	*/
	bool Getm_bomb();
	/**
	* @brief Getm_pumkin
	*
	* 获得是否为窝瓜
	* @param 无
	* @return bool 是否为窝瓜
	*/
	bool Getm_pumkin();
	/**
	* @brief Getm_isdead
	*
	* 获得死亡状态
	* @param 无
	* @return bool 返回死亡状态
	*/
	bool Getm_isdead();
	/**
	* @brief Getm_isidle
	*
	* 获得等待状态
	* @param 无
	* @return bool 返回等待状态
	*/
	bool Getm_isidle();
	/**
	* @brief Changem_normal
	*
	* 获得僵尸类别
	* @param 无
	* @return bool 返回僵尸类别
	*/
	void Changem_normal(bool normal);
protected: 
	int m_hp;  	                            //血量 .          /**< 物体的血量 */
	int m_speed;                            //速度.           /**< 物体的运动速度 */
	bool m_isIdle;                          //是否在闲置.     /**< 是否闲置 */
	bool m_isMove;                          //是否在移动.     /**< 是否移动 */
	bool m_isDead;                          //是否已死亡.     /**< 是否死亡 */
	bool m_isAttack;                        //是否在攻击.     /**< 是否在攻击 */
	bool m_isBomb;                          //是否被爆炸.     /**< 是否被爆炸 */
	bool m_isBullet;                        //是否可以发子弹. /**< 是否可以发子弹 */
	bool m_isCreatsun;                      //是否可以生产阳光./**< 是否可以产生阳光 */
	bool m_isPumkin;                        //是否是窝瓜。     /**< 是否是窝瓜 */
	bool m_ischomper;                       //是否是食人花     /**< 是否是食人花 */
	int m_balltype;                         //子弹类型.        /**< 子弹类型 */
	int m_imgNum;                           //actobj的图片序号. /**< actobj的图片序号 */
	int m_imgSum;                           //actobj的图片类型总数. /**< actobj的图片类型总数 */
	int m_animRate;                         //actobj的动画帧率.   /**< actobj的动画帧率 */
	int m_objType;                          //区分僵尸和植物.    /**< 区分僵尸和植物 1为僵尸 0为植物 */
	int m_bomb;                                                  /**< 是否爆炸 */
	bool m_isNormal;                        //是否变为普通僵尸.  /**< 是否是普通僵尸 */

};

#endif // !defined(AFX_ACTIVEOBJ_H__6CD6E9AB_4AE9_41B4_9483_91B734C60195__INCLUDED_)

