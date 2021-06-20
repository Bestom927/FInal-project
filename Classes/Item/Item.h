#ifndef _ITEM_H_
#define _ITEM_H_

#include "cocos2d.h"
#include "Const/Const.h"
#include "ui/CocosGUI.h"


using namespace cocos2d;

/**
*@brief ��Ʒ��
*/
class Item :public Node
{
public:
	/**
	*@brief �󶨾���
	*/
	void bindSprite(Sprite* pSprite);

	Sprite* getSprite();



	virtual bool onContactBegin(PhysicsContact& contact);
	virtual bool onContactSeparate(PhysicsContact& contact);

	/**
	*@brief ����������
	*/
	void generatePhysicalBody(std::string message, int itemTag);

protected:
	Sprite* m_pSprite;
};

#endif
#pragma once
