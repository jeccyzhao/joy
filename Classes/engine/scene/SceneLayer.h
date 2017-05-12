#pragma once
#ifndef _SCENE_LAYER_
#define _SCENE_LAYER_

#include "cocos2d.h"

#ifndef WIN32
#include <pthread.h>
#include <unistd.h>
#endif

using namespace cocos2d;

class SceneLayer : public cocos2d::Layer
{
public:
	SceneLayer();
	virtual ~SceneLayer();

	// implement the "static create()" method manually
	CREATE_FUNC(SceneLayer);

	// initialization
	virtual bool init();

	void addUiLayer(Layer * layer, float zOrder);

private:
};

#endif