/**
*@file NormalGun.h
*@author ������
*@date 6/1/2021
*/
#ifndef _NORMALGUN_H_
#define _NORMALGUN_H_

#include "Gun.h"
#include "NormalBullet.h"
class NormalGun :public Gun
{
public:
	CREATE_FUNC(NormalGun);
	/**
	*@brief ����һö�ӵ�
	*@author ������
	*/
	Bullet* createBullet() override;

	bool init() override;
};
#endif // !_NORMALGUN_H_
