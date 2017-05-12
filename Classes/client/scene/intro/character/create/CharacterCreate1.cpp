#include "CharacterCreate1.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
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
	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate1::update(float dt)
{
	updateFomas(dt);
}