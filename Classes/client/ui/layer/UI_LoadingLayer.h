#ifndef LOADING_LAYER_H
#define LOADING_LAYER_H

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class LoadingLayer : public cocos2d::Layer
{
public:
	LoadingLayer();
	virtual ~LoadingLayer();

	CREATE_FUNC(LoadingLayer);

	virtual bool init();

	void update(float dt);
	void ShowLoading(bool isShowOnly = false);
	void HideLoading();

private:
	bool m_hide;
	Sprite* m_bgSprite;
};

#endif