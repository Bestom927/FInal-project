/**
*@file Hero.cpp
*@author ���Ӻ�(Zhang Zihan),������,���
*@time 2021-06-11
*/

//#pragma once
#ifndef _HERO_H_
#define _HERO_H_
#include "cocos2d.h"
#include "Role/Role.h"
#include "Item/NormalGun.h"
#include "Item/Item.h"
#include "Const/Const.h"
USING_NS_CC;

class Hero : public Role
{
public:

	static Hero* createHero(cocos2d::Point position);
	void soldierPositionInit(cocos2d::Point position);

	virtual bool init();
	//CREATE_FUNC(Soldier);


	//��������
	Animate* createAnimate(const std::string  pActionName);

	//�ƶ�����
	void move(int face, const std::string pAnimateName);
	//�����¼�
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void keyPressedDuration(EventKeyboard::KeyCode code);
	//����¼�
	void onMouseDown(EventMouse* event);
	void onMouseUp(EventMouse* event);
	void onMouseMove(EventMouse* event);
	bool isMouseMove();
	//ײǽ���
	void setHitWall(bool m_isHitWall);
	bool getIsHitWall();
	//��ת
	float angle(const Vec2& v1, const Vec2& v2);
	void rotate(Vec2& point, float angle);
	void update(float dt = 0.4f);
	//���ý�����Ʒ
	static void setPresentContactItem(Item* pItem);
	static Item* getPresentContactItem();

	//��õ�ǰ����
	Sprite* getSprite();
	//����������
	void setMainWeapon(Weapon* pWeapon);
	//��ȡ��ǰ������
	Weapon* getMainWeapon();

	int m_nowFacing;

	std::map<cocos2d::EventKeyboard::KeyCode, bool> m_keys;

	std::string m_pHeroSpriteName = "Hero1";

protected:

	static Item* m_pPresentContactItem ;

	Sprite* m_pHeroSprite;

	//Hero* m_pHero;

	bool m_isHitWall=false;

	bool b_isMouseMove;
	//������
	Weapon* m_pMainWeapon;
};

#endif//!_Hero_H__