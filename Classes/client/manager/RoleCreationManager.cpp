#include "RoleCreationManager.h"

static std::string getDressResource(E_PLAYER_SEX sex, E_PLAYER_DRESS_TYPE dress, int index)
{
}

RoleCreationManager::RoleCreationManager() 
{
	this->roleModel = RoleModel::create();
	this->roleModel->setPosition(430, designResolutionSize.height - 30);
}

RoleCreationManager::~RoleCreationManager() 
{
	CC_SAFE_DELETE(this->roleModel);
}

RoleModel* RoleCreationManager::getRole()
{
	return this->roleModel;
}

void RoleCreationManager::initRole(E_PLAYER_JOB job, E_PLAYER_SEX sex)
{
	this->roleModel->initDress(FACE_BEGIN, HEAD_BEGIN[0]);

	// body & cloth
	this->roleModel->initDress(BODY_BEGIN,		(sex == MALE ? MALE_BODY_BEGIN[0]	: FEMALE_BODY_BEGIN[0]));
	this->roleModel->initDress(BODY_CLOTH,		(sex == MALE ? MALE_BODY_CLOTH[job]	: FEMALE_BODY_CLOTH[job]));
	
	// face
	this->roleModel->initDress(EYE,				(sex == MALE ? MALE_FACE[0]			: FEMALE_FACE[0]));

	// leg & pants
	this->roleModel->initDress(LEG_BEGIN,		(sex == MALE ? MALE_LEG_BEGIN[0]	: FEMALE_LEG_BEGIN[0]));
	this->roleModel->initDress(LEG_PANTS,		(sex == MALE ? MALE_LEG_PANTS[job]	: FEMALE_LEG_PANTS[job]));
	
	// feet & shoes
	this->roleModel->initDress(FEET_SHOES,		(sex == MALE ? MALE_FEET_SHOES[job]	: FEMALE_FEET_SHOES[job]));
	this->roleModel->initDress(FEET_BEGIN,		(sex == MALE ? MALE_FEET_BEGIN[0]	: FEMALE_FEET_BEGIN[0]));

	// hair
	this->roleModel->initDress(HAIR_BANG2,		(sex == MALE ? MALE_HAIR_BANG2[0]	: FEMALE_HAIR_BANG2[0]));
	this->roleModel->initDress(HAIR_BANG1,		(sex == MALE ? MALE_HAIR_BANG1[0]	: FEMALE_HAIR_BANG1[0]));
	this->roleModel->initDress(HAIR_INNERHAIR,	(sex == MALE ? MALE_HAIR_INNER[0]	: FEMALE_HAIR_INNER[0]));
	this->roleModel->initDress(HAIR_OUTERHAIR,	(sex == MALE ? MALE_HAIR_OUTER[0]	: FEMALE_HAIR_OUTER[0]));

	this->roleModel->playAnimation(STAND);
}