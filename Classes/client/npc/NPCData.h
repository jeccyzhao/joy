#pragma once

#include "string"
#include "cocos2d.h"

USING_NS_CC;

enum NPCType
{
	NORMAL_NPC = 0,
	ITEM_EQUIP_NPC,
	SHOP_NPC
};

enum NPCFlagSign
{
	YELLOW_QUES_MARK = 0,
	GRAY_QUES_MARK,
	YELLOW_EXCLAMATION_MARK,
	NPCFlagSign_UNKNOW
};

enum eTaskGlobleState
{
	E_ACCEPT_TASK = 0,
	E_OVER_TASK,
	E_TASK_STATE_UNKNOW
};

class NPCData : public cocos2d::CCNode
{
public:
	int	mID;
	int mRcsTypeID;
	NPCType mType;
	std::string mName;
	std::string mMotto;
	std::string mHeadImageIcon;
	std::string mTaskIntroImageIcon;
	std::string mTaskUpLogoImageIcon;
	float posx;
	float posy;
	bool bFlip;
public:
	NPCData()
	{
		mID = 0;
		mRcsTypeID = 0;
		mType = NORMAL_NPC;
		posx = posy = 0;
		bFlip = false;
	}
	~NPCData() { ; }
};
