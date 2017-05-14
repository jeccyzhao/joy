#include "CharacterCreate2.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\scene\intro\character\create\CharacterCreate1.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

ePlayerHuddle CharacterCreate2::huddle = HUDDLE_NONE;

Scene* CharacterCreate2::createScene()
{
	auto scene = Scene::create();
	auto layer = CharacterCreate2::create();
	scene->addChild(layer);
	return scene;
}

void CharacterCreate2::setPlayerHuddle(ePlayerHuddle playerHuddle)
{
	huddle = playerHuddle;
}

ePlayerHuddle CharacterCreate2::getPlayerHuddle()
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

	Sprite* efxSprite;

	switch (huddle)
	{
		case HUDDLE_BUD:
			addChild(getSprite("charcreate/create3/back_fo_1-1.png"));
			efxSprite = getSprite("charcreate/create3/efx_fo_1-1.png", 124, designResolutionSize.height - 228, Vec2::ANCHOR_TOP_LEFT);
			efxSprite->runAction(Animate::create(createAnimation("charcreate/create3/efx_fo_1", 4, 0.5f)));
			break;
		case HUDDLE_EVIL:
			addChild(getSprite("charcreate/create3/back_mo_1-1.png"));
			efxSprite = getSprite("charcreate/create3/efx_mo_1-1.png", 98, designResolutionSize.height - 217, Vec2::ANCHOR_TOP_LEFT);
			efxSprite->runAction(Animate::create(createAnimation("charcreate/create3/efx_mo_1", 4, 0.5f)));
			break;
		default:
			break;
	}

	if (efxSprite)
	{
		addChild(efxSprite);
	}

	addChild(initJobButton(JOB_SWORDMAN, "jb1"));
	addChild(initJobButton(JOB_BOWMAN, "jb2"));
	addChild(initJobButton(JOB_MAGICIAN, "jb3"));
	addChild(initJobButton(JOB_TRANSFORMER, "jb4"));

	addChild(getSprite("charcreate/create3/zhiye_1-1.png", 0, designResolutionSize.height, Vec2::ANCHOR_TOP_LEFT));

	addPreButtonToLayer(this);
	addNextButtonToLayer(this, false);
	addFomasToLayer(this);

	CursorManager::Get()->addCursorToLayer(this);
	scheduleUpdate();

	return true;
}

void CharacterCreate2::setJobDescSprite(ePlayerJob job)
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
			jobDescSprite->setDisplayFrame(getSpriteFrameByName(jobDescFile));
		}
		else
		{
			jobDescSprite = getSprite(jobDescFile, 320, designResolutionSize.height - 140, Vec2::ANCHOR_TOP_LEFT);
			addChild(jobDescSprite);
		}
	}
}

Button* CharacterCreate2::initJobButton(ePlayerJob job, string nodeName)
{
	Button* button = nullptr;
	
	switch (job)
	{
		case JOB_SWORDMAN:
			button = createButton(89, designResolutionSize.height - 320,
				"charcreate/create3/radio1_1-1.png", "charcreate/create3/radio1_1-2.png",
				"charcreate/create3/radio1_1-3.png", "", [this](Ref* sender) {
				setJobDescSprite(JOB_SWORDMAN);
				refreshJobButtonStatus((Button*)sender);
			});
			break;
		case JOB_BOWMAN:
			button = createButton(140, designResolutionSize.height - 371,
				"charcreate/create3/radio2_1-1.png", "charcreate/create3/radio2_1-2.png",
				"charcreate/create3/radio2_1-3.png", "", [this](Ref* sender) {
				setJobDescSprite(JOB_BOWMAN);
				refreshJobButtonStatus((Button*)sender);
			});
			break;
		case JOB_MAGICIAN:
			button = createButton(212, designResolutionSize.height - 371,
				"charcreate/create3/radio3_1-1.png", "charcreate/create3/radio3_1-2.png",
				"charcreate/create3/radio3_1-3.png", "", [this](Ref* sender) {
				setJobDescSprite(JOB_MAGICIAN);
				refreshJobButtonStatus((Button*)sender);
			});
			break;
		case JOB_TRANSFORMER:
			button = createButton(263, designResolutionSize.height - 320,
				"charcreate/create3/radio4_1-1.png", "charcreate/create3/radio4_1-2.png",
				"charcreate/create3/radio4_1-3.png", "", [this](Ref* sender) {
				setJobDescSprite(JOB_TRANSFORMER);
				refreshJobButtonStatus((Button*)sender);
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

void CharacterCreate2::refreshJobButtonStatus(Button* currentToggleButton)
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

		currentToggleButton->setClicked(true);
	}
}

void CharacterCreate2::onPreButtonClick()
{
	Director::getInstance()->replaceScene(CharacterCreate1::createScene());
}

void CharacterCreate2::onNextButtonClick()
{
}

void CharacterCreate2::update(float dt)
{
	updateFomas(dt);
}