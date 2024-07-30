#include "studentDatabase.h"
#include <string.h>

#define MESSAGE_LENGTH 256	// エラーメッセージの文字数、この.cファイルでしかMESSAGE_LENGTHは使えない

// グローバル変数
static int num = 0;	// データベースに登録されている学生の数、このファイル中でしか使えない
static student student_database[MAX_STUDENT];	// 学生のデータベース、このファイルしか使えない
int Error = MESSAGE_OK;	// エラーメッセージ

//データベースの初期化
void initDatabase() {
	int i;
	for (i = 0; i < MAX_STUDENT; i++) {
		student_database[i].id = -1;
		strcpy_s(student_database[i].name, LENGTH, "");
	}
	Error = MESSAGE_OK;	// エラーメッセージクリア
	num = 0;
}

//DBの登録
int add(int id, char* name) {
	// すでに登録されている場合は登録しない
	if (get(id) == NULL && num < MAX_STUDENT) {
		student_database[num].id = id;
		strcpy_s(student_database[num].name, LENGTH, name);
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
