#include "CursorTextField.h"

#define FONT_NAME                       "fonts/Yahei.ttf"
#define FONT_SIZE                       20

const static float DELTA = 0.5f;

static Rect getRect(Node * node)
{
	Rect rc;
	rc.origin = node->getPosition();
	rc.size = node->getContentSize();
	rc.origin.x -= rc.size.width / 2;
	rc.origin.y -= rc.size.height / 2;
	return rc;
}

CursorTextField::CursorTextField() 
:_trackNode(0)
{
	TextFieldTTF();

	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(CursorTextField::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(CursorTextField::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	m_pInputText = NULL;
	m_isPassword = false;
	m_maxLength = 0;
}

CursorTextField::~CursorTextField()
{
	CC_SAFE_DELETE(m_pInputText);
}

bool CursorTextField::onTouchBegan(Touch  *touch, Event  *event)
{
	CCLOG("++++++++++++++++++++++++++++++++++++++++++++");
	_beginPos = touch->getLocation();
	return true;
}

CursorTextField* CursorTextField::textFieldWithPlaceHolder(const char *placeholder,  float fontSize, const char *fontName, Vec2 anchorPoint)
{
	CursorTextField *pRet = new CursorTextField();
	if (pRet && pRet->initWithPlaceHolder(placeholder, fontName, fontSize))
	{
		pRet->setAnchorPoint(anchorPoint);
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return NULL;
}

void CursorTextField::onTouchEnded(Touch  *touch, Event  *event)
{
	if (!_trackNode)
	{
		return;
	}

	auto endPos = touch->getLocation();

	float delta = 5.0f;
	if (std::abs(endPos.x - _beginPos.x) > delta
		|| std::abs(endPos.y - _beginPos.y) > delta)
	{
		// not click
		_beginPos.x = _beginPos.y = -1;
		return;
	}

	// decide the trackNode is clicked.
	Rect rect;
	rect.size = &m_designedSize != NULL ? m_designedSize : _trackNode->getContentSize();

	auto clicked = isScreenPointInRect(endPos, Camera::getVisitingCamera(), _trackNode->getWorldToNodeTransform(), rect, nullptr);
	this->onClickTrackNode(clicked);
	CCLOG("----------------------------------");
}

void CursorTextField::onClickTrackNode(bool bClicked)
{
	auto pTextField = (TextFieldTTF*)_trackNode;
	if (bClicked)
	{
		// TextFieldTTFTest be clicked
		CCLOG("TextFieldTTFDefaultTest:TextFieldTTF attachWithIME");
		pTextField->attachWithIME();
	}
	else
	{
		// TextFieldTTFTest not be clicked
		CCLOG("TextFieldTTFDefaultTest:TextFieldTTF detachWithIME");
		pTextField->detachWithIME();
	}
}

void CursorTextField::keyboardWillShow(IMEKeyboardNotificationInfo& info)
{
	CCLOG("TextInputTest:keyboardWillShowAt(origin:%f,%f, size:%f,%f)",
		info.end.origin.x, info.end.origin.y, info.end.size.width, info.end.size.height);

	if (!_trackNode)
	{
		return;
	}

	auto rectTracked = getRect(_trackNode);
	CCLOG("TextInputTest:trackingNodeAt(origin:%f,%f, size:%f,%f)",
		rectTracked.origin.x, rectTracked.origin.y, rectTracked.size.width, rectTracked.size.height);

	// if the keyboard area doesn't intersect with the tracking node area, nothing need to do.
	if (!rectTracked.intersectsRect(info.end))
	{
		return;
	}

	// assume keyboard at the bottom of screen, calculate the vertical adjustment.
	float adjustVert = info.end.getMaxY() - rectTracked.getMinY();
	CCLOG("TextInputTest:needAdjustVerticalPosition(%f)", adjustVert);

	// move all the children node of KeyboardNotificationLayer
	auto& children = getChildren();
	Node * node = 0;
	ssize_t count = children.size();
	Vec2 pos;
	for (int i = 0; i < count; ++i)
	{
		node = children.at(i);
		pos = node->getPosition();
		pos.y += adjustVert;
		node->setPosition(pos);
	}
}

void CursorTextField::onExit()
{
	TextFieldTTF::onExit();
}

void CursorTextField::onEnter()
{
	TextFieldTTF::onEnter();
	
	m_pInputText = new std::string();

	if (this->m_isPassword)
	{
		this->setSecureTextEntry(true);
	}

	this->setDelegate(this);

	_trackNode = this;
}

bool CursorTextField::onTextFieldAttachWithIME(TextFieldTTF * sender)
{
	if (m_pInputText->empty()) 
	{
		return false;
	}

	return false;
}

bool CursorTextField::onTextFieldDetachWithIME(TextFieldTTF * sender)
{
	return false;
}

bool CursorTextField::onTextFieldInsertText(TextFieldTTF * sender, const char * text, size_t nLen)
{
	// if insert enter, treat as default to detach with ime
	if ('\n' == *text)
	{
		return false;
	}

	if (m_maxLength > 0 && sender->getCharCount() >= m_maxLength)
	{
		return true;
	}

	m_pInputText->append(text);

	return false;
}

bool CursorTextField::onDraw(cocos2d::TextFieldTTF*  sender)
{
	return true;
}

void CursorTextField::setPassword(bool passwordMode)
{
	this->m_isPassword = passwordMode;
}

bool CursorTextField::onTextFieldDeleteBackward(TextFieldTTF * sender, const char * delText, size_t nLen)
{
	m_pInputText->resize(m_pInputText->size() - nLen);
	return false;
}

void CursorTextField::setMaxLength(unsigned int len)
{
	this->m_maxLength = len;
}

bool CursorTextField::isPassword() 
{
	return this->m_isPassword;
}

void CursorTextField::setDesignedSize(Size size)
{
	this->m_designedSize = size;
}

Size CursorTextField::getDesignedSize()
{
	return this->m_designedSize;
}