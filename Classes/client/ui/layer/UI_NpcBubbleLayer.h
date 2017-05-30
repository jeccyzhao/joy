#ifndef NPC_BUBBLE_LAYER_H
#define NPC_BUBBLE_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "client\Client.h"
#include "engine\util\GameUtils.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class NpcBubbleLayer : public cocos2d::Layer
{
public:
	NpcBubbleLayer();
	virtual ~NpcBubbleLayer();
	CREATE_FUNC(NpcBubbleLayer);
	virtual bool init();
};

#endif