//===================================================================

#include "课程设计.h"

//===================================================================
//定义全局变量
int year=0;		//存放年份
int month=0;	//存放月份
int day=0;		//存放日
int week=0;		//存放星期
int s=0;		//计算万年历的公式变量

//===================================================================
//调用函数
int checkDate();
int getDays();
int getDate();
int isLeapyear();
int showCalendar();
int getWeek();
int getfirstdaysweek();
int	printWeek();
int printMonth();
int daysofmonth(int month);

//===================================================================
//主菜单
int exercise_5()
{
	//*****************************************************
	//定义变量
	int choose;//选择器

	//*****************************************************
	printf("☆欢迎使用《万年历》软件v6.0☆\n");

	//*****************************************************
part1:
	//执行函数
	getDate();													//获取日期												
	//计算万年历
	if (checkDate()==0)											//检查日期合法性
	{
		printf("请输入的日期有误,请重新输入!\n");
		goto part1;
	}
	else
	{
		goto part2;
	}

	//*****************************************************
part2:
	s=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400+getDays();
	showCalendar();												//打印月历
	printf("The day you choose is :\n");
	printf("%d-%d-%d,",year,month,day);
	printWeek();												//输出星期
	printf("  The day is %dth in year.",getDays());				//输出第几天
	
	printf("\n\n");

	//*****************************************************
part3:
	printf("**********************\n");
	printf("*      请选择操作    *\n");
	printf("*1.输入另一个日期    *\n");
	printf("*2.退出              *\n");
	printf("*3.返回主菜单        *\n");
	printf("**********************\n");

	scanf("%d",&choose);
	switch (choose)
	{
	case 1:
		{
			system("cls");
			goto part1;
			break;
		}
	case 2:
		{
			goto part4;
			break;
		}
	case 3:
		{
			system("cls");
			main();
			break;
		}
	default:
		{
			printf("错误!!!请重新选择\n");
			goto part3;
			break;
		}
	}

	//*****************************************************
part4:
	return 0;
}

//===================================================================
//获取日期
int getDate()
{
	//*****************************************************
	//用户提示
	printf("请输入年份year=");
	scanf("%d",&year);
	printf("请输入月份month=");
	scanf("%d",&month);
	printf("请输入日day=");
	scanf("%d",&day);

	//*****************************************************
	return 0;
}

//===================================================================

//检查日期合法性
int checkDate()
{
	//*****************************************************
	int check=0;	//存放真值

	//*****************************************************
	//调用函数
	int isLeapyear();

	//*****************************************************
	if (year>0)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			{
				if (1<=day&&day<=31)
				{
					check=1;
				}
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			{
				if (1<=day&&day<=30)
				{
					check=1;
				}
				break;
			}
		case 2:
			{
				check=0;

				if (isLeapyear()==1)
				{
					if (1<=day&&day<=29)
					{
						check=1;
					}
					else if (isLeapyear()==0)
					{
						if (1<=day&&day<=28)
						{
							check=1;
						}
					}
				}
				break;
			}
		}
	}

	//*****************************************************
	return (check);
}

//===================================================================
//判断是否是否是闰年
int isLeapyear()
{
	//*****************************************************
	int leap=0;

	//*****************************************************
	if ((year%4==0&&year!=100)||(year%100==0))
	{
		leap=1;
	}
	else
	{
		leap=0;
	}

	//*****************************************************
	return (leap);
}

//===================================================================
//显示日期所在月历
int showCalendar()
{
	//*****************************************************
	int i;		//计数器
	int n;		//计数器

	//*****************************************************
	printf("The calender of %d ",year);
	
	//*****************************************************
	if (isLeapyear()==1)
	{
		printf("[leap year]");
	}
	else
	{
		printf("[not leap year]");
	}
	
	printf("\n");
	
	//*****************************************************
	printf("===================================\n");
	printMonth();
	printf(" %d\n",month);

	//*****************************************************
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	if (getfirstdaysweek()!=7)
	{
		for (i=1,n=1;i<=getfirstdaysweek();n++,i++)
		{
			printf("     ");
		}
	}

	for (i=1;i<=daysofmonth(month);n++,i++)
	{
		if (i!=day)
		{
			printf("%4d ",i);
		}
		if (i==day)
		{
			printf(" [%2d]",i);
		}
		if ((n)%7==0)
		{
			printf("\n");
		}
	}

	printf("\n");
	printf("===================================\n");
	return 0;
}

//===================================================================

//计算输入日期是星期几
int getWeek()
{
	return (s%7);
}

//===================================================================

//计算输入的月份一日是星期几
int getfirstdaysweek()
{
	return ((s-day+1)%7);
}

//===================================================================
int getDays()
{
	//*****************************************************
	int i;
	int n;

	//*****************************************************
	n=0;

	//*****************************************************
	for (i=1;i<month;i++)
	{
		n=n+daysofmonth(i);
	}

	//*****************************************************
	n=n+day;

	//*****************************************************
	return n;
}

//===================================================================

//输出输入日期是星期几
int printWeek()
{
	switch (getWeek())
	{
	case 1:
		{
			printf("Monday!");
			break;
		}
	case 2:
		{
			printf("Tuesday!");
			break;
		}
	case 3:
		{
			printf("Wednesday!");
			break;
		}
	case 4:
		{
			printf("Thursday!");
			break;
		}
	case 5:
		{
			printf("Friday!");
			break;
		}
	case 6:
		{
			printf("Saturday!");
			break;
		}
	default :
		{
			printf("Sunday!");
			break;
		}
	}
	
	return 0;
}

//===================================================================

//输出月份
int printMonth()
{
	switch (month)
	{
	case 1:
		{
			printf("January");
			break;
		}
	case 2:
		{
			printf("February");
			break;
		}
	case 3:
		{
			printf("March");
			break;
		}
	case 4:
		{
			printf("April");
			break;
		}
	case 5:
		{
			printf("May");
			break;
		}
	case 6:
		{
			printf("June");
			break;
		}
	case 7:
		{
			printf("July");
			break;
		}
	case 8:
		{
			printf("August");
			break;
		}
	case 9:
		{
			printf("September");
			break;
		}
	case 10:
		{
			printf("October");
			break;
		}
	case 11:
		{
			printf("November");
			break;
		}
	case 12:
		{
			printf("December");
			break;
		}
	default:
		{
		}
	}
	return 0;
}

//===================================================================

//计算月份天数
int daysofmonth(int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		{
			return (31);
			break;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		{
			return (30);
			break;
		}
	case 2:
		{
			if (isLeapyear()==1)
			{
				return (29);
			}
			else
			{
				return (28);
			}
			break;
		}
	default:
		{
			printf("输入有误！\n");
			return 0;
		}
	}
}
//===================================================================