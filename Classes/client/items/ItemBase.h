#ifndef ITEM_BASE_H
#define ITEM_BASE_H

#include "cocos2d.h"

class ItemBase : public cocos2d::CCNode
{
public:
	ItemBase();
	virtual ~ItemBase();

	virtual unsigned int getEquipLevel();
public:
	unsigned int	m_id;					//��ƷId
	char			m_name[128];			//��Ʒ��
	bool			b_isPiledUp;			//�Ƿ�ɶѵ�
	unsigned int	m_maxPiledNum;			//���ѵ�����
	unsigned int	m_source[5];			//��ȡ��ʽ
	unsigned int	m_byeprice;				//����۸�
	unsigned int	m_sellprice;			//�����۸�
	unsigned int	m_requiredLevel;		//�ȼ�Ҫ��
	unsigned int	m_type;					//��Ʒ����
	bool			b_Destroyed;			//�Ƿ�ɴݻ�
	char            m_szDescription[512];	//�����ֶ�
	std::string		m_useDes;				//ʹ������
	unsigned int	m_quality;				//��ƷƷ��(���ڱ߿��������ɫ)
	unsigned int	m_iconId;				//��ƷId���
	unsigned int	m_order;				//��ƷƷ��
	unsigned int	m_banch;				//�Ƿ����һ��ʹ��
};

#endif