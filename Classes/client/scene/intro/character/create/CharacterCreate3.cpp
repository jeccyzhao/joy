#include "CharacterCreate3.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\scene\intro\character\create\CharacterCreate2.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

Scene* CharacterCreate3::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterCreate3::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool CharacterCreate3::init()
{
	if (!Layer::init())
	{
		return false;
	}

	addBackgroundToLayer(this);
	//addChild(getSprite("charcreate/create1/back_1-1.png"));
	//addChild(getSprite("charcreate/create1/zhiye_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT)); 

	addPreButtonToLayer(this);
	addNextButtonToLayer(this, false);
	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate3::onPreButtonClick()
{
	Director::getInstance()->replaceScene(CharacterCreate2::createScene());
}

void CharacterCreate3::onNextButtonClick()
{
}

void CharacterCreate3::update(float dt)
{
	updateFomas(dt);
}