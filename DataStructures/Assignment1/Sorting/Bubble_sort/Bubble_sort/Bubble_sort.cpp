#include<iostream>
using namespace std;
void Bubble_sort(int *p, int length)
{
	int flag = 0;
	for (int i = 0; i < length; i++)
	{
		flag = 0;
		for (int j = 0; j < length - i - 1; j++)
		{

			if (p[j+1] < p[j])
			{
				p[j+1] = p[j] + p[j+1];
				p[j] = p[j+1] - p[j];
				p[j+1] =p[j+1] - p[j];
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
int main()
{
	int a;
	cout << "Enter the length";
	cin >> a;
	int *p = new int[a];
	for (int i = 0; i < a; i++)
	{
		cin >> p[i];
	}
	Bubble_sort(p, a);
	for (int i = 0; i < a; i++)
	{
		cout << " " << p[i];
	}
	system("pause");
	return 0;
}