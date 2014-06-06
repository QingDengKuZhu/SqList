#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

void InitList(SQLIST *pL)
{
	pL->elem = (Elem*)malloc(sizeof(Elem) * LIST_INIT_SIZE);
	if (!pL->elem)
	{
		printf("在InitList函数中,动态内存分配失败!\n");
		exit(ERROR);
	}
	
	pL->length = 0;	/*初始长度为0*/
	pL->Listsize = LIST_INIT_SIZE;/*最大允许长度为初始动态内存分配数量*/

	return;
}


void DestroyList(SQLIST *pL)
{
	free(pL->elem);
	pL->elem = NULL;

	pL->length = 0;
	pL->Listsize = 0;

	return;
}


size_t LocateElem(const SQLIST *pL, const Elem v)
{
	size_t pL_length = ListLength(pL);
	size_t i;
	Elem e;	/*存放结点数值以便与v做比较*/
	for (i=1; i<=pL_length; ++i)
	{
		GetElem(pL, i, &e);/* 函数一定返回OK */
		if (v == e)
		{
			return i;
		}
	}

	return 0;
}


size_t ListLength(const SQLIST *pL)
{
	return pL->length;
}


BOOL ListEmpty(const SQLIST *pL)
{
	if (0 == ListLength(pL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



STATUS DeleteList(SQLIST *pL, const size_t pos, Elem *e)
{
	size_t pL_length = ListLength(pL);
	size_t cur = pos;
	
	/*判断删除的位置是否合理*/
	if (cur<0 || cur>pL_length)
	{
		return FAILE;
	}

	*e = pL->elem[cur-1];

	while (cur < pL_length)
	{
		pL->elem[cur-1] = pL->elem[cur];
		++cur;
	}

	--(pL->length);
	return OK;
}


STATUS InsertList(SQLIST *pL, const size_t pos, const Elem v)
{
	Elem *pnewbase = NULL;
	size_t j = 0;
	size_t pL_length = ListLength(pL);
	
	/*判断插入点是否存在*/
	if (!pL->elem || pos<1 || pos>pL_length+1)
	{
		return FAILE;
	}
	
	/*若当前线性表已满,则不能再插入元素*/
	if (pL_length >= pL->Listsize)
	{
		pnewbase = (Elem *)realloc(pL->elem, (pL_length+LIST_INCREMENT)*sizeof(Elem));
		if (!pnewbase)
		{
			printf("在InitList函数中,动态内存分配错误!\n");
			exit(ERROR);
		}

		pL->elem = pnewbase;
		pL->Listsize += LIST_INCREMENT;
	}

	/*插入元素*/
	if (TRUE == ListEmpty(pL))
	{
		pL->elem[pos-1] = v;
	}
	else
	{	/*注意,此循环无法停止,因为j是size_t类型,无法达到循环的终止条件(0-1!=-1)
		for (j=pL_length-1; j>=pos-1; --j)
		{
			pL->elem[j+1] = pL->elem[j];
		}
		*/
		for (j=pL_length; j>=pos; --j)
		{
			pL->elem[j]  = pL->elem[j-1];
		}

		pL->elem[pos-1] = v;
	}
	++(pL->length);
	
	return OK;
}


void ClearList(SQLIST * pL)
{
	pL->length = 0;

	return;
}


STATUS GetElem(const SQLIST *pL, const size_t pos, Elem *e)
{
	if (pos<1 || pos>ListLength(pL))
	{
		return FAILE;
	}
	else
	{
		*e = pL->elem[pos-1];
		return OK;
	}
}


void TraveList(const SQLIST *pL)
{
	size_t i = 1;
	Elem e;
	while (OK == GetElem(pL, i, &e))
	{
		printf("%d ", e);
		++i;
	}
	printf("\n");

	return;
}