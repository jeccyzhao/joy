#include "UI_MiniMapLayer.h"

MiniMapLayer::MiniMapLayer() {}
MiniMapLayer::~MiniMapLayer() {}

bool MiniMapLayer::init() 
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/minimap-{n}.plist");

	m_bgSprite = getSprite("minimap/back_1-1.png", POSITION_X, POSITION_Y, Vec2::ANCHOR_TOP_LEFT);
	addChild(m_bgSprite);

	addChild(createButton(POSITION_X + 3, POSITION_Y - 4, "minimap/worldmap_1", [this](Ref* sender) {}));
	addChild(createButton(POSITION_X + 22, POSITION_Y - 4, "minimap/guide_1", [this](Ref* sender) {}));
	addChild(createButton(POSITION_X + MINI_MAP_WIDTH - 22, POSITION_Y - 4, "minimap/min_1", [this](Ref* sender) {}));
	addChild(createButton(POSITION_X + MINI_MAP_WIDTH - 22, POSITION_Y - 4, "minimap/max_1", [this](Ref* sender) {}));

	m_mapSprite = getSprite("minimap/nomap_1-1.png", POSITION_X + 5, POSITION_Y - 28, Vec2::ANCHOR_TOP_LEFT);
	m_mapSprite->setScaleX((MINI_MAP_WIDTH - 10.0f) / 200);
	m_mapSprite->setScaleY((MINI_MAP_MEDIUM_HEIGHT + 0.0f) / 150);
	addChild(m_mapSprite);

	addChild(getSprite("minimap/edge/c1_1-1.png", POSITION_X, POSITION_Y - 22, Vec2::ANCHOR_TOP_LEFT));
	addChild(getSprite("minimap/edge/c2_1-1.png", POSITION_X + 195, POSITION_Y - 22, Vec2::ANCHOR_TOP_LEFT));
	addChild(getSprite("minimap/edge/c3_1-1.png", POSITION_X, POSITION_Y - MINI_MAP_MEDIUM_HEIGHT - 27, Vec2::ANCHOR_TOP_LEFT));
	addChild(getSprite("minimap/edge/c4_1-1.png", POSITION_X + 195, POSITION_Y - MINI_MAP_MEDIUM_HEIGHT - 27, Vec2::ANCHOR_TOP_LEFT));

	auto edge1 = getSprite("minimap/edge/e1_1-1.png", POSITION_X + 5, POSITION_Y - 22, Vec2::ANCHOR_TOP_LEFT);
	edge1->setScaleX((MINI_MAP_WIDTH - 10.0f) / 400);
	addChild(edge1);

	auto edge2 = getSprite("minimap/edge/e2_1-1.png", POSITION_X + 5, POSITION_Y - MINI_MAP_MEDIUM_HEIGHT - 27, Vec2::ANCHOR_TOP_LEFT);
	edge2->setScaleX((MINI_MAP_WIDTH - 10.0f) / 400);
	addChild(edge2);

	auto edge3 = getSprite("minimap/edge/e3_1-1.png", POSITION_X, POSITION_Y - 28, Vec2::ANCHOR_TOP_LEFT);
	edge3->setScaleY((MINI_MAP_MEDIUM_HEIGHT + 0.0f)/ 400);
	addChild(edge3);

	auto edge4 = getSprite("minimap/edge/e4_1-1.png", POSITION_X + 195, POSITION_Y - 28, Vec2::ANCHOR_TOP_LEFT);
	edge4->setScaleY((MINI_MAP_MEDIUM_HEIGHT + 0.0f) / 400);
	addChild(edge4);

	return true;
}