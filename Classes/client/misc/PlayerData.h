#pragma once

enum ePlayerJob
{
	JOB_SWORDMAN,       // 力士
	JOB_BOWMAN,         // 弓箭手
	JOB_MAGICIAN,       // 魔法师
	JOB_TRANSFORMER     // 变化师
};

enum ePlayerHuddle
{
	HUDDLE_NONE,
	HUDDLE_BUD,			// 圣
	HUDDLE_EVIL			// 魔
};

enum ePlayerSexual
{
	MALE,           // 男
	FEMALE          // 女
};

enum sPlayerAnimation
{
	STAND,          // 站立
	JUMP,           // 跳跃
	RUN,            // 奔跑
	SIT,            // 坐立
	CRAWL,          // 攀爬
	LADDER,         // 爬梯
	ROPE            // 爬绳
};