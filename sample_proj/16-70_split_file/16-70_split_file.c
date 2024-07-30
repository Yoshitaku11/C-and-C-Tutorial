#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENT 10			// 学生の最大数
#define LENGTH 50						// 学生の名前の最大長さ
#define MESSAGE_LENGTH 256	// エラーメッセージの文字数

enum ERROR {
	MESSAGE_OK,
	MESSAGE_ERROR
};

// 構造体の宣言
typedef struct {
	int id;
	char name[LENGTH];
}student;

// グローバル変数
int num = 0;
student student_database[MAX_STUDENT];
int Error;

// 関数プロトタイプ宣言
void initDatabase();	// データベースの初期化
int add(int, char*);	// データベースへのデータの登録（学生番号、名前）
student* get(int);	// 学生のデータの取得
void showStudentData(student*);	// 学生データの表示
void showError();	// エラーの表示

void main() {
	int i;
	char names[][LENGTH] = { "田島", "佐々木", "加藤", "柳沢" };
	int ids[] = { 1,2,2,4 };
	initDatabase();
	for (i = 0; i < 4; i++) {
		add(ids[i], names[i]);
		printf("Registered: %d %s\n", ids[i], names[i]);
		showError();
	}
	for (i = 0; i < 3; i++) {
		showStudentData(get(i + 1));
	}
}

//データベースの初期化
void initDatabase() {
	int i;
	for (i = 0; i < MAX_STUDENT; i++) {
		student_database[i].id = -1;
		strcpy_s(student_database[i].name,LENGTH, "");
	}
	Error = MESSAGE_OK;	// エラーメッセージクリア
	num = 0;
}
//DBの登録
int add(int id, char* name) {
	// すでに登録されている場合は登録しない
	if (get(id) == NULL && num < MAX_STUDENT) {
		student_database[num].id = id;
		strcpy_s(student_database[num].name,LENGTH, name);
		num++;
		Error = MESSAGE_OK;
		return 1;
	}
	Error = MESSAGE_ERROR;	// 登録できない場合はエラー
	return 0;
}

student* get(int id) {
	int i;
	for (i = 0; i < MAX_STUDENT; i++) {
		if (student_database[i].id == id)
			return &student_database[i];	// idと一致したアドレスを返す
	}
	return NULL;	//	見つからない場合はNULLを返す
}


void showStudentData(student* studentData) {
	if (studentData != NULL) {
		printf("id: %d\nname: %s\n", studentData->id, studentData->name);
	}
	else
		printf("登録されていません");
}


// エラーメッセージの表示
void showError() {
	if (Error == MESSAGE_ERROR)
		printf("Registration error!!\n");
	else
		printf("Registration complete!!\n");
}

