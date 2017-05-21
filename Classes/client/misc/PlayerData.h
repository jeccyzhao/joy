#pragma once

enum E_PLAYER_JOB
{
	JOB_SWORDMAN,       // 力士
	JOB_BOWMAN,         // 弓箭手
	JOB_MAGICIAN,       // 魔法师
	JOB_TRANSFORMER,    // 变化师
	JOB_NONE
};

enum E_PLAYER_HUDDLE
{
	HUDDLE_BUD,			// 圣
	HUDDLE_EVIL,		// 魔
	HUDDLE_NONE
};

enum E_PLAYER_SEX
{
	MALE,           // 男
	FEMALE          // 女
};

enum E_PLAYER_ACTION
{
	SIT,            // 坐立
	JUMP,           // 跳跃
	STAND,          // 站立
	LADDER,         // 爬梯
	CRAWL,          // 攀爬
	ROPE,           // 爬绳
	RUN,            // 奔跑
	MAGIC, 
	ONEHAND, 
	TWOHANDS
};

const std::string E_PLAYER_ACTION_STR[10] = { "sit", "jump", "stand", "ladder", "crawl", "rope", "run", "magic", "onehand", "twohands" };

enum E_PLAYER_DRESS_TYPE 
{ 
	FACE_BEGIN,		// 头部
	BODY_BEGIN,		// 身体
	FEET_BEGIN,		// 脚
	LEG_BEGIN,		// 腿

	BODY_CLOTH,		// 衣服
	LEG_PANTS,		// 裤子
	FEET_SHOES,		// 鞋
	HAIR_BANG2,		// 后发
	HAIR_BANG1,		// 外层头发
	HAIR_INNERHAIR,	// 顶发
	HAIR_OUTERHAIR,	// 前发
	FACE,			// 脸
	EYE,			// 眼睛
	ARM				// 武器
};