#include "GameScene.h"
#include "Client/Client.h"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene()
{
	auto scene = GameScene::createWithPhysics();
	if (DEBUG_DRAW)
	{
		scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	}
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	return true;
}