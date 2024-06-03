#include <stdio.h>

// プロトタイプ宣言
void swap(int*, int*);

void main() {
	int a = 1, b = 2;
	printf("a = %d b = %d\n", a, b);
	swap(&a, &b);	// ポインタの引数なので、アドレスを渡す
	printf("a = %d b = %d\n", a, b);
}

void swap(int* num1, int* num2) {
	int temp = *num1;	// intの変数に*num1、値を入れる。　*num1だとアドレスが入ってしまうので、中身を入れること
	*num1 = *num2;
	*num2 = temp;
}