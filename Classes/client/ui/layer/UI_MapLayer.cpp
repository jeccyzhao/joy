#include "UI_MapLayer.h"
#include "client/manager/GameDataManager.h"
#include "engine/util/GameUtils.h"

MapLayer::MapLayer() 
{
	m_currentMapName = "";
}

MapLayer::~MapLayer() {}

bool MapLayer::init()
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

	return true;
}

void MapLayer::loadMap(string mapName)
{
	if (m_currentMapName != mapName)
	{
		m_currentMapName = mapName;
		MapInfo *mapInfo = GameDataManager::Get()->loadMapInfoByName(m_currentMapName);
		if (mapInfo)
		{
			//m_mapItems = mapInfo->mapItems;
			preLoadResources("nsyt/" + mapName + "-{n}.plist", 0, 6);
			for (auto &mapItem : mapInfo->mapItems)
			{
				string itemNo = getFullItemNo(mapItem->itemNo);
				log("Adding item %s on map %s", itemNo.c_str(), mapName.c_str());

				auto sprite = getSprite(mapName + "/" + itemNo + ".png");
				if (sprite)
				{
					sprite->setPosition(designResolutionSize.width - mapItem->x - sprite->getContentSize().width,
						designResolutionSize.height - mapItem->y - sprite->getContentSize().height);

					this->addChild(sprite);
				}

				//this->setPosition(-map->playerX, -map->playerY);
			}
		}
	}
}