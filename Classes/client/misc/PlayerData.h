#pragma once

enum E_PLAYER_JOB
{
	JOB_SWORDMAN,       // ��ʿ
	JOB_BOWMAN,         // ������
	JOB_MAGICIAN,       // ħ��ʦ
	JOB_TRANSFORMER,    // �仯ʦ
	JOB_NONE
};

enum E_PLAYER_HUDDLE
{
	HUDDLE_BUD,			// ʥ
	HUDDLE_EVIL,		// ħ
	HUDDLE_NONE
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

const std::string E_PLAYER_ACTION_STR[10] = { "sit", "jump", "stand", "ladder", "crawl", "rope", "run", "magic", "onehand", "twohands" };

enum E_PLAYER_DRESS_TYPE 
{ 
	FACE_BEGIN,		// ͷ��
	BODY_BEGIN,		// ����
	FEET_BEGIN,		// ��
	LEG_BEGIN,		// ��

	BODY_CLOTH,		// �·�
	LEG_PANTS,		// ����
	FEET_SHOES,		// Ь
	HAIR_BANG2,		// ��
	HAIR_BANG1,		// ���ͷ��
	HAIR_INNERHAIR,	// ����
	HAIR_OUTERHAIR,	// ǰ��
	FACE,			// ��
	EYE,			// �۾�
	ARM				// ����
};