#include "Client\Manager\MetadataManager.h"

static MetadataManager* _dmInstance;
MetadataManager::MetadataManager() :m_db(NULL)
{
};

MetadataManager* MetadataManager::getInstance(string dbName)
{
	if (_dmInstance == NULL)
	{
		_dmInstance = new MetadataManager();
		_dmInstance->m_db = DBUtil::getInstance(dbName);
	}

	return _dmInstance;
};

Vector<MapItem*> MetadataManager::loadMapItemByName(string mapNo)
{
	string sql = "select item_no, x, y, offset_x, offset_y, visible, item_name, t5, size from t_map_item where map_no='" + mapNo + "' order by t2 asc, t1 asc";
	log("Debug: loadMapItemByName - %s", sql);

	Vector<MapItem*> vec;
	vector<map<string, string>> data = m_db->searchData(sql);
	for (map<string, string> entry : data)
	{
		MapItem *mapItem = new MapItem();
		log("%s", entry.find("item_no")->second.c_str());
		mapItem->itemNo = entry.find("item_no")->second;
		mapItem->itemName = entry.find("item_name")->second;
		mapItem->x = atoi(entry.find("x")->second.c_str());
		mapItem->y = atoi(entry.find("y")->second.c_str());
		mapItem->offsetX = atoi(entry.find("offset_x")->second.c_str()) / 100;
		mapItem->offsetY = atoi(entry.find("offset_y")->second.c_str()) / 100;
		mapItem->frame = atoi(entry.find("t5")->second.c_str());
		mapItem->size = atoi(entry.find("size")->second.c_str());

		string itemNo = mapItem->itemNo;
		if (itemNo.length() < 8)
		{
			int count = 8 - itemNo.length();
			for (int i = 1; i <= count; i++)
			{
				itemNo = "0" + itemNo;
			}

			mapItem->itemNo = itemNo;
		}

		vec.pushBack(mapItem);
	}

	return vec;
};

Vector<MapEntrance*> MetadataManager::loadMapEntranceByName(string mapNo)
{
	string sql = "select dest_mapid, entrance_name, entrance_x, entrance_y, t3 from t_map_entrance where map_no='" + mapNo + "' and dest_mapid is not null";
	log("Debug: loadMapEntranceByName - %s", sql);

	Vector<MapEntrance*> vec;
	vector<map<string, string>> data = m_db->searchData(sql);
	for (map<string, string> entry : data)
	{
		MapEntrance *mapEntrance = new MapEntrance();
		mapEntrance->destMapNo = entry.find("dest_mapid")->second;
		mapEntrance->entranceName = entry.find("entrance_name")->second;
		mapEntrance->entranceX = atoi(entry.find("entrance_x")->second.c_str());
		mapEntrance->entranceY = atoi(entry.find("entrance_y")->second.c_str());
		vec.pushBack(mapEntrance);
	}

	return vec;
}

MapInfo* MetadataManager::loadMapInfoByName(string mapNo)
{
	string sql = "select map_id, map_no, map_name, map_width, map_height, role_x, role_y, map_music, debug from t_map where map_no='" + mapNo + "'";
	log("Debug: loadMapInfoByName - %s", sql);

	auto mapInfo = new MapInfo();
	vector<map<string, string>> data = m_db->searchData(sql);
	for (map<string, string> entry : data)
	{
		log("%s", entry.find("map_name")->second.c_str());
		mapInfo->mapName = entry.find("map_name")->second;
		mapInfo->mapWidth = atoi(entry.find("map_width")->second.c_str());
		mapInfo->mapHeight = atoi(entry.find("map_height")->second.c_str());
		mapInfo->mapId = entry.find("map_id")->second.c_str();
		mapInfo->mapMusic = entry.find("map_music")->second;
		mapInfo->playerX = atoi(entry.find("role_x")->second.c_str());
		mapInfo->playerY = atoi(entry.find("role_y")->second.c_str());

		//log("%s", mapInfo->mapName);
		break;
	}

	if (mapInfo->mapWidth > 0)
	{
		mapInfo->mapItems = this->loadMapItemByName(mapNo);
		mapInfo->mapEntrances = this->loadMapEntranceByName(mapNo);
	}

	return mapInfo;
};
