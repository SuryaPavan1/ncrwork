#include <iostream>
#include <process.h>
#include <conio.h>
#include "Function_Menu.hpp"
#include "Class_NetworkInit.hpp"
using namespace std;


void CommandHandle(NetworkInit& a);

void CommandHandle(NetworkInit& a)
{
	char command[5];
	
	cin.ignore();
	
	while(1)
	{
		if(_kbhit())
		{
			cin.getline(command,20);
		}
		
		if(!strcmp(command,"quit"))
		{
			a.~NetworkInit();
			break;
		}
	}
}

void RunServer();

void RunServer()
{
	//WriteRunCounter();
	char IP[16]="127.0.0.1";
    u_short PORT=444;
    thread CommandHandler;

    system("cls");
	//cout<<"\n\n\t\tEnter the server ip address: ";
  	//cin>>IP;
    //cout<<endl;
    			
   // cout<<"\t\tEnter the server port: ";
    //cin>>PORT;
    //cout<<endl;
    			    			
    NetworkInit com(IP,PORT);
    CommandHandler = thread(CommandHandle,ref(com));

    com.AcceptConn();
}

void about();

void about()
{
	system("cls");
	cout<<"TCP Chat Server"<<endl;

}

void help();

void help()
{
	system("cls");
	cout<<"Press 1 to start server"<<endl;
	cout<<"Then enter the ip address on which the server should be accessible...it should be your PC's local ip or 127.0.0.1 for localhost"<<endl;
	cout<<"After that enter the port on which it should work"<<endl;
	cout<<"Now the Server is setup and now clients can connect"<<endl;
	system("pause");
}
int main()
{
	do
	{
		switch(Menu())
		{
			case 1:
				RunServer();
				break;
				
			case 2:
				about();
				break;
					
			case 3:
				help();
				break;
						
			case 4:
				exit(0);
				break;
		}
	}while(1);

	return 0;
}
