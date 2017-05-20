#ifndef __JOYXY_DBUTIL_H__
#define __JOYXY_DBUTIL_H__

#include "cocos2d.h"
#include "Engine\3rdparty\sqlite3.h"

USING_NS_CC;
using namespace std;

class DBUtil
{
private:
	sqlite3* m_pDataBase;
	string m_dbName;

	DBUtil();
	DBUtil(string dbName);
	virtual ~DBUtil();
public:

	static DBUtil* getInstance();
    static void destoryInstance();

	/**
     *  �����ݿ�(����)
     *
     *  @param aDataBaseName ���ݿ���
     */
	void openDBWithName(string aDataBaseName);

	/**
     *  �ر����ݿ�
     */
	void closeDB();

	/**
     *  �������ݱ�
     *
     *  @param aSql       ����sql���
     *  @param aTableName ����
     */
    void createTable(string aSql, string aTableName);

	/**
     *  ͨ��������ѯ�ñ��Ƿ����
     *
     *  @param aTabelName ����
     *
     *  @return true: ���� false: ������
     */
	bool isExistTableByName(string aTabelName);

	/**
     *  ɾ�����ݱ�
     *
     *  @param aSql       ɾ��sql���
     *  @param aTableName ����
     */
    void deleteTable(string aSql, string aTableName);

	 /**
     *  �����¼
     *
     *  @param aSql ��������sql���
     */
    void insertData(string aSql);
     
    /**
     *  ɾ����¼
     *
     *  @param aSql ɾ������sql���
     */
    void deleteData(string aSql);
     
    /**
     *  �޸ļ�¼
     *
     *  @param aSql �޸�����sql���
     */
    void updateData(string aSql);
     
    /**
     *  ��ѯ��¼
     *
     *  @param aSql     �޸�����sql���
     */
    vector<map<string, string>> searchData(string aSql);
     
    /**
     *  ��ѯ��¼������
     *
     *  @param sql ��ѯ��¼sql���
     *
     *  @return ��¼����
     */
    int searchDataCount(string aSql);
     
    /**
     *  ��ʼ����
     *
     *  @return �������(sqlite3�ṩ�ĺ�)
     */
    int beginTransaction();
     
    /**
     *  �ύ����(ʧ�ܻع�)
     *
     *  @param aResult       �������
     *
     *  @return �������(sqlite3�ṩ�ĺ�)
     */
    int comitTransaction(int aResult);
};

#endif