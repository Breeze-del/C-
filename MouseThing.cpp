// MouseThing.cpp: implementation of the CMouseThing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "stdio.h"
#include "MouseThing.h"
#include "Resource.h"
#include "Game.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMouseThing::CMouseThing()
{

}

CMouseThing::~CMouseThing()
{

}
bool CMouseThing::CheckMouseCard(int x, int y) {
	int now_x = 89;
	int now_y = 8;
	for (int i = 0; i < 6; i++) {
		if (x > now_x && x < now_x + 50 && y > now_y && y < now_y + 66) {
			if (m_isplant == false && m_cards->m_card[i].m_isCd == false && m_game->Getm_sunnum() >= m_cards->Getm_cost(i)) {
				m_isplant = true;
				m_planttype = i;
				ChangeImg();
			}
			else {
				if (m_planttype == i) {
					m_isplant = false;
				}
				else if (m_game->Getm_sunnum() >= m_cards->Getm_cost(i) && m_cards->m_card[i].m_isCd == false) {
					m_planttype = i;
					ChangeImg();
				}
			}
			return true;
		}
		now_x += 51;
	}
	return false;
}
void CMouseThing::MouseOn(int event, int x, int y, int flags, void* param) {
	CMouseThing* it = (CMouseThing*)param;

	if (it->m_game->Getm_gametype() == 1) {
		if (x > 225 && x < 550 && y > 540 && y < 580 && event == 1) {
			it->m_game->Changem_type(2);
			it->m_game->Changem_musiccount(0);
		}
		return; 
	}
	if (it->m_game->Getm_gametype() == 3) {
		if (x > 225 && x < 550 && y > 540 && y < 580 && event == 1) {
			it->m_game->Changem_type(1);
			it->m_game->Changem_musiccount(0);
		}

		return;
	}
	//动态设置坐标.
	it->m_game->m_plant.SetPos(x, y);
	CvPoint position = it->PosXYtoIJ(x, y);
	position = it->PosIJtoXY(position.x, position.y);
	it->m_game->m_plant_write.SetPos(position.x, position.y);

	if (it->m_scoop->m_isMove) {
		it->m_scoop->SetPos(x, y - 80);
		if (it->m_scoop->m_Position.x < 0) it->m_scoop->m_Position.x = 0;
		if (it->m_scoop->m_Position.x + it->m_scoop->m_img->width > it->m_game->m_bg.m_img->width)
			it->m_scoop->m_Position.x = it->m_game->m_bg.m_img->width - it->m_scoop->m_img->width;
		if (it->m_scoop->m_Position.y < 0) it->m_scoop->m_Position.y = 0;
		if (it->m_scoop->m_Position.y + it->m_scoop->m_img->height > it->m_game->m_bg.m_img->height)
			it->m_scoop->m_Position.y = it->m_game->m_bg.m_img->height - it->m_scoop->m_img->height;
	}
	if (event == 1) {
		bool flag;
		// 如果当前不是移动铲子、种植状态.发生点击事件就去调用拾起阳光函数.
		if (it->m_scoop->m_isMove == false && it->m_isplant == false) {
			it->m_game->GetSun(x, y);
		}
		//如果当前不是铲子移动状态，发生点击事件就去调用种植函数.
		if (it->m_scoop->m_isMove == false)
			flag = it->CheckMouseCard(x, y);

		//如果当前为种植状态,发生点击事件我们就应该去判断是否种植成功
		if (it->m_isplant == true) 
		{
			CvPoint position;
			position = it->PosXYtoIJ(it->m_game->m_plant.m_Position.x, it->m_game->m_plant.m_Position.y);
			//如果当前坐标在土地中.
			if (position.x >= 0 && position.x < 9 && position.y >= 0 && position.y < 5) {
				//如果当前位置没有种植植物.
				if (it->m_game->CheckPos(position.x, position.y)) {
					//创建植物
					it->m_game->CreatPlants(it->m_planttype, position.x, position.y);
					it->m_cards->m_card[it->m_planttype].m_isCd = true;
					it->m_cards->m_card[it->m_planttype].Changem_timer(0);
					it->m_isplant = false;
				}
			}
			//种植在外面.就取消种植状态.
			else if (flag == false) {
				it->m_isplant = false;
			}
		}

		if (it->m_game->m_scoop.m_isMove) {
			CvPoint position;
			position = it->PosXYtoIJ(it->m_game->m_plant.m_Position.x, it->m_game->m_plant.m_Position.y);
			if (position.x >= 0 && position.x < 9 && position.y >= 0 && position.y < 5 && (it->m_game->CheckPos(position.x, position.y) == false)) {
				it->m_game->Changem_clearx(32 + position.x * 82);
				it->m_game->Chnagem_cleary(75 + position.y * 100);
			}
		}
		if (610 <= x && x <= 677 && 0 <= y && y <= 70 && it->m_game->m_scoop.m_isMove == false) {
			it->m_game->m_scoop.m_isMove = true;
		}
		else if (it->m_game->m_scoop.m_isMove == true) {
			it->m_game->m_scoop.m_isMove = false;
			it->m_game->m_scoop.SetPos(610, 0);
		}
	}
}

void CMouseThing::MouseComeOn(CGame *game)
{
	m_game = game;
	m_cards = &game->m_cards;
	m_scoop = &game->m_scoop;
	m_isplant = false;
	cvSetMouseCallback("game", MouseOn, this);
}
CvPoint CMouseThing::PosIJtoXY(int i, int j)
{
	CvPoint position;
	position.x = 32 + i * 82;
	position.y = 75 + j * 100;
	return position;
}

CvPoint CMouseThing::PosXYtoIJ(int x, int y)
{
	CvPoint position;
	if (x < 32 || y < 75) {
		position.x = -1;
		position.y = -1;
	}
	else {
		position.x = (x - 32) / 82;
		position.y = (y - 75) / 100;
		if (position.x >= 9 || position.y >= 5) {
			position.x = -1;
			position.y = -1;
		}
	}
	return position;
}

void CMouseThing::ChangeImg()
{
	if (m_planttype == 0) {
		m_game->m_plant.m_img = CResource::m_iceshooter[0];
		m_game->m_plant_write.m_img = CResource::m_iceshooter_write;
	}
	else if (m_planttype == 1) {
		m_game->m_plant.m_img = CResource::m_nut[0];
		m_game->m_plant_write.m_img = CResource::m_nut_write;
	}
	else if (m_planttype == 2) {
		m_game->m_plant.m_img = CResource::m_peashooter[0];
		m_game->m_plant_write.m_img = CResource::m_peashooter_write;
	}
	else if (m_planttype == 3) {
		m_game->m_plant.m_img = CResource::m_pumpkin[0];
		m_game->m_plant_write.m_img = CResource::m_pumpkin_write;
	}
	else if (m_planttype == 4) {
		m_game->m_plant.m_img = CResource::m_sunflower[0];
		m_game->m_plant_write.m_img = CResource::m_sunflower_write;
	}
	else if (m_planttype == 5) {
		m_game->m_plant.m_img = CResource::m_cherrybomb[0];
		m_game->m_plant_write.m_img = CResource::m_cherrybomb_write;
	}
}

void CMouseThing::CheckPos()
{
	if (m_game->m_plant.m_Position.y - 35 < 0) m_game->m_plant.m_Position.y = 35;
	if (m_game->m_plant.m_img->height + m_game->m_plant.m_Position.y - 35 > m_game->m_bg.m_img->height)
		m_game->m_plant.m_Position.y = m_game->m_bg.m_img->height + 35 - m_game->m_plant.m_img->height;
	if (m_game->m_plant.m_Position.x - 50 < 0) m_game->m_plant.m_Position.x = 50;
	if (m_game->m_plant.m_img->width + m_game->m_plant.m_Position.x - 50 > m_game->m_bg.m_img->width)
		m_game->m_plant.m_Position.x = m_game->m_bg.m_img->width + 50 - m_game->m_plant.m_img->width;
}

bool CMouseThing::Getm_isplant()
{
	return m_isplant;
}
