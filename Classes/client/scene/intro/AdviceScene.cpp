#include "AdviceScene.h"
#include "engine\util\GameUtils.h"
#include "client\scene\intro\server\ServerChannelScene.h"
#include "client\manager\CursorManager.h"

USING_NS_CC;

AdviceScene::~AdviceScene()
{
	fomas.clear();
}

Scene* AdviceScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AdviceScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool AdviceScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	isSceneFaded = false;

	addChild(getSprite("stage1/bg_1-1.png"));
	addChild(getSprite("stage1/long_1-1.png"));
	addChild(getSprite("stage1/advice_1-1.png"));

	Sprite* foma1 = getSprite("stage1/piaoyun2_1-1.png", 550, 0);
	fomas.pushBack(foma1);

	Sprite* foma2 = getSprite("stage1/piaoyun3_1-1.png", 525, 0);
	fomas.pushBack(foma2);

	Sprite* foma3 = getSprite("stage1/piaoyun3_1-1.png", 100, 0);
	fomas.pushBack(foma3);

	addChild(foma1);
	addChild(foma2);
	addChild(foma3);

	CursorManager::Get()->addCursorToLayer(this);
	
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(AdviceScene::onMouseClick, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	scheduleOnce(schedule_selector(AdviceScene::onSceneFaded), 5.0f);
	scheduleUpdate();
	return true;
}

void AdviceScene::update(float dt)
{
	Sprite* foma1 = fomas.at(0);
	foma1->setPosition(foma1->getPosition().x, foma1->getPosition().y + 1);

	Sprite* foma2 = fomas.at(1);
	foma2->setPosition(foma2->getPosition().x, foma2->getPosition().y + 0.8);

	Sprite* foma3 = fomas.at(2);
	foma3->setPosition(foma3->getPosition().x, foma3->getPosition().y + 1);
}

void AdviceScene::onMouseClick(Event *event)
{
	EventMouse* e = (EventMouse*)event;
	if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
	{
		if (!isSceneFaded)
		{
			isSceneFaded = true;
			auto scene = TransitionFade::create(1.0f, ServerChannelScene::createScene());
			Director::getInstance()->replaceScene(scene);
		}
	}
}

void AdviceScene::onSceneFaded(float dt)
{
	if (!isSceneFaded)
	{
		isSceneFaded = true;
		auto scene = TransitionFade::create(1.0f, ServerChannelScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}
}