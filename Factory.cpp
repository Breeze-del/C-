// Factory.cpp: implementation of the CFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Factory.h"
#include"Resource.h"
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#pragma   comment(linker,   "/subsystem:\"windows\"   /entry:\"mainCRTStartup\""   )
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
DWORD WINAPI Zombies(LPVOID pM)             //背景音乐子线程函数
{
	mciSendString("play .\\music\\zombies.mp3 ", NULL, 0, NULL);
	return 0;
}
DWORD WINAPI Level(LPVOID pM)             //背景音乐子线程函数
{
	mciSendString("play .\\music\\level.mp3 ", NULL, 0, NULL);
	return 0;
}
CFactory::CFactory()
{
	Init();
	m_warnimg = CResource::m_warning;
	m_prepare = CResource::m_prepare;
	m_isp = true;
}

CFactory::~CFactory()
{

}
/*
0.寒冰射手
1.坚果
2.豌豆射手
3.窝瓜
4.向日葵
5.樱桃炸弹

*/
CActiveObj* CFactory::Creat(int num, int i, int j)
{
	if (num == 0) {
		CActiveObj *it = new CIceShooter();
		it->SetPos(i, j);
		return it;
	}
	else if (num == 1) {
		CActiveObj *it = new CNut();
		it->SetPos(i, j);
		return it;
	}
	else if (num == 2) {
		CActiveObj *it = new CPeaShooter();
		it->SetPos(i, j);
		return it;
	}
	else if (num == 3) {
		CActiveObj *it = new CPumkin();
		it->SetPos(i, j);
		return it;
	}
	else if (num == 4) {
		CActiveObj *it = new CSunFlower();
		it->SetPos(i, j);
		return it;
	}
	else if (num == 5) {
		CActiveObj *it = new CCherrybomb();
		it->SetPos(i, j);
		return it;
	}
}


CActiveObj* CFactory::Spawn() //生成怪物的算法.
{
	m_spawntime++;
	int rate1, rate2;
	rate1 = m_spawnrate - m_spawntime / 500;
	rate2 = 4000 - m_spawntime / 50;
	if (rate2 < 500)rate2 = 500;
	if (rate1 < 50)rate1 = 50;
	if (m_spawntime % rate1 == 0) {
		CreateThread(NULL, 0, Zombies, NULL, 0, NULL);
		if (rand() % 20 < (3 + m_spawntime / 5000) && m_spawntime > 10000) {
			CActiveObj* it = new CDoorZombie();
			return it;
		}
		else if (rand() % 20 < (5 + m_spawntime / 3000) && m_spawntime > 5000) {
			CActiveObj* it = new CDrumZombie();
			return it;
		}
		else if (rand() % 20 < (10 + m_spawntime / 2000) && m_spawntime > 2000) {
			CActiveObj* it = new CHatZombie();
			return it;
		}
		else {
			CActiveObj* it = new CZombies();
			return it;
		}
	}
	if (m_spawntime % rate2 < 10 && m_spawntime >= 4000) {
		CreateThread(NULL, 0, Level, NULL, 0, NULL);
		if (m_spawntime > 8000 && rand() % 5 < 2) {
			CActiveObj* it = new CDoorZombie();
			return it;
		}
		else if (rand() % 5 < 3) {
			CActiveObj* it = new CDrumZombie();
			return it;
		}
		else if (rand() % 5 < 4) {
			CActiveObj* it = new CHatZombie();
			return it;
		}
		else {
			CActiveObj* it = new CZombies();
			return it;
		}
	}
	return NULL;
}

void CFactory::Init()
{
	m_spawntime = 0;
	m_spawnrate = 500;
}

int CFactory::Getm_spawntime()
{
	return m_spawntime;
}
