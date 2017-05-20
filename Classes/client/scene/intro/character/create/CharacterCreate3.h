#pragma once
#ifndef _CHARACTER_CREATE3_SCENE_H_
#define _CHARACTER_CREATE3_SCENE_H_

#include "cocos2d.h"
#include "CharacterCreateBase.h"
#include "ui\UIButton.h"
#include "client\misc\PlayerData.h"
#include "client\misc\character\RoleModel.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

#define NUM_FRAMES_SEXUAL		2;
#define NUM_FRAMES_MALE_HAIR	6;
#define NUM_FRAMES_MALE_EYE		6;
#define NUM_FRAMES_FEMALE_HAIR	9;
#define NUM_FRAMES_FEMALE_EYE	6;

class CharacterCreate3 : public cocos2d::Layer, CharacterCreateBase
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(CharacterCreate3);

	virtual void update(float dt);

	static E_PLAYER_JOB getPlayerJob();
	static void setPlayerJob(E_PLAYER_JOB playerJob);

protected:
	void onPreButtonClick() override;
	void onNextButtonClick() override;

private:
	void loadRoleResources();
	static E_PLAYER_JOB job;
	Button* createBtn;
	RoleModel* roleModel;

	Sprite* sexTextSprite;
	Sprite* eyeTextSprite;
	Sprite* hairTextSprite;
	E_PLAYER_SEX sexual;

	int currentSexIndex;
	int currentEyeIndex;
	int currentHairIndex;

	void onSexButtonClick(int inc);
	void onEyeButtonClick(int inc);
	void onHairButtonClick(int inc);

	void updateSexTextSprite();
	void updateEyeTextSprite(bool reset = false);
	void updateHairTextSprite(bool reset = false);

};
#endif