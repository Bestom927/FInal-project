/*
* @file NormalBullet.h
* @author:������
* @time:2021/5/29
*/

#ifndef _NORMALBULLET_H_
#define _NORMALBULLET_H_

#include "Bullet.h"

class NormalBullet :public Bullet
{
public:
	CREATE_FUNC(NormalBullet);

	virtual void attack(float mouseX, float mouseY, Point heroPoint, int curFacing,
		Node* sprite = nullptr) override;

	virtual bool init() override;

};
#endif // !_NORMALBULLET_H_

