#pragma once

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

enum CursorIconType
{
	CURSOR_NORMAL,
	CURSOR_ATTACK,
	CURSOR_TALK,
	CURSOR_BUY,
	CURSOR_SELL,
	CURSOR_HAND,
	CURSOR_WAIT,
	CURSOR_IMBUE,
	CURSOR_TARGET_NORMAL,
	CURSOR_TARGET_FOCUS,
	CURSOR_TARGET_INVALID
};

struct CursorIconData
{
	std::string spriteName;
	unsigned int frames;
	bool animation;
	bool loop;

	CursorIconData()
	{
		spriteName = "";
		frames = 0;
		animation = false;
		loop = false;
	}

	CursorIconData(std::string spriteName, unsigned int frames, bool animation, bool loop)
	{
		this->spriteName = spriteName;
		this->frames = frames;
		this->animation = animation;
		this->loop = loop;
	}
};