#include<stdio.h>
#include<malloc.h>
int main() {
	char *text = (char*)malloc(20 * sizeof(char));

	int i = 0, charcount = 0, tabcount = 0, spacecount = 0, digitcount = 0;
	printf("Enter the text: ");
	scanf_s("%[^\n]", text,30);
	while (text[i] != '\0')
	{
		if (text[i] > 'a'&&text[i]<'z' || text[i]>'A'&&text[i] < 'Z')
			charcount++;
		else if (text[i] == 9)
			tabcount++;
		else if (text[i] == ' ')
			spacecount++;
		else if (text[i] > 47 && text[i] < 58)
			digitcount++;
		i++;
	}
	
	printf("\n character count is %d ", charcount);
	printf("\n The tab count is %d ", tabcount);
	printf("\n The space count is %d ", spacecount);
	printf("\n The digit count is %d ", digitcount);
	return 0;
}
