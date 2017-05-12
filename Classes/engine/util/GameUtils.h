#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__

#include "cocos2d.h"
#include "ui\UIButton.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

cocos2d::Sprite* getSprite(string filename, float x = 0, float y = 0, Vec2 anchorPoint = Vec2::ZERO);

bool resourcePresentForLoading(string filename);
const char* gbk2UTF8(const char* gb2312);

Button* createButton(const float x, const float y,
					 const std::string &imagePattern, 
					 const Widget::ccWidgetClickCallback &clickEvent = nullptr,
				     const std::string joiner = "-",
					 const std::string imageExt = ".png",
					 const int start = 1);

Button* createButton(const float x, const float y, 
					 const std::string &normalImage,
					 const std::string &hoverImage,
					 const std::string &pressedImage,
					 const std::string &disableImage = "",
					 const Widget::ccWidgetClickCallback &clickEvent = nullptr,
					 Vec2 anchorPoint = Vec2::ANCHOR_TOP_LEFT,
				     Widget::TextureResType texType = Widget::TextureResType::PLIST);

Animation* createAnimation(const std::string &spriteName, int frames, float delay, bool loop = true);

void preLoadResources(const vector<std::string> resources);

#endif