#pragma once

#ifndef __GAME_UTILS_H__
#define __GAME_UTILS_H__

#include "cocos2d.h"
#include "ui\UIButton.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

/**
* Retrieves sprite by specified file from frame cache, if not found, it will try initialize from file directly.
*
* @filename: name of sprite
* @x: x position 
* @y: y position
* @anchorPoint: anchor point of sprite
*/
Sprite* getSprite(string filename, float x = 0, float y = 0, Vec2 anchorPoint = Vec2::ZERO);

/**
* Retrieves sprite frame by specified file from frame cache.
*
* @spriteName: name of sprite
*/
SpriteFrame* getSpriteFrameByName(const string spriteName);

bool resourcePresentForLoading(string filename);

/**
* Converts string from GBK to UTF-8 encoding
*
* @gb2312: string with GBK encoding
*/
const char* gbk2UTF8(const char* gb2312);

/**
* Creates UI button
*
* @x: x position
* @y: y position
* @imagePattern: pattern of image file which would be iterated to construct sprite frames
* @clickEvent: click event
* @bright: disabled if true given
* @joiner: joiner to construct the image file path
* @imageExt: extension of image file
* @start: starting index of the image
*/
Button* createButton(const float x, const float y,
					 const std::string &imagePattern, 
					 const Widget::ccWidgetClickCallback &clickEvent = nullptr,
					 const bool bright = true,	
				     const std::string joiner = "-",
					 const std::string imageExt = ".png",
					 const int start = 1);

/**
* Creates UI button
*
* @x: x position
* @y: y position
* @normalImage: image file to represent normal status
* @hoverImage: image file to represent hover status
* @pressedImage: image file to represent pressed status
* @disableImage: image file to represent disabled status
* @clickEvent: click event
* @anchorPoint: anchor point of button image
* @texType: texture resource type
*/
Button* createButton(const float x, const float y, 
					 const std::string &normalImage,
					 const std::string &hoverImage,
					 const std::string &pressedImage,
					 const std::string &disableImage = "",
					 const Widget::ccWidgetClickCallback &clickEvent = nullptr,
					 const bool bright = true,
					 Vec2 anchorPoint = Vec2::ANCHOR_TOP_LEFT,
				     Widget::TextureResType texType = Widget::TextureResType::PLIST);

/**
 * Creates animation which would be used on sprite
 *
 * @spriteName: name of sprite
 * @frames: total number of sprite frames
 * @delay: delay per unit of animation
 * @loop: flag to indicate whether the animation looped or not
 */
Animation* createAnimation(const std::string &spriteName, int frames, float delay, bool loop = true);

/**
  * Pre-load all given resources
  *
  * @resources: list of resource bundles
  */
void preLoadResources(const vector<std::string> resources);

#endif