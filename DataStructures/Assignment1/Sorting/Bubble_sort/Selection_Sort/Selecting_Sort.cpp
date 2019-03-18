#include<iostream>
using namespace std;
void Selection_Sort(int *data,int length)
{
	int min,temp;
	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (data[min] > data[j])
			{
				min = j;
			}
		}
		temp = data[i];
		data[i] = data[min];
		data[min] = temp;
	}
}
int main()
{
	int length,*data=NULL;
	cout << "enter the length";
	cin >> length;
	data = new int[length];
	for (int i = 0; i < length; i++)
	{
		cin >> data[i];
	}
	Selection_Sort(data, length);
	cout << "The sorted array is ";
	for (int i = 0; i < length; i++)
	{
		cout << data[i]<<" ";
	}
    system("pause");
	return 0;
	
}