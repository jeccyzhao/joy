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
	*  ���ص�ͼ
	*
	*  @param mapName ��ͼ�����
	*/
	MapInfo* loadMapInfoByName(string mapNo);

private:
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

#endif	