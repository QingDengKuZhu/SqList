/**********************
**顺序线性表的基本操作.
***********************/
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "Main_First.h"
#include "Data.h"
/*
pL为指向顺序线性表的指针,且pL不为NULL.
*/

/*构造一个空的顺序线性表.*/
void InitList(PSQLIST pL);

/*销毁顺序线性表.*/
void DestroyList(PSQLIST pL);

/*将顺序线性表清空.*/
void ClearList(PSQLIST pL);

/*判断顺序线性表是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL ListEmpty(PSQLIST pL);

//返回顺序线性表的长度
size_t ListLength(PSQLIST pL);

//获取顺序线性表中第pos个元素.若操作成功,函数返回OK,pe保存满足条件的结点的地址;若操作失败,函数返回FAILE,pe为NULL.
SATUES GetList(PSQLIST pL, size_t pos, int *pe);

//返回顺序线性表中第一个与e相等的元素的位序(从1开始).若成功函数返回相应的位序;否者返回0.
size_t LocateElem(PSQLIST pL, int e);

//在顺序线性表中第pos个位置之前插入新的数据元素e(1 <= pos <= ListLength(pL)+1).若成功,函数返回OK;否者返回FAILE.
SATUES InsertList(PSQLIST pL, size_t pos, int e);

//删除顺序线性表中第pos个元素.若成功删除,函数返回OK,pe保存被删除元素的地址;否者函数返回FAILE,pe为NULL.
SATUES DeleteList(PSQLIST pL, size_t pos, int *pe);

//遍输出顺序线性表
void TraveList(PSQLIST pL);

#endif