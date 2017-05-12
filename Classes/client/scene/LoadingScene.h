#pragma once
#ifndef _LOADING_SCENE_H_
#define _LOADING_SCENE_H_

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class LoadingScene : public cocos2d::Layer
{
public:

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene(string resourcePath, int targetScene);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LoadingScene);

	// loads the local resources
	void loadLocalResources(vector<string> resources);

protected:
	
	// function after scene enter
	virtual void onEnter();
	
	// callback function for async loading
	void onLoadResourceCallback(Texture2D* texture, string res);

private:

	// number of loaded resources
	int numLoadedRes;

	// number of total resources to load
	int numTotalRes;
};
#endif