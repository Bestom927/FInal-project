#include "GameOver.h"


bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//ԭ������
	Point origin = Director::getInstance()->getVisibleOrigin();

	if (isWin)
	{
		auto* endingLabel = Label::createWithSystemFont("You Win!", "Arial", 70, Size::ZERO, TextHAlignment::RIGHT);
		endingLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 5 + 40));
		//endingLabel->setColor(cocos2d::Color3B::RED);
		this->addChild(endingLabel, 1);
		isWin = false;
	}
	else
	{
		auto* endingLabel = Label::createWithSystemFont("Game Over!", "Arial", 70, Size::ZERO, TextHAlignment::RIGHT);
		endingLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 5 + 40));
		//endingLabel->setColor(cocos2d::Color3B::RED);
		this->addChild(endingLabel, 1);
	}
	
	std::string endScoreMessage = "Your score is " + std::to_string(globalHero->getScore());
	Label* m_pEndScoreMessage = Label::createWithTTF(endScoreMessage, "fonts/IRANYekanBold.ttf", 50.f);
	m_pEndScoreMessage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 5 - 55));
	this->addChild(m_pEndScoreMessage, 1);

	std::string endTimeMessage;
	if (g_iDuration % 60 < 10) {
		endTimeMessage = "Passing time is " + std::to_string(g_iDuration / 60) + ":0" + std::to_string(g_iDuration % 60);
	}
	else {
		endTimeMessage = "Passing time is " + std::to_string(g_iDuration / 60) + ':' + std::to_string(g_iDuration % 60);
	}
	Label* m_pEndTimeMessage = Label::createWithTTF(endTimeMessage, "fonts/IRANYekanBold.ttf", 40.f);
	m_pEndTimeMessage->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 4 - 35));
	this->addChild(m_pEndTimeMessage, 1);

	auto* GoBackItemImage = MenuItemImage::create(
		"button/Return-normal.png",
		"button/Return-push.png");

	auto GoBackItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(GameOver::GoBackControl, this),
		GoBackItemImage,
		NULL);
	GoBackItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 4 - 140));

	Menu* mn = Menu::create(GoBackItem, NULL);
	mn->setPosition(Size::ZERO);
	this->addChild(mn);

	return true;

	
}

Scene* GameOver::createLayer(RenderTexture* sqr)
{
	Scene* scene = Scene::create();
	GameOver* gameOverLayer = GameOver::create();
	scene->addChild(gameOverLayer, 1);
	//���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite
  //����Sprite��ӵ�GamePause��������
  //�õ����ڵĴ�С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* screenShotPicture = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	screenShotPicture->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //����λ��,������������λ�á�
	screenShotPicture->setFlippedY(true);            //��ת����ΪUI�����OpenGL���겻ͬ
	screenShotPicture->setColor(cocos2d::Color3B::GRAY); //ͼƬ��ɫ���ɫ
	scene->addChild(screenShotPicture);

	Sprite* background = Sprite::create("menu/Pause/PauseBackground.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //����λ��,������������λ�á�
	scene->addChild(background);

	return scene;
}

void GameOver::GoBackControl(cocos2d::Ref* pSender)
{
	if (isEffect) 
	{
		auto soundEffectID = AudioEngine::play2d("sound/Blip.mp3", false);
		//������
	}
	auto scene = MyMenu::createScene();
	Director::getInstance()->replaceScene(scene);

}






