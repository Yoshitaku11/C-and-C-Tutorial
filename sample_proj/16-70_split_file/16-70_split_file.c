#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENT 10			// �w���̍ő吔
#define LENGTH 50						// �w���̖��O�̍ő咷��
#define MESSAGE_LENGTH 256	// �G���[���b�Z�[�W�̕�����

enum ERROR {
	MESSAGE_OK,
	MESSAGE_ERROR
};

// �\���̂̐錾
typedef struct {
	int id;
	char name[LENGTH];
}student;

// �O���[�o���ϐ�
int num = 0;
student student_database[MAX_STUDENT];
int Error;

// �֐��v���g�^�C�v�錾
void initDatabase();	// �f�[�^�x�[�X�̏�����
int add(int, char*);	// �f�[�^�x�[�X�ւ̃f�[�^�̓o�^�i�w���ԍ��A���O�j
student* get(int);	// �w���̃f�[�^�̎擾
void showStudentData(student*);	// �w���f�[�^�̕\��
void showError();	// �G���[�̕\��

void main() {
	int i;
	char names[][LENGTH] = { "�c��", "���X��", "����", "����" };
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

//�f�[�^�x�[�X�̏�����
void initDatabase() {
	int i;
	for (i = 0; i < MAX_STUDENT; i++) {
		student_database[i].id = -1;
		strcpy_s(student_database[i].name,LENGTH, "");
	}
	Error = MESSAGE_OK;	// �G���[���b�Z�[�W�N���A
	num = 0;
}
//DB�̓o�^
int add(int id, char* name) {
	// ���łɓo�^����Ă���ꍇ�͓o�^���Ȃ�
	if (get(id) == NULL && num < MAX_STUDENT) {
		student_database[num].id = id;
		strcpy_s(student_database[num].name,LENGTH, name);
		num++;
		Error = MESSAGE_OK;
		return 1;
	}
	Error = MESSAGE_ERROR;	// �o�^�ł��Ȃ��ꍇ�̓G���[
	return 0;
}

student* get(int id) {
	int i;
	for (i = 0; i < MAX_STUDENT; i++) {
		if (student_database[i].id == id)
			return &student_database[i];	// id�ƈ�v�����A�h���X��Ԃ�
	}
	return NULL;	//	������Ȃ��ꍇ��NULL��Ԃ�
}


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

