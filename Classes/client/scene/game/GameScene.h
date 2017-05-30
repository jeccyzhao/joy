#pragma once
#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include <cocos2d.h>
#include "client/ui/layer/UI_SysMenuLayer.h"
#include "client/ui/layer/UI_MiniMapLayer.h"
#include "client/ui/layer/UI_MapLayer.h"
#include "client/ui/layer/UI_ToolBarLayer.h"
#include "client/ui/layer/UI_PlayerTagLayer.h"
#include "client/ui/layer/UI_LoadingLayer.h"
#include "client/ui/layer/LayerConstants.h"
#include "client/ui/ctrls/CursorTextField.h"
#include "client/manager/CursorManager.h"
#include "client/Client.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	void update(float dt) override;
private:
	MiniMapLayer*		m_miniMapLayer;
	SystemMenuLayer*	m_sysMenuLayer;
	MapLayer*			m_mapLayer;
	ToolBarLayer*		m_toolBarLayer;
	PlayerTagLayer*		m_playerTagLayer;
	LoadingLayer*		m_loadingLayer;
};

#endif