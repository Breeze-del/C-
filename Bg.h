// Bg.h: interface for the CBg class.
//
//////////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"


#if !defined(AFX_BG_H__C9ABEB5D_2BE6_436C_9607_C182F28045A2__INCLUDED_)
#define AFX_BG_H__C9ABEB5D_2BE6_436C_9607_C182F28045A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @class CBg
* @brief  背景类
*
* 背景类 储存着背景和绘画背景
*/
class CBg
{
public:
	/**
	* @brief Show
	*
	*将背景图绘画到窗口上
	* @param *img  背景图指针  
	* 
	*/
	void Show(IplImage* img);
	/**
	* @brief  Draw
	*
	*刷新背景图，更新背景图
	* @param 无
	* 
	*/
	void Draw();
	CBg();
	virtual ~CBg();
	IplImage* m_img;   /**< 背景图指针 */
	IplImage* m_clone;  /**< 背景图克隆图指针 */

};

#endif // !defined(AFX_BG_H__C9ABEB5D_2BE6_436C_9607_C182F28045A2__INCLUDED_)

