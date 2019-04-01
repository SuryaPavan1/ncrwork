
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Function_SQLConnection.hpp"
using namespace std;
struct AuthDataParsed
{
	int ID;
	int sID;
}; 

void AuthDataParser(char RawMessage[],AuthDataParsed& msg);

void AuthDataParser(char RawMessage[],AuthDataParsed& msg)
{
	char id[3] = "";
	char sid[3] = "";
	
	for(int i=0;i<2;i++)
	{
		id[i] = RawMessage[i];
	}
	
	for(int i=0;i<2;i++)
	{
		sid[i] = RawMessage[i+2];
	}
	
	msg.ID = atoi(id);
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR*)"SELECT * FROM CLIENTID", SQL_NTS)) {
		cout << "Error query";
		SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		SQLDisconnect(sqlConnHandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVersion;
	int flag = 0;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		if (int(sqlVersion) == msg.ID)
			flag = 1;
	}
	char Query[40] = "INSERT INTO ClientID VALUES(";
	char temp[5];
	_itoa_s(msg.ID, temp, 10);
	cout << temp;
	strcat_s(Query,temp);
	strcat_s(Query, ")");
	cout << Query;

	if (flag == 0)
	{
		SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
		if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR*)Query, SQL_NTS)) {
			cout << "Error querying SQL Server";
			cout << "\n";
			SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
			SQLDisconnect(sqlConnHandle);
			SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
			SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
		}
	}
	msg.sID = atoi(sid);
	
}




