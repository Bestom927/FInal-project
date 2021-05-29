#include "Item.h"

void Item::bindSprite(Sprite* pSprite)
{
    m_pSprite = pSprite;
    this->addChild(m_pSprite);
}

Sprite* Item::getSprite()
{
    return m_pSprite;
}