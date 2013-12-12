#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

void InitList(PSQLIST pL)
{
	pL->elem = (int*)malloc(sizeof(int) * LIST_INIT_SIZE);
	if (!pL->elem)
	{
		printf("在InitList函数中,动态内存分配失败!\n");
		exit(ERROR);
	}
	
	pL->length = 0;	/*初始长度为0*/
	pL->Listsize = LIST_INIT_SIZE;/*最大允许长度为初始动态内存分配数量*/

	return;
}


void DestroyList(PSQLIST pL)
{
	free(pL->elem);
	pL->elem = NULL;

	pL->length = 0;
	pL->Listsize = 0;

	return;
}


size_t LocateElem(PSQLIST pL, int e)
{
	size_t pL_length = ListLength(pL);
	size_t i;
	int *p = NULL;
	for (i=1; i<=pL_length; ++i)
	{
		GetList(pL, i, p);/* 函数一定返回OK */
		if (*p == e)
		{
			return i;
		}
	}

	return 0;
}


size_t ListLength(PSQLIST pL)
{
	return pL->length;
}


BOOL ListEmpty(PSQLIST pL)
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



STATUS DeleteList(PSQLIST pL, size_t pos, int *e)
{
	size_t pL_length = ListLength(pL);
	
	/*判断删除的位置是否合理*/
	if (pos<0 || pos>pL_length)
	{
		return FAILE;
	}

	*e = pL->elem[pos-1];

	while (pos < pL_length)
	{
		pL->elem[pos-1] = pL->elem[pos];
		++pos;
	}

	--(pL->length);
	return OK;
}


STATUS InsertList(PSQLIST pL, size_t pos, int e)
{
	int *pnewbase = NULL;
	size_t j = 0;
	size_t pL_length = ListLength(pL);
	
	/*判断插入点是否存在*/
	if (pos<1 || pos>pL_length+1)
	{
		return FAILE;
	}
	
	/*若当前线性表已满,则不能再插入元素*/
	if (pL_length >= pL->Listsize)
	{
		pnewbase = (int *)realloc(pL->elem, (pL_length+LIST_INCREMENT)*sizeof(int));
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
		pL->elem[pos-1] = e;
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

		pL->elem[pos-1] = e;
	}
	++(pL->length);
	
	return OK;
}


void ClearList(PSQLIST pL)
{
	pL->length = 0;

	return;
}


STATUS GetList(PSQLIST pL, size_t pos, int *e)
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


void TraveList(PSQLIST pL)
{
	size_t i = 1;
	int e;
	while (OK == GetList(pL, i, &e))
	{
		printf("%d ", e);
		++i;
	}
	printf("\n");

	return;
}