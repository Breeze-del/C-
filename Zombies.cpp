// Zombies.cpp: implementation of the CZombies class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Zombies.h"
#include "Resource.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZombies::CZombies()
{
	m_isNormal = true;
	m_isBomb = false;
	m_isDead = false;
	m_objType = 1;
	CResource::LoadImg(CResource::m_normalZom_move, m_Move_Img, 6);
	CResource::LoadImg(CResource::m_normalZom_attack, m_Attack_Img, 6);
	CResource::LoadImg(CResource::m_normalZom_bomb, m_Bomb_Img, 10);
	CResource::LoadImg(CResource::m_normalZom_dead, m_Dead_Img, 7);
	SetAnimType("move");
	m_Position.j = rand() % 5;
	m_Position.y = 100 * m_Position.j + 28;
	m_Position.x = 800;
}

CZombies::~CZombies()
{

}

void CZombies::Draw(IplImage *bg)
{
	if (m_isBomb && m_isDead) return;
	IplImage* now_img = m_it[m_imgNum / m_animRate];
	m_imgNum = (m_imgNum + 1) % (m_animRate * m_imgSum);
	for (int i = 0; i < now_img->height; i++) {
		for (int j = 0; j < now_img->width; j++) {
			if (i + m_Position.y >= bg->height ||
				j + m_Position.x >= bg->width ||
				i + m_Position.y < 0 ||
				j + m_Position.x < 0
				)continue;
			if (CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0) >= 230 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) >= 230 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2) >= 230
				)continue;//´¿É«¿ØÖÆ
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 0)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 1)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 2)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2);
		}
	}
	if (m_isBomb && m_imgNum == m_Bomb_Img.size() * m_animRate - 1) {
		m_isNormal = true;
		SetAnimType("dead");
	}
}

void CZombies::SetAnimType(string str)
{
	m_isIdle = false;
	m_isAttack = false;
	m_isMove = false;
	m_imgNum = 0;
	if (str == "bomb") {
		m_it = m_Bomb_Img.begin();
		m_imgSum = m_Bomb_Img.size();
		m_isBomb = true;
	}
	else if (m_isNormal) {
		if (str == "idle") {
			m_it = m_Idle_Img.begin();
			m_imgSum = m_Idle_Img.size();
			m_isIdle = true;
		}
		else if (str == "move") {
			m_it = m_Move_Img.begin();
			m_imgSum = m_Move_Img.size();
			m_isMove = true;
			m_imgNum = rand() % m_imgSum;
		}
		else if (str == "attack") {
			m_it = m_Attack_Img.begin();
			m_imgSum = m_Attack_Img.size();
			m_isAttack = true;
		}
		else if (str == "dead") {
			m_it = m_Dead_Img.begin();
			m_imgSum = m_Dead_Img.size();
			m_isDead = true;
			if (m_isBomb == false)
				m_Position.x -= 68, m_Position.y -= 15;
		}
	}
	else {
		if (str == "move") {
			m_it = m_Move_Img_my.begin();
			m_imgSum = m_Move_Img.size();
			m_isMove = true;
		}
		else if (str == "attack") {
			m_it = m_Attack_Img_my.begin();
			m_imgSum = m_Attack_Img.size();
			m_isAttack = true;
		}
	}
	if (m_isMove) {
		m_speed = 1;
	}
	else {
		m_speed = 0;
	}
}

void CZombies::SetAttack()
{
	SetAnimType("attack");

}

void CZombies::TakeDamage(int damage)
{
	if (m_hp < 0) return;
	m_hp -= damage;

	if (m_hp < 100) {

		m_isNormal = true;
		SetAnimType("move");
	}
	if (m_objType == 1)
		if (m_hp < 0) {
			SetAnimType("dead");
		}
}
