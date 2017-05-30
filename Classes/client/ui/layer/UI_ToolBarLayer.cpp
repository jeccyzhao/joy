#include "UI_ToolBarLayer.h"

ToolBarLayer::ToolBarLayer() {}
ToolBarLayer::~ToolBarLayer() {}

bool ToolBarLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/mainui-{n}.plist");

	addChild(getSprite("mainui/mainui_1-1.png", 0, designResolutionSize.height - 450, Vec2::ANCHOR_TOP_LEFT));

	addChild(createButton(474, designResolutionSize.height - 567,
		"mainui/button/expbtn_1-1.png", "mainui/button/expbtn_1-2.png", "mainui/button/expbtn_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(2, designResolutionSize.height - 568,
		"mainui/button/channelbtn_1-1.png", "mainui/button/channelbtn_1-2.png", "mainui/button/channelbtn_1-3.png", "", [this](Ref* sender) {
	}));
	addChild(createButton(496, designResolutionSize.height - 567,
		"mainui/button/chatup_1-1.png", "mainui/button/chatup_1-2.png", "mainui/button/chatup_1-3.png", "", [this](Ref* sender) {
	}));
	
	//addChild(createButton(496, designResolutionSize.height - 567,
	//	"mainui/button/chatdown_1-1.png", "mainui/button/chatdown_1-2.png", "mainui/button/chatdown_1-3.png", "", [this](Ref* sender) {
	//}));

	addChild(createButton(772, designResolutionSize.height - 522,
		"mainui/button/mail_1-1.png", "mainui/button/mail_1-2.png", "mainui/button/mail_1-3.png", "", [this](Ref* sender) {
	}));

	addChild(createButton(764, designResolutionSize.height - 490,
		"mainui/button/skillmenu_1-1.png", "mainui/button/skillmenu_1-2.png", "mainui/button/skillmenu_1-3.png", "", [this](Ref* sender) {
	}));

	return true;
}