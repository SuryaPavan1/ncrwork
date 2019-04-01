#pragma once

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <process.h>
#include <thread>
#include <fstream>
#include <string>
#include <memory>

#include "Function_NetworkCom.hpp"
#include "Function_SQLConnection.hpp"
using namespace std;

#pragma comment (lib, "ws2_32.lib")
   
int ClientStore = 0;                            

class NetworkInit 
{
private:
	//declarations of winsock library objects necessary for the sockets parts to run
	WSAData NetworkData;
    int ListenSocket;
    SOCKADDR_IN Address;
    int AddressSize; 
    
public:
	NetworkInit(); // default constructor
	
    NetworkInit(char IP[],u_short PORT) // argumented constructor
	{  
		
//---------------------------------------Initailize Winsock API----------------------------------------------------------------------------------------------------------------------------
		//process to start the winsock api
		cout<<"Intializing Winsock API";                                                                           
		for(int i=0;i<17;i++)                                                                                                                
		{
			cout<<".";
		}
		if(!WSAStartup(MAKEWORD(2,1),(WSAData*)&NetworkData))
		{
			cout<<"done"<<endl;
		}
		else
		{
			cout << "Error starting Winsock API" << endl;
			cout << "Shutting down the server" << endl;
		    
			closesocket(ListenSocket);
			for(int i=0;i<10;i++)
			{
		    closesocket(ClientConn[i]);
		    }
	        WSACleanup();
	        exit(0);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		Address.sin_port = htons(PORT);
		Address.sin_family = AF_INET;
		inet_pton(AF_INET, IP, &Address.sin_addr);
		
//---------------------------------------Binding Listening Socket--------------------------------------------------------------------------------------------------------------------------		
		//process of binding the socket
		
		cout<<"Binding socket";
		for(int i=0;i<26;i++)
		{
			cout<<".";
			
		}


		ListenSocket = socket(AF_INET,SOCK_STREAM,0);
		
		if(::bind(ListenSocket, (SOCKADDR*)&Address, sizeof(Address)) != SOCKET_ERROR)
		{
			cout<<"done"<<endl;
		}
		else
		{
			cout<<"Error Binding the port"<<endl;
			
		    
			cout<<"Shutting down the server"<<endl;
			
		    
		   	closesocket(ListenSocket);
		   for(int i=0;i<10;i++)
			{
		    closesocket(ClientConn[i]);
		    }
	        WSACleanup();
	        exit(0);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------Intialize listening socket------------------------------------------------------------------------------------------------------------------------		        
		//initialize the listening socket
		
		cout<<"Initializing listening socket";
		
		for(int i=0;i<11;i++)
		{
			cout<<".";
			
		}
		if(!listen(ListenSocket,SOMAXCONN))
		{
			cout<<"done"<<endl;
			
		}
		else
		{
			cout<<"Error in starting listening socket"<<endl;
		    
			cout<<"Shutting down the server"<<endl;

			closesocket(ListenSocket);
		    for(int i=0;i<10;i++)
			{
		    closesocket(ClientConn[i]);
		    }
	        WSACleanup();
	        exit(0);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
		
		AddressSize = sizeof(Address);
		for(int i=0;i<10;i++)
		{
			ClientConn[i] = INVALID_SOCKET;
			ClientConn[i] = socket(AF_INET,SOCK_STREAM,0);
			
			if(ClientConn[i] == INVALID_SOCKET)
		    {
		        cout<<"Error in initialising  listening socket "<<i<<endl;
				
		    }			
		    else
	     	{
		    	cout<<"Socket intialized "<<i<<endl;
		    }			
	    	
		}
	    
	    system("pause");
	    system("cls");
		SQLConnection();
	    cout<<"\t\tTCP Chat Server"<<endl<<endl; // display of server information
		cout<<"\t\t----------------------------------------"<<endl;	
		cout<<"\t\t IP Address :"<<IP<<endl;
		cout<<"\t\t Port Number:"<<PORT<<endl;
		cout<<"\t\t----------------------------------------"<<endl;
    }
//--------------------------------------------Intitalize all client handler sockets--------------------------------------------------------------------------------------------------------		
  
	void AcceptConn()
	{
		for(;;)
		{
	  	    if((ClientConn[ClientStore] = accept(ListenSocket,(SOCKADDR*)&Address,&AddressSize)))
	  		    {
				

				/*	cout<<"Client connected "<<endl;
					send(ClientConn[ClientStore], "Enter your id ", 57, 0);
					recv(ClientConn[ClientStore], id, 512, 0);
					cout << id;
					send(ClientConn[ClientStore], "Enter password ", 57, 0);
					recv(ClientConn[ClientStore], password, 512, 0);
					cout << password;
					while (UserAuthentication(id, password)) {
						send(ClientConn[ClientStore], "Enter a valid password ", 57, 0);
						recv(ClientConn[ClientStore], password, 512, 0);
					}*/
					send(ClientConn[ClientStore],"Enter your id ",57,0); // send necessary instructions to the client
					CreateClientThread(ClientStore); // call function to create new client managing thread
					ClientStore++;		  	//increment the client counter
				}
        }
    }

	
    
    ~NetworkInit()
    {

    	// destructor -- shutdown the winsock api, delete the socket object
    	for(int i=0;i<10;i++)
    	{
    		cout<<"Closing socket "<<i<<endl;
    		closesocket(ClientConn[i]);
		}
		cout<<"Shutting down Winsock API"<<endl;
		
		
		closesocket(ListenSocket);
		WSACleanup();
		exit(0);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
