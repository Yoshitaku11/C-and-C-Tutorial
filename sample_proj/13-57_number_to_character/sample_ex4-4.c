#include <stdio.h>
#include <string.h>

void main() {
	char s1[256], s2[256];
	int a = 100, b = 200;
	sprintf(s1, "%d", a);
	sprintf(s2, "b‚Ì’l‚Í%d‚Å‚·B", b);
	puts(s1);
	puts(s2);
}