#include <stdio.h>
#include <string.h>

void main() {
	char s[10];
	int len;
	//   ������̃R�s�[
	strcpy(s, "ABC");
	printf("s=%s\n", s);
	//   ������̌���
	strcat(s, "DEF");
	printf("s=%s\n", s);
	//   ������̒���
	len = strlen(s);
	printf("������̒����F%d\n", len);
}