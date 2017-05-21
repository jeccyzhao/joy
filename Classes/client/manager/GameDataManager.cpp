#include "GameDataManager.h"

GameDataManager::GameDataManager()
{
	m_dbConnection = DBUtil::getInstance();
	m_dbConnection->openDBWithName("res/joyxy.db");
}

GameDataManager::~GameDataManager()
{
	m_dbConnection->closeDB();
}

int GameDataManager::getMotionDataFrames(const std::string id, const std::string actionName, const std::string actionCode)
{
	string sql = "select * from t_motion where (pak_cat || '_' || item_type || '_' || item_no) = '" + id + 
		"' and action_name = '" + actionName + "' and action_code = '" + actionCode + "'";

	std::vector<std::map<std::string, std::string>> ret = m_dbConnection->searchData(sql);
	if (!ret.empty())
	{
		std::map<std::string, std::string> row = ret.at(0);
		int startFrame = atoi(row["start_frame"].c_str());
		int endFrame = atoi(row["end_frame"].c_str());
		return endFrame - startFrame + 1;
	}

	return -1;
}