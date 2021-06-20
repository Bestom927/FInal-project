#include "NormalGun.h"
#include "GlobalPara/GlobalParameter.h"
Bullet* NormalGun::createBullet() {
	Bullet* pBullet = NormalBullet::create();
	//����һ���ӵ���������ǹ���ӵ�������
	m_bulletCount--;
	pBullet->Bullet::setDamage(NormalGun::getDamage());
	if (isEffect) 
	{
		AudioEngine::play2d(QS::sound::kShoot);
	}
	return pBullet;
}

bool NormalGun::init() {
	scheduleUpdate();

	auto listenerKeyboard = EventListenerKeyboard::create();
	//�����¼���Ӧ����
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(Weapon::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(Weapon::onKeyReleased, this);
	//ע����̼���
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);

	Sprite* pSprite = Sprite::create("Item/NormalGun.png");
	if (pSprite == nullptr)
	{
		log("weapons.png not found");
	}
	m_pSpriteWeapon = pSprite;
	bindSprite(pSprite);
	pSprite->setScale(.4f);
	pSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	pSprite->setPosition(0, 0);
	generatePhysicalBody(QS::message::kGunMessage,QS::kHeroSwordRestingTag);
	setWeaponName(QS::Name::kNormalGunWeapon);
	Weapon::setDamage(2);
	Weapon::setInterval(.2f);
	Weapon::setState(false);
	//������Ϊ30
	Weapon::setBulletCount(30);
	Weapon::setBulletCountMax(30);
	return true;
}