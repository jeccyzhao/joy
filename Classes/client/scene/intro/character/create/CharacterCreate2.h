#pragma once
#ifndef _CHARACTER_CREATE2_SCENE_H_
#define _CHARACTER_CREATE2_SCENE_H_

#include "cocos2d.h"
#include "ui\UIButton.h"
#include "CharacterCreateBase.h"
#include "client\misc\PlayerData.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class CharacterCreate2 : public cocos2d::Layer, CharacterCreateBase
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(CharacterCreate2);

	virtual void update(float dt);

	static E_PLAYER_HUDDLE getPlayerHuddle();
	static void setPlayerHuddle(E_PLAYER_HUDDLE playerHuddle);

protected:
	void onPreButtonClick() override;
	void onNextButtonClick() override;

private:
	static E_PLAYER_HUDDLE huddle; 
	void refreshJobButtonStatus(Button* currentToggleButton, E_PLAYER_JOB job);
	void setJobDescSprite(E_PLAYER_JOB job);
	Button* initJobButton(E_PLAYER_JOB job, string nodeName);
	Sprite* jobDescSprite;
	Sprite* swirlSprite;
	Animation* swirlAnimation;
	E_PLAYER_JOB selectedJob;
	void onAfterSelecteJob(Node * pSender);
	bool proceeding;
	void onLoadResourceCallback(Texture2D* texture);
};
#endif