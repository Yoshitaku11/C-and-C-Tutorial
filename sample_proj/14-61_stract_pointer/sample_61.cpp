#include <stdio.h>
#include <string.h>

// 学生のデータを入れる構造体
typedef struct {
	int id;	// 学生番号
	char name[256]; // 名前
	int age; // 年齢
}student_data;

void setData(student_data*, int, char*, int);
void showData(student_data*);

void main(){
	student_data data[4];
	int i;
	int id[] = { 1, 2, 3, 4 };
	char name[][256] = { "山田太郎", "佐藤涼香", "太田茂", "中田唯宇個" };
	int age[] = { 19, 20, 21, 22 };
	// データの設定
	for (i = 0; i < 4; i++) {
		setData(&data[i], id[i], name[i], age[i]);
	}

	// データの内訳を表示
	for (i = 0; i < 4; i++) {
		showData(&data[i]);
	}
}

void setData(student_data* data, int id, char* name, int age) {
// 構造体のポインタに対して値を渡す場合はallow演算子 -> が利用される
	data->id = id;
	strcpy_s(data->name, name);
	data->age = age;
}

void showData(student_data* data) {
	printf(" id: %d\n name: %s\n age: %d\n", data->id, data->name, data->age);
}