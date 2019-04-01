#pragma once

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>


#pragma comment (lib, "ws2_32.lib")

using namespace std;


SOCKET ServerCom = INVALID_SOCKET;
int ClientAddressSize;

SOCKADDR_IN ClientAddress;

class ClientNetworkInit
{
	private:
	    WSAData ClientNetworkData;
	    char message[512];

    public:
        ClientNetworkInit(char sIP[],u_short sPORT)
        {
        	                                                                                                   
		    for(int i=0;i<15;i++)                                                                                                                
	   	    {
			  cout<<".";
			  Sleep(100);
		    }
		    if(!WSAStartup(MAKEWORD(2,2),(WSAData*)&ClientNetworkData))
		    {
		    	cout<<"done"<<endl;
			}
			else
			{
				cout<<"Error starting Winsock API"<<endl;
			    
			    cout<<"Shutting down the server"<<endl;
			    
				closesocket(ServerCom);
	            WSACleanup();
	            exit(0);
			}
            
		    ClientAddress.sin_port = htons(sPORT);
		    ClientAddress.sin_family = AF_INET;
			inet_pton(AF_INET, sIP, &ClientAddress.sin_addr);
		    
		    ClientAddressSize = sizeof(ClientAddress);
		    ServerCom = socket(AF_INET,SOCK_STREAM,0);
		    
		    if(ServerCom == INVALID_SOCKET)
		    {
		        cout<<"Error initialising socket"<<endl;
				closesocket(ServerCom);
	            WSACleanup();
	            exit(0);
			}
			else
			{
				cout<<"Socket Intialised"<<endl;
			}
		}
        void ConnectServer()
        {
            int val;
            val = connect(ServerCom,(SOCKADDR*)&ClientAddress,ClientAddressSize); 
            if(!val)
            {
               cout<<"Connected to server"<<endl;
			} 
			   
		    else
		    {
		     cout<<"Unable to connect to the server"<<endl;	
		     
			
		     cout<<"Closing chat client"<<endl;
		     
			 
		     WSACleanup();
		     exit(0);
		    }
	    }
};
