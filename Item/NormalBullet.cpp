
#include "NormalBullet.h"

void NormalBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node* sprite )
{
	float x = heroPoint.x + (curFacing == 0 ? 25.0 : -25.0);
	float y = heroPoint.y += 20.0;
	m_pBulletSprite->setPosition(x,y);

	auto v = Vec2(mouseX - heroPoint.x, mouseY - heroPoint.y);
	//��λ��
	v.normalize();    
	//�ٶ�����
	v *= 400;          
	m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}

bool NormalBullet::init()
{
    auto pNormalBullet = Sprite::create("NormalBullet.png");
	if (pNormalBullet == nullptr)
	{
		log("NormalBullet.png not found");
	}
	bindSprite(pNormalBullet, QS::Kind::kSelf, QS::BulletShape::kCircle);

	setSpeed(3);

	m_isArrive = false;
	//Ҫ������ӽڵ��ϰ��
	this->addChild(pNormalBullet);

	return true;
}