#include "CursorManager.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"
#include "client\assert\AssertResource.h"

CursorManager::CursorManager()
{
	m_cursorSprite = nullptr;
	init();
}

void CursorManager::setCursor(CursorIconType iconType)
{
	if (m_cursorIconType != iconType)
	{
		m_cursorIconType = iconType;
		auto cursorInfo = getCursorIconData(iconType);
		if (cursorInfo.animation)
		{
			Animation* animation = createAnimation(cursorInfo.spriteName, cursorInfo.frames, 0.5f);
			auto sprite = getSprite(cursorInfo.spriteName + "-1.png");
			sprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
			sprite->runAction(Animate::create(animation));

			if (m_cursorSprite == nullptr)
			{
				sprite->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
			}

			m_cursorSprite = sprite;
		}
	}
}

Sprite* CursorManager::getCursorSprite()
{
	return m_cursorSprite;
}

void CursorManager::addCursorToLayer(Layer* layer)
{
	if (m_cursorSprite != nullptr)
	{
		bool isRetained = false;
		if (m_cursorSprite->getParent() != nullptr)
		{
			m_cursorSprite->retain();
			m_cursorSprite->getParent()->removeChild(m_cursorSprite, false);
			isRetained = true;
		}

		layer->addChild(this->m_cursorSprite, 10000);
		if (isRetained)
		{
			m_cursorSprite->release();
		}

	}
}

CursorIconData CursorManager::getCursorIconData(CursorIconType iconType)
{
	switch (iconType)
	{
		case CURSOR_NORMAL:
			return CursorIconData(CURSOR_ICON_NORMAL, 2, true, true);
		case CURSOR_ATTACK:
			return CursorIconData(CURSOR_ICON_ATTACK, 2, true, true);
		case CURSOR_BUY:
			return CursorIconData(CURSOR_ICON_BUY, 2, true, true);
		case CURSOR_TALK:
			return CursorIconData(CURSOR_ICON_NPC, 2, true, true);
		default:
			return CursorIconData(CURSOR_ICON_NORMAL, 2, true, true);
	}
}

void CursorManager::init()
{
	preLoadResources(CURSOR_RESOURCE_BUNDLES);

	this->setCursor(CURSOR_NORMAL);

	m_mouseListener = EventListenerMouse::create();
	m_mouseListener->onMouseMove = [&](cocos2d::EventMouse* event)
	{
		if (m_cursorSprite)
		{
			Point mouse = event->getLocation();
			mouse.y = designResolutionSize.height - mouse.y;
			m_cursorSprite->setPosition(Point(mouse.x, mouse.y));
		}
	};
	
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_mouseListener, m_cursorSprite);
}

CursorManager::~CursorManager()
{
}