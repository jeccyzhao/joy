#include "LoadingLayer.h"
#include "engine\util\GameUtils.h"

LoadingLayer::LoadingLayer() {}
LoadingLayer::~LoadingLayer() {}

bool LoadingLayer::init()
{
	m_bgSprite = Sprite::create("res/loading-" + to_string(random(0, 10)) + ".png");
	if (m_bgSprite)
	{
		m_bgSprite->setAnchorPoint(Vec2::ZERO);
		m_bgSprite->setPosition(0, 0);
		this->addChild(m_bgSprite);
	}

	return true;
}

void LoadingLayer::update(float dt) 
{
	if (!m_hide)
	{
		m_hide = true;
		
		// TODO: hide from paraent layer
	}
}

void LoadingLayer::ShowLoading(bool isShowOnly /* = false */) 
{
	// change background with another random texture
	auto newBgSprite = getSprite("res/loading-" + to_string(random(0, 10)) + ".png");
	if (newBgSprite)
	{
		m_bgSprite->setSpriteFrame(newBgSprite->getSpriteFrame());
	}

	this->setVisible(true);
	if (false == isShowOnly)
	{
		m_hide = false;
		scheduleOnce(schedule_selector(LoadingLayer::update), 0.01f);
	}
}

void LoadingLayer::HideLoading() 
{
	this->setVisible(false);
	m_hide = true;
}