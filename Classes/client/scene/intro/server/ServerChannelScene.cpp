#include "ServerChannelScene.h"
#include "engine\util\GameUtils.h"
#include "client\scene\intro\login\LoginScene.h"
#include "client\manager\CursorManager.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

ServerChannelScene::~ServerChannelScene()
{
	fomas.clear();
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

	addChild(getSprite("stage1/bg_1-1.png"));
	addChild(getSprite("stage1/long_1-1.png"));
	addChild(getSprite("stage1/logo_1-1.png", 282, 583, Vec2::ANCHOR_TOP_LEFT));
	addChild(getSprite("serverselect/back_1-1.png", 270, 600 - 225, Vec2::ANCHOR_TOP_LEFT));

	addChild(createButton(322, 600 - 457, "serverselect/enter_1", [this](Ref* sender) {
		Director::getInstance()->replaceScene(LoginScene::createScene());
	}));
	
	addChild(createButton(440, 600 - 457, "serverselect/quit_1", [this](Ref* sender) {
		Director::getInstance()->end();
	}));

	addChild(createButton(381, 600 - 457, "serverselect/refresh_1", [this](Ref* sender) {
	}));

	int marginY = 0;
	for (int i = 1; i <= NUM_LINES; i++)
	{
		marginY = (i < 3 ? 0 : (i < 5 ? 1 : (i < 7 ? 2 : (i < 9 ? 3 : 4))));
		Button* levelButton = createButton(406 - (i % 2) * 108, 600 - (284 + marginY * 32),
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
		});

		levelButton->setTag(i);
		levelButton->setName("LBTN-" + to_string(i));
		addChild(levelButton);
	}

	Sprite* foma1 = getSprite("stage1/piaoyun2_1-1.png", 550, 0);
	fomas.pushBack(foma1);
	addChild(foma1);

	Sprite* foma2 = getSprite("stage1/piaoyun3_1-1.png", 525, 0);
	fomas.pushBack(foma2);
	addChild(foma2);

	Sprite* foma3 = getSprite("stage1/piaoyun3_1-1.png", 100, 0);
	fomas.pushBack(foma3);
	addChild(foma3);

	CursorManager::Get()->addCursorToLayer(this);

	scheduleUpdate();
	return true;
}

void ServerChannelScene::update(float dt)
{
	Sprite* foma1 = fomas.at(0);
	foma1->setPosition(foma1->getPosition().x, foma1->getPosition().y + 1);
	if (foma1->getPosition().y > 700)
	{
		foma1->setPosition(foma1->getPosition().x, 0);
	}

	Sprite* foma2 = fomas.at(1);
	foma2->setPosition(foma2->getPosition().x, foma2->getPosition().y + 0.8);
	if (foma2->getPosition().y > 1200)
	{
		foma2->setPosition(foma2->getPosition().x, 0);
	}

	Sprite* foma3 = fomas.at(2);
	foma3->setPosition(foma3->getPosition().x, foma3->getPosition().y + 1);
	if (foma3->getPosition().y > 1200)
	{
		foma3->setPosition(foma3->getPosition().x, 0);
	}
}
