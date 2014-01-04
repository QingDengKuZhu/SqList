#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

STATUS PriorELem(PSQLIST pL, const int v, int *pre_e)
{
	size_t pos = LocateElem(pL, v);
	if (pos!=0 && pos!=1)/*如果存在并且不为第一个结点*/
	{
		GetElem(pL, pos-1, pre_e);
		return OK;
	}
	else
	{
		return FALSE;
	}

}


STATUS NextELem(PSQLIST pL, const int v, int *next_e)
{
	size_t pos = LocateElem(pL, v);
	if (pos!=0 && pos!=ListLength(pL))/*如果存在并且不为最后一个结点*/
	{
		GetElem(pL, pos+1, next_e);
		return OK;
	}
	else
	{
		return FALSE;
	}
}



void UnionList(PSQLIST pLa, PSQLIST pLb)
{
	size_t i;
	size_t pos = ListLength(pLb);
	const int v;

	for (i=1; i<=pos; ++i)
	{
		GetElem(pLb, i, &v);
		if (0 == LocateElem(pLa, v) )/*比较是否在pLa中*/
		{
			InsertList(pLa, ListLength(pLa)+1, v);/*若不在,将数据插入表尾*/
		}
	}
}