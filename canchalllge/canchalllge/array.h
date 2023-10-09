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
	a.size = init_size;     //д�����봴��ĺ�����С
	a.array = (int*)malloc(sizeof(int) * a.size);      //����һ��ռ�����������
	
	assert(a.array);

	return a;    //�����������

}

void array_free(Array* a) {

	free(a->array);    //��Ϊ���ͷ�a�����������Ƭ�ռ䣬��Ȼ���������㣬����Ƭ�ռ䲻�᣻
	a->array = NULL;    //��ֹ���ε���free;
	a->size = 0;

}

int array_size(const Array* a){
		return a->size;
}

int array_get(const Array* a,int index)    //��ȡ�õ�Ԫ�ϵ���ֵ
{
	return a->array[index];
}

void array_set(Array* a,int index,int value)    //���øõ�Ԫ�ϵ�ֵ
{
	a->array[index] = value;
}

void array_inflate(Array* a, int more_size)
{
	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));         //�ٴ�����һƬ�ռ䣬��Ƭ�ռ�=ԭ�ռ�+��չ�ռ�
	
	assert(p);

	int i;
	for (i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}        //��aԭ���Ķ���������������Ŀռ���

	free(a->array);        //�ͷ�ԭ�����ڴ�
	a->array = p;         //ʹԭ�����ַ��Ǩ���µ�ַ
	a->size += more_size;       //�������鳤��

}