// Card.h: interface for the CCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARD_H__5838F85A_0F00_4BE5_B388_8C9F6C4FAE9F__INCLUDED_)
#define AFX_CARD_H__5838F85A_0F00_4BE5_B388_8C9F6C4FAE9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cv.h"
#include "highgui.h"
#include "StillObj.h"
/**
* @class CCard
* @brief  卡片类
*
* 卡片类 里面存有所有植物的卡片 控制冷却时间、植物消耗阳光数和卡片图像的绘制
*/
class CCard
{
public:
	/**
	* @brief Init
	*
	*初始化卡片位置、冷却时间、花费
	* @param 无
	*
	*/
	void Init();
	/**
	* @brief Draw
	*
	*将三种状态的卡片绘画到背景图上  第一种冷却状态 第二种冷却完毕阳光数满足 第三种冷却完毕阳光数不满足
	* @param bg 背景图指针
	* @param sunnum 阳光数
 	*/
	void Draw(IplImage* bg, int sunnum);
	CCard();
	virtual ~CCard();
	/**
	* @brief Getm_cost
	*
	*获取卡片的花费阳光数
	* @param num 第几张卡片
	* @return int 返回卡片代表植物的话费阳光数
	*/
	int Getm_cost(int num);
	CStillObj m_card[6];   /**< 六张卡片的组件数组 */
private:
	int m_cost[6];        /**< 六张卡片的花费数 */
};

#endif // !defined(AFX_CARD_H__5838F85A_0F00_4BE5_B388_8C9F6C4FAE9F__INCLUDED_)

