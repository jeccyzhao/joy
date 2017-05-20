#include "CharacterSelectScene.h"
#include "engine\util\GameUtils.h"
#include "client\scene\intro\login\LoginScene.h"
#include "client\scene\intro\character\create\CharacterCreate1.h"
#include "client\manager\CursorManager.h"
#include "ui\UIButton.h"

USING_NS_CC;

Scene* CharacterSelectScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterSelectScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool CharacterSelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/charselect-{n}.plist");

	addBackgroundToLayer(this);
	
	addChild(createButton(632, 600 - 530, "charselect/back_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(LoginScene::createScene());
	}));

	addChild(createButton(15, 600 - 481, "charselect/create_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(CharacterCreate1::createScene());
	}));

	addChild(createButton(15, 600 - 530, "charselect/delete_1", [this](Ref* sender) {
	}, false));

	addChild(createButton(632, 600 - 481, "charselect/startgame_1", [this](Ref* sender) {
	}, false));

	Vector<SpriteFrame*> spriteFrames;
	for (int i = 1; i <= 3; i++)
	{
		spriteFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("charselect/roleback_1-" + to_string(i) + ".png"));
	}

	Animation *animation = Animation::createWithSpriteFrames(spriteFrames);
	animation->setLoops(-1);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(0.7f / 3.0f);
	for (int i = 1; i <= 3; i++)
	{
		Sprite* sprite = getSprite("charselect/roleback_1-1.png");
		sprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
		sprite->setPosition(Vec2(67 + (i - 1) * 234, 600 - 142));
		addChild(sprite);

		//sprite->runAction(Animate::create(animation));
	}

	for (int i = 1; i <= 3; i++)
	{
		addChild(getSprite("charselect/cloud_1-1.png", 90 + 234 * (i - 1), 600 - 279, Vec2::ANCHOR_TOP_LEFT));
	}

	CursorManager::Get()->addCursorToLayer(this);

	return true;
}
