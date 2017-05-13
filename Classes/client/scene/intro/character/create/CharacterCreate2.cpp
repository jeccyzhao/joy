#include "CharacterCreate2.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\scene\intro\character\create\CharacterCreate1.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

ePlayerHuddle CharacterCreate2::huddle = HUDDLE_NONE;

Scene* CharacterCreate2::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterCreate2::create();
	scene->addChild(layer);
	return scene;
}

void CharacterCreate2::setPlayerHuddle(ePlayerHuddle playerHuddle)
{
	huddle = playerHuddle;
}

ePlayerHuddle CharacterCreate2::getPlayerHuddle()
{
	return huddle;
}

// on "init" you need to initialize your instance
bool CharacterCreate2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	addBackgroundToLayer(this);

	switch (huddle)
	{
		case HUDDLE_BUD:
			addChild(getSprite("charcreate/create3/back_fo_1-1.png"));
			break;
		case HUDDLE_EVIL:
			addChild(getSprite("charcreate/create3/back_mo_1-1.png"));
			break;
		default:
			break;
	}

	addChild(getSprite("charcreate/create3/zhiye_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT));

	addPreButtonToLayer(this);
	addNextButtonToLayer(this, false);
	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate2::onPreButtonClick()
{
	Director::getInstance()->replaceScene(CharacterCreate1::createScene());
}

void CharacterCreate2::onNextButtonClick()
{
}

void CharacterCreate2::update(float dt)
{
	updateFomas(dt);
}