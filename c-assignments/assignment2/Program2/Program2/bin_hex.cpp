#include<stdio.h>
void binToHex(int binary)
{


	int  hexadecimalval = 0, i = 1, rem;
	while (binary != 0)
	{
		rem = binary % 10;
		hexadecimalval = hexadecimalval + rem * i;
		i = i * 2;
		binary = binary / 10;
	}
	printf(" hexadecimal value is: %lX", hexadecimalval);
}
void HexToBin()
{
	char binarynum[100], hexa[100];
	long int i = 0;

	printf("Enter the value for hexadecimal ");
	scanf_s("%s", hexa, 100);
	printf("\n binary value of %s : ", hexa);
	while (hexa[i])
	{
		switch (hexa[i])
		{
		case '0':
			printf("0000"); break;
		case '1':
			printf("0001"); break;
		case '2':
			printf("0010"); break;
		case '3':
			printf("0011"); break;
		case '4':
			printf("0100"); break;
		case '5':
			printf("0101"); break;
		case '6':
			printf("0110"); break;
		case '7':
			printf("0111"); break;
		case '8':
			printf("1000"); break;
		case '9':
			printf("1001"); break;
		case 'A':
			printf("1010"); break;
		case 'B':
			printf("1011"); break;
		case 'C':
			printf("1100"); break;
		case 'D':
			printf("1101"); break;
		case 'E':
			printf("1110"); break;
		case 'F':
			printf("1111"); break;
		case 'a':
			printf("1010"); break;
		case 'b':
			printf("1011"); break;
		case 'c':
			printf("1100"); break;
		case 'd':
			printf("1101"); break;
		case 'e':
			printf("1110"); break;
		case 'f':
			printf("1111"); break;
		default:
			printf("\n Invalid hexa digit %c ");
		}
		i++;
	}

}

int main()
{
	int binary, option;
	printf("Enter your choice:\n");
	printf("1.binary-hexadecimal \n");
	printf("2.hexadecimal-binary  ");
	scanf_s("%d", &option);
	if (option == 1)
	{
		printf("Enter the binary number :");
		scanf_s("%d", &binary);
		binToHex(binary);
	}
	else if (option == 2)
	{
		HexToBin();
	}
	getchar();
	getchar();
	return 0;
}
