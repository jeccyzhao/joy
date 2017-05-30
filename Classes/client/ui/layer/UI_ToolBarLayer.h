#ifndef TOOL_BAR_LAYER_H
#define TOOL_BAR_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "client\Client.h"
#include "engine\util\GameUtils.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class ToolBarLayer : public cocos2d::Layer
{
public:
	ToolBarLayer();
	virtual ~ToolBarLayer();
	CREATE_FUNC(ToolBarLayer);
	virtual bool init();
};

#endif