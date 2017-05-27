#include "SystemMenuLayer.h"

SystemMenuLayer::SystemMenuLayer() {}
SystemMenuLayer::~SystemMenuLayer() {}

bool SystemMenuLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/mainui-{n}.plist");

	m_bgSprite = getSprite("mainui/sysmenu/back_1-1.png", 741, designResolutionSize.height - 164, Vec2::ANCHOR_TOP_LEFT);
	addChild(m_bgSprite);

	addChild(createButton(740, designResolutionSize.height - 165, 
		"mainui/sysmenu/login_1-1.png", "mainui/sysmenu/login_1-2.png", "mainui/sysmenu/login_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 196, 
		"mainui/sysmenu/setting_1-1.png", "mainui/sysmenu/setting_1-2.png", "mainui/sysmenu/setting_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 228, 
		"mainui/sysmenu/expression_1-1.png", "mainui/sysmenu/expression_1-2.png", "mainui/sysmenu/expression_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 257, 
		"mainui/sysmenu/map_1-1.png", "mainui/sysmenu/map_1-2.png", "mainui/sysmenu/map_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 286, 
		"mainui/sysmenu/guild_1-1.png", "mainui/sysmenu/guild_1-2.png", "mainui/sysmenu/guild_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 316, 
		"mainui/sysmenu/comm_1-1.png", "mainui/sysmenu/comm_1-2.png", "mainui/sysmenu/comm_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 345, 
		"mainui/sysmenu/quest_1-1.png", "mainui/sysmenu/quest_1-2.png", "mainui/sysmenu/quest_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 375, 
		"mainui/sysmenu/skill_1-1.png", "mainui/sysmenu/skill_1-2.png", "mainui/sysmenu/skill_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 404, 
		"mainui/sysmenu/item_1-1.png", "mainui/sysmenu/item_1-2.png", "mainui/sysmenu/item_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(740, designResolutionSize.height - 433, 
		"mainui/sysmenu/character_1-1.png", "mainui/sysmenu/character_1-2.png", "mainui/sysmenu/character_1-3.png", "", [this](Ref* sender) {
	}));

	return true;
}

