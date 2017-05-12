#pragma once

#ifndef __MOUSE_OVER_BUTTON_H__
#define __MOUSE_OVER_BUTTON_H__

#include "cocos2d.h"
#include "ui\UIButton.h"

USING_NS_CC;

class MouseOverButton : public cocos2d::ui::Button
{
public:

	static MouseOverButton* create(
		const std::string &normalImage, 
		const std::string &hoverImage,
		const std::string &pressedImage, 
		const std::string &disabledImage, 
		const ccMenuCallback& callback);

	~MouseOverButton();

protected:
	EventListenerMouse* mouseListener;

private:
	void onMouseMove(Event *event);
	void setMouseListener();
};

#endif /* defined(__MOUSE_OVER_BUTTON_H__) */