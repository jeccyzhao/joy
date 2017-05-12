#include "CharacterCreate1.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\scene\intro\character\CharacterSelectScene.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

Scene* CharacterCreate1::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterCreate1::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool CharacterCreate1::init()
{
	if (!Layer::init())
	{
		return false;
	}

	addBackgroundToLayer(this);
	addChild(getSprite("charcreate/create1/back_1-1.png"));
	addChild(getSprite("charcreate/create1/xinxiang_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT)); 

	auto foButton = createButton(174, designResolutionSize.height - 296, 
		"charcreate/create1/fo_1-1.png", "charcreate/create1/fo_1-2.png", "charcreate/create1/fo_1-3.png", "", [this](Ref* sender) {

		Button* trigger = (Button*)sender;
		trigger->setClicked(true);

		Node* node = getChildByName("btn_mo");
		if (node)
		{
			Button* button = (Button*)node;
			button->setClicked(false);
		}
	});

	foButton->setName("btn_fo");
	addChild(foButton);

	auto moButton = createButton(542, designResolutionSize.height - 296,
		"charcreate/create1/mo_1-1.png", "charcreate/create1/mo_1-2.png", "charcreate/create1/mo_1-3.png", "", [this](Ref* sender) {
		
		Button* trigger = (Button*)sender;
		trigger->setClicked(true);

		Node* node = getChildByName("btn_fo");
		if (node)
		{
			Button* button = (Button*)node;
			button->setClicked(false);
		}
	});

	moButton->setName("btn_mo");
	addChild(moButton);

	addChild(createButton(632, designResolutionSize.height - 481, "charcreate/create1/prev_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(CharacterSelectScene::createScene());
	}));
	addChild(createButton(632, designResolutionSize.height - 530, "charcreate/create1/next_1", [this](Ref* sender) {
		//Director::getInstance()->replaceScene(CharacterSelectScene::createScene());
	}));
	
	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate1::update(float dt)
{
	updateFomas(dt);
}