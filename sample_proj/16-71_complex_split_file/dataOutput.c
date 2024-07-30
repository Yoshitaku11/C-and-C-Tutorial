#include "dataOutput.h"
#include<stdio.h>

extern int Error;	// エラーメッセージ、studentDatabase.cからのErrorを利用している


void showStudentData(student* studentData) {
	if (studentData != NULL) {
		printf("id: %d\nname: %s\n", studentData->id, studentData->name);
	}
	else
		printf("登録されていません");
}


// エラーメッセージの表示
void showError() {
	if (Error == MESSAGE_ERROR)
		printf("Registration error!!\n");
	else
		printf("Registration complete!!\n");
}