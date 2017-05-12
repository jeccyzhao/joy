#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
//#include "Client\Manager\MetadataManager.h"
#include <string>

USING_NS_CC;
using namespace std;

Scene* HelloWorld::createScene()
{
	auto scene = HelloWorld::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		log("Key %d was pressed!", (int)keyCode);

		auto target = event->getCurrentTarget();
		float currentX = target->getPosition().x;
		float currentY = target->getPosition().y;

		int count = 0;
		int delta = 10;
		if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			target->setPosition(currentX, currentY - delta);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			target->setPosition(currentX - delta, currentY);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			target->setPosition(currentX + delta, currentY);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			target->setPosition(currentX, currentY + delta);
		}
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	/*
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    */
	/*
	auto dbMgr = MetadataManager::getInstance("res/joyxy.db");
	MapInfo *map = dbMgr->loadMapInfoByName("changan_stage001");
	if (map)
	{
		Vector<MapItem*> mapItems = map->mapItems;
		int count = 0;
		string spriteFileName = "res/nsyt/00000159.png";
		if (FileUtils::getInstance()->isFileExist(spriteFileName))
		{
			//auto polygonInfo = AutoPolygon::generatePolygon(spriteFileName);
			//auto sprite = Sprite::create(spriteFileName);
			auto sprite = Sprite::create(spriteFileName);
			if (sprite)
			{
				sprite->setPosition(Vec2(0, 0));
				sprite->setAnchorPoint(Vec2::ZERO);
				this->addChild(sprite, 0);
			}
		}
	}
	*/

	//this->setPosition(this->getPosition().x + 5, 0);
	
	/*
	string files[] = {};
	for (string file : files) 
	{
		printf("%s\n", file);
		auto sprite = Sprite::create("nsyt/" + file + ".png");
		sprite->setPosition(Vec2(0, 0));
		sprite->setAnchorPoint(Vec2::ZERO);
		this->addChild(sprite, 0);
	}
	*/

	scheduleUpdate();

    return true;
}

void HelloWorld::update(float dt)
{
	//log("update %f %f", this->getPosition().x, this->getPosition().y);
	//this->setPosition(this->getPosition().x - 0.5, this->getPosition().y - 0.5);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
