#include "LoginScene.h"
#include "engine\util\GameUtils.h"
#include "client\scene\intro\server\ServerChannelScene.h"
#include "client\scene\intro\character\CharacterSelectScene.h"
#include "client\manager\CursorManager.h"
#include "client\Client.h"
#include "ui\UIButton.h"
#include "ui\UICheckBox.h"

USING_NS_CC;

Scene* LoginScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoginScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool LoginScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/stage1-{n}.plist", 0, 1);
	preLoadResources("ui/Login-{n}.plist");

	addChild(getSprite("stage1/bg_1-1.png"));
	addChild(getSprite("stage1/logo_1-1.png", 282, 583, Vec2::ANCHOR_TOP_LEFT));
	addChild(getSprite("Login/back_1-1.png"));

	addChild(createButton(404, designResolutionSize.height - 389, "Login/ok_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(CharacterSelectScene::createScene());
	}));
	addChild(createButton(490, designResolutionSize.height - 389, "Login/cancel_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(ServerChannelScene::createScene());
	}));

	addChild(createButton(314, designResolutionSize.height - 384, "Login/register_1"));
	addChild(createButton(247, designResolutionSize.height - 384, "Login/getpwd_1"));
	addChild(createButton(476, designResolutionSize.height - 346, "Login/softkbd_1"));

	auto checkbox = CheckBox::create("Login/checkbox_1-1.png", 
									 "Login/checkbox_1-2.png", "Login/checkbox_1-2.png", "Login/checkbox_1-2.png", "Login/checkbox_1-2.png",
									 Widget::TextureResType::PLIST);
	checkbox->setPosition(Vec2(481, designResolutionSize.height - 309));
	checkbox->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	addChild(checkbox);

	auto uidTextBox = TextFieldTTF::textFieldWithPlaceHolder("Test", "Arial", 20); // ::create();
	//uidTextBox->setContentSize(Size(150, 20));
	uidTextBox->setPosition(308, designResolutionSize.height - 312);
	addChild(uidTextBox);

	CursorManager::Get()->addCursorToLayer(this);

	return true;
}
