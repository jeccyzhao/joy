#include "GameScene.h"
#include "client/Client.h"
#include "client\manager\GameDataManager.h"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	auto layer = GameScene::create();

	scene->addChild(layer);

	if (DEBUG_DRAW)
	{
		scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	}

	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		log("Key %d was pressed!", (int)keyCode);

		auto target = event->getCurrentTarget();
		float currentX = target->getPosition().x;
		float currentY = target->getPosition().y;

		int count = 0;
		int delta = 10;
		if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			target->setPosition(currentX, currentY - delta);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			target->setPosition(currentX - delta, currentY);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			target->setPosition(currentX + delta, currentY);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			target->setPosition(currentX, currentY + delta);
		}
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto gameDataMgr = GameDataManager::Get();
	string mapName = "home";
	MapInfo *map = gameDataMgr->loadMapInfoByName(mapName);
	if (map)
	{
		preLoadResources("nsyt/" + mapName + "-{n}.plist", 0, 6);
		Vector<MapItem*> mapItems = map->mapItems;

		for (auto &mapItem : mapItems)
		{
			string fullItemNo = mapItem->itemNo;
			while (fullItemNo.length() < 8)
			{
				fullItemNo = "0" + fullItemNo;
			}

			auto sprite = getSprite(mapName + "/" + fullItemNo + ".png", mapItem->x, mapItem->y); // , Vec2::ANCHOR_TOP_LEFT);
			if (sprite)
			{
				addChild(sprite);
			}
		}

		/*
		int count = 0;
		string spriteFileName = "res/nsyt/00000159.png";
		if (FileUtils::getInstance()->isFileExist(spriteFileName))
		{
			//auto polygonInfo = AutoPolygon::generatePolygon(spriteFileName);
			//auto sprite = Sprite::create(spriteFileName);
			auto sprite = Sprite::create(spriteFileName);
			if (sprite)
			{
				sprite->setPosition(Vec2(0, 0));
				sprite->setAnchorPoint(Vec2::ZERO);
				this->addChild(sprite, 0);
			}
		}
		*/
	}

	return true;
}

void GameScene::update(float dt)
{

}