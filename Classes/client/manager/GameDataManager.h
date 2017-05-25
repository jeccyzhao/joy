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
	*  ���ص�ͼ
	*
	*  @param mapName ��ͼ�����
	*/
	MapInfo* loadMapInfoByName(string mapNo);

private:

	DBUtil* m_dbConnection;

	/**
	*  ���ص�ͼԪ��
	*
	*  @param mapName ��ͼ�����
	*/
	Vector<MapItem*> loadMapItemByName(string mapNo);

	/**
	*  ���ص�ͼ����
	*
	*  @param mapName ��ͼ�����
	*/
	Vector<MapEntrance*> loadMapEntranceByName(string mapNo);
};