#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <winsock2.h>
#include <windows.h>
#include "Library_IDManager.hpp"
#include "Function_MessageParser.hpp"

using namespace std;

////////// variables ////////////                      
thread HandleClient[10]; 
SOCKET ClientConn[10];


////////////////////////////////////////////////// Function NetworkCom //////////////////////////////////////////////////////////////////////////////////////////////////
void NetworkCom(int loc);   
int UserAuthentication(char* idChar, char* password)
{

	char Query[200] = "SELECT * FROM UserData WHERE ID=";
	strcat_s(Query, idChar);
	//Data Extraction
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR*)Query, SQL_NTS)) {
		cout << "Error query";
		SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		SQLDisconnect(sqlConnHandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVersion;
	if (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		if (strcmp(password, (char *)(sqlVersion)) == 0)
			return 1;
	}
	return 0;
}
void NetworkCom(int loc)
{
	int flag = 0;
    char datatemp[512] = " ";
    char msgtemp[512] = " ";
	char id[3];
	char password[50];
	int cstate;
    AuthDataParsed AuthData;
  
	recv(ClientConn[loc], id, 512, 0);
	cout << id;
	send(ClientConn[loc], "Enter password ", 57, 0);
	recv(ClientConn[loc], password, 512, 0);
	cout << password;
	while (UserAuthentication(id, password)) {
		send(ClientConn[loc], "Enter a valid password", 57, 0);
		recv(ClientConn[loc], password, 512, 0);
	}
	send(ClientConn[loc], "Enter id of client with whom you want to chat", 57, 0);
	do
	{
		cstate=recv(ClientConn[loc], datatemp, 512, 0);
	} while (cstate <= 0);

	AuthDataParser(datatemp,AuthData);
	IDStore(AuthData.ID,loc);
	
	cout<<">>"<<"ID # "<<AuthData.ID<<" sID # "<<AuthData.sID<<endl;
	
	while(ClientConn[loc] != INVALID_SOCKET)
	{  
	    flag = recv(ClientConn[loc],msgtemp,512,0);
	    
	    flag = 0;
	    
		flag = send(ClientConn[ReturnLocation(AuthData.sID)],msgtemp,512,0);
		
	    flag = 0;
	    
		if(!strcmp(msgtemp,"EXIT"))
		{
			closesocket(ClientConn[loc]);
			cout<<"Client "<<AuthData.ID<<" has disconnected"<<endl;
			cout<<"Client "<<AuthData.sID<<" has disconnected"<<endl;
			break;
		}
	}
    
}

/////////////////////////////////////////////////// Function CreateClientThread ///////////////////////////////////////////////////////////////////////////////////////
void CreateClientThread(int location);

void CreateClientThread(int location)
{
   	HandleClient[location] = thread(NetworkCom,location);
   	HandleClient[location].detach();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


