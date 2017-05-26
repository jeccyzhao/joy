#pragma once

#include "cocos2d.h"
#include "engine\Singleton.h"
#include "client\misc\CursorData.h"
#include "client\Client.h"

USING_NS_CC;

class DressUpManager : public TSingleton<DressUpManager>
{
public:
	DressUpManager();
	~DressUpManager();
private:
};