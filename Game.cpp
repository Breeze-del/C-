// Game.cpp: implementation of the CGame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "Game.h"
#include "math.h"
#include "time.h"
#include "Resource.h"
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#pragma   comment(linker,   "/subsystem:\"windows\"   /entry:\"mainCRTStartup\""   )
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
DWORD WINAPI Plant(LPVOID pM)             //种植声音
{
	mciSendString("play .\\music\\plant.mp3", NULL, 0, NULL);
	return 0;
}
DWORD WINAPI Hit(LPVOID pM)             //子弹声音
{
	mciSendString("play .\\music\\hit.mp3", NULL, 0, NULL);
	return 0;
}
DWORD WINAPI Eat(LPVOID pM)             //僵尸吃植物的声音.
{
	mciSendString("play .\\music\\eat.mp3", NULL, 0, NULL);
	return 0;
}
DWORD WINAPI Lose(LPVOID pM)             //僵尸吃植物的声音.
{
	mciSendString("play .\\music\\losemusic.mp3", NULL, 0, NULL);
	return 0;
}
DWORD WINAPI Pumkin(LPVOID pM)             //窝瓜声音
{
	mciSendString("play .\\music\\pumkin.mp3", NULL, 0, NULL);
	return 0;
}
CGame::CGame()
{
	cvNamedWindow("game", 1);
	m_musiccount = 0;
}

CGame::~CGame()
{
	cvDestroyWindow("game");
}

void CGame::Init()
{
	int i;
	srand(time(NULL));
	m_sunnum = 100;
	m_suntime = 0;
	m_score = 0;
	memset(m_mpt, 0, sizeof(m_mpt));
	memset(m_zomnum, 0, sizeof(m_zomnum));
	m_mouse.MouseComeOn(this);               //鼠标系统初始化.
	m_cards.Init();                          //卡片系统初始化.
	m_scoop.Init();                          //铲子系统初始化.
	m_factory.Init();                        //工厂系统初始化.
	m_scoop.m_isMove = false;                //铲子状态初始化.
	m_waittime = 30;                         //控制帧率
	m_pretime = clock();                     //计时器
	m_startimg = CResource::m_startimg;      //开始菜单.
	m_endimg = CResource::m_endimg;          //结束菜单
	m_gametype = 1;                          // 1.start.2.game.3.end
	m_clearx = m_cleary = -1;
	cvInitFont(&m_sunfont, CV_FONT_HERSHEY_SCRIPT_COMPLEX, 0.4, 0.4, 0, 1, 8);
	cvInitFont(&m_level, CV_FONT_HERSHEY_SCRIPT_COMPLEX, 0.6, 0.6, 0, 1, 8);
	for (i = 0; i < m_gameobj.size(); i++) {
		delete m_gameobj[i];
	}
	m_gameobj.clear();
	m_ball.clear();
	m_sun.clear();
}
void CGame::Run()
{
	while ( 1) {
		if (m_musiccount == 0 && m_gametype == 1) {
			//play start music
			PlaySound(TEXT(".\\music\\startmusic.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			m_musiccount++;
		}
		Init();
		m_bg.Show(m_startimg);    //开始界面.
		if (WaitAndQuit()) {
			break;
		}
		while (m_gametype == 2) {
			if (m_musiccount == 0 && m_gametype == 2) {
				//play game music
				PlaySound(TEXT(".\\music\\gamemusic.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				m_musiccount++;
			}
			cvSetMouseCallback("game", CMouseThing::MouseOn, &this->m_mouse);
			SpawnZombies();
			Time();
			MoveObj();
			CheckAttack();
			ClearObj();
			CountText();
			cvPutText(m_bg.m_img, m_sunstr, cvPoint(24, 75), &m_sunfont, CV_RGB(0, 0, 0));
			cvPutText(m_bg.m_img, m_levelstr, cvPoint(700, 594), &m_level, CV_RGB(0, 0, 0));
			cvPutText(m_bg.m_img, m_scorestr, cvPoint(110, 590), &m_sunfont, CV_RGB(0, 0, 0));
			Draw();
			m_bg.Draw();
			CheckEnd();
			if (WaitAndQuit()) {
				m_gametype = 1;
				m_musiccount = 0;
				break;
			}
		}
		while (m_gametype == 3) {
			m_bg.Show(m_endimg);    //结束界面.
			WaitAndQuit();
			if (m_musiccount == 0 && m_gametype == 3) {
				//play end music
				CreateThread(NULL, 0, Lose, NULL, 0, NULL);
				PlaySound(TEXT(".\\music\\endmusic.wav"), NULL, SND_FILENAME | SND_SYNC);
				m_musiccount++;
			}
		}
	}
}
void CGame::Draw()
{
	//actobj的绘制
	m_cards.Draw(m_bg.m_img, m_sunnum);
	SortObj(); //先对obj排序.
	m_scoop.Draw(m_bg.m_img, 1);
	for (int i = 0; i < m_gameobj.size(); i++) {
		m_gameobj[i]->Draw(m_bg.m_img);
	}
	//种植提示的绘制
	for (int i = 0; i < m_ball.size(); i++) {
		m_ball[i].Draw(m_bg.m_img, 1);
	}
	if (m_mouse.Getm_isplant()) {
		CvPoint position;
		position = m_mouse.PosXYtoIJ(m_plant.m_Position.x, m_plant.m_Position.y);
		if (position.x >= 0 && position.x < 9 && position.y >= 0 && position.y < 5 && CheckPos(position.x, position.y)) {
			m_plant_write.Draw(m_bg.m_img, 1);
		}
		m_mouse.CheckPos();
		m_plant.Draw(m_bg.m_img, 1, 1, 1, -50, -35);
	}
	for (int i = 0; i < m_sun.size(); i++) {
		m_sun[i].Draw(m_bg.m_img, 1);
	}
	if (m_scoop.m_isMove == true) {
		m_scoop.Draw(m_bg.m_img, 1);
	}
}

void CGame::Time()
{
	int i;
	for (i = 0; i < 6; i++) {
		m_cards.m_card[i].Time();
	}
	for (i = 0; i < m_gameobj.size(); i++) {
		m_gameobj[i]->Time();
	}
	for (i = 0; i < m_gameobj.size(); i++) {
		m_gameobj[i]->Move();
	}
	for (i = 0; i < m_sun.size(); i++) {
		m_sun[i].Time();
	}
	for (i = 0; i < m_ball.size(); i++) {
		m_ball[i].Move();
	}
	CreatBall();
	CreatSun();
}

void CGame::GetSun(int x, int y)
{
	int i;
	for (i = 0; i< m_sun.size(); i++) {
		int ox = m_sun[i].m_Position.x + 35;
		int oy = m_sun[i].m_Position.y + 35;
		if ((x - ox) * (x - ox) + (y - oy) * (y - oy) <= 900) {
			m_sun[i].Changem_timer(100);
			m_sun[i].m_isGet = true;
			m_sun[i].m_speedx = (10 - m_sun[i].m_Position.x) / 8;
			m_sun[i].m_speedy = (0 - m_sun[i].m_Position.y) / 8;
		}
	}

}

bool CGame::CheckPos(int i, int j)
{
	if (m_mpt[i][j])return false;
	return true;
}

void CGame::CreatPlants(int num, int i, int j)
{
	CreateThread(NULL, 0, Plant, NULL, 0, NULL);
	m_sunnum -= m_cards.Getm_cost(num);
	m_mpt[i][j] = num + 1;
	m_gameobj.push_back(m_factory.Creat(num, i, j));
}


void CGame::ClearObj()
{
	int i;
	//清除actobj
	for (i = 0; i < m_gameobj.size(); i++) {
		if (m_gameobj[i]->CheckDead() || m_gameobj[i]->m_Position.x == m_clearx && m_gameobj[i]->m_Position.y == m_cleary) {
			if (m_gameobj[i]->Getobjtype() == 0)//如果是植物
				m_mpt[m_gameobj[i]->m_Position.i][m_gameobj[i]->m_Position.j] = 0;
			else {
				m_zomnum[m_gameobj[i]->m_Position.j] --;
				m_score += 100;
			}
			m_gameobj.erase(m_gameobj.begin() + i);
		}
	}
	//清除太阳.
	for (i = 0; i< m_sun.size(); i++) {
		if (m_sun[i].m_isEnd == true) {
			m_sunnum += 25;
			if (m_sunnum > 999999) m_sunnum = 999999;
			m_sun.erase(m_sun.begin() + i);
		}
		else if (m_sun[i].Getm_timer() == m_sun[i].Getm_timerate())
			m_sun.erase(m_sun.begin() + i);
	}
	//清除子弹
	for (i = 0; i < m_ball.size(); i++) {
		if (m_ball[i].Getm_dead())
			m_ball.erase(m_ball.begin() + i);
		else if (m_ball[i].m_Position.x > 800)
			m_ball.erase(m_ball.begin() + i);
	}
	m_clearx = m_cleary = -1;

}

void CGame::CreatBall()
{
	int i;
	for (i = 0; i < m_gameobj.size(); i++) {
		if (m_gameobj[i]->Getm_isbullet() == true && m_zomnum[m_gameobj[i]->m_Position.j]) {
			m_gameobj[i]->Changem_isbullet(false);
			CBall step;
			step.SetPos(m_gameobj[i]->m_Position.x + 65, m_gameobj[i]->m_Position.y + 10);
			step.m_Position.j = m_gameobj[i]->m_Position.j;
			if (m_gameobj[i]->Getballtype() == 0)
				step.SetType("normal");
			else
				step.SetType("ice");
			m_ball.push_back(step);
		}
	}

}

void CGame::CreatSun()
{
	int x, y, i;
	if (m_suntime > 500) {
		CSun step;

		x = rand() % (680 - 85) + 85;  //x : 85~680;
		y = -50;
		step.SetPos(x, y);
		y = rand() % 200 + 300;  // y: 300~500
		step.m_aimy = y;
		step.m_isMove = true;
		m_sun.push_back(step);
		m_suntime = 0;
	}
	else {
		m_suntime++;
	}
	//花产生的阳光;
	for (i = 0; i < m_gameobj.size(); i++) {
		if (m_gameobj[i]->Getm_iscreatsun()) {
			m_gameobj[i]->Changem_iscreatsun(false);
			CSun step;
			x = m_gameobj[i]->m_Position.x;
			y = m_gameobj[i]->m_Position.y;
			step.SetPos(x, y);
			step.m_isMove = true;
			step.m_aimy = y + 30;
			m_sun.push_back(step);
		}
	}
}

void CGame::MoveObj()
{
	int i;
	for (i = 0; i < m_sun.size(); i++) {
		m_sun[i].Move();
	}
}

bool CGame::WaitAndQuit()
{
	char key;
	while (clock() - m_pretime < m_waittime) {
		key = cvWaitKey(5);
		if (key == 27)
			return true;
		if (key == ' ')
		{
			cvWaitKey(0);
		}
	}
	m_pretime = clock();
	return false;
}

void CGame::CountText()
{
	char num[10];
	int len, i, k;
	sprintf(num, "%d", m_sunnum);
	len = strlen(num);
	k = (6 - len) / 2;
	for (i = 0; i < k; i++) {
		m_sunstr[i] = ' ';
	}
	for (; i < k + len; i++) {
		m_sunstr[i] = num[i - k];
	}
	for (; i < 6; i++) {
		m_sunstr[i] = ' ';
	}
	m_sunstr[6] = '\0';
	sprintf(m_levelstr, "%d", m_factory.Getm_spawntime() / 4000 + 1);
	sprintf(m_scorestr, "%d", m_score);
}

void CGame::SpawnZombies()
{
	CActiveObj* it = m_factory.Spawn();
	if (it != NULL) {
		m_zomnum[it->m_Position.j] ++;
		m_gameobj.push_back(it);
	}
}

void CGame::CheckAttack()
{
	int i, j;
	//僵尸转换attack形态
	for (i = 0; i < m_gameobj.size(); i++) {
		for (j = 0; j < m_gameobj.size(); j++) {
			if (m_gameobj[i]->m_Position.j == m_gameobj[j]->m_Position.j
				&& m_gameobj[j]->m_Position.x - m_gameobj[i]->m_Position.x > 0
				&& m_gameobj[j]->m_Position.x - m_gameobj[i]->m_Position.x < 70
				&& m_gameobj[i]->Getobjtype() == 0
				&& m_gameobj[j]->Getm_ismove() == true) {
				m_gameobj[j]->SetAttack();
				CreateThread(NULL, 0, Eat, NULL, 0, NULL);
			}

		}
	}
	//检测僵尸对植物的攻击.
	for (j = 0; j < m_gameobj.size(); j++) {
		if (m_gameobj[j]->Getm_attack() == true && m_gameobj[j]->Getobjtype() == 1) {
			for (i = 0; i < m_gameobj.size(); i++) {
				if (m_gameobj[i]->m_Position.j == m_gameobj[j]->m_Position.j
					&& m_gameobj[j]->m_Position.x - m_gameobj[i]->m_Position.x > 0
					&& m_gameobj[j]->m_Position.x - m_gameobj[i]->m_Position.x < 70
					&& m_gameobj[i]->Getobjtype() == 0) {
					m_gameobj[i]->TakeDamage(1);
					break;
				}
			}
			if (i == m_gameobj.size() && m_gameobj[j]->Getm_attack())
				m_gameobj[j]->SetAnimType("move");
		}
	}
	//检测子弹对僵尸的攻击
	for (i = 0; i < m_ball.size(); i++) {
		for (j = 0; j < m_gameobj.size(); j++) {
			if (m_ball[i].m_Position.j == m_gameobj[j]->m_Position.j
				&& m_gameobj[j]->m_Position.x - m_ball[i].m_Position.x >= 0
				&& m_gameobj[j]->m_Position.x - m_ball[i].m_Position.x <= m_ball[i].m_img->width
				&& m_gameobj[j]->Getobjtype() == 1 && (m_gameobj[j]->Getm_ismove() || m_gameobj[j]->Getm_attack())) {
				m_ball[i].Changem_dead(true);
				if (m_ball[i].Getm_type() == 1)
					m_gameobj[j]->TakeDamage(15);
				else {
					m_gameobj[j]->TakeDamage(25);
				}
				CreateThread(NULL, 0, Hit, NULL, 0, NULL);
			}
		}
	}
	//检测炸弹对僵尸的攻击.
	for (i = 0; i < m_gameobj.size(); i++) {
		if (m_gameobj[i]->Getm_bomb()) {
			for (j = 0; j < m_gameobj.size(); j++) {
				if (m_gameobj[j]->Getobjtype() == 1
					&& abs(m_gameobj[i]->m_Position.j - m_gameobj[j]->m_Position.j) <= 1
					&& abs(m_gameobj[j]->m_Position.x - m_gameobj[i]->m_Position.x) < 75
					)
					m_gameobj[j]->SetAnimType("bomb");

			}
		}
	}
	//窝瓜对僵尸的攻击
	for (i = 0; i < m_gameobj.size(); i++) {
		if (m_gameobj[i]->Getm_pumkin() && m_gameobj[i]->Getm_isidle()) {
			for (j = 0; j < m_gameobj.size(); j++) {
				if (m_gameobj[i]->m_Position.j == m_gameobj[j]->m_Position.j &&
					m_gameobj[j]->Getobjtype() == 1 &&
					m_gameobj[j]->Getm_isdead() == false &&
					abs(m_gameobj[i]->m_Position.x - m_gameobj[j]->m_Position.x) <100) 
				{
					m_gameobj[i]->m_Position.x = m_gameobj[j]->m_Position.x;
					m_gameobj[i]->m_Position.y = m_gameobj[j]->m_Position.y - 100;
					CreateThread(NULL, 0, Pumkin, NULL, 0, NULL);
					m_gameobj[i]->SetAnimType("attack");
					m_gameobj[j]->Changem_normal(true);
					m_gameobj[j]->SetAnimType("dead");
				}
			}
		}
	}
}

void CGame::SortObj()
{
	int i, j;
	for (i = 0; i < m_gameobj.size(); i++) {
		for (j = 0; j < m_gameobj.size() - i - 1; j++) {
			if (m_gameobj[j]->m_Position.j > m_gameobj[j + 1]->m_Position.j
				|| m_gameobj[j]->m_Position.j == m_gameobj[j + 1]->m_Position.j
				&& m_gameobj[j]->m_Position.x > m_gameobj[j + 1]->m_Position.x) {
				CActiveObj* step;
				step = m_gameobj[j];
				m_gameobj[j] = m_gameobj[j + 1];
				m_gameobj[j + 1] = step;
			}
		}
	}

}

void CGame::CheckEnd()
{
	int i;
	for (i = 0; i < m_gameobj.size(); i++) {
		if (m_gameobj[i]->Getobjtype() == 1 && m_gameobj[i]->m_Position.x < 0) {
			m_gametype = 3;
			m_musiccount = 0;
		}
	}
}

int CGame::Getm_sunnum()
{
	return m_sunnum;
}

int CGame::Getm_gametype()
{
	return m_gametype;
}

void CGame::Changem_type(int type)
{
	m_gametype = type;
}

void CGame::Changem_musiccount(int count)
{
	m_musiccount = count;
}

void CGame::Changem_clearx(int clearx)
{
	m_clearx = clearx;
}
void CGame::Chnagem_cleary(int cleary)
{
	m_cleary = cleary;
}
