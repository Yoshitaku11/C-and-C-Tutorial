#ifndef _STUDENT_DATABASE_H_
#define _STUDENT_DATABASE_H_


#define MAX_STUDENT 10			// 学生の最大数
#define LENGTH 50						// 学生の名前の最大長さ

enum ERROR {
	MESSAGE_OK,
	MESSAGE_ERROR
};

// 構造体の宣言
typedef struct {
	int id;
	char name[LENGTH];
}student;



// 関数プロトタイプ宣言
void initDatabase();	// データベースの初期化
int add(int, char*);	// データベースへのデータの登録（学生番号、名前）
student* get(int);	// 学生のデータの取得


#endif // _STUDENT_DATABASE_H_
