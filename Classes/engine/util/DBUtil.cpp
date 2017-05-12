#include "DBUtil.h"

static DBUtil* s_pInstance = NULL;

DBUtil::DBUtil():m_pDataBase(NULL) 
{
}

DBUtil::DBUtil(string dbName)
{
	m_dbName = dbName;
}
 
DBUtil::~DBUtil() 
{
}
 
DBUtil* DBUtil::getInstance(string dbName) 
{
    if (!s_pInstance) 
	{
        s_pInstance = new DBUtil(dbName);
    }
    return s_pInstance;
}
 
void DBUtil::destoryInstance() 
{
    delete s_pInstance;
    s_pInstance = NULL;
}

/**
 *  �����ݿ�(����)
 *
 *  @param aDataBaseName ���ݿ���
 */
void DBUtil::openDBWithName(std::string aDataBaseName) 
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::string dbPath = aDataBaseName;
#else
    std::string writeablePath = FileUtils::getInstance()->getWritablePath();
	//log("path=%s", writeablePath.c_str());
	std::string dbPath = writeablePath + aDataBaseName;
#endif
     
    int result = sqlite3_open(dbPath.c_str(), &m_pDataBase);
    char* errMsg = NULL;
    if (result != SQLITE_OK) {
        log("Open database failed with error code:%d��message:%s\n", result, errMsg);
    }
     
    if (errMsg) {
        sqlite3_free(errMsg);
        errMsg = NULL;
    }
}
 
/**
 *  �ر����ݿ�
 */
void DBUtil::closeDB() {
    if (m_pDataBase) {
        sqlite3_close(m_pDataBase);
        m_pDataBase = NULL;
    }
}
 
/**
 *  �������ݱ�
 *
 *  @param aSql       ����sql���
 *  @param aTableName ����
 *
 *  @usage string sql = "create table user(id integer, username text, password text)";
 */
void DBUtil::createTable(std::string aSql, std::string aTableName) {
     
    openDBWithName(m_dbName);
     
    if (!isExistTableByName(aTableName)) {
        char* errMsg = NULL;
        int result = sqlite3_exec(m_pDataBase, aSql.c_str(), NULL, NULL, &errMsg);
        if (result != SQLITE_OK) {
            log("������ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg);
        }
         
        if (errMsg) {
            sqlite3_free(errMsg);
            errMsg = NULL;
        }
    }
     
    closeDB();
}
 
/**
 *  �Ƿ����ĳ�����ݱ�Ĳ�ѯ�ص�
 *
 *  @return 0
 */
int isExistTableCallback(void* para, int n_column, char ** column_value, char ** column_name) {
    bool *isExisted_= (bool*)para;
    *isExisted_= (**column_value) != '0';
    return 0;
}
 
/**
 *  ͨ��������ѯ�ñ��Ƿ����
 *
 *  @param aTabelName ����
 *
 *  @return true: ���� false: ������
 */
bool DBUtil::isExistTableByName(std::string aTabelName) {
     
    if (m_pDataBase) {
        //�жϱ��Ƿ����
        bool isExist;
        char* errMsg = NULL;
        std::string sql = "select count(type) from sqlite_master where type = 'table' and name = '" + aTabelName + "'";
        int result = sqlite3_exec(m_pDataBase, sql.c_str(), isExistTableCallback, &isExist, &errMsg);
         
        if (result != SQLITE_OK) {
            log("��ѯ���Ƿ����ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg);
        }
         
        if (errMsg) {
            sqlite3_free(errMsg);
            errMsg = NULL;
        }
         
        return isExist;
    }
     
    return false;
}
 
/**
 *  ɾ�����ݱ�
 *
 *  @param aSql       ɾ��sql���
 *  @param aTableName ����
 *
 *  @usage string sql = "drop table name";
 */
void DBUtil::deleteTable(std::string aSql, std::string aTableName) {
     
    openDBWithName(m_dbName);
     
    beginTransaction();
     
    int result = 0;
    if (isExistTableByName(aTableName)) {
        char* errMsg = NULL;
        result = sqlite3_exec(m_pDataBase, aSql.c_str(), NULL, NULL, &errMsg);
        if (result != SQLITE_OK) {
            log("������ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg);
        }
         
        if (errMsg) {
            sqlite3_free(errMsg);
            errMsg = NULL;
        }
    }
     
    comitTransaction(result);
     
    closeDB();
     
}
 
/**
 *  �����¼
 *
 *  @param aSql ��������sql���
 *
 *  @usage string sql = "insert into User(name) values ('cc') ";
 */
void DBUtil::insertData(std::string aSql) {
     
    openDBWithName(m_dbName);
     
    beginTransaction();
     
    char* errMsg = NULL;
    int result = sqlite3_exec(m_pDataBase, aSql.c_str(), NULL, NULL, &errMsg);
    if (result != SQLITE_OK) {
        log("�����¼ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg );
    }
     
    if (errMsg) {
        sqlite3_free(errMsg);
        errMsg = NULL;
    }
     
    comitTransaction(result);
     
    closeDB();
}
 
/**
 *  ɾ����¼
 *
 *  @param aSql ��������sql���
 *
 *  @usage string sql = "delete from User where name = 'cc'";
 */
void DBUtil::deleteData(std::string aSql) {
     
    openDBWithName(m_dbName);
     
    beginTransaction();
     
    char* errMsg = NULL;
    int result = sqlite3_exec(m_pDataBase, aSql.c_str(), NULL, NULL, &errMsg);
    if (result != SQLITE_OK ) {
        log("ɾ����¼ʧ�ܣ�������:%d������ԭ��:%s\n" , result, errMsg);
    }
     
    if (errMsg) {
        sqlite3_free(errMsg);
        errMsg = NULL;
    }
     
    comitTransaction(result);
     
    closeDB();
     
}
 
/**
 *  �޸ļ�¼
 *
 *  @param aSql �޸�����sql���
 */
void DBUtil::updateData(std::string aSql) {
     
    openDBWithName(m_dbName);
     
    beginTransaction();
     
    char* errMsg = NULL;
    int result = sqlite3_exec(m_pDataBase, aSql.c_str(), NULL, NULL, &errMsg );
    if (result != SQLITE_OK) {
        log( "�޸ļ�¼ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg );
    }
     
    if (errMsg) {
        sqlite3_free(errMsg);
        errMsg = NULL;
    }
     
    comitTransaction(result);
     
    closeDB();
}
 
/**
 *  ��ѯ�ص�
 *
 *  @return 0
 */
int searchDataCallback(void* para, int n_column, char** column_value, char** column_name ) {
    std::map<std::string, std::string> mapResults ;
    for (int i = 0; i < n_column; i++) {
        mapResults.insert(std::make_pair<std::string, std::string>((std::string)column_name[i], (std::string)column_value[i]));
    }
    std::vector<std::map<std::string, std::string> >* vect = (std::vector<std::map<std::string, std::string> >*)para;
    vect->push_back(mapResults);
    return 0;
}
 
 
/**
 *  ��ѯ��¼
 *
 *  @param aSql     ��ѯ����sql���
 */
std::vector<std::map<std::string, std::string> > DBUtil::searchData(std::string aSql) {
     
//    long long int startTime = getNowTime();
//    CCLOG("startTime=%lld", getNowTime());
    
	log("DBUtil::searchData with sql: %s", aSql);

    openDBWithName(m_dbName);
     
    //vector�ǲ�ѯ�Ľ������ÿһ�����������map��
    //map�ĵ�һstring��key(�ֶ���)���ڶ���string��value(��ѯ���Ķ�Ӧ����)
    std::vector<std::map<std::string, std::string>> vec;
     
    char* errMsg = NULL;
    int result = sqlite3_exec(m_pDataBase, aSql.c_str(), searchDataCallback, &vec, &errMsg);
    if (result != SQLITE_OK) {
        log("searchData failed with error code: %d, message:%s", result, errMsg);
    }
     
    if (errMsg) {
        sqlite3_free(errMsg);
        errMsg = NULL;
    }
     
    closeDB();
     
//    long long int endTime = getNowTime();
//    CCLOG("endTime=%lld", endTime);
//    CCLOG("needTime=%lld", endTime - startTime);
     
    return vec;
}
 
/**
 *  ��ѯ���������ص�
 *
 *  @return 0
 */
int searchDataCountCallback(void* para, int n_column, char** column_value, char** column_name) {
    int* count = (int*)para;
    *count = (int)atof(column_value[0]);
    return 0;
}
 
/**
 *  ��ѯ��¼������
 *
 *  @param sql ��ѯ��¼sql���
 *
 *  @return ��¼����
 */
int DBUtil::searchDataCount(std::string aSql) {
     
    openDBWithName(m_dbName);
    log("DBUtil::searchDataCount with sql: %s", aSql);

    int count = 0;
    char* errMsg = NULL;
    int result = sqlite3_exec(m_pDataBase, aSql.c_str(), searchDataCountCallback, &count, &errMsg);
    if (result != SQLITE_OK) {
        log( "��ѯ��¼����ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg);
    }
     
    if (errMsg) {
        sqlite3_free(errMsg);
        errMsg = NULL;
    }
     
    closeDB();
     
    return count;
}
 
/**
 *  ��ʼ����
 *
 *  @return �������(sqlite3�ṩ�ĺ�)
 */
int DBUtil::beginTransaction() {
    char* errMsg = NULL;
    int result = sqlite3_exec(m_pDataBase, "begin transaction", 0, 0, &errMsg);
    if (result != SQLITE_OK ){
        log("��ʼ�����¼ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg);
    }
    return result;
}
 
/**
 *  �ύ����(ʧ�ܻع�)
 *
 *  @param aResult       �������
 *
 *  @return �������(sqlite3�ṩ�ĺ�)
 */
int DBUtil::comitTransaction(int aResult) {
    if (aResult == SQLITE_OK) {
        char* errMsg = NULL;
        int result = sqlite3_exec(m_pDataBase, "commit transaction", 0, 0, &errMsg);
        if (result != SQLITE_OK) {
            log("�ύ�����¼ʧ�ܣ�������:%d������ԭ��:%s\n" , result, errMsg);
        }
        return result;
    } else {
        char* errMsg = NULL;
        int result = sqlite3_exec(m_pDataBase, "rollback transaction", 0, 0, &errMsg);
        if (result != SQLITE_OK ) {
            log("�ع������¼ʧ�ܣ�������:%d������ԭ��:%s\n", result, errMsg);
        }
        return result;
    }
}
