/**
*@file Hero.cpp
*@author ���Ӻ�(Zhang Zihan),������,���
*@time 2021-06-11
*/

//#pragma once
#ifndef _AIHERO_H_
#define _AIHERO_H_
#include "cocos2d.h"
#include "Monster/Monster.h"
#include "Item/MonsterBullet.h"
#include "Item/NormalGun.h"
#include "Const/Const.h"
#include "GlobalPara/GlobalParameter.h"
USING_NS_CC;

class AIHero : public Monster
{
public:

	static AIHero* createAIHero(cocos2d::Point position, std::string pName);
	void soldierPositionInit(cocos2d::Point position);

	virtual bool init(Point position, std::string pName);
	//CREATE_FUNC(Soldier);

	//��������
	Animate* createAIAnimate(const std::string  pActionName);

	//�ƶ�����
	virtual void AImove(int face, const std::string pAnimateName);


	void scheduleUpdateAIHero(float dt);


	Sprite* getSprite();
	//����������
	void setMainWeapon(Weapon* pWeapon);
	//��ȡ��ǰ������
	Weapon* getMainWeapon();

	CC_SYNTHESIZE(int, _m_nomFacing, M_nowFacing);
	CC_SYNTHESIZE(int, m_score, Score);
	//��������ӵ�����
	CC_SYNTHESIZE(int, m_bulletCountInHero,BulletCountInHero);

	bool judgeAIHeroDie();

	void setHeroSpriteName(std::string pName);
	std::string getHeroSpriteName();
protected:


	std::string m_pHeroSpriteName;

	Sprite* m_pHeroSprite;

	clock_t m_lastShotTime;
	

	//������
	Weapon* m_pMainWeapon;
};

#endif//!_Hero_H__
