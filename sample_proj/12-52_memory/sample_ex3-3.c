#include <stdio.h>
#include <stdlib.h>

#define SIZE    3

void main() {
	int* p1 = NULL;
	double *p2 = NULL;
	int i;
	//  �z��̐���
	p1 = (int*)malloc(sizeof(int)*SIZE);
	p2 = (double*)malloc(sizeof(double)*SIZE);
	//  �l�̑��
	for (i = 0; i < SIZE; i++) {
		p1[i] = i;
		p2[i] = i / 10.0;
	}
	//  ���ʂ̏o��
	for (i = 0; i < SIZE; i++) {
		printf("p1[%d]=%d  p2[%d]=%f\n", i, p1[i], i, p2[i]);
	}
	//  �������̊J��
	free(p1);
	free(p2);
}