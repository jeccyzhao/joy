#pragma once

#include "cocos2d.h"
#include "engine\Singleton.h"
#include "client\misc\CursorData.h"
#include "client\Client.h"

USING_NS_CC;

class CursorManager : public TSingleton<CursorManager>
{
public:
	CursorManager();
	~CursorManager();
	void init();
	void setCursor(CursorIconType iconType);
	void addCursorToLayer(Layer* layer);
	Sprite* getCursorSprite();
private:
	Sprite* m_cursorSprite;
	Animation* m_cursorAnimation;
	CursorIconType m_cursorIconType;
	EventListenerMouse* m_mouseListener;
	CursorIconData getCursorIconData(CursorIconType iconType);
};