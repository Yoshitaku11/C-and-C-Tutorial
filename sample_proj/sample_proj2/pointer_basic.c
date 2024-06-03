#include <stdio.h>

// プロトタイプ宣言
void show(int, int, int);

void main() {
	int a = 100;
	int b = 200;
	int* p = NULL;	// 整数型のポインタ
	p = &a;			// pにaのアドレスを代入
	show(a, b, *p);	// *pにすることで、中身を確認することができる
	*p = 300;	// *pに値を代入
	show(a, b, *p);
	p = &b;	// pにbのアドレスを代入
	show(a, b, *p);
	*p = 400;	// *pに値を代入
	show(a, b, *p);
}

/*
 まとめると
 p = &a ： アドレスを代入可能
 *p = 100 ： アドレスを代入した後の中身を参照、変更可能
 
 注意点
 ・ポインタはNULLで初期化すること
 ・アドレスを指定しないまま、値を代入しないこと
*/

void show(int n1, int n2, int n3){
	printf("a = %d b = %d p = %d\n", n1, n2, n3);
}