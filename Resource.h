// Resource.h: interface for the CResource class.
//
//////////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include "vector"
using namespace std;


#if !defined(AFX_RESOURCE_H__6BC9150F_ACCE_4042_8B98_AEE1A550DB9D__INCLUDED_)
#define AFX_RESOURCE_H__6BC9150F_ACCE_4042_8B98_AEE1A550DB9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @class Resource
* @brief  图片资源类
*管理 加载所有游戏图片资源
*
*/
class CResource
{
public:
	/**
	* @brief Clear
	*
	* 清除图片资源
	* @param img 图片指针
	* @param num 多少张图片
	*/
	void Clear(IplImage* img[], int num);
	CResource();
	virtual ~CResource();
	/**
	* @brief LoadImg
	*
	* 加载图片到vector里
	* @param in 图片指针
	* @param out 图片vector的名字
	* @param num 多少张图片
	*/
	static void LoadImg(IplImage *in[], vector <IplImage* >& out, int num);
	static IplImage* m_ball;                                   /**< 子弹的图 */
	static IplImage* m_iceball;                                /**< 寒冰子弹的图 */ 
	static IplImage* m_sun;                                    /**< 太阳的图 */
	static IplImage* m_bg;                                     /**< 背景 */
	static IplImage* m_scoop;                                  /**< 铲子图 */
	static IplImage* m_cards[7];                               /**< 卡片图 */
	static IplImage* m_peashooter[4];                          /**< 豌豆射手图 */
	static IplImage* m_sunflower[3];                           /**< 向日葵图片 */ 
	static IplImage* m_iceshooter[3];                          /**< 寒冰豌豆射手 */
	static IplImage* m_pumpkin[4];                             /**< 窝瓜图片 */
	static IplImage* m_pumpkin_attack[4];                      /**< 窝瓜攻击图 */
	static IplImage* m_nut[4];                                 /**< 坚果图 */
	static IplImage* m_cherrybomb[6];                          /**< 樱桃炸弹图 */
	static IplImage* m_peashooter_write;                       /**< 豌豆射手阴影图 */
	static IplImage* m_sunflower_write;                        /**< 向日葵阴影图 */
	static IplImage* m_iceshooter_write;                       /**< 寒冰豌豆阴影图 */
	static IplImage* m_pumpkin_write;                          /**< 窝瓜阴影图 */
	static IplImage* m_nut_write;                              /**< 坚果阴影图 */
	static IplImage* m_cherrybomb_write;                       /**< 樱桃炸弹阴影图 */
	static IplImage* m_hatZom_move[11];                        /**< 帽子僵尸移动 */
	static IplImage* m_hatZom_attack[6];                       /**< 帽子僵尸攻击 */
	static IplImage* m_doorZom_move[9];                        /**< 铁门僵尸移动 */
	static IplImage* m_doorZom_attack[6];                       /**< 铁门僵尸攻击 */
	static IplImage* m_drumZom_move[6];                        /**< 铁帽僵尸移动 */
	static IplImage* m_drumlZom_attack[6];                    /**< 铁帽僵尸攻击 */
	static IplImage* m_normalZom_move[6];                      /**< 普通僵尸移动 */
	static IplImage* m_normalZom_dead[7];                       /**< 普通僵尸死亡 */
	static IplImage* m_normalZom_attack[6];                    /**< 普通僵尸攻击 */
	static IplImage* m_normalZom_bomb[10];                    /**< 普通僵尸爆炸 */
	static IplImage* m_startimg;                             /**< 界面开始图 */ 
	static IplImage* m_endimg;                               /**< 界面结束图 */
	static IplImage* m_warning;                               /**< 警告图 */
	static IplImage* m_prepare;                                 /**< 准备图 */
};

#endif // !defined(AFX_RESOURCE_H__6BC9150F_ACCE_4042_8B98_AEE1A550DB9D__INCLUDED_)

