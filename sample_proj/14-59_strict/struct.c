#include <stdio.h>
#include <string.h>

// 構造体
struct physical
{
	int id;    // 受診番号
	char name[256];     // 名前
	int age;    // 年齢
	double height; // 身長
	double weight; // 体重
};

// 構造体の名前をtypedefで定義
typedef struct physical physical_data;    // struct physicalをphysical_dataだけで宣言可能

void main() {
/*	struct physical data;
	data.id = 1;
	strcpy_s(data.name,sizeof(data.name), "吉岡隆");
	data.age = 20;
	data.height = 170.0;
	data.weight = 65.0;

	printf("id = %d \n 名前 = %s\n 年齢 = %d \n 身長 = %.2f\n 体重=%.2f", data.id, data.name, data.age, data.height, data.weight);
*/
	int size;
	physical_data data[] = {
		{1, "Takeshi", 20, 160, 60 },
		{2, "Takumi", 24, 165, 70},
		{3, "Akira", 24, 180, 70},
	};

	size = sizeof(data) / sizeof(data[0]); // 要素数を計算

	//printf("%d\n", size);

		for(int  i = 0;  i < size; i++)
		{
			printf("id = %d \n 名前 = %s\n 年齢 = %d \n 身長 = %.2f\n 体重=%.2f\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
		}
}