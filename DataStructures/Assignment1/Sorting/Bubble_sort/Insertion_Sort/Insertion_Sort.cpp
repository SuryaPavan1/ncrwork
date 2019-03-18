#include<iostream>
using namespace std;
void Insertion_Sort(int *data, int length)
{
	int k;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			k = data[i];
			j = i - 1;
			while(j>=0&&data[j]>k)
			{
				data[j + 1] = data[j];
				j = j - 1;
			}
			data[j+1] = k;
		}
	}
}
int main()
{
	int length, *data = NULL;
	cout << "enter the length";
	cin >> length;
	data = new int[length];
	for (int i = 0; i < length; i++)
	{
		cin >> data[i];
	}
	Insertion_Sort(data, length);
	cout << "The sorted array is ";
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
	system("pause");
	return 0;

}