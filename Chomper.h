#pragma once
#include "ActiveObj.h"
/**
* @class CChomper
* @brief  食人花
*
* 食人花类 CActiveObj派生类 绘制图像和时间函数
*/
class CChomper :
	public CActiveObj
{
public:
	CChomper();
	~CChomper();
	/**
	* @brief Draw
	*
	*绘图函数绘制食人花动画
	* @param bg 背景图
	*
	*/
	void Draw(IplImage* bg);
	/**
	* @brief Timething
	*
	*时间函数
	* @param 无
	*
	*/
	void Timething();
};

