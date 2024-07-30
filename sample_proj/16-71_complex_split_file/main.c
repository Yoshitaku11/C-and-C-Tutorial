#include<stdio.h>
#include"studentDatabase.h"
#include"dataOutput.h"

void main() {
	int i;
	char names[][LENGTH] = { "“c“‡", "²X–Ø", "‰Á“¡", "–ö‘ò" };
	int ids[] = { 1,2,2,4 };
	initDatabase();
	for (i = 0; i < 4; i++) {
		add(ids[i], names[i]);
		printf("Registered: %d %s\n", ids[i], names[i]);
		showError();
	}
	for (i = 0; i < 3; i++) {
		showStudentData(get(i + 1));
	}
}






