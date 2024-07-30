#ifndef _STUDENT_DATABASE_H_
#define _STUDENT_DATABASE_H_


#define MAX_STUDENT 10			// �w���̍ő吔
#define LENGTH 50						// �w���̖��O�̍ő咷��

enum ERROR {
	MESSAGE_OK,
	MESSAGE_ERROR
};

// �\���̂̐錾
typedef struct {
	int id;
	char name[LENGTH];
}student;



// �֐��v���g�^�C�v�錾
void initDatabase();	// �f�[�^�x�[�X�̏�����
int add(int, char*);	// �f�[�^�x�[�X�ւ̃f�[�^�̓o�^�i�w���ԍ��A���O�j
student* get(int);	// �w���̃f�[�^�̎擾


#endif // _STUDENT_DATABASE_H_
