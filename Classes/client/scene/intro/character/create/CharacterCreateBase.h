#pragma once
#ifndef _CHARACTER_CREATE_BASE_SCENE_H_
#define _CHARACTER_CREATE_BASE_SCENE_H_

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "client\scene\intro\IntroSceneBase.h"
#include "client\misc\PlayerData.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class CharacterCreateBase : public IntroSceneBase
{
protected:
	Button* preButton;
	Button* nextButton;
	void addPreButtonToLayer(Layer* layer, bool bright = true);
	void addNextButtonToLayer(Layer* layer, bool bright = false);
	virtual void onPreButtonClick();
	virtual void onNextButtonClick();
	void addHuddleBackgroundToLayer(Layer* layer, E_PLAYER_HUDDLE huddle);
private:
	Sprite* efxSprite;
	Sprite* huddleBackSprite;
};
#endif