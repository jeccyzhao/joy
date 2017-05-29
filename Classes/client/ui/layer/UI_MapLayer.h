#pragma once
#ifndef MAP_LAYER_H
#define MAP_LAYER_H

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class MapLayer : public cocos2d::Layer
{
public:
	MapLayer();
	virtual ~MapLayer();
	CREATE_FUNC(MapLayer);
	virtual bool init();
	void loadMap(string mapName);
private:
	//Vector<MapItem*> m_mapItems;
	string m_currentMapName;
};

#endif