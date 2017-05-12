#include "IntroSceneBase.h"
#include "engine\util\GameUtils.h"
#include "client\manager\CursorManager.h"
#include "client\Client.h"
#include "ui\UIButton.h"

USING_NS_CC;

IntroSceneBase::~IntroSceneBase()
{
	fomas.clear();
}

IntroSceneBase::IntroSceneBase()
{
	fomas.pushBack(getSprite("stage1/piaoyun2_1-1.png", 550, 0));
	fomas.pushBack(getSprite("stage1/piaoyun3_1-1.png", 525, 0));
	fomas.pushBack(getSprite("stage1/piaoyun3_1-1.png", 100, 0));
}

void IntroSceneBase::addFomasToLayer(Layer* layer)
{
	for (int i = 0; i < fomas.size(); i++)
	{
		layer->addChild(fomas.at(i));
	}
}

void IntroSceneBase::addBackgroundToLayer(Layer* layer)
{
	layer->addChild(getSprite("stage1/bg_1-1.png"));
	layer->addChild(getSprite("stage1/long_1-1.png"));
}

void IntroSceneBase::updateFomas(float dt)
{
	Sprite* foma1 = fomas.at(0);
	foma1->setPosition(foma1->getPosition().x, foma1->getPosition().y + 1);
	if (foma1->getPosition().y > 700)
	{
		foma1->setPosition(foma1->getPosition().x, 0);
	}

	Sprite* foma2 = fomas.at(1);
	foma2->setPosition(foma2->getPosition().x, foma2->getPosition().y + 0.8);
	if (foma2->getPosition().y > 1200)
	{
		foma2->setPosition(foma2->getPosition().x, 0);
	}

	Sprite* foma3 = fomas.at(2);
	foma3->setPosition(foma3->getPosition().x, foma3->getPosition().y + 1);
	if (foma3->getPosition().y > 1200)
	{
		foma3->setPosition(foma3->getPosition().x, 0);
	}
}