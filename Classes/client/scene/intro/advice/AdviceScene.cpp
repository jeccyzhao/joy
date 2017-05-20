#include "AdviceScene.h"
#include "engine\util\GameUtils.h"
#include "client\scene\intro\server\ServerChannelScene.h"
#include "client\manager\CursorManager.h"

USING_NS_CC;

AdviceScene::~AdviceScene()
{
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

	preLoadResources("ui/stage1-{n}.plist", 0, 1);

	isSceneFaded = false;

	addBackgroundToLayer(this);
	addChild(getSprite("stage1/advice_1-1.png"));
	addFomasToLayer(this);

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
	updateFomas(dt);
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