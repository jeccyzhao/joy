#include "UI_NpcBubbleLayer.h"

NpcBubbleLayer::NpcBubbleLayer() {}
NpcBubbleLayer::~NpcBubbleLayer() {}

bool NpcBubbleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}