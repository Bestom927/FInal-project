
#include "ShotGunBullet.h"

void ShotGunBullet::attack(float direX, float direY, Point heroPoint, int curFacing, Node* sprite)
{
	float x = heroPoint.x; //+ (curFacing == 0 ? 25.0 : -25.0);
	float y = heroPoint.y + (curFacing == 0 ? 25.0 : -25.0);// += 20.0;

	this->setPosition(x, y);
	//log("posAA x: %d  posAA y: %d", pos.x, pos.y);
	auto v = Vec2(direX, direY);
	//��λ��
	v.normalize();
	//�ٶ�����
	v *= 400;
	m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}

bool ShotGunBullet::init()
{
	auto pShotGunBullet = Sprite::create("Item/ShotGunBullet.png");
	if (pShotGunBullet == nullptr)
	{
		log("pShotGunBullet.png not found");
	}
	//�ӵ�����������ӵ���
	bindSprite(pShotGunBullet, QS::Kind::kSelf, QS::BulletShape::kCircle);

	setSpeed(3);

	m_isArrive = false;

	return true;
}