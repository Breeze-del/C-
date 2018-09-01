// Sun.h: interface for the CSun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUN_H__C5E0AD02_F834_499D_A93F_E59B1FDD75D1__INCLUDED_)
#define AFX_SUN_H__C5E0AD02_F834_499D_A93F_E59B1FDD75D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StillObj.h"
/**
* @class CSun
* @brief  太阳
*  太阳类
*
*/
class CSun : public CStillObj
{
public:
	/**
	* @brief Move
	*
	* 太阳移动函数
	* @param 无
	*
	*/
	void Move();
	CSun();
	virtual ~CSun();
	/**
	* @brief Changem_isGet
	*
	* 改变是否拾起
	* @param isget 是否拾起
	*
	*/
	void Changem_isGet(bool isGet);
	/**
	* @brief Changem_speedx
	*
	* 改变移动速度
	* @param speedx 速度
	*
	*/
	void Changem_speedx(int speedx);
	/**
	* @brief Changem_speedy
	*
	* 改变移动速度
	* @param speedy 速度
	*
	*/
	void Changem_speedy(int speedy);
	/**
	* @brief Changem_isEnd
	*
	* 改变是否结束
	* @param isEnd 结束
	*
	*/
	bool Getm_isEnd();
	/**
	* @brief Changem_aimy
	*
	* 改变目标位置
	* @param aimy 位置
	*
	*/
	void Changem_aimy(int aimy);
	/**
	* @brief Changem_isMove
	*
	* 改变是否移动
	* @param aimy 目标位置
	*
	*/
	void Changem_isMove(bool Move);
	int m_speedx, m_speedy;                     /**< 太阳移动速度 */
	int m_aimy;                                /**< 太阳目标点 */
	bool m_isMove;                             /**< 是否移动 */
	bool m_isGet;                              /**< 是否拾起 */
	bool m_isEnd;                              /**< 是否结束 */
};

#endif // !defined(AFX_SUN_H__C5E0AD02_F834_499D_A93F_E59B1FDD75D1__INCLUDED_)

