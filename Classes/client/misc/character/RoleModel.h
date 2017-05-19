#pragma once

#include "engine\util\GameUtils.h"
#include "client\misc\PlayerData.h"
#include "client\Client.h"
#include "cocos2d.h"

USING_NS_CC;

enum E_DRESS_TYPE { BEGIN_HEAD, BEGIN_BODY, BEGIN_LEG, EYE };
const std::string E_ACTION_STR[10] = { "sit", "jump", "stand", "ladder", "crawl", "rope", "run", "magic", "onehand", "twohands" };

struct DressSprite
{
	Sprite* sprite;
	std::string id;
	E_PLAYER_ACTION action;
	float x;
	float y;
	std::string spriteName;

	DressSprite(std::string id, E_PLAYER_ACTION action = STAND, float x = 0, float y = 0)
	{
		this->id = id;
		this->action = action;
		this->x = x;
		this->y = y;

		sprite = getSprite(getSpriteName(), this->x, this->y, Vec2::ANCHOR_TOP_LEFT);
		sprite->setLocalZOrder(Z_ORDER_ROLE);
	}

	std::string getSpriteName(int type = 1)
	{
		return getSpriteNameById(this->id, this->action, type);
	}

	std::string getSpriteNameById(const std::string id, E_PLAYER_ACTION action, int type = 1)
	{
		std::string appendix = "";
		switch (action)
		{
			case JUMP || LADDER || ROPE || CRAWL || SIT:
				appendix = "-1";
				break;
			default:
				appendix = to_string(type) + "_1-1";
				break;
		}

		this->spriteName = id + "_" + E_ACTION_STR[action] + "_" + appendix + ".png";
		return this->spriteName;
	}

	void changeDress(std::string id)
	{
		if (this->id != id && sprite)
		{
			this->id = id;
			sprite->setSpriteFrame(getSpriteFrameByName(this->id));
		}
	}
};

struct RoleEquipDress
{
	Sprite* faceSprite;
	Sprite* clothSprite;
	Sprite* pantsSprite;
	Sprite* shoesSprite;
	Sprite* armSprite;
	Sprite* shieldSprite;
	Sprite* earringSprite;
	Sprite* neacklaceSprite;
	Sprite* ring1Sprite;
	Sprite* ring2Sprite;
	Sprite* bangleSprite;
	Sprite* stoneSprite;
};

class RoleModel : public cocos2d::Layer
{
public:
	RoleModel();
	~RoleModel();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(RoleModel);

	void changeDress(E_DRESS_TYPE type, std::string id);
private:

	std::string name;
	E_PLAYER_JOB job;
	E_PLAYER_HUDDLE huddle;
	int level;

	DressSprite* face;
	DressSprite* bodyBegin;
	DressSprite* legBegin;
	DressSprite* eye;
};