#pragma once

enum E_PLAYER_JOB
{
	JOB_NONE,
	JOB_SWORDMAN,       // 力士
	JOB_BOWMAN,         // 弓箭手
	JOB_MAGICIAN,       // 魔法师
	JOB_TRANSFORMER     // 变化师
};

enum E_PLAYER_HUDDLE
{
	HUDDLE_NONE,
	HUDDLE_BUD,			// 圣
	HUDDLE_EVIL			// 魔
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