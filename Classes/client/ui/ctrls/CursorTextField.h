#pragma once
#ifndef __CURSOR_TEXT_FIELD_H__
#define __CURSOR_TEXT_FIELD_H__

#include "cocos2d.h"
USING_NS_CC;

#define DEFAULT_FONT_NAME		"fonts/Yahei.ttf"
#define DEFAULT_FONT_SIZE		12


class CursorTextField : public TextFieldTTF, public TextFieldDelegate
{
public:
	CursorTextField();
	~CursorTextField();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	// static
	static CursorTextField* textFieldWithPlaceHolder(const char *placeholder = "", 
													 float fontSize = DEFAULT_FONT_SIZE, 
													 const char *fontName = DEFAULT_FONT_NAME, 
													 Vec2 anchorPoint = Vec2::ANCHOR_TOP_LEFT);
	// Layer
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual void keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info)override;

	// TextFieldDelegate
	virtual bool onTextFieldAttachWithIME(TextFieldTTF *pSender)override;
	virtual bool onTextFieldDetachWithIME(TextFieldTTF * pSender)override;
	virtual bool onTextFieldInsertText(TextFieldTTF * sender, const char * text, size_t nLen)override;
	virtual bool onTextFieldDeleteBackward(TextFieldTTF * sender, const char * delText, size_t nLen)override;
	bool onDraw(cocos2d::TextFieldTTF*  sender);

	//void setColor(const Color3B& color3);

	// 判断是否点击在TextField处
	//bool isInTextField(Touch *pTouch);

	void setMaxLength(unsigned int len);
	void setPassword(bool passwordMode);
	bool isPassword();
	void setDesignedSize(Size size);
	Size getDesignedSize();
private:
	
	void onClickTrackNode(bool bClicked);

	cocos2d::Node*  _trackNode;
	cocos2d::Vec2  _beginPos;

	// 输入框内容
	std::string *m_pInputText;

	// 允许输入最大字符数
	unsigned int m_maxLength;

	// 密码输入模式
	bool m_isPassword;

	// 字符显示区域大小限制
	Size m_designedSize;
};

#endif
