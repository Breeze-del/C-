// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include "Bg.h"
#include "Ball.h"
#include "Card.h"
#include "Scoop.h"
#include "MouseThing.h"
#include "StillObj.h"
#include "ActiveObj.h"
#include "Factory.h"
#include "Sun.h"
#include <vector>
using namespace std;

#if !defined(AFX_GAME_H__229A557E_913E_41AC_8146_55EA7035A1EE__INCLUDED_)
#define AFX_GAME_H__229A557E_913E_41AC_8146_55EA7035A1EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @class CGame
* @brief  游戏引擎类
*
* 游戏引擎类 综合控制所有组件的运行
*/
class CGame
{
public:
	/**
	* @brief CheckEnd
	*
	* 检查游戏是否已经结束 结束了就改变游戏进程变量
	* @param 无
	*
	*/
	void CheckEnd();
	/**
	* @brief Init
	*
	* 初化始游戏引擎 完成对组件的加载和变量的初化始
	* @param 无
	*
	*/
	void Init();
	/**
	* @brief SortObj
	*
	* 对游戏组件进行排序 位置远的排在后面 位置近的排在前面 
	* @param 无
	*
	*/
	void SortObj();
	/**
	* @brief CheckAttack
	*
	* 检查所有组件的攻击行为 僵尸转化攻击状态 植物攻击僵尸 僵尸攻击植物 子弹攻击僵尸 炸弹攻击僵尸 窝瓜攻击僵尸
	* @param 无
	*
	*/
	void CheckAttack();
	/**
	* @brief SpawnZombies
	*
	* 利用工厂产生僵尸，并记录每行僵尸的数目
	* @param 无
	*
	*/
	void SpawnZombies();
	/**
	* @brief CountText
	*
	* 记录拾起阳光总数 和得分总数
	* @param 无
	*
	*/
	void CountText();
	/**
	* @brief WaitAndQuit
	*
	* 更新游戏时间和ESC退出游戏 空格暂停游戏
	* @param 无
	*
	*/
	bool WaitAndQuit();
	/**
	* @brief MoveObj
	*
	* 太阳移动函数 使产生的阳光竖直移动 并且到底之后一段时间后删除阳光
	* @param 无
	*
	*/
	void MoveObj();
	/**
	* @brief CreatSun
	*
	* 生成阳光 包括随时间随机位置产生阳光 花随时间产生阳光
	* @param 无
	*
	*/
	void CreatSun();
	/**
	* @brief CreatBall
	*
	* 产生子弹 获取子弹的类型并标记符号 normal普通子弹 ice寒冰子弹
	* @param 无
	*
	*/
	void CreatBall();
	/**
	* @brief ClearObj
	*
	* 清除所有游戏组件 包括植物 子弹 太阳
	* @param 无
	*
	*/
	void ClearObj();
	CGame();
	virtual ~CGame();
	/**
	* @brief CreatPlants
	*
	* 利用工厂产生植物 并且完成扣除消耗 标记地图
	* @param num 植物编号
	* @param i 植物位置列数
	* @param j 植物位置行数
	*/
	void CreatPlants(int num, int i, int j);
	CCard m_cards;                          //卡片系统. /**< 卡片系统 */
	CScoop m_scoop;                         //铲子.    /**< 铲子 */
	CBg m_bg;                               //背景.    /**< 背景图 */
	CStillObj m_plant;                      //种植时候的图片./**< 植物实图 */
	CStillObj m_plant_write;                //种植时候的影子./**< 植物虚图 */
	/**
	* @brief CheckPos
	*
	* 判断土地是否有植物 
	* @param i 植物位置列数
	* @param j 植物位置行数
	* @return bool 返回是否有植物 true有植物 false无植物
	*/
	bool CheckPos(int i, int j);             //判断该土地是否有植物.
	/**
	* @brief GetSun
	*
	* 拾起阳光函数
	* @param x 阳光像素列位置
	* @param y 阳光像素行位置
	*/
	void GetSun(int x, int y);               //拾起阳光函数.
	/**
	* @brief Time
	*
	* 每帧调用的计时器函数 负责笤俑所有组件自己的时间函数和移动函数 创造子弹和阳光
	* @param 无
	*/
	void Time();                            //每帧调用的计时器函数.
	/**
	* @brief Draw
	*
	* 所有的gameobj组件的绘制函数
	* @param 无
	* 
	*/
	void Draw();                            //所有gameobj的绘制.
	/**
	* @brief Run
	*
	* 游戏运行函数
	* @param 无
	* 
	*/
	void Run();                             //游戏运行函数.
	/**
	* @brief Getm_sunnum
	*
	* 返回阳光总数
	* @param 无
	* @return int 阳光总数
	*/
	int Getm_sunnum();
	/**
	* @brief Chnagem_type
	*
	* 改变游戏进行状态
	* @param type 游戏进行状态 1为开始 2为进行中 3为结束
	* 
	*/
	void Changem_type(int type);
	/**
	* @brief Getm_gametype
	*
	* 获得游戏进行状态
	* @param 无
	* @return 返回游戏游戏进行状态 
	*/
	int Getm_gametype();
	/**
	* @brief Changem_musiccount
	*
	* 改变音乐限制的变量
	* @param count 音乐限制参数
	*
	*/
	void Changem_musiccount(int count);
	/**
	* @brief Chnagem_clearx
	*
	* 改变清除位置x
	* @param clearx 清除位置x
	*
	*/
	void Changem_clearx(int clearx);
	/**
	* @brief Chnagem_cleary
	*
	* 改变清除位置y
	* @param cleary 清除位置y
	*
	*/
	void Chnagem_cleary(int cleary);
private:
	IplImage* m_startimg;                   //开始界面图片.     /**< 开始界面图片 */
	IplImage* m_endimg;                    //结束界面图片.      /**< 结束界面图片 */
	int m_waittime;                         //每帧时间          /**< 每帧时间 */
	int m_pretime;                          //记录上帧时间.     /**< 记录上帧时间 */
	int m_sunnum;                           //阳光总数.         /**< 阳光总数 */
	int m_mpt[9][5];                        //土地.             /**< 土地 */
	int m_zomnum[5];                        //每行僵尸数量.     /**< 每行僵尸数量 */
	int m_clearx;                                               /**< 清除位置X */
	int m_cleary;                           //铲子清除的位置.   /**< 清除位置Y */
	int m_score;                                                /**< 得到的分数值 */
	int m_suntime;                          //生产太阳计时器.   /**< 生产太阳的计时器 */
	int m_musiccount;                       //音乐播放限制参数.  /**< 音乐播放限制参数 */
	int m_gametype;                         //游戏当前环节.     /**< 游戏进行的环节数 */
	char m_sunstr[10];                      //太阳数目字符串格式.  /**< 太阳数目字符串格式 */
	char m_levelstr[10];                    //关卡字符串格式.    /**< 关卡字符串格式 */
	char m_scorestr[10];                    //分数字符串格式.     /**< 分数字符串格式 */
	CvFont m_sunfont;                       //显示太阳数目的文字. /**< 显示太阳数目的文字 */
	CvFont m_level;                         //关卡.              /**< 关卡 */
	CMouseThing m_mouse;                    //鼠标事件系统.      /**< 鼠标事件系统 */
	CFactory m_factory;                     //生产工厂.          /**< 工厂系统 */
	vector<CActiveObj* > m_gameobj;         //所有的actobj.      /**< 所有的actobj组件 */ 
	vector<CBall> m_ball;                   //所有的子弹.        /**< 所有的子弹 */
	vector<CSun> m_sun;                     //所有的太阳.        /**< 所有的太阳 */
};

#endif // !defined(AFX_GAME_H__229A557E_913E_41AC_8146_55EA7035A1EE__INCLUDED_)

