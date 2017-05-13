#include "CharacterCreateBase.h"
#include "engine\util\GameUtils.h"
#include "client\Client.h"

void CharacterCreateBase::addPreButtonToLayer(Layer* layer, bool bright)
{
	preButton = createButton(632, designResolutionSize.height - 481, "charcreate/create3/prev_1", [this](Ref* sender) { onPreButtonClick();});
	preButton->setBright(bright);

	layer->addChild(preButton);
}

void CharacterCreateBase::addNextButtonToLayer(Layer* layer, bool bright)
{
	nextButton = createButton(632, designResolutionSize.height - 530, "charcreate/create3/next_1", [this](Ref* sender) { onNextButtonClick(); });
	nextButton->setBright(bright);
	layer->addChild(nextButton);
}

void CharacterCreateBase::onPreButtonClick() {}
void CharacterCreateBase::onNextButtonClick() {}