#pragma once
#ifndef __CURSOR_TEXT_FIELD_H__
#define __CURSOR_TEXT_FIELD_H__

#include "cocos2d.h"
USING_NS_CC;

class CursorTextField : public TextFieldTTF, public TextFieldDelegate
{
private:
	// 点击开始位置
	Point m_beginPos;

	// 光标精灵
	Sprite *m_pCursorSprite;

	// 光标动画
	Action *m_pCursorAction;

	// 光标坐标
	Point m_cursorPos;

	// 输入框内容
	std::string *m_pInputText;

	// 允许输入最大字符数
	size_t m_charLimit;

	// 密码输入模式
	bool m_isPassword;

	// 字符显示区域大小限制
	Size m_designedSize;

public:
	CursorTextField();
	~CursorTextField();

	// static
	static CursorTextField* textFieldWithPlaceHolder(const char *placeholder, 
													 const char *fontName, 
													 float fontSize, Vec2 anchorPoint = Vec2::ANCHOR_TOP_LEFT);

	// Layer
	void onEnter();
	void onExit();

	// 初始化光标精灵
	void initCursorSprite(const int nHeight = 12);
	void setColor(const Color3B& color3);

	// TextFieldDelegate
	virtual bool onTextFieldAttachWithIME(TextFieldTTF *pSender);
	virtual bool onTextFieldDetachWithIME(TextFieldTTF * pSender);
	virtual bool onTextFieldInsertText(TextFieldTTF * pSender, const char * text, int nLen);
	virtual bool onTextFieldDeleteBackward(TextFieldTTF * pSender, const char * delText, int nLen);

	// CCLayer Touch
	bool ccTouchBegan(Touch *pTouch, Event *pEvent);
	void ccTouchEnded(Touch *pTouch, Event *pEvent);

	// 判断是否点击在TextField处
	bool isInTextField(Touch *pTouch);

	// 得到TextField矩形
	Rect getRect();

	// 打开输入法
	void openIME();

	// 关闭输入法
	void closeIME();

	// 设置字符长度限制，一个汉字三个字符
	void setCharLimit(int charLimitNum);
	int getCharLimit();

	// 重载原函数，用来显示星号
	void setString(const char* displayTx, const char* inputTx);

	//点击弹出输入法的尺寸范围
	void setDesignedSize(Size size);
	Size getDesignedSize();
};

#endif
