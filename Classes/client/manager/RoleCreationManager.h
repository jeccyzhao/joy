#pragma once

#ifndef _ROLE_CREATION_MANAGER_H_
#define _ROLE_CREATION_MANAGER_H_

#include "cocos2d.h"
#include "engine\Singleton.h"
#include "client\Client.h"
#include "client\misc\character\RoleModel.h"
#include "client\misc\PlayerData.h"

USING_NS_CC;
using namespace std;

static std::string HEAD_BEGIN[]			= { "FACE_face_000" }; 
static std::string JOB_ARM[]			= { "ARM_blade_100", "ARM_bow_000001", "ARM_staff_000001", "ARM_odd_100" };

// male
static std::string MALE_BODY_BEGIN[]	= { "BODY_begin_000001" };
static std::string MALE_HAIR_BANG2[]	= { "BANG2_bang_01","BANG2_bang_03","BANG2_bang_05","BANG2_bang_07","BANG2_bang_09","BANG2_bang_11" };
static std::string MALE_FACE[]			= { "FACE_face_001" , "FACE_face_003","FACE_face_005","FACE_face_007","FACE_face_009","FACE_face_011" };
static std::string MALE_HAIR_INNER[]	= { "INNERHAIR_innerhair_01","INNERHAIR_innerhair_03","INNERHAIR_innerhair_05", "INNERHAIR_innerhair_07","INNERHAIR_innerhair_09","INNERHAIR_innerhair_11" };
static std::string MALE_HAIR_OUTER[]	= { "OUTERHAIR_outerhair_01","OUTERHAIR_outerhair_03","OUTERHAIR_outerhair_05", "OUTERHAIR_outerhair_07","OUTERHAIR_outerhair_09","OUTERHAIR_outerhair_11" };
static std::string MALE_HAIR_BANG1[]	= { "BANG_bang_01","BANG_bang_03","BANG_bang_05","","BANG_bang_09","BANG_bang_11" };
static std::string MALE_BODY_CLOTH[]	= { "BODY_cloth_000009","BODY_cloth_000011","BODY_cloth_000012","BODY_cloth_000010" };
static std::string MALE_LEG_BEGIN[]		= { "LEG_begin_000002" };
static std::string MALE_LEG_PANTS[]		= { "LEG_pants_000009","LEG_pants_000011","LEG_pants_000012","LEG_pants_000010" };
static std::string MALE_FEET_BEGIN[]	= { "FEET_begin_000005" };
static std::string MALE_FEET_SHOES[]	= { "FEET_shoes_000008","FEET_shoes_000010","FEET_shoes_000011","FEET_shoes_000009" };

// female
static std::string FEMALE_BODY_BEGIN[]	= { "BODY_begin_000003" };
static std::string FEMALE_HAIR_BANG2[]	= { "BANG2_bang_02","LONGHAIR_longhair_02","BANG2_bang_06","BANG2_bang_08","LONGHAIR_longhair_01","BANG2_bang_12","BANG2_bang_14","BANG2_bang_16","BANG2_bang_18" };
static std::string FEMALE_FACE[]		= { "FACE_face_002","FACE_face_004","FACE_face_006","FACE_face_008","FACE_face_010","FACE_face_012" };
static std::string FEMALE_HAIR_INNER[]	= { "INNERHAIR_innerhair_02","INNERHAIR_innerhair_04","INNERHAIR_innerhair_06","INNERHAIR_innerhair_08", "INNERHAIR_innerhair_10","INNERHAIR_innerhair_12","INNERHAIR_innerhair_14","INNERHAIR_innerhair_16","INNERHAIR_innerhair_18" };
static std::string FEMALE_HAIR_OUTER[]	= { "OUTERHAIR_outerhair_02","OUTERHAIR_outerhair_04","OUTERHAIR_outerhair_06","OUTERHAIR_outerhair_08", "OUTERHAIR_outerhair_10","OUTERHAIR_outerhair_12","OUTERHAIR_outerhair_14","OUTERHAIR_outerhair_16","OUTERHAIR_outerhair_18" };
static std::string FEMALE_HAIR_BANG1[]	= { "BANG_bang_02","BANG_bang_04","BANG_bang_06","","BANG2_bang_10", "","BANG_bang_14","","" };
static std::string FEMALE_BODY_CLOTH[]	= { "BODY_cloth_000005","BODY_cloth_000007","BODY_cloth_000008","BODY_cloth_000006" };
static std::string FEMALE_LEG_BEGIN[]	= { "LEG_begin_000004" };
static std::string FEMALE_LEG_PANTS[]	= { "LEG_pants_000005","","","" };
static std::string FEMALE_FEET_BEGIN[]	= { "FEET_begin_000006" };
static std::string FEMALE_FEET_SHOES[]	= { "FEET_shoes_000004","FEET_shoes_000006","FEET_shoes_000007","FEET_shoes_000005" };

class RoleCreationManager //: public TSingleton<RoleCreationManager>
{
public:
	RoleCreationManager();
	~RoleCreationManager();

	void initRole(E_PLAYER_JOB job, E_PLAYER_SEX sex = MALE);

	RoleModel* getRole();

private:
	RoleModel* roleModel;
	E_PLAYER_JOB job;
};

#endif