/**********************
**主函数, 测试
***********************/

#include "Main_First.h"
#include "Data.h"
#include "Data_Base.h"
#include "Test.h"

int main(void)
{
	int select;		/*保存选择变量*/
	size_t pos;		/*位序*/
	int e;			/*结点的值*/
	
	SQLIST L;
	InitList(&L);
	
	while (1)	/*while_@1*/
	{
		system("cls");
		Menu();

		printf("请输入您的选择(1~10):");
		scanf("%d", &select);
		getchar();

		switch (select)	/*switch_@1*/
		{
		case 1:			/*插入数据*/
			pos = InputPos("插入位置为:");
			e = InputValue("结点元素为:");
			if (FAILE == InsertList(&L, pos, e))
			{
				printf("插入失败!\n");
			}
			else
			{
				printf("插入成功!\n");
			}
			
			getchar();
			break;
		case 2:			/*整表输出*/
			printf("整表为:");
			TraveList(&L);
			
			getchar();
			break;
		case 3:			/*删除结点*/
			pos = InputPos("删除的结点位置是:");
			if (OK == DeleteList(&L, pos, &e))
			{
				printf("删除成功,删除的元素是%d!\n", e);
			}
			else
			{
				printf("删除失败!\n");
			}

			getchar();
			break;

		case 4:			/*输出表的长度*/
			printf("线性表长度: %d \n", ListLength(&L));
			
			getchar();
			break;
		default:
			printf("请重新选择!\n");
			
			getchar();
			break;
		}/*switch_@1*/

	}	/*while_@1*/
	
	return EXIT_SUCCESS;
}