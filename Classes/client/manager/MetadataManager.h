#ifndef META_DATA_MANAGER_H
#define META_DATA_MANAGER_H

#include "cocos2d.h"
#include "Engine\Util\DBUtil.h"
#include "Client\Misc\MapData.h"

using namespace std;

USING_NS_CC;

class MetadataManager
{
private:
	DBUtil* m_db;

	MetadataManager();
	~MetadataManager();

	//cocos2d::Map<string, MapInfo*> m_mapInfoCache;

public:
	static MetadataManager* getInstance(string dbName);

	/**
	*  加载地图
	*
	*  @param mapName 地图编号名
	*/
	MapInfo* loadMapInfoByName(string mapNo);

private:
	/**
	*  加载地图元素
	*
	*  @param mapName 地图编号名
	*/
	Vector<MapItem*> loadMapItemByName(string mapNo);

	/**
	*  加载地图传送
	*
	*  @param mapName 地图编号名
	*/
	Vector<MapEntrance*> loadMapEntranceByName(string mapNo);
};

#endif	