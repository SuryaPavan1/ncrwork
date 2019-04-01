#ifndef SQL_RESULT_LEN
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
using namespace std;


#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

//define handles and variables
SQLHANDLE sqlConnHandle;
SQLHANDLE sqlStmtHandle;
SQLHANDLE sqlEnvHandle;
SQLCHAR retconstring[SQL_RETURN_CODE_LEN];

	
void COMPLETED()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	exit(0);
}
	void SQLConnection() {
		sqlConnHandle = NULL;
		sqlStmtHandle = NULL;
	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		   COMPLETED();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		COMPLETED();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
	    	COMPLETED();

	//output
	cout << "Attempting connection to SQL Server...";
	cout << "\n";

	//connect to SQL Server	
	//I am using a trusted connection and port 14808
	//it does not matter if you are using default or named instance
	//just make sure you define the server name and the port
	//You have the option to use a username/password instead of a trusted connection
	//but is more secure to use a trusted connection
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		//(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;UID=username;PWD=password;",
		(SQLCHAR*)"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=chatDatabase;UID=myID;PWD=myPW;Trusted=true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		COMPLETED();

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		COMPLETED();

	default:
		break;
	}

	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		COMPLETED();




}
	
#endif