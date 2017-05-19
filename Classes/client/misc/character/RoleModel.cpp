#include "RoleModel.h"

RoleModel::RoleModel()
{
}

RoleModel::~RoleModel()
{
}

void RoleModel::changeDress(E_DRESS_TYPE type, std::string id)
{
	switch (type)
	{
		case BEGIN_HEAD:
			face->changeDress(id);
			break;
		case BEGIN_BODY:
			bodyBegin->changeDress(id);
			break;
		case BEGIN_LEG:
			legBegin->changeDress(id);
			break;
		case EYE:
			eye->changeDress(id);
			break;
		default:
			break;
	}
}

bool RoleModel::init()
{
	if (!Layer::init())
	{
		return false;
	}

	preLoadResources("MotionData_Role/FACE_face_000-{n}.plist");

	face		= new DressSprite("FACE_face_000");
	bodyBegin	= new DressSprite("BODY_begin_000001");
	legBegin	= new DressSprite("LEG_begin_000002");
	eye			= new DressSprite("FACE_face_011");

	addChild(legBegin->sprite);
	addChild(bodyBegin->sprite);
	addChild(face->sprite);
	addChild(eye->sprite);

	return true;
}