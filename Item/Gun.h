/**
*@file Gun.h
*@author ������
*@date 6/1/2021
*/

#ifndef _GUN_H_
#define _GUN_H_

#include "Weapon.h"
class Gun :public Weapon
{
public:
	/**
	*@brief ����һö�ӵ�
	*@author ������
	*/
	virtual Bullet* createBullet();

	/**
	*@brief ��ȡ���������ٶ�
	*@author ������
	*/
	float getInterval();

	/**
	*@brief ��ȡ����һ�η��伸ö�ӵ�
	*@author ������
	*/
	int getBulletCount();

	/**
	*@brief �������������ٶ�
	*@author ������
	*/
	void setInterval(float interval);

	/**
	*@brief ��������һ�η��伸ö�ӵ�
	*@author ������
	*/
	void setBulletCount(int count);
protected:
	float m_attackInterval;
	int m_bulletCount;
};
#endif // !_SWORD_H_
