#pragma once

#include "cocos2d.h"
#include <string>

USING_NS_CC;
using namespace std;

class MapItem : public Ref
{
public:
	string itemNo;						// Ԫ�ر��
	string itemName;					// Ԫ����
	int x;								// X����
	int y;								// Y����
	int offsetX;						// ƫ��X����
	int offsetY;						// ƫ��Y����
	bool visible;						// �Ƿ�ɼ�
	int frame;							// ֡
	int size;							// ��̬ͼ��
};

class MapEntrance : public Ref
{
public:
	string destMapNo;					// ����Ŀ�ĵ�ͼ���
	string entranceName;				// ����������
	int entranceX;						// X����
	int entranceY;						// Y����
};

class MapInfo : public Ref
{
public:
	string mapId;						// ��ͼID, ���ݿ��е�����ֵ
	string mapName;						// ��ͼ��
	string mapNo;						// ��ͼ�����
	string mapMusic;					// ��ͼ����
	int mapWidth;						// ��ͼ���
	int mapHeight;						// ��ͼ�߶�
	int playerX;						// ��ͼ����X����
	int playerY;						// ��ͼ����Y����

	Vector<MapItem*> mapItems;			// ��ͼԪ��
	Vector<MapEntrance*> mapEntrances;	// ��ͼ������
};

