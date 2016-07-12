#include "课程设计.h"

//===================================================================
int main()
{
	int choose;
	choose=0;
a:	
	printf("☆欢迎进入《课程设计》（大一上）！☆\n");
	printf("**************************************\n");
	printf("*1.打字练习                          *\n");
	printf("*2.数据处理                          *\n");
	printf("*3.英文单词处理                      *\n");
	printf("*4.学生成绩管理                      *\n");
	printf("*5.显示指定日期的月历                *\n");
	printf("*6.工资管理程序                      *\n");
	printf("*7.退出                              *\n");
	printf("**************************************\n");
	printf("请输入您的选择：");
	scanf("%d",&choose);
	printf("请稍后.");
	printf("..");
	printf("...\n");
	switch (choose)
	{
	case 1:
		{
			system("cls");
			exercise_1();
			break;
		}
	case 2:
		{
			system("cls");
			exercise_2();
			break;
		}
	case 3:
		{
			system("cls");
			exercise_3();
			break;
		}
	case 4:
		{
			system("cls");
			exercise_4();
			break;
		}
	case 5:
		{
			system("cls");
			exercise_5();
			break;
		}
	case 6:
		{
			system("cls");
			exercise_6();
			break;
		}
	case 7:
		{
			return 0;
		}
	default:
		{
			system("cls");
			printf("输入有误，请重新输入!!");
			goto a;
		}
	}
	return 0;
}