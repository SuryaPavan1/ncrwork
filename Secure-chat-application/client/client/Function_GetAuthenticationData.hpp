#include <iostream>
#include <string>
using namespace std;

void GetAuthenticationData(char msg[]);

void GetAuthenticationData(char msg[])
{
	string myid;
	string password;
	string chatid;
	
	cout<<"Enter your ID: ";
	cin>>myid;

	cout << "Enter your password";
	cin >> password;
	//ClientAuthentication(id,password);
	cout<<"Enter the ID with whom you want to chat: ";
	cin>>chatid;
		
	myid = myid + chatid;
	
	strcpy_s(msg,5,myid.c_str());  
	
}