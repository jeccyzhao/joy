#include "UI_PlayerTagLayer.h"

PlayerTagLayer::PlayerTagLayer() {}
PlayerTagLayer::~PlayerTagLayer() {}

bool PlayerTagLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/playertag-{n}.plist");

	addChild(getSprite("playertag/mo/back_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT));

	return true;
}