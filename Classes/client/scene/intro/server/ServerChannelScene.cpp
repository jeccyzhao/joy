#include "ServerChannelScene.h"
#include "engine\util\GameUtils.h"
#include "client\scene\intro\login\LoginScene.h"
#include "client\manager\CursorManager.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

ServerChannelScene::~ServerChannelScene()
{
}

Scene* ServerChannelScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ServerChannelScene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool ServerChannelScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/stage1-{n}.plist", 0, 1);
	preLoadResources("ui/serverselect-{n}.plist");

	addBackgroundToLayer(this);
	addChild(getSprite("stage1/logo_1-1.png", 282, 583, Vec2::ANCHOR_TOP_LEFT));
	addChild(getSprite("serverselect/back_1-1.png", 270, designResolutionSize.height - 225, Vec2::ANCHOR_TOP_LEFT));

	enterButton = createButton(322, designResolutionSize.height - 457, "serverselect/enter_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(LoginScene::createScene());
	}, false);
	addChild(enterButton);
	
	addChild(createButton(440, designResolutionSize.height - 457, "serverselect/quit_1", [this](Ref* sender) {
		Director::getInstance()->end();
	}));

	addChild(createButton(381, designResolutionSize.height - 457, "serverselect/refresh_1", [this](Ref* sender) {
	}));

	int marginY = 0;
	for (int i = 1; i <= NUM_LINES; i++)
	{
		marginY = (i < 3 ? 0 : (i < 5 ? 1 : (i < 7 ? 2 : (i < 9 ? 3 : 4))));
		Button* levelButton = createButton(406 - (i % 2) * 108, designResolutionSize.height - (284 + marginY * 32),
			"serverselect/line" + to_string(i) + "/green_1-1.png",
			"serverselect/line" + to_string(i) + "/green_1-2.png",
			"serverselect/line" + to_string(i) + "/green_1-2.png", 
			"",  
		[this](Ref* sender) {
			Button* trigger = (Button*) sender;
			int currentTag = trigger->getTag();
			for (int i = 1; i <= NUM_LINES; i++)
			{
				Node* node = getChildByName("LBTN-" + to_string(i));
				if (node && node->getTag() != currentTag)
				{
					Button* button = (Button*) node;
					button->setClicked(false);
				}
			}

			trigger->setClicked(true);
			enterButton->setBright(true);
		});

		levelButton->setTag(i);
		levelButton->setName("LBTN-" + to_string(i));
		addChild(levelButton);
	}

	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);

	scheduleUpdate();
	return true;
}

void ServerChannelScene::update(float dt)
{
	updateFomas(dt);
}
