#pragma once
#ifndef __CURSOR_TEXT_FIELD_H__
#define __CURSOR_TEXT_FIELD_H__

#include "cocos2d.h"
USING_NS_CC;

class CursorTextField : public TextFieldTTF, public TextFieldDelegate
{
private:
	// �����ʼλ��
	Point m_beginPos;

	// ��꾫��
	Sprite *m_pCursorSprite;

	// ��궯��
	Action *m_pCursorAction;

	// �������
	Point m_cursorPos;

	// ���������
	std::string *m_pInputText;

	// ������������ַ���
	size_t m_charLimit;

	// ��������ģʽ
	bool m_isPassword;

	// �ַ���ʾ�����С����
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

	// ��ʼ����꾫��
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

	// �ж��Ƿ�����TextField��
	bool isInTextField(Touch *pTouch);

	// �õ�TextField����
	Rect getRect();

	// �����뷨
	void openIME();

	// �ر����뷨
	void closeIME();

	// �����ַ��������ƣ�һ�����������ַ�
	void setCharLimit(int charLimitNum);
	int getCharLimit();

	// ����ԭ������������ʾ�Ǻ�
	void setString(const char* displayTx, const char* inputTx);

	//����������뷨�ĳߴ緶Χ
	void setDesignedSize(Size size);
	Size getDesignedSize();
};

#endif
