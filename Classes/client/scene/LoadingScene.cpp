#include "LoadingScene.h"
#include "client\Client.h"
#include "client\scene\intro\advice\AdviceScene.h"
#include "client\scene\intro\character\create\CharacterCreate1.h"
#include "client\manager\CursorManager.h"

USING_NS_CC;

static string resourcePath = "";

Scene* LoadingScene::createScene(string res, int targetScene)
{
	resourcePath = res;

	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool LoadingScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	
	auto background = Sprite::create("res/loading.jpg");
	if (background)
	{
		background->setAnchorPoint(Vec2::ZERO);
		background->setPosition(0, 0);
		this->addChild(background, 0);
	}

	//CursorManager::Get()->addCursorToLayer(this);
	//schedule(schedule_selector(LoadingScene::update));

	return true;
}

void LoadingScene::onEnter()
{
	// init the counts
	numLoadedRes = 0;

	vector<string> resources;
	if (FileUtils::getInstance()->isFileExist(resourcePath))
	{
		resources.push_back(resourcePath);
	}
	else
	{
		for (int i = 0; i < MAXIMUM_PLIST_ITERATION; i++)
		{
			string fileName = resourcePath + to_string(i) + ".plist";
			if (FileUtils::getInstance()->isFileExist(fileName))
			{
				numTotalRes++;
				resources.push_back(resourcePath + to_string(i));
			}
		}
	}

	this->loadLocalResources(resources);
}

void LoadingScene::loadLocalResources(vector<string> resources)
{
	for (string resource : resources)
	{
		TextureCache::getInstance()->addImageAsync(resource + ".pvr.ccz",
			CC_CALLBACK_1(LoadingScene::onLoadResourceCallback, this, resource));
	}
}

void LoadingScene::onLoadResourceCallback(Texture2D* texture, string res)
{
	numLoadedRes++;
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(res + string(".plist"), texture);

	if (numLoadedRes == numTotalRes)
	{
		log("Resources loaded successfully");

		// clean up
		resourcePath = "";
		numLoadedRes = 0;
		numTotalRes = 0;

		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, CharacterCreate1::createScene()));
	}
}