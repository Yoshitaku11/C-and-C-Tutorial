#include <stdio.h>
#include <string.h>

// �w���̃f�[�^������\����
typedef struct {
	int id;	// �w���ԍ�
	char name[256]; // ���O
	int age; // �N��
}student_data;

void setData(student_data*, int, char*, int);
void showData(student_data*);

void main(){
	student_data data[4];
	int i;
	int id[] = { 1, 2, 3, 4 };
	char name[][256] = { "�R�c���Y", "��������", "���c��", "���c�B�F��" };
	int age[] = { 19, 20, 21, 22 };
	// �f�[�^�̐ݒ�
	for (i = 0; i < 4; i++) {
		setData(&data[i], id[i], name[i], age[i]);
	}

	// �f�[�^�̓����\��
	for (i = 0; i < 4; i++) {
		showData(&data[i]);
	}
}

void setData(student_data* data, int id, char* name, int age) {
// �\���̂̃|�C���^�ɑ΂��Ēl��n���ꍇ��allow���Z�q -> �����p�����
	data->id = id;
	strcpy_s(data->name, name);
	data->age = age;
}

void showData(student_data* data) {
	printf(" id: %d\n name: %s\n age: %d\n", data->id, data->name, data->age);
}