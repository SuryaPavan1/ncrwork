
/*Write a program to count the number of ‘e’ in the following array of
pointer to the string.
char * s [ ] = {
“we will teach you how to “ ;
“Move a mountain “ ;
“Level a building “ ;
“Erase the past “;
“Make a million “ ;}.*/

#include<stdio.h>
int main()
{
	char s[5][30]={ "we will teach you how to","Move a mountain","Level a building","Erase the past","Make a million" };
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; s[i][j] != '\0'; j++) {
			if (s[i][j] == 'e' || s[i][j] == 'E') {
				count++;
			}
		}
	}
	printf("the number of e's %d\n", count);
	getchar();
	getchar();
	return 0;
}