#ifndef SYS_MENU_LAYER_H
#define SYS_MENU_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class SystemMenuLayer : public cocos2d::CCLayer
{
public:
	SystemMenuLayer();
	virtual ~SystemMenuLayer();

	CREATE_FUNC(SystemMenuLayer);

	virtual bool init();

private:
	Sprite* m_bgSprite;
};

#endif