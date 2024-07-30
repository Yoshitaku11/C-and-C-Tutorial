#include<stdio.h>

//データを入れる構造体
typedef struct {
	int a;
	double d;
}num_data;

//二種類の値設定関数
void dealData1(num_data data);			// 値渡し
void dealData2(num_data* pData);		// データ渡し

void main() {
	num_data n1 = { 1, 1.2 }, n2 = { 1, 1.2 };
	printf("n1のアドレス: 0x%x n2のアドレス:0x%x\n", (unsigned int)&n1, (unsigned int)&n2);
	dealData1(n1);
	dealData2(&n2);
	printf("n1.a = %d n1.d = %f\n", n1.a, n1.d);	// データ渡しなので、関数を出たら元の値に戻る
	printf("n2.a = %d n2.d = %f\n", n2.a, n2.d);	// 参照渡しなので、関数を出ても値が保持される
}

// 値渡しはなるべく使わないほうがいい。データのコピーが大きくなるし、スタック領域を余計に使うことになる。
void dealData1(num_data data) {
	printf("a=%d d=%f\n", data.a, data.d);
	printf("dealData1にわたってきたデータのアドレス: 0x%x\n", (unsigned int)&data);
	data.a = 2;
	data.d = 2.4;
}

void dealData2(num_data* pData) {
	printf("a=%d d=%f\n", pData->a, pData->d);
	printf("dealData2にわたってきたデータのアドレス: 0x%x\n", (unsigned int)pData);	// pDataがアドレス
	pData->a = 2;
	pData->d = 2.4;
}

// num_data* pdata
// pdata はアドレス
// *pdataが値になるが、構造体なのでpdata->aが値になる