#pragma once
#ifndef _CHARACTER_CREATE1_SCENE_H_
#define _CHARACTER_CREATE1_SCENE_H_

#include "cocos2d.h"
#include "CharacterCreateBase.h"
#include "ui\UIButton.h"
#include "client\misc\PlayerData.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class CharacterCreate1 : public cocos2d::Layer, CharacterCreateBase
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(CharacterCreate1);

	virtual void update(float dt);

protected:
	void onPreButtonClick() override;
	void onNextButtonClick() override;
	E_PLAYER_HUDDLE selectedHuddle;

private:
	void updateButtonStatus(Ref* triggerButton, string revertButtonTagName);
};
#endif