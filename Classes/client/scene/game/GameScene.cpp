#include "GameScene.h"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	auto layer = GameScene::create();

	scene->addChild(layer);

	if (DEBUG_DRAW)
	{
		scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	}

	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->m_sysMenuLayer = SystemMenuLayer::create();
	this->m_miniMapLayer = MiniMapLayer::create();
	this->m_mapLayer = MapLayer::create();
	this->m_mapLayer->loadMap("home");

	addChild(m_mapLayer, 9998);
	addChild(m_sysMenuLayer, 9999);
	addChild(m_miniMapLayer, 9999);

	CursorManager::Get()->addCursorToLayer(this);

	return true;
}

void GameScene::update(float dt)
{

}