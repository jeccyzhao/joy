#include "CursorTextField.h"

const static float DELTA = 0.5f;

static int _calcCharCount(const char * pszText)
{
	int n = 0;
	char ch = 0;
	while ((ch = *pszText))
	{
		CC_BREAK_IF(!ch);
		if (0x80 != (0xC0 & ch))
		{
			++n;
		}

		++pszText;
	}
	return n;
}

CursorTextField::CursorTextField()
{
	TextFieldTTF();

	m_pCursorSprite = NULL;
	m_pCursorAction = NULL;
	m_pInputText = NULL;

	m_isPassword = false;
	m_charLimit = 30;
}

CursorTextField::~CursorTextField()
{
	CC_SAFE_DELETE(m_pCursorSprite);
	//CC_SAFE_DELETE(m_pCursorAction);
	CC_SAFE_DELETE(m_pInputText);
}

void CursorTextField::onEnter()
{
	TextFieldTTF::onEnter();
	//TouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, false);
	this->setDelegate(this);
}

CursorTextField * CursorTextField::textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize, Vec2 anchorPoint)
{
	CursorTextField *pRet = new CursorTextField();

	if (pRet && pRet->initWithPlaceHolder("", fontName, fontSize))
	{
		pRet->autorelease();
		if (placeholder)
		{
			pRet->setPlaceHolder(placeholder);
		}

		pRet->setAnchorPoint(anchorPoint);
		pRet->initCursorSprite(fontSize);
		pRet->m_pCursorSprite->setVisible(true);

		return pRet;
	}

	CC_SAFE_DELETE(pRet);

	return NULL;
}

void CursorTextField::initCursorSprite(int height)
{
	// 初始化光标
	const int column = 4;
	int pixels[20][column];
	for (int i = 0; i< height; ++i) {
		for (int j = 0; j<column; ++j) {
			pixels[i][j] = 0xffffffff;
		}
	}

	Texture2D *texture = new Texture2D();

	// 指针，指针长度，像素类型，像素宽度，高度，内容大小
	texture->initWithData(pixels, 20, Texture2D::PixelFormat::RGB888, 1, height, Size(column, height));

	m_pCursorSprite = Sprite::createWithTexture(texture);
	Size winSize = getContentSize();
	m_cursorPos = Vec2(0, winSize.height / 2);
	m_pCursorSprite->setPosition(m_cursorPos);
	this->addChild(m_pCursorSprite);

	m_pCursorAction = RepeatForever::create((ActionInterval *)Sequence::create(FadeOut::create(0.25f), FadeIn::create(0.25f), NULL));
	m_pCursorSprite->runAction(m_pCursorAction);

	m_pInputText = new std::string();
}

bool CursorTextField::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	m_beginPos = pTouch->getLocationInView();
	m_beginPos = Director::getInstance()->convertToGL(m_beginPos);
	return true;
}

Rect CursorTextField::getRect()
{
	Size size = getContentSize();
	if (&m_designedSize != NULL) {
		size = getDesignedSize();
	}
	else {
		size = getContentSize();
	}

	Rect rect = Rect(getPosition().x - size.width / 2.0f, getPosition().y - size.height / 2.0f, size.width, size.height);
	return  rect;
}

//设置触摸弹出输入法的区域大小
void CursorTextField::setDesignedSize(cocos2d::Size size)
{
	m_designedSize = size;
}

Size CursorTextField::getDesignedSize()
{
	return m_designedSize;
}

bool CursorTextField::isInTextField(cocos2d::Touch *pTouch)
{
	Point pToushPos = pTouch->getLocation();
	return getRect().containsPoint(pToushPos);
}

void CursorTextField::ccTouchEnded(cocos2d::Touch *pTouch, cocos2d::CCEvent *pEvent)
{
	Point endPos = pTouch->getLocationInView();
	endPos = Director::getInstance()->convertToGL(endPos);

	// 判断是否为点击事件
	if (::abs(endPos.x - m_beginPos.x) > DELTA ||
		::abs(endPos.y - m_beginPos.y))
	{
		// 不是点击事件
		m_beginPos.x = m_beginPos.y = -1;
		return;
	}

	log("width: %f, height: %f.", getContentSize().width, getContentSize().height);

	// 判断是打开输入法还是关闭输入法
	isInTextField(pTouch) ? openIME() : closeIME();
}

bool CursorTextField::onTextFieldAttachWithIME(cocos2d::TextFieldTTF *pSender)
{
	if (m_pInputText->empty()) {
		return false;
	}

	m_pCursorSprite->setPosition(Vec2(getContentSize().width + 1, getContentSize().height / 2));
	return false;
}

bool CursorTextField::onTextFieldInsertText(cocos2d::TextFieldTTF *pSender, const char *text, int nLen)
{
	CCLOG("Width: %f", pSender->getContentSize().width);
	CCLOG("Text: %s", text);
	CCLOG("Length: %d", nLen);

	std::string tempStr = m_pInputText->substr();
	tempStr.append(text);
	if (tempStr.length() > m_charLimit) 
	{
		return true;
	}

	m_pInputText->append(text);
	setString(m_pInputText->c_str(), m_pInputText->c_str());
	m_pCursorSprite->setPosition(Vec2(getContentSize().width + 1, getContentSize().height / 2));

	return true;
}

bool CursorTextField::onTextFieldDeleteBackward(cocos2d::TextFieldTTF *pSender, const char *delText, int nLen)
{
	m_pInputText->resize(m_pInputText->size() - nLen);
	setString(m_pInputText->c_str(), m_pInputText->c_str());

	m_pCursorSprite->setPosition(Vec2(getContentSize().width + 1, getContentSize().height / 2));

	if (m_pInputText->empty()) 
	{
		m_pCursorSprite->setPosition(Vec2(1, getContentSize().height / 2));
	}

	return false;
}

bool CursorTextField::onTextFieldDetachWithIME(cocos2d::TextFieldTTF *pSender)
{
	return false;
}

void CursorTextField::openIME()
{
	m_pCursorSprite->setVisible(true);
	this->attachWithIME();
}

void CursorTextField::closeIME()
{
	m_pCursorSprite->setVisible(false);
	this->detachWithIME();
}

void CursorTextField::onExit()
{
	this->detachWithIME();
	TextFieldTTF::onExit();
	//CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
}

void CursorTextField::setString(const char *displayTx, const char* inputTx)
{
	CC_SAFE_DELETE(m_pInputText);

	if (inputTx)
	{
		m_pInputText = new std::string(inputTx);
	}
	else
	{
		m_pInputText = new std::string;
	}

	/*
	// if there is no input text, display placeholder instead
	if (!m_pInputText->length())
	{
		LabelTTF::setString(m_pPlaceHolder->c_str());
	}
	else
	{
		CCLabelTTF::setString(displayTx);
	}
	*/
	//    m_nCharCount = _calcCharCount(m_pInputText->c_str());
}

void CursorTextField::setColor(const Color3B& color3)
{
	updateColor();
	m_pCursorSprite->setColor(color3);
}