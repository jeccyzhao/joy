#pragma once
#ifndef _INTRO_BASE_SCENE_H_
#define _INTRO_BASE_SCENE_H_

#include "cocos2d.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class IntroSceneBase
{
public:
	IntroSceneBase();
	~IntroSceneBase();
protected:
	Vector<Sprite*> fomas;
	void updateFomas(float dt);
	void addFomasToLayer(Layer* layer);
	void addBackgroundToLayer(Layer* layer);
};

#endif
