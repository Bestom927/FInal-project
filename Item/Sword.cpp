
#include "Sword.h"
//#include "SwordBullet.h"

bool Sword::init()
{
	scheduleUpdate();

	auto listenerKeyboard = EventListenerKeyboard::create();
	//�����¼���Ӧ����
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(Weapon::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(Weapon::onKeyReleased, this);
	//ע����̼���
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);

    log("Trying to create sword");
    Sprite* pSprite = Sprite::create("Item/Sword-1.png");
    m_pSpriteWeapon = pSprite;
    bindSprite(pSprite);
	generatePhysicalBody(QS::message::kSwordMessage, QS::kHeroSwordRestingTag);
    //��ʱ����ת60��
    //pSprite->setRotation(-40.f);
	setWeaponName(QS::Name::kSwordWeapon);
    Weapon::setInterval(.2f);
    Weapon::setBulletCount(0);
    Weapon::setDamage(4);
	Weapon::setState(false);
	pSprite->setScale(0.6f);
    return true;
}

Bullet* Sword::createBullet()
{
    /*����ص�������Ҫ�ټ��һ�¿�����*/

    auto begin = CallFunc::create([&]() {
        //m_pSprite->setVisible(false);
		//m_pSprite->setTag(QS::kHeroSwordAttackingTag);
		generatePhysicalBody(QS::message::kSwordMessage, QS::kHeroSwordAttackingTag);
		});
    auto delay = DelayTime::create(0.9);
    auto end = CallFunc::create([&]() {
        //m_pSprite->setVisible(true);
		m_pSprite->setTag(QS::kHeroSwordRestingTag);
        });
    auto seq = Sequence::create(begin, delay, end, nullptr);
    //Bullet* pBullet = SwordBullet::create();
	m_pSprite->runAction(Spawn::create(seq, createAnimate("Sword1"), nullptr));

	auto pBullet = NormalBullet::create();
	//if (gIsEffectPlaying)
    //    AudioEngine::play2d(QS::files::kSwordAttack);
    return pBullet;
}

Animate* Sword::createAnimate(const std::string pActionName)
{
	/* ����ͼƬ֡������� */
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Item/"+pActionName + ".plist","Item/"+ pActionName + ".png");

	int iFrameNum = 3;
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameVec;

	/* ��һ���б�������SpriteFrame���� */
	for (int i = 1; i <= iFrameNum; i++) {
		/* ��SpriteFrame������л�ȡSpriteFrame���� */
		switch (100)
		{
		case QS::kUp:
			frame = frameCache->getSpriteFrameByName(StringUtils::format("W0%d.png", i));
			break;
		case QS::kDown:
			frame = frameCache->getSpriteFrameByName(StringUtils::format("S0%d.png", i));
			break;
		case QS::kRight:
			frame = frameCache->getSpriteFrameByName(StringUtils::format("D0%d.png", i));
			break;
		case QS::kLeft:
			frame = frameCache->getSpriteFrameByName(StringUtils::format("A0%d.png", i));
			break;
		default:
			frame = frameCache->getSpriteFrameByName(StringUtils::format("sword2-%d.png", i));
			log("sword picture ");
		}
		frameVec.pushBack(frame);
	}

	/* ʹ��SpriteFrame�б����������� */
	Animation* animation = Animation::createWithSpriteFrames(frameVec, 0.1f, 1);

	animation-> setRestoreOriginalFrame(true);

	/* ��������װ��һ������ */
	Animate* action = Animate::create(animation);

	/*�������*/
	AnimationCache::destroyInstance();
	SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
	//TextureCache::getInstance()->removeUnusedTextures();

	return action;
}