#include "MiniMapLayer.h"

MiniMapLayer::MiniMapLayer() {}
MiniMapLayer::~MiniMapLayer() {}

bool MiniMapLayer::init() 
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/minimap-{n}.plist");

	m_bgSprite = getSprite("minimap/back_1-1.png", 601, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT);
	addChild(m_bgSprite);

	return true;
}