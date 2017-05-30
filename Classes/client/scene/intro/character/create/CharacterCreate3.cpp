#include "CharacterCreate3.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\manager\RoleCreationManager.h"
#include "client\scene\intro\character\create\CharacterCreate2.h"
#include "client\Client.h"
#include "client\ui\ctrls\CursorTextField.h"
#include "client\misc\character\RoleModel.h"
#include "ui\UIButton.h"
#include "ui\UITextField.h"
#include <cmath>

USING_NS_CC;

E_PLAYER_JOB CharacterCreate3::job = JOB_NONE;

Scene* CharacterCreate3::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterCreate3::create();
	scene->addChild(layer);
	return scene;
}

E_PLAYER_JOB CharacterCreate3::getPlayerJob()
{
	return job;
}

void CharacterCreate3::setPlayerJob(E_PLAYER_JOB playerJob)
{
	job = playerJob;
}

// on "init" you need to initialize your instance
bool CharacterCreate3::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("ui/charcreate-{n}.plist");

	sexual = MALE;
	currentSexIndex = 1;
	currentEyeIndex = 1;
	currentHairIndex = 1;

	addBackgroundToLayer(this);
	addHuddleBackgroundToLayer(this, CharacterCreate2::getPlayerHuddle());
	addChild(getSprite("charcreate/create4/descback_1-1.png", 318, designResolutionSize.height - 132, Vec2::ANCHOR_TOP_LEFT));

	int jobIndex = 0;
	switch (job)
	{
		case JOB_SWORDMAN:
			addChild(getSprite("charcreate/create4/c1_1-1.png", 89, designResolutionSize.height - 320, Vec2::ANCHOR_TOP_LEFT));
			jobIndex = 1;
			break;
		case JOB_BOWMAN:
			addChild(getSprite("charcreate/create4/c2_1-1.png", 140, designResolutionSize.height - 371, Vec2::ANCHOR_TOP_LEFT));
			jobIndex = 2;
			break;
		case JOB_MAGICIAN:
			addChild(getSprite("charcreate/create4/c3_1-1.png", 212, designResolutionSize.height - 371, Vec2::ANCHOR_TOP_LEFT));
			jobIndex = 3;
			break;
		case JOB_TRANSFORMER:
			addChild(getSprite("charcreate/create4/c4_1-1.png", 263, designResolutionSize.height - 320, Vec2::ANCHOR_TOP_LEFT));
			jobIndex = 4;
			break;
		default:
			break;
	}

	if (jobIndex > 0)
	{
		addChild(getSprite("charcreate/create4/desc_1-" + to_string(jobIndex) + ".png", 318, designResolutionSize.height - 255, Vec2::ANCHOR_TOP_LEFT));
	}
	
	// sprites of sexual
	sexTextSprite = getSprite("charcreate/create4/xinbie_1-1.png", 456, designResolutionSize.height - 165, Vec2::ANCHOR_TOP_LEFT);
	addChild(createButton(386, designResolutionSize.height - 162, "charcreate/create4/left_1",  [this](Ref* sender) { onSexButtonClick(-1); }));
	addChild(createButton(560, designResolutionSize.height - 162, "charcreate/create4/right_1", [this](Ref* sender) { onSexButtonClick(1); }));
	addChild(sexTextSprite);

	// sprites of hairs
	hairTextSprite = getSprite("charcreate/create4/toufa1_1-1.png", 418, designResolutionSize.height - 195, Vec2::ANCHOR_TOP_LEFT);
	addChild(createButton(386, designResolutionSize.height - 192, "charcreate/create4/left_1",  [this](Ref* sender) { onHairButtonClick(-1); }));
	addChild(createButton(560, designResolutionSize.height - 192, "charcreate/create4/right_1", [this](Ref* sender) { onHairButtonClick(1);  }));
	addChild(hairTextSprite);

	// sprites of eye
	eyeTextSprite = getSprite("charcreate/create4/yan1_1-1.png", 418, designResolutionSize.height - 225, Vec2::ANCHOR_TOP_LEFT);
	addChild(createButton(386, designResolutionSize.height - 222, "charcreate/create4/left_1",  [this](Ref* sender) { onEyeButtonClick(-1); }));
	addChild(createButton(560, designResolutionSize.height - 222, "charcreate/create4/right_1", [this](Ref* sender) { onEyeButtonClick(1);  }));
	addChild(eyeTextSprite);

	nameInput = CursorTextField::textFieldWithPlaceHolder(" ");
	nameInput->setPosition(395, designResolutionSize.height - 139);
	nameInput->setDesignedSize(Size(170, 20));
	nameInput->setMaxLength(20);
	addChild(nameInput);

	addChild(getSprite("charcreate/create4/zhiye_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT));
	addPreButtonToLayer(this);

	createBtn = createButton(632, designResolutionSize.height - 530, "charcreate/create4/create_1", [this](Ref* sender) { }, false);
	addChild(createBtn);
	addFomasToLayer(this);

	this->loadRoleResources();
	
	/*
	roleModel = RoleModel::create();
	roleModel->setPosition(430, designResolutionSize.height - 30); 
	roleModel->playAnimation(STAND);
	addChild(roleModel);
	*/

	RoleCreationManager* rcm = new RoleCreationManager();
	rcm->initRole(job, MALE);

	this->roleModel = rcm->getRole();
	this->roleModel->show(430, designResolutionSize.height - 30);
	addChild(this->roleModel);

	addChild(getSprite("charcreate/create4/cloud_1-1.png", 570, designResolutionSize.height - 198, Vec2::ANCHOR_TOP_LEFT));

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate3::loadRoleResources()
{
	// initialize plist resources as pvr.ccz was loaded in previous scene 
	preLoadResources("MotionData_Role/BODY_begin_000001-{n}.plist", 0, 2);
	//preLoadResources("MotionData_Role/BODY_begin_000003-{n}.plist", 0, 2);
	preLoadResources("MotionData_Role/LEG_begin_000002-{n}.plist",  0, 2);
	//preLoadResources("MotionData_Role/LEG_begin_000004-{n}.plist",  0, 2);
	preLoadResources("MotionData_Role/FEET_begin_000005-{n}.plist", 0, 2);
	//preLoadResources("MotionData_Role/FEET_begin_000006-{n}.plist", 0, 2);
	preLoadResources("MotionData_Role/FACE_face_011-{n}.plist");				// eye
	preLoadResources("MotionData_Role/INNERHAIR_innerhair_01-{n}.plist");
	preLoadResources("MotionData_Role/OUTERHAIR_outerhair_01-{n}.plist");
	preLoadResources("MotionData_Role/BANG_bang_01-{n}.plist"); 
}

void CharacterCreate3::onSexButtonClick(int inc)
{
	currentSexIndex = abs(currentSexIndex + inc) % NUM_FRAMES_SEXUAL;
	if (currentSexIndex == 0)
	{
		currentSexIndex = NUM_FRAMES_SEXUAL;
	}

	sexual = (currentSexIndex == 1 ? MALE : FEMALE);
	updateSexTextSprite();
}

void CharacterCreate3::onEyeButtonClick(int inc)
{
	int frames;
	switch (sexual)
	{
		case FEMALE:
			frames = NUM_FRAMES_FEMALE_EYE;
			break;
		case MALE:
			frames = NUM_FRAMES_MALE_EYE;
			break;
		default:
			break;
	}

	currentEyeIndex = abs(currentEyeIndex + inc) % frames;
	if (currentEyeIndex == 0)
	{
		currentEyeIndex = frames;
	}

	updateEyeTextSprite();
}

void CharacterCreate3::onHairButtonClick(int inc)
{
	int frames;
	switch (sexual)
	{
		case FEMALE:
			frames = NUM_FRAMES_FEMALE_HAIR;
			break;
		case MALE:
			frames = NUM_FRAMES_MALE_HAIR;
			break;
		default:
			break;
	}

	currentHairIndex = abs(currentHairIndex + inc) % frames;
	if (currentHairIndex == 0)
	{
		currentHairIndex = frames;
	}

	updateHairTextSprite();
}

void CharacterCreate3::updateSexTextSprite() 
{
	sexTextSprite->setSpriteFrame("charcreate/create4/xinbie_1-" + to_string(currentSexIndex) + ".png");
	updateEyeTextSprite(true);
	updateHairTextSprite(true);
}

static int getSexualCodeByType(E_PLAYER_SEX type)
{
	int code;
	switch (type)
	{
		case FEMALE:
			code = 2;
			break;
		case MALE:
			code = 1;
			break;
		default:
			code = 1;
			break;
	}

	return code;
}

void CharacterCreate3::updateEyeTextSprite(bool reset)
{
	int sexualCode = getSexualCodeByType(sexual);
	if (reset)
	{
		currentEyeIndex = 1;
	}

	eyeTextSprite->setSpriteFrame("charcreate/create4/yan" + to_string(sexualCode ) + "_1-" + to_string(currentEyeIndex) + ".png");

	this->roleModel->updateDress(EYE, (sexual == MALE ? MALE_FACE[currentEyeIndex - 1] : FEMALE_FACE[currentEyeIndex - 1]));
}

void CharacterCreate3::updateHairTextSprite(bool reset)
{
	int sexualCode = getSexualCodeByType(sexual);
	if (reset)
	{
		currentHairIndex = 1;
	}

	hairTextSprite->setSpriteFrame("charcreate/create4/toufa" + to_string(sexualCode) + "_1-" + to_string(currentHairIndex) + ".png");

	this->roleModel->updateDress(HAIR_BANG1, (sexual == MALE ? MALE_HAIR_BANG1[currentHairIndex - 1] : FEMALE_HAIR_BANG1[currentHairIndex - 1]));
	this->roleModel->updateDress(HAIR_BANG2, (sexual == MALE ? MALE_HAIR_BANG2[currentHairIndex - 1] : FEMALE_HAIR_BANG2[currentHairIndex - 1]));
	this->roleModel->updateDress(HAIR_INNERHAIR, (sexual == MALE ? MALE_HAIR_INNER[currentHairIndex - 1] : FEMALE_HAIR_INNER[currentHairIndex - 1]));
	this->roleModel->updateDress(HAIR_OUTERHAIR, (sexual == MALE ? MALE_HAIR_OUTER[currentHairIndex - 1] : FEMALE_HAIR_OUTER[currentHairIndex - 1]));
}

void CharacterCreate3::onPreButtonClick()
{
	Director::getInstance()->replaceScene(CharacterCreate2::createScene());
}

void CharacterCreate3::onNextButtonClick()
{
}

void CharacterCreate3::update(float dt)
{
	updateFomas(dt);
}