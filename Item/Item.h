/**
*@file Item.h
*@author ������
*@date 5/28/2021
*/

#ifndef _ITEM_H_
#define _ITEM_H_

#include "cocos2d.h"
#include "Const/Const.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

/**
*@brief ��Ʒ��
*@author ������
*/

class Item :public Node
{
public:
	/**
	*@brief �󶨾���
	*/
	void bindSprite(Sprite* pSprite);

	/**
	*@brief ��ȡ����
	*@author ������
	*/
	Sprite* getSprite();

	/**
	*@brief ��������
	*@author ������
	*/
	virtual void interact() = 0;

	/**
	*@brief �޸�m_pPresentContactItem
	*@author ������
	*/
	//virtual bool onContactBegin(PhysicsContact& contact);
	//virtual bool onContactSeparate(PhysicsContact& contact);

	/**
	*@brief ����������
	*@author ������
	*/
	void generatePhysicalBody(std::string message, const std::string itemName);

protected:
	Sprite* m_pSprite;
	//ui::Scale9Sprite* m_pMessage;
	//ui::Scale9Sprite* m_pShopMessage;
};

/**
*@brief ����������������ʾ��Ϣ
*@author ������
*/
//ui::Scale9Sprite* showMessage(const std::string& message);
#endif
#pragma once
