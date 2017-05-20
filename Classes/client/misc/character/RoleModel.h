#pragma once

#include "cocos2d.h"
#include "engine\util\GameUtils.h"
#include "client\misc\PlayerData.h"
#include "client\Client.h"
#include "client\manager\GameDataManager.h"


USING_NS_CC;

enum E_DRESS_TYPE { BEGIN_HEAD, BEGIN_BODY, BEGIN_LEG, EYE };
const std::string E_ACTION_STR[10] = { "sit", "jump", "stand", "ladder", "crawl", "rope", "run", "magic", "onehand", "twohands" };

struct AnimationFrame
{
	std::string id;
	std::string actionName;
	std::string actionCode;
	int frames;
};

struct DressSprite
{
	Sprite* sprite;
	std::string id;
	E_PLAYER_ACTION action;
	Animation* animation;
	float x;
	float y;
	std::string spriteName;
	bool hasAnimation;

	DressSprite(std::string id, E_PLAYER_ACTION action = STAND, float x = 0, float y = 0)
	{
		this->id = id;
		this->x = x;
		this->y = y;

		this->spriteName = getSpriteName(id, action);
		this->setAction(action);

		this->sprite = getSprite(this->spriteName, this->x, this->y, Vec2::ANCHOR_TOP_LEFT);
		this->sprite->setLocalZOrder(Z_ORDER_ROLE);

		playAnimation(this->action);
	}

	void playAnimation (E_PLAYER_ACTION action)
	{
		if (this->hasAnimation)
		{
			this->sprite->runAction(Animate::create(this->animation));
		}
	}

	void setAction(E_PLAYER_ACTION targetAction)
	{
		if (this->action != targetAction)
		{
			this->action = targetAction;
			int frames = GameDataManager::Get()->getMotionDataFrames(this->id, E_ACTION_STR[targetAction], "1_1");
			if (frames > 1)
			{
				this->animation = createAnimation(getSpriteName(1, true), frames, 0.5f, true, true, true);
				this->hasAnimation = true;
			}
			else
			{
				this->hasAnimation = false;
			}
		}
	}

	std::string getSpriteName(int type = 1, bool isPattern = false)
	{
		return getSpriteName(this->id, this->action, type, isPattern);
	}

	std::string getSpriteName(const std::string id, E_PLAYER_ACTION action, int type = 1, bool isPattern = false)
	{
		std::string appendix = "";
		std::string index = (isPattern ? "{n}" : "1");
		switch (action)
		{
			case JUMP || LADDER || ROPE || CRAWL || SIT:
				appendix = "-" + index;
				break;
			default:
				appendix = to_string(type) + "_1-" + index;
				break;
		}

		return id + "_" + E_ACTION_STR[action] + "_" + appendix + ".png";;
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