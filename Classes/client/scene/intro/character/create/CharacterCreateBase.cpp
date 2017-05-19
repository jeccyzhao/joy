#include "CharacterCreateBase.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"

void CharacterCreateBase::addPreButtonToLayer(Layer* layer, bool bright)
{
	preButton = createButton(632, designResolutionSize.height - 481, "charcreate/create3/prev_1", [this](Ref* sender) { onPreButtonClick();}, bright);
	layer->addChild(preButton);
}

void CharacterCreateBase::addNextButtonToLayer(Layer* layer, bool bright)
{
	nextButton = createButton(632, designResolutionSize.height - 530, "charcreate/create3/next_1", [this](Ref* sender) { onNextButtonClick(); }, bright);
	layer->addChild(nextButton);
}

void CharacterCreateBase::addHuddleBackgroundToLayer(Layer* layer, E_PLAYER_HUDDLE huddle)
{
	switch (huddle)
	{
		case HUDDLE_BUD:
			layer->addChild(getSprite("charcreate/create3/back_fo_1-1.png"));
			efxSprite = getSprite("charcreate/create3/efx_fo_1-1.png", 124, designResolutionSize.height - 228, Vec2::ANCHOR_TOP_LEFT);
			efxSprite->runAction(Animate::create(createAnimation("charcreate/create3/efx_fo_1", 4, 0.5f)));
			break;
		case HUDDLE_EVIL:
			layer->addChild(getSprite("charcreate/create3/back_mo_1-1.png"));
			efxSprite = getSprite("charcreate/create3/efx_mo_1-1.png", 98, designResolutionSize.height - 217, Vec2::ANCHOR_TOP_LEFT);
			efxSprite->runAction(Animate::create(createAnimation("charcreate/create3/efx_mo_1", 4, 0.5f)));
			break;
		default:
			break;
	}

	if (efxSprite)
	{
		layer->addChild(efxSprite);
	}
}

void CharacterCreateBase::onPreButtonClick() {}
void CharacterCreateBase::onNextButtonClick() {}