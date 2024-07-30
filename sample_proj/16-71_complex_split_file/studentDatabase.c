#include "studentDatabase.h"
#include <string.h>

#define MESSAGE_LENGTH 256	// �G���[���b�Z�[�W�̕������A����.c�t�@�C���ł���MESSAGE_LENGTH�͎g���Ȃ�

// �O���[�o���ϐ�
static int num = 0;	// �f�[�^�x�[�X�ɓo�^����Ă���w���̐��A���̃t�@�C�����ł����g���Ȃ�
static student student_database[MAX_STUDENT];	// �w���̃f�[�^�x�[�X�A���̃t�@�C�������g���Ȃ�
int Error = MESSAGE_OK;	// �G���[���b�Z�[�W

//�f�[�^�x�[�X�̏�����
void initDatabase() {
	int i;
	for (i = 0; i < MAX_STUDENT; i++) {
		student_database[i].id = -1;
		strcpy_s(student_database[i].name, LENGTH, "");
	}
	Error = MESSAGE_OK;	// �G���[���b�Z�[�W�N���A
	num = 0;
}

//DB�̓o�^
int add(int id, char* name) {
	// ���łɓo�^����Ă���ꍇ�͓o�^���Ȃ�
	if (get(id) == NULL && num < MAX_STUDENT) {
		student_database[num].id = id;
		strcpy_s(student_database[num].name, LENGTH, name);
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
