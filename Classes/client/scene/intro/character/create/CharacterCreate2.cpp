#include "CharacterCreate2.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\scene\intro\character\create\CharacterCreate1.h"
#include "client\scene\intro\character\create\CharacterCreate3.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

E_PLAYER_HUDDLE CharacterCreate2::huddle = HUDDLE_NONE;

Scene* CharacterCreate2::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterCreate2::create();
	scene->addChild(layer);
	return scene;
}

void CharacterCreate2::setPlayerHuddle(E_PLAYER_HUDDLE playerHuddle)
{
	huddle = playerHuddle;
}

E_PLAYER_HUDDLE CharacterCreate2::getPlayerHuddle()
{
	return huddle;
}

// on "init" you need to initialize your instance
bool CharacterCreate2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	addBackgroundToLayer(this);
	addHuddleBackgroundToLayer(this, huddle);

	addChild(initJobButton(JOB_SWORDMAN, "jb1"));
	addChild(initJobButton(JOB_BOWMAN, "jb2"));
	addChild(initJobButton(JOB_MAGICIAN, "jb3"));
	addChild(initJobButton(JOB_TRANSFORMER, "jb4"));
	addChild(getSprite("charcreate/create3/zhiye_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT));

	swirlSprite = getSprite("charcreate/create3/swirl_1-1.png", 89, designResolutionSize.height - 120, Vec2::ANCHOR_TOP_LEFT);
	swirlSprite->setVisible(false);
	addChild(swirlSprite);

	addPreButtonToLayer(this);
	addNextButtonToLayer(this, false);
	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate2::setJobDescSprite(E_PLAYER_JOB job)
{
	string jobDescFile = "";
	switch (job)
	{
		case JOB_SWORDMAN:
			jobDescFile = "charcreate/create3/desc_1-1.png";
			break;
		case JOB_BOWMAN:
			jobDescFile = "charcreate/create3/desc_1-2.png";
			break;
		case JOB_MAGICIAN:
			jobDescFile = "charcreate/create3/desc_1-3.png";
			break;
		case JOB_TRANSFORMER:
			jobDescFile = "charcreate/create3/desc_1-4.png";
			break;
		default:
			break;
	}

	if (jobDescFile != "")
	{
		if (jobDescSprite)
		{
			jobDescSprite->setSpriteFrame(getSpriteFrameByName(jobDescFile));
		}
		else
		{
			jobDescSprite = getSprite(jobDescFile, 320, designResolutionSize.height - 140, Vec2::ANCHOR_TOP_LEFT);
			addChild(jobDescSprite);
		}
	}
}

Button* CharacterCreate2::initJobButton(E_PLAYER_JOB job, string nodeName)
{
	Button* button = nullptr;
	
	switch (job)
	{
		case JOB_SWORDMAN:
			button = createButton(89, designResolutionSize.height - 320,
				"charcreate/create3/radio1_1-1.png", "charcreate/create3/radio1_1-2.png",
				"charcreate/create3/radio1_1-3.png", "", [this](Ref* sender) {
				refreshJobButtonStatus((Button*)sender, JOB_SWORDMAN);
			});
			break;
		case JOB_BOWMAN:
			button = createButton(140, designResolutionSize.height - 371,
				"charcreate/create3/radio2_1-1.png", "charcreate/create3/radio2_1-2.png",
				"charcreate/create3/radio2_1-3.png", "", [this](Ref* sender) {
				refreshJobButtonStatus((Button*)sender, JOB_BOWMAN);
			});
			break;
		case JOB_MAGICIAN:
			button = createButton(212, designResolutionSize.height - 371,
				"charcreate/create3/radio3_1-1.png", "charcreate/create3/radio3_1-2.png",
				"charcreate/create3/radio3_1-3.png", "", [this](Ref* sender) {
				refreshJobButtonStatus((Button*)sender, JOB_MAGICIAN);
			});
			break;
		case JOB_TRANSFORMER:
			button = createButton(263, designResolutionSize.height - 320,
				"charcreate/create3/radio4_1-1.png", "charcreate/create3/radio4_1-2.png",
				"charcreate/create3/radio4_1-3.png", "", [this](Ref* sender) {
				refreshJobButtonStatus((Button*)sender, JOB_TRANSFORMER);
			});
			break;
		default:
			break;
	}

	if (button)
	{
		button->setName(nodeName);
	}

	return button;
}

void CharacterCreate2::refreshJobButtonStatus(Button* currentToggleButton, E_PLAYER_JOB job)
{
	if (currentToggleButton)
	{
		for (int i = 1; i <= 4; i++)
		{
			Node* node = getChildByName("jb" + to_string(i));
			if (node)
			{
				Button* button = (Button*)node;
				button->setClicked(false);
			}
		}

		if (!nextButton->isBright())
		{
			nextButton->setBright(true);
		}

		setJobDescSprite(job);
		currentToggleButton->setClicked(true);
		selectedJob = job;
	}
}

void CharacterCreate2::onPreButtonClick()
{
	if (!proceeding)
	{
		Director::getInstance()->replaceScene(CharacterCreate1::createScene());
	}
}

void CharacterCreate2::onLoadResourceCallback(Texture2D* texture)
{
	log(texture->getName());
}

void CharacterCreate2::onNextButtonClick()
{
	if (swirlSprite->getNumberOfRunningActions() == 0)
	{
		asyncLoadResources("MotionData_Role/BODY_begin_000001-{n}.pvr.ccz", 0, 2, 
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/BODY_begin_000003-{n}.pvr.ccz", 0, 2,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/LEG_begin_000002-{n}.pvr.ccz", 0, 2,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/LEG_begin_000004-{n}.pvr.ccz", 0, 2,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/FEET_begin_000005-{n}.pvr.ccz", 0, 2,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/FEET_begin_000006-{n}.pvr.ccz", 0, 2,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/FACE_face_011-{n}.pvr.ccz", 0, 0, 
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/INNERHAIR_innerhair_09-{n}.pvr.ccz", 0, 0,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));
		asyncLoadResources("MotionData_Role/OUTERHAIR_outerhair_09-{n}.pvr.ccz", 0, 0,
			CC_CALLBACK_1(CharacterCreate2::onLoadResourceCallback, this));

		proceeding = true;

		switch (selectedJob)
		{
			case JOB_SWORDMAN:
				swirlSprite->setPosition(89, designResolutionSize.height - 320);
				break;
			case JOB_BOWMAN:
				swirlSprite->setPosition(140, designResolutionSize.height - 371);
				break;
			case JOB_MAGICIAN:
				swirlSprite->setPosition(212, designResolutionSize.height - 371);
				break;
			case JOB_TRANSFORMER:
				swirlSprite->setPosition(263, designResolutionSize.height - 320);
				break;
			default:
				break;
		}

		swirlSprite->setVisible(true);
		swirlSprite->runAction(Sequence::create(
			Animate::create(createAnimation("charcreate/create3/swirl_1", 8, 0.4f, false, false)),
			CallFuncN::create(this, callfuncN_selector(CharacterCreate2::onAfterSelecteJob)), NULL
		));
	}
}

void CharacterCreate2::onAfterSelecteJob(Node * pSender)
{
	CharacterCreate3::setPlayerJob(selectedJob);
	Director::getInstance()->replaceScene(CharacterCreate3::createScene());
}

void CharacterCreate2::update(float dt)
{
	updateFomas(dt);
}