#include <stdio.h>

// �v���g�^�C�v�錾
void swap(int*, int*);

void main() {
	int a = 1, b = 2;
	printf("a = %d b = %d\n", a, b);
	swap(&a, &b);	// �|�C���^�̈����Ȃ̂ŁA�A�h���X��n��
	printf("a = %d b = %d\n", a, b);
}

void swap(int* num1, int* num2) {
	int temp = *num1;	// int�̕ϐ���*num1�A�l������B�@*num1���ƃA�h���X�������Ă��܂��̂ŁA���g�����邱��
	*num1 = *num2;
	*num2 = temp;
}