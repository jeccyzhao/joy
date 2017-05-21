#pragma once

#include "cocos2d.h"
#include "engine\util\GameUtils.h"
#include "client\misc\PlayerData.h"
#include "client\Client.h"
#include "client\manager\GameDataManager.h"

USING_NS_CC;

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

	DressSprite()
	{
		this->sprite = nullptr;
		this->action = STAND;
		this->x = 0;
		this->y = 0;
	}

	DressSprite(std::string id, E_PLAYER_ACTION action = STAND, float x = 0, float y = 0)
	{
		this->id = id;
		this->x = x;
		this->y = y;

		this->spriteName = getSpriteName(id, action);
		this->action = action;

		this->sprite = getSprite(this->spriteName, this->x, this->y, Vec2::ANCHOR_TOP_LEFT);
		this->sprite->setLocalZOrder(Z_ORDER_ROLE);
	}

	void playAnimation(E_PLAYER_ACTION action)
	{
		this->action = action;
		int frames = GameDataManager::Get()->getMotionDataFrames(this->id, E_PLAYER_ACTION_STR[action], "1_1");
		if (frames > 1)
		{
			this->animation = createAnimation(getSpriteName(1, true), frames, 0.3f, true, true, true);
			this->sprite->stopAllActions();
			this->sprite->runAction(Animate::create(this->animation));
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

		return id + "_" + E_PLAYER_ACTION_STR[action] + "_" + appendix + ".png";;
	}

	void updateDress(std::string id)
	{
		if (this->id != id)
		{
			this->id = id;
			if (id != "")
			{
				// load resources before updating sprite frame
				preLoadResources(ROLE_MOTION_DATA_PATH + "/" + id + "-{n}.plist", 0, 3);

				this->spriteName = getSpriteName(this->id, this->action);
				if (sprite)
				{
					sprite->stopAllActions();
					sprite->setSpriteFrame(getSpriteFrameByName(this->spriteName));

					playAnimation(this->action);
				}
				else
				{
					sprite = getSprite(this->spriteName, this->x, this->y, Vec2::ANCHOR_TOP_LEFT);
				}

				if (sprite)
				{
					sprite->setVisible(true);
				}
			}
			else
			{
				sprite->setVisible(false);
			}
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

	void updateDress(E_PLAYER_DRESS_TYPE type, std::string id);
	void playAnimation(E_PLAYER_ACTION action = STAND);
	
	void initDress(E_PLAYER_DRESS_TYPE dressType, std::string id);
	void show(float x, float y);
private:

	std::string name;
	E_PLAYER_JOB job;
	E_PLAYER_HUDDLE huddle;
	int level;

	DressSprite* faceBegin;
	DressSprite* bodyCloth;
	DressSprite* bodyBegin;
	DressSprite* legBegin;
	DressSprite* legPants;
	DressSprite* feetShoes;
	DressSprite* faceEye;
	DressSprite* feetBegin;
	DressSprite* arm;
	DressSprite* shield;
	DressSprite* hairBang2;
	DressSprite* hairInner;
	DressSprite* hairOuter;
	DressSprite* hairBang1;
};
