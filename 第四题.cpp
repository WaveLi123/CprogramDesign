//===================================================================
#include "课程设计.h"

#define N 100

//===================================================================
//本题调用函数
void getstudent(int i);
void printstudent(int x);
void rework();
void decre();
void searchstudent();
void printfail();
void finaltopgirl();

//===================================================================
#define SIZE 50
char sex[]={'F','M'};
int n;					//计数器,选择器
int i;					//计数器
int choose;				//选择器

//===================================================================
//结构体数据
struct student
{
	int No;			//学号
	char name[10];	//姓名
	char sex;		//性别
	int usual;		//平时成绩
	int mid;		//期中成绩
	int final;		//期末成绩
	double total;	//总评
}stud[SIZE]={0,0,0,0,0,0,0};

//===================================================================
//主控
int exercise_4()
{

part1:
	//输出菜单
	printf("**********************************\n");
	printf("*    学生成绩处理v6.0            *\n");
	printf("*请选择功能                      *\n");
	printf("*      1.添加新同学              *\n");
	printf("*      2.查找并修改              *\n");
	printf("*      3.排序输出                *\n");
	printf("*      4.输出所有总评不及格的同学*\n");
	printf("*      5.输出期末成绩最高的女生  *\n");
	printf("*      6.返回主菜单                *\n");
	printf("**********************************\n");

	//选择
	scanf("%d",&choose);

	switch (choose)
	{
	case 1:
		{
			system("cls");
			n=1;

			//获取数据
			for (i=0;i<SIZE,n==1;i++)
			{
				getstudent(i);
				
				printf("是否继续？1.是 2.退回主菜单");
				scanf("%d",&n);
			}
			system("cls");

			goto part1;
		}
	case 2:
		{
			system("cls");
part2:
			//查找
			searchstudent();

			//修改
			rework();

			printf("是否继续？1.是 2.退回主菜单");
			scanf("%d",&n);
			switch (n)
			{
			case 1:
				{
					goto part2;
				}
			case 2:
				{
					goto part1;
				}
			}
		}
	case 3:
		{
			system("cls");
			decre();
			goto part1;
		}
	case 4:
		{
			system("cls");
			printfail();
			goto part1;
		}
	case 5:
		{
			system("cls");
			finaltopgirl();
			goto part1;
		}
	case 6:
		{
			system("cls");
			main();
			break;
		}
	default :
		{
			system("cls");
			printf("错误，请重新选择!\n");
			goto part1;
		}
	}

	return 0;
}

//===================================================================
//获取数据
void getstudent(int i)
{
	printf("请输入学生学号与姓名\n");

	//学号
	printf("No.");
	scanf("%d",&stud[i].No);

	//姓名
	printf("name:");
	scanf("%s",stud[i].name);

	//随机数种子
	srand((unsigned)time(NULL));

	//性别
	stud[i].sex=sex[rand()%2];

	//平时成绩
	stud[i].usual=rand()%100;

	//期中成绩
	stud[i].mid=rand()%100;

	//期末成绩
	stud[i].final=rand()%100;

	//总评
	stud[i].total=(double)stud[i].usual*0.10+(double)stud[i].mid*0.30+(double)stud[i].final*0.60;
}

//===================================================================
//输出成绩
void printstudent(int x)
{
	printf("学号：No.%d\n",stud[x].No);
	printf("姓名：%s\n",stud[x].name);
	printf("姓别：%c\n",stud[x].sex);
	printf("平时成绩：%d\n",stud[x].usual);
	printf("期中成绩：%d\n",stud[x].mid);
	printf("期末成绩：%d\n",stud[x].final);
	printf("总评：%.2f\n\n\n",stud[x].total);
}

//===================================================================
//查找学生
void searchstudent()
{
	printf("请输入您要查找的学生学号");
	scanf("%d",&choose);
	for (i=0;i<SIZE;i++)
	{
		if (stud[i].No==choose)
		{
			printf("您查找的记录如下\n");
			printstudent(i);
		}
	}
}

//===================================================================
//修改记录
void rework()
{
	printf("请输入修改后的平时成绩:");
	scanf("%d",&stud[i].usual);
	printf("请输入修改后的期中成绩:");
	scanf("%d",&stud[i].mid);
	printf("请输入修改后的期末成绩:");
	scanf("%d",&stud[i].final);
	stud[i].total=stud[i].usual*0.1+stud[i].mid*0.3+stud[i].final*0.6;

	printf("修改完毕，您修改后的记录如下:\n");
	printstudent(i);
}

//===================================================================
//总评成绩递减排序
void decre()
{
	student a={0,0,0,0,0,0,0};		//临时交换

	//排序
	for (i=0;i<SIZE;i++)
	{
		for (n=i;n<SIZE;n++)
		{
			if (stud[i].total>stud[n].total)
			{
				stud[i]=a;
				stud[i]=stud[n];
				stud[n]=a;
			}
		}
	}
}

//===================================================================
//总评不及格
void printfail()
{
	for (i=0;i<SIZE;i++)
	{
		if (stud[i].total<60)
		{
			printstudent(i);
		}
	}
}

//===================================================================
//输出期末成绩最高的女生
void finaltopgirl()
{
	student a={0,0,0,0,0,0,0};		//临时交换

	//排序
	for (i=0;i<SIZE;i++)
	{
		for (n=i;n<SIZE;n++)
		{
			if (stud[i].final>stud[n].final)
			{
				stud[i]=a;
				stud[i]=stud[n];
				stud[n]=a;
			}
		}
	}

	//输出
	for (i=0;i<SIZE;i++)
	{
		if (stud[i].sex=='F')
		{
			printstudent(i);
			break;
		}
	}
}
//===================================================================