#pragma once

#include "cocos2d.h"
#include "engine\Singleton.h"

USING_NS_CC;

class CustomizedCursor : public TSingleton<CustomizedCursor>
{
public:
	CustomizedCursor();
	~CustomizedCursor();
private:
	Sprite* cursorSprite;
};