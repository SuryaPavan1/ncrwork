#include<iostream> 
using namespace std;

template <class T>
void Lsearch(T *a, T item, int n)
{
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == item)
		{
			cout << "\n Item found at position = " << i + 1 << "\n\n";
			z = 1;
			return;
		}
	}
	cout << "\nNot Found\n\n";
}
int main()
{
	int sizeI, sizeD, sizeF;
	int arrayInt[10];
	cout << "Enter no of elements in Int array:";
	cin >> sizeI;
	cout << "Enter array elements";
	for (int k = 0; k < sizeI; k++)
		cin >> arrayInt[k];
	double arrayDouble[10];
	cout << "Enter no of elements in Double array:";
	cin >> sizeD;
	for (int j = 0; j < sizeD; j++)
		cin >> arrayDouble[j];
	float arrayFloat[10];
	cout << "Enter no of elements in Float array:";
	cin >> sizeF;
	for (int j = 0; j < sizeF; j++)
		cin >> arrayDouble[j];
	int itemI;
	double itemD;
	float itemF;

	cout << "\n Elements of Integer Array \n";
	for (int i = 0; i < sizeI; i++)
	{
		cout << arrayInt[i] << " ";
	}
	cout << "\n Enter an item to be search: ";
	cin >> itemI;

	cout << "\n Linear Search Method\n";
	Lsearch(arrayInt, itemI, sizeI);
	cout << "\n Elements of double Array \n";
	for (int i = 0; i < sizeD; i++)
	{
		cout << arrayDouble[i] << " ";
	}
	cout << "\n Enter an item to be search: ";
	cin >> itemD;

	cout << "Linear Search Method\n";
	Lsearch(arrayDouble, itemD, sizeD);
	cout << "\n Elements of Float Array \n";
	for (int i = 0; i < sizeF; i++)
	{
		cout << arrayInt[i] << " ";
	}
	cout << " \nEnter an item to be search: ";
	cin >> itemF;

	cout << "\n Linear Search Method\n";
	Lsearch(arrayFloat, itemF, sizeF);

	return 0;
}