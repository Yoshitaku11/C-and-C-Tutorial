#include "dataOutput.h"
#include<stdio.h>

extern int Error;	// �G���[���b�Z�[�W�AstudentDatabase.c�����Error�𗘗p���Ă���


void showStudentData(student* studentData) {
	if (studentData != NULL) {
		printf("id: %d\nname: %s\n", studentData->id, studentData->name);
	}
	else
		printf("�o�^����Ă��܂���");
}


// �G���[���b�Z�[�W�̕\��
void showError() {
	if (Error == MESSAGE_ERROR)
		printf("Registration error!!\n");
	else
		printf("Registration complete!!\n");
}