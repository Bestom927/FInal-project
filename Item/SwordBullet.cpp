//
//#include "Role/Hero.h"
//#include "SwordBullet.h"
//
//bool SwordBullet::init()
//{	
//	unsigned short const actionStep = 4;
//	//��������֡����  (Ҳ�ɿ���cache��������������,����Ч�ʸ���)
//	SpriteFrame* frame_r = nullptr;
//	SpriteFrame* frame_l = nullptr;
//	for (unsigned short i = 1; i <= actionStep; i++)
//	{
//		//��ʽ���ַ���������spintf
//		frame_r = SpriteFrame::create(StringUtils::format("item/bullets/sword_action%d.png", i),
//			Rect(0, 0, 60, 60));
//		frame_l = SpriteFrame::create(StringUtils::format("item/bullets/sword_action%d.png", i),
//			Rect(0, 0, 60, 60));
//		if (frame_l == nullptr || frame_r == nullptr)
//		{
//			log("animate sword_action%d.png lost", i);
//		}
//		else
//		{
//			//����ѡ�����в�
//			frame_r->setAnchorPoint(Vec2(0.f, 0.5f));
//			m_rightActionVec.pushBack(frame_r);
//			//����ѡ�����в�
//			frame_l->setAnchorPoint(Vec2(1.f, 0.5f));
//			m_leftActionVec.pushBack(frame_l);
//		}
//	}
//
//	m_pBulletSprite = Sprite::create("item/sword1.png");
//	if (m_pBulletSprite == nullptr)
//	{
//		log("item/sword1.png can't be shown");
//	}
//	bindSprite(m_pBulletSprite, QS::Kind::kSelf, QS::BulletShape::kCircle, QS::Name::kCloseDamage);
//	return true;
//}
//
//void SwordBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node* sprite)
//{
//	if (Hero::getInstance() == nullptr)
//		return;
//	if (curFacing == QS::Move::kLeft)
//	{
//		m_pBulletSprite->setFlippedX(true);
//	}
//	//���÷�������λ��
//	auto point = heroPoint + Vec2((curFacing == QS::Move::kRight ? 15.f : -15.f), 20.f);
//	m_pBulletSprite->setPosition(point);
//
//	auto joint = PhysicsJointFixed::construct(Hero::getInstance()->getPhysicsBody(),
//		m_pBulletSprite->getPhysicsBody(), heroPoint);
//	joint->setCollisionEnable(false);
//	Hero::getInstance()->getScene()->getPhysicsWorld()->addJoint(joint);
//
//	Animation* animation = nullptr;
//	if (curFacing == QS::kRight)
//	{
//		animation = Animation::createWithSpriteFrames(m_rightActionVec);
//	}
//	else
//	{
//		animation = Animation::createWithSpriteFrames(m_leftActionVec);
//	}
//	animation->setLoops(1);
//	animation->setDelayPerUnit(0.1f);
//	Animate* actionOne = Animate::create(animation);
//	auto end = CallFunc::create([&]() {
//		//        getScene()->getPhysicsWorld()->removeJoint(joint);
//		this->removeFromParentAndCleanup(true);
//		});
//	actionOne->retain();
//	auto seq = Sequence::create(actionOne, end, nullptr);
//	m_pBulletSprite->runAction(seq);
//	log("sword attack!");
//	
//}