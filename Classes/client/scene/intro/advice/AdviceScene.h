#pragma once
#ifndef _ADVICE_SCENE_H_
#define _ADVICE_SCENE_H_

#include "cocos2d.h"
#include "client\scene\intro\IntroSceneBase.h"

USING_NS_CC;
using namespace std;

class AdviceScene : public cocos2d::Layer, IntroSceneBase
{
public:
	~ AdviceScene();

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(AdviceScene);

	virtual void update(float dt);

protected:
	void onSceneFaded(float dt);
	void onMouseClick(Event *event);
private:
	bool isSceneFaded;

};
#endif