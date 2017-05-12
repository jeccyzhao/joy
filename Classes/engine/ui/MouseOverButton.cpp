#include "MouseOverButton.h"

MouseOverButton::~MouseOverButton()
{
	_eventDispatcher->removeEventListener(mouseListener);
}

MouseOverButton* MouseOverButton::create(
	const std::string &normalImage, 
	const std::string &hoverImage,
	const std::string &pressedImage, 
	const std::string &disabledImage, 
	const ccMenuCallback &callback)
{
	MouseOverButton *ret = new (std::nothrow) MouseOverButton();

	/*
	if (ret && ret->initWithNormalImage(normalImage, selectedImage, disabledImage, callback))
	{
		ret->setMouseListener();
		ret->autorelease();
		return ret;
	}
	*/

	CC_SAFE_DELETE(ret);
	return nullptr;
}

void MouseOverButton::onMouseMove(Event *event)
{
	EventMouse* e = (EventMouse*)event;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 locationInNode = convertToNodeSpace(Vec2(e->getCursorX(), e->getCursorY() + visibleSize.height));

	Rect r = Rect(0, 0, getContentSize().width, getContentSize().height);

	// Show selected image if mouse over
	//r.containsPoint(locationInNode) ? selected() : unselected();
}

void MouseOverButton::setMouseListener()
{
	// Create a mouse listener
	mouseListener = EventListenerMouse::create();
	mouseListener->onMouseMove = CC_CALLBACK_1(MouseOverButton::onMouseMove, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}