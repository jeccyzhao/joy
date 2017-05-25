#pragma once

#include "cocos2d.h"
#include "engine\Singleton.h"
#include "client\Client.h"
#include "engine\util\DBUtil.h"
#include "client\misc\MapData.h"

USING_NS_CC;

class GameDataManager : public TSingleton<GameDataManager>
{
public:
	GameDataManager();
	~GameDataManager();
	
	int getMotionDataFrames(const std::string id, const std::string actionName, const std::string actionCode);

	/**
	*  加载地图
	*
	*  @param mapName 地图编号名
	*/
	MapInfo* loadMapInfoByName(string mapNo);

private:

	DBUtil* m_dbConnection;

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