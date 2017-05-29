#ifndef MINI_MAP_LAYER_H
#define MINI_MAP_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

static const int POSITION_X = 601;
static const int POSITION_Y = designResolutionSize.height;
static const int MINI_MAP_WIDTH = 200;
static const int MINI_MAP_MIN_HEIGHT = 60;
static const int MINI_MAP_MEDIUM_HEIGHT = 100;
static const int MINI_MAP_MAX_HEIGHT = 150;

class MiniMapLayer : public cocos2d::Layer
{
public:
	MiniMapLayer();
	virtual ~MiniMapLayer();

	CREATE_FUNC(MiniMapLayer);

	virtual bool init();

private:
	Sprite* m_bgSprite;
	Sprite* m_mapSprite;
};

#endif