#pragma once

#include "cocos2d.h"
#include "engine\Singleton.h"
#include "client\Client.h"
#include "engine\util\DBUtil.h"

USING_NS_CC;

class GameDataManager : public TSingleton<GameDataManager>
{
public:
	GameDataManager();
	~GameDataManager();
	
	int getMotionDataFrames(const std::string id, const std::string actionName, const std::string actionCode);

private:
	DBUtil* m_dbConnection;
};