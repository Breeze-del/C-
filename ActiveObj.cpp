// ActiveObj.cpp: implementation of the CActiveObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ActiveObj.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CActiveObj::CActiveObj()
{
	m_hp = 100;
	m_animRate = 8;
	m_isBullet = false;
	m_isCreatsun = false;
	m_bomb = false;
	m_isBomb = false;
	m_isPumkin = false;
	m_isNormal = false;
	m_speed = 0;
	m_objType = 0;

}

CActiveObj::~CActiveObj()
{

}

void CActiveObj::Move()
{
	m_Position.x -= m_speed;
}

void CActiveObj::SetAnimType(string str)
{
	m_isIdle = false;
	m_isAttack = false;
	m_isMove = false;
	m_imgNum = 0;
	if (str == "idle") {
		m_it = m_Idle_Img.begin();
		m_imgSum = m_Idle_Img.size();
		m_isIdle = true;
	}
	else if (str == "move") {
		m_it = m_Move_Img.begin();
		m_imgSum = m_Move_Img.size();
		m_isMove = true;
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
	}
	if (m_isMove) {
		m_speed = 1;
	}
	else {
		m_speed = 0;
	}
}

void CActiveObj::TakeDamage(int damage)
{
	if (m_hp < 0) return;
	m_hp -= damage;
	if (m_hp < 0) {
		SetAnimType("dead");
	}
}

bool CActiveObj::CheckDead()
{
	if (m_isDead == true && (m_imgNum == m_Dead_Img.size() * m_animRate - 1 || m_Dead_Img.size() == 0)
		|| (m_isBomb && m_isDead))
		return true;
	return false;
}

void CActiveObj::SetPos(int i, int j)
{
	m_Position.i = i;
	m_Position.j = j;
	m_Position.x = 32 + i * 82;
	m_Position.y = 75 + j * 100;
}

void CActiveObj::Draw(IplImage *bg)
{

	IplImage* now_img = m_it[m_imgNum / m_animRate];
	m_imgNum = (m_imgNum + 1) % (m_animRate * m_imgSum);

	for (int i = 0; i < now_img->height; i++) {
		for (int j = 0; j < now_img->width; j++) {
			if (i + m_Position.y >= bg->height ||
				j + m_Position.x >= bg->width ||
				i + m_Position.y < 0 ||
				j + m_Position.x < 0
				)continue;
			if (CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0) <= 10 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) >= 135 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1) <= 155 &&
				CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2) <= 10
				)continue;//´¿É«¿ØÖÆ
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 0)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 0);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 1)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 1);
			CV_IMAGE_ELEM(bg, uchar, i + m_Position.y, (j + m_Position.x) * 3 + 2)
				= CV_IMAGE_ELEM(now_img, uchar, i, j * 3 + 2);
		}
	}

}

void CActiveObj::Timething()
{

}


void CActiveObj::SetAttack()
{
	SetAnimType("attack");
}

int CActiveObj::Getobjtype()
{
	return m_objType;
}

bool CActiveObj::Getm_isbullet()
{
	return m_isBullet;
}

void CActiveObj::Changem_isbullet(bool isbullet)
{
	m_isBullet = isbullet;
}

int CActiveObj::Getballtype()
{
	return m_balltype;
}

void CActiveObj::Changem_iscreatsun(bool iscreatsun)
{
	m_isCreatsun = iscreatsun;
}

bool CActiveObj::Getm_iscreatsun()
{
	return m_isCreatsun;
}

bool CActiveObj::Getm_ismove()
{
	return m_isMove;
}

void CActiveObj::Changem_ismove(bool ismove)
{
	m_isMove = ismove;
}

bool CActiveObj::Getm_attack()
{
	return m_isAttack;
}

bool CActiveObj::Getm_bomb()
{
	return m_bomb;
}

bool CActiveObj::Getm_isdead()
{
	return m_isDead;
}

bool CActiveObj::Getm_pumkin()
{
	return m_isPumkin;
}

bool CActiveObj::Getm_isidle()
{
	return m_isIdle;
}

void CActiveObj::Changem_normal(bool normal)
{
	m_isNormal = normal;
}
