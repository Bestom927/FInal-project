
#include "MonsterBullet.h"


void MonsterBullet::attack(float direX, float direY, Point heroPoint, int curFacing, Node* sprite)
{
	float x = heroPoint.x; //+ (curFacing == 0 ? 25.0 : -25.0);
	//�����ӵ��в�֮ͬ��
	float y = heroPoint.y;// += 20.0;

	this->setPosition(x, y);
	//log("posAA x: %d  posAA y: %d", pos.x, pos.y);
	auto v = Vec2(direX, direY);
	//��λ��
	v.normalize();
	//�ٶ�����
	v *= 200;
	m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}

bool MonsterBullet::init()
{
	auto pNormalBullet = Sprite::create("MonsterBullet.png");
	if (pNormalBullet == nullptr)
	{
		log("MonsterBullet.png not found");
	}
	//�ӵ�����������ӵ���
	bindSprite(pNormalBullet, QS::Kind::kMonster, QS::BulletShape::kRectangle);

	setSpeed(3);

	m_isArrive = false;

	return true;
}