#ifndef MINI_MAP_LAYER_H
#define MINI_MAP_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class MiniMapLayer : public cocos2d::CCLayer
{
public:
	MiniMapLayer();
	virtual ~MiniMapLayer();

	CREATE_FUNC(MiniMapLayer);

	virtual bool init();

private:
	Sprite* m_bgSprite;
};

#endif