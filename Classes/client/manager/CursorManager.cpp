#include "CursorManager.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"
#include "client\assert\AssertResource.h"

CursorManager::CursorManager()
{
	m_cursorSprite = nullptr;
	m_cursorIconType = NONE;
	init();
}

void CursorManager::setCursor(CursorIconType iconType)
{
	if (m_cursorIconType != iconType)
	{
		if (m_cursorIconType != NONE)
		{
			// stop actions on sprite before updating
			m_cursorSprite->stopAllActions();
		}

		m_cursorIconType = iconType;
		auto cursorInfo = getCursorIconData(iconType);
		if (cursorInfo.animation)
		{
			Animation* animation = createAnimation(cursorInfo.spriteName, cursorInfo.frames, 0.5f);
			if (m_cursorSprite == nullptr)
			{
				auto sprite = getSprite(cursorInfo.spriteName + "-1.png");
				sprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
				sprite->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2); 
				m_cursorSprite = sprite;
			}
			else
			{
				// replace using another cursor 
				m_cursorSprite->setSpriteFrame(getSpriteFrameByName(cursorInfo.spriteName + "-1.png"));
			}

			m_cursorSprite->runAction(Animate::create(animation));
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

		layer->addChild(this->m_cursorSprite, Z_ORDER_MOUSE);
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