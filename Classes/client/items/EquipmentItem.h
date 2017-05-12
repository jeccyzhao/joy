#ifndef EQUIPMENT_ITEM_H
#define EQUIPMENT_ITEM_H

#include "ItemBase.h"

class EquipmentItem : public ItemBase
{
public:
	EquipmentItem();
	virtual ~EquipmentItem();
	virtual unsigned int getEquipLevel();
public:
	unsigned int		m_ownerType;		//ʹ��������
	unsigned int		m_equipPart;		//װ��λ��
	unsigned int		m_equipLevel;		//װ���ȼ�
};

#endif