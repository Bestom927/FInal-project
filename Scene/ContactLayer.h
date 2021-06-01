/*@file ContactLayer.h
* @author ������
* @time 2021/6/1
*/
#ifndef _CONTACTLAYER_H_
#define _CONTACTLAYER_H_

#include "Role/Hero.h"
#include "Item/Item.h"
#include "Item/Bullet.h"
using namespace cocos2d;
class ContactLayer :public Layer
{
public:
	CREATE_FUNC(ContactLayer);

	//��ʼ������
	bool init();
	/**
	*@brief �ӵ����Ӣ��
	*@author ������
	*/
	void bindHero(Hero* pNowHero);
	/**
	*@brief  ������¼��������ӵ�
	*@author ������
	*/
	bool onMouseDown(EventMouse* event);

	bool onContactBegin(PhysicsContact& contact);

	void physicalBodyManage(std::string name1, std::string name2,Node* body1,Node* body2);

	static ContactLayer* getInstance();
protected:
	static ContactLayer* m_pPresentContactLayer;
private:
	Hero* m_pHero;
	clock_t  m_lastShotTime;
};


#endif // !_CONTACTLAYER_H_

