#include "GameScene.h"
#include "client/Client.h"
#include "client/manager/GameDataManager.h"
#include "client/ui/layer/SystemMenuLayer.h"
#include "client/ui/layer/MiniMapLayer.h"
#include "client/manager/CursorManager.h"

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

	addChild(SystemMenuLayer::create(), 9999);
	addChild(MiniMapLayer::create(), 9999);

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
			
			log("Adding item %s on map %s", fullItemNo.c_str(), mapName.c_str());

			auto sprite = getSprite(mapName + "/" + fullItemNo + ".png");
			if (sprite)
			{
				sprite->setPosition(
					designResolutionSize.width - mapItem->x - sprite->getContentSize().width,
					designResolutionSize.height - mapItem->y - sprite->getContentSize().height);

				addChild(sprite);
				//break;
			}
			
			log(map->playerX);
			log(map->playerY);
			//this->setPosition(-map->playerX, -map->playerY);
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

	CursorManager::Get()->addCursorToLayer(this);

	return true;
}

void GameScene::update(float dt)
{

}