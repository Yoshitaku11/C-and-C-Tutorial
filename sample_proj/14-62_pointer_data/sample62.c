#include<stdio.h>

//�f�[�^������\����
typedef struct {
	int a;
	double d;
}num_data;

//���ނ̒l�ݒ�֐�
void dealData1(num_data data);			// �l�n��
void dealData2(num_data* pData);		// �f�[�^�n��

void main() {
	num_data n1 = { 1, 1.2 }, n2 = { 1, 1.2 };
	printf("n1�̃A�h���X: 0x%x n2�̃A�h���X:0x%x\n", (unsigned int)&n1, (unsigned int)&n2);
	dealData1(n1);
	dealData2(&n2);
	printf("n1.a = %d n1.d = %f\n", n1.a, n1.d);	// �f�[�^�n���Ȃ̂ŁA�֐����o���猳�̒l�ɖ߂�
	printf("n2.a = %d n2.d = %f\n", n2.a, n2.d);	// �Q�Ɠn���Ȃ̂ŁA�֐����o�Ă��l���ێ������
}

// �l�n���͂Ȃ�ׂ��g��Ȃ��ق��������B�f�[�^�̃R�s�[���傫���Ȃ邵�A�X�^�b�N�̈��]�v�Ɏg�����ƂɂȂ�B
void dealData1(num_data data) {
	printf("a=%d d=%f\n", data.a, data.d);
	printf("dealData1�ɂ킽���Ă����f�[�^�̃A�h���X: 0x%x\n", (unsigned int)&data);
	data.a = 2;
	data.d = 2.4;
}

void dealData2(num_data* pData) {
	printf("a=%d d=%f\n", pData->a, pData->d);
	printf("dealData2�ɂ킽���Ă����f�[�^�̃A�h���X: 0x%x\n", (unsigned int)pData);	// pData���A�h���X
	pData->a = 2;
	pData->d = 2.4;
}

// num_data* pdata
// pdata �̓A�h���X
// *pdata���l�ɂȂ邪�A�\���̂Ȃ̂�pdata->a���l�ɂȂ�