#pragma once

#include "cocos2d.h"
#include <string>

USING_NS_CC;
using namespace std;

class MapItem : public Ref
{
public:
	string itemNo;						// 元素编号
	string itemName;					// 元素名
	int x;								// X坐标
	int y;								// Y坐标
	int offsetX;						// 偏移X坐标
	int offsetY;						// 偏移Y坐标
	bool visible;						// 是否可见
	int frame;							// 帧
	int size;							// 动态图数
};

class MapEntrance : public Ref
{
public:
	string destMapNo;					// 传送目的地图编号
	string entranceName;				// 传送门名称
	int entranceX;						// X坐标
	int entranceY;						// Y坐标
};

class MapInfo : public Ref
{
public:
	string mapId;						// 地图ID, 数据库中的主键值
	string mapName;						// 地图名
	string mapNo;						// 地图编号名
	string mapMusic;					// 地图音乐
	int mapWidth;						// 地图宽度
	int mapHeight;						// 地图高度
	int playerX;						// 地图出生X坐标
	int playerY;						// 地图出生Y坐标

	Vector<MapItem*> mapItems;			// 地图元素
	Vector<MapEntrance*> mapEntrances;	// 地图传送门
};

