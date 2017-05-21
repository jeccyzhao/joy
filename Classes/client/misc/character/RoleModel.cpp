#include "RoleModel.h"
#include "client\manager\GameDataManager.h"

RoleModel::RoleModel()
{
	bodyBegin = new DressSprite();
	bodyCloth = new DressSprite();
	legBegin = new DressSprite();
	legPants = new DressSprite();
	feetShoes = new DressSprite();
	feetBegin = new DressSprite();
	faceBegin = new DressSprite();
	faceEye = new DressSprite();
	
	arm = new DressSprite();
	shield = new DressSprite();

	hairBang2 = new DressSprite();
	hairBang1 = new DressSprite();
	hairInner = new DressSprite();
	hairOuter = new DressSprite();

}

RoleModel::~RoleModel()
{
}

void RoleModel::updateDress(E_PLAYER_DRESS_TYPE type, std::string id)
{
	switch (type)
	{
		case BODY_CLOTH:
			bodyCloth->updateDress(id);
			break;
		case LEG_BEGIN:
			legBegin->updateDress(id);
			break;
		case LEG_PANTS:
			legPants->updateDress(id);
			break;
		case FEET_SHOES:
			feetShoes->updateDress(id);
			break;
		case BODY_BEGIN:
			bodyBegin->updateDress(id);
			break;
		case FEET_BEGIN:
			feetBegin->updateDress(id);
			break;
		case HAIR_BANG2:
			hairBang2->updateDress(id);
			break;
		case HAIR_BANG1:
			hairBang1->updateDress(id);
			break;
		case HAIR_INNERHAIR:
			hairInner->updateDress(id);
			break;
		case HAIR_OUTERHAIR:
			hairOuter->updateDress(id);
			break;
		case EYE:
			faceEye->updateDress(id);
			break;
		case FACE_BEGIN:
			faceBegin->updateDress(id);
			break;
		case ARM:
			arm->updateDress(id);
			break;
		default:
			break;
	}
}

void RoleModel::playAnimation(E_PLAYER_ACTION action)
{
	this->bodyBegin->playAnimation(action);
	this->bodyCloth->playAnimation(action);
	this->legBegin->playAnimation(action);
	this->legPants->playAnimation(action); 
	this->faceBegin->playAnimation(action);
	this->feetBegin->playAnimation(action);
	this->feetShoes->playAnimation(action);
	this->faceEye->playAnimation(action);
	this->hairBang1->playAnimation(action);
	this->hairBang2->playAnimation(action);
	this->hairInner->playAnimation(action);
	this->hairOuter->playAnimation(action);
}

void RoleModel::show(float x, float y)
{
	addChild(hairBang2->sprite);
	addChild(legBegin->sprite);
	addChild(legPants->sprite);
	addChild(feetBegin->sprite);
	addChild(feetShoes->sprite);
	addChild(bodyBegin->sprite);
	addChild(bodyCloth->sprite);
	addChild(faceBegin->sprite);
	addChild(faceEye->sprite);
	addChild(hairInner->sprite);
	addChild(hairOuter->sprite);

	if (hairBang1->sprite)
	{
		addChild(hairBang1->sprite);
	}

	this->setPosition(x, y);
}

void RoleModel::initDress(E_PLAYER_DRESS_TYPE dressType, std::string id)
{
	this->updateDress(dressType, id);
}

bool RoleModel::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("MotionData_Role/FACE_face_000-{n}.plist");
	
	//head = new DressSprite("FACE_face_000");
	this->setLocalZOrder(Z_ORDER_ROLE);

	return true;
}