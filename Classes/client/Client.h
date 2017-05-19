#pragma once
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "cocos2d.h"
#include "engine\util\GameUtils.h"

using namespace cocos2d;
using namespace std;

#define DESIGN_RESOLUTION_480X320   0
#define DESIGN_RESOLUTION_800X600   1
#define DESIGN_RESOLUTION_1024X768  2

#define Z_ORDER_ROLE			999998
#define Z_ORDER_GAME_SCENE		999999
#define Z_ORDER_MOUSE			1000000

/* If you want to switch design resolution, change next line */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_800X600
#define DEBUG_DRAW true

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_480X320)
static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_800X600)
static cocos2d::Size designResolutionSize = cocos2d::Size(800, 600);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1024X768)
static cocos2d::CCSize designResolutionSize = cocos2d::Size(1024, 768);
#else
#error unknown target design resolution!
#endif

// The title been shown as window subject name
static const char* GAME_TITLE = "JoyXY";

// The flag to turn on display FPS
static const bool DISPLAY_FPS = true;

// The FPS value 
static const float FPS = 1.0f / 60;

// The maximum number of iteration to read plist files
static const int MAXIMUM_PLIST_ITERATION = 100;

static const int NUM_LINES = 5;

// The flag to indicate that it will draw all objects only for debug purpose
//static const bool DEBUG_DRAW = true;

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)

#endif /* __CLIENT_H__ */