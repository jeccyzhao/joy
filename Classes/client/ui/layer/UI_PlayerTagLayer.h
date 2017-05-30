#ifndef PLAYER_TAG_LAYER_H
#define PLAYER_TAG_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "client\Client.h"
#include "engine\util\GameUtils.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class PlayerTagLayer : public cocos2d::Layer
{
public:
	PlayerTagLayer();
	virtual ~PlayerTagLayer();
	CREATE_FUNC(PlayerTagLayer);
	virtual bool init();
};

#endif