
#include "ContactLayer.h"
bool ContactLayer::init()
{
	//д������¼������彻���¼�
	auto mouseListener = cocos2d::EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(ContactLayer::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(ContactLayer::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	m_pPresentContactLayer = this;
	return true;
}

/*
bool ContactLayer::onMouseDown(EventMouse* event)
{
	//���ε�����ļ��ʱ����
	auto curTime = std::clock();
	if (static_cast<float>(curTime - m_lastShotTime) / CLOCKS_PER_SEC
		< m_pHero->getMainWeapon()->getInterval())
	{
		return true;
	}
	m_lastShotTime = curTime;
	//û���ӵ�
	if (0 == m_pHero->getMainWeapon()->getBulletCount()) {
		;
	}
	else {
		for (int i = 0; i < m_pHero->getMainWeapon()->getBulletCount(); i++) {
			Bullet* pBullet = m_pHero->getMainWeapon()->createBullet();
			pBullet->attack(event->getCursorX(), event->getCursorY(), m_pHero->getPosition(), m_pHero->getFacing());
			this->addChild(pBullet);
		}
		return true;
	}
}

void ContactLayer::physicalBodyManage(std::string name1, std::string name2, Node* body1, Node* body2)
{
    if (name1 == QS::Name::kBullet ||name1 == QS::Name::kCloseDamage)
    {
        if (name2 == QS::Name::kMonster)
        {
            log("Monster shot");
            dynamic_cast<Monster*>(body2)->reduceHealth(
                m_pHero->getBaseDamage() + m_pHero->getMainWeapon()->getDamage());
        }
        if (name1 == QS::Name::kBullet)
        {
            body1->setVisible(false);
            body1->removeFromParentAndCleanup(true);
        }
    }
    else if (name2 == QS::Name::kBullet ||name2 == QS::Name::kCloseDamage)
    {
        if (name1 == QS::Name::kMonster)
        {
            log("Monster shot");
            dynamic_cast<Monster*>(body1)->reduceHealth(
                m_pHero->getBaseDamage() + m_pHero->getMainWeapon()->getDamage());
        }
        if (name2 == QS::Name::kBullet)
        {
            body2->setVisible(false);
            body2->removeFromParentAndCleanup(true);
        }
    }
    else if (name1 == QS::Name::kMonsterBullet ||name1 == QS::Name::kMonsterClose)
    {
        if (name2 == QS::Name::kHero)
        {
            log("Hero shot");
            Hero::getInstance()->reduceHealth(
                dynamic_cast<Bullet*>(body1->getParent())->getDamage());
        }
        if (name1 == QS::Name::kMonsterBullet)
        {
            body1->setVisible(false);
            body1->removeFromParentAndCleanup(true);
        }
    }
    else if (name2 == QS::Name::kMonsterBullet ||name2 == QS::Name::kMonsterClose)
    {
        if (name1 == QS::Name::kHero)
        {
            log("Hero shot");
            Hero::getInstance()->reduceHealth(
                dynamic_cast<Bullet*>(body2->getParent())->getDamage());
        }
        if (name2 == QS::Name::kMonsterBullet)
        {
            body2->setVisible(false);
            body2->removeFromParentAndCleanup(true);
        }
    }
}
*/
bool ContactLayer::onContactBegin(PhysicsContact& contact)
{
	auto body1 = contact.getShapeA()->getBody()->getNode();
	auto body2 = contact.getShapeB()->getBody()->getNode();
	//���Ժ걣֤body1��body2��ָ��ָ��
	assert(body1 != nullptr && body2 != nullptr);
	physicalBodyManage(body1->getName(), body2->getName(),body1,body2);
	return true;
}
void ContactLayer::bindHero(Hero* pNowHero)
{
	m_pHero = pNowHero;
}
ContactLayer* ContactLayer::getInstance()
{
	return m_pPresentContactLayer;
}