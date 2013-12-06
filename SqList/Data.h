/*****************
**顺序线性表数据结构
*****************/
#ifndef DATA_H
#define DATA_H

#include "Main_First.h"
#define LIST_INIT_SIZE 1	//顺序线性表初始分配量
#define LIST_INCREMENT 1	//顺序线性表空间的每次分配增量

typedef struct SqList
{
	int *elem;//存储空间基址
	size_t length;//当顺序线性表的表长
	size_t Listsize;//当前顺序线性表允许的的最大长度

}SQLIST,*PSQLIST;


#endif