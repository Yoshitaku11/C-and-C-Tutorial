#include <stdio.h>
#include <string.h>

// �\����
struct physical
{
	int id;    // ��f�ԍ�
	char name[256];     // ���O
	int age;    // �N��
	double height; // �g��
	double weight; // �̏d
};

// �\���̖̂��O��typedef�Œ�`
typedef struct physical physical_data;    // struct physical��physical_data�����Ő錾�\

void main() {
/*	struct physical data;
	data.id = 1;
	strcpy_s(data.name,sizeof(data.name), "�g����");
	data.age = 20;
	data.height = 170.0;
	data.weight = 65.0;

	printf("id = %d \n ���O = %s\n �N�� = %d \n �g�� = %.2f\n �̏d=%.2f", data.id, data.name, data.age, data.height, data.weight);
*/
	int size;
	physical_data data[] = {
		{1, "Takeshi", 20, 160, 60 },
		{2, "Takumi", 24, 165, 70},
		{3, "Akira", 24, 180, 70},
	};

	size = sizeof(data) / sizeof(data[0]); // �v�f�����v�Z

	//printf("%d\n", size);

		for(int  i = 0;  i < size; i++)
		{
			printf("id = %d \n ���O = %s\n �N�� = %d \n �g�� = %.2f\n �̏d=%.2f\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
		}
}