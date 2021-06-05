/**
*@file Weapon.h
*@author ������
*@date 5/28/2021
*/
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Bullet.h"
#include "AudioEngine.h"
#include "Item.h" 

using namespace cocos2d;
class Weapon :public Item
{
public:
	/*
	* @brief:���ù�����
	* @author:������
	*/
	void setDamage(int weaponDamage);
	/*
	* @brief:��ȡ������
	* @author:������
	*/
	int getDamage();
	/**
	*@brief �л�����״̬
	*@author ������
	*/
	void setState(bool isInHand);

	/*
	* @brief:ֱ�Ӵӳ�Ա��������ȡ���ڵĳ���״̬
	* @author:������
	*/
	bool getState();
	/**
	*@brief ��������������
	@@author ������
	*/
	void interact() override;
	//TODO:�������������

protected:
	Sprite* m_pSpriteWeapon = nullptr;

	bool m_isInHand = false;
	int m_weaponDamage;
};


#endif // !_WEAPON_H_
