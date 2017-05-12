#pragma once
#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include <cocos2d.h>
USING_NS_CC;

class GameScene : public cocos2d::Scene
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif