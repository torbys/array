#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct {
	int* array;
	int size;
} Array;

Array array_creatr(int init_size) {

	Array a;
	a.size = init_size;     //写入你想创造的函数大小
	a.array = (int*)malloc(sizeof(int) * a.size);      //申请一块空间放置你的数组
	
	assert(a.array);

	return a;    //返回这个数组

}

void array_free(Array* a) {

	free(a->array);    //是为了释放a里面申请的那片空间，虽然结束会清零，但这片空间不会；
	a->array = NULL;    //防止二次调用free;
	a->size = 0;

}

int array_size(const Array* a){
		return a->size;
}

int array_get(const Array* a,int index)    //读取该单元上的数值
{
	return a->array[index];
}

void array_set(Array* a,int index,int value)    //设置该单元上的值
{
	a->array[index] = value;
}

void array_inflate(Array* a, int more_size)
{
	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));         //再次请求一片空间，这片空间=原空间+拓展空间
	
	assert(p);

	int i;
	for (i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}        //将a原来的东西拷贝到新请求的空间里

	free(a->array);        //释放原来的内存
	a->array = p;         //使原数组地址搬迁到新地址
	a->size += more_size;       //更改数组长度

}