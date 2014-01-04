/**********************
**顺序线性表的扩展操作.
***********************/
#ifndef DATA_EXPAND_H
#define DATA_EXPAND_H

#include "Main_First.h"
#include "Data.h"

/*
pL为指向顺序线性表的指针,且pL不为NULL.
*/

/*返回顺序线性表的前驱元素.若v是顺序线性表的数据元素,且不是第一个,则用*e返回它的前一个元素,函数返回OK;否者函数返回FALSE, *pre_e无定义*/
STATUS PriorELem(PSQLIST pL, const int v, int *pre_e);

/*返回顺序线性表的后驱元素.若v是顺序线性表的数据元素,且不是第最后个,则用*e返回它的后一个元素,函数返回OK;否者函数返回FALSE, *next_e无定义*/
STATUS NextELem(PSQLIST pL, const int v, int *next_e);

/*将所有在线性表pLb中但是不在pLa中的数据元素插入到pLa后面*/
void UnionList(PSQLIST pLa, PSQLIST pLb);

#endif
