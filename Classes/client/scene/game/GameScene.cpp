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
	this->m_toolBarLayer = ToolBarLayer::create();
	this->m_mapLayer = MapLayer::create();
	this->m_mapLayer->loadMap("home");
	this->m_playerTagLayer = PlayerTagLayer::create();

	/*
	addChild(m_mapLayer,		UI_LAYER_MAP);
	addChild(m_sysMenuLayer,	UI_LAYER_MAINUI);
	addChild(m_miniMapLayer,	UI_LAYER_MAINUI);
	addChild(m_toolBarLayer,	UI_LAYER_MAINUI);
	addChild(m_playerTagLayer,	UI_LAYER_MAINUI);
	*/

	auto textFiled = CursorTextField::textFieldWithPlaceHolder(""); 
	textFiled->setPosition(100, 200);
	addChild(textFiled);

	CursorManager::Get()->addCursorToLayer(this);

	return true;
}

void GameScene::update(float dt)
{

}