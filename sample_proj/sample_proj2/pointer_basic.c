#include <stdio.h>

// �v���g�^�C�v�錾
void show(int, int, int);

void main() {
	int a = 100;
	int b = 200;
	int* p = NULL;	// �����^�̃|�C���^
	p = &a;			// p��a�̃A�h���X����
	show(a, b, *p);	// *p�ɂ��邱�ƂŁA���g���m�F���邱�Ƃ��ł���
	*p = 300;	// *p�ɒl����
	show(a, b, *p);
	p = &b;	// p��b�̃A�h���X����
	show(a, b, *p);
	*p = 400;	// *p�ɒl����
	show(a, b, *p);
}

/*
 �܂Ƃ߂��
 p = &a �F �A�h���X�����\
 *p = 100 �F �A�h���X����������̒��g���Q�ƁA�ύX�\
 
 ���ӓ_
 �E�|�C���^��NULL�ŏ��������邱��
 �E�A�h���X���w�肵�Ȃ��܂܁A�l�������Ȃ�����
*/

void show(int n1, int n2, int n3){
	printf("a = %d b = %d p = %d\n", n1, n2, n3);
}