#pragma once

enum E_PLAYER_JOB
{
	JOB_NONE,
	JOB_SWORDMAN,       // ��ʿ
	JOB_BOWMAN,         // ������
	JOB_MAGICIAN,       // ħ��ʦ
	JOB_TRANSFORMER     // �仯ʦ
};

enum E_PLAYER_HUDDLE
{
	HUDDLE_NONE,
	HUDDLE_BUD,			// ʥ
	HUDDLE_EVIL			// ħ
};

enum E_PLAYER_SEX
{
	MALE,           // ��
	FEMALE          // Ů
};

enum E_PLAYER_ACTION
{
	SIT,            // ����
	JUMP,           // ��Ծ
	STAND,          // վ��
	LADDER,         // ����
	CRAWL,          // ����
	ROPE,           // ����
	RUN,            // ����
	MAGIC, 
	ONEHAND, 
	TWOHANDS
};