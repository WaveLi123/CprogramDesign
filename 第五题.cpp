//===================================================================

#include "�γ����.h"

//===================================================================
//����ȫ�ֱ���
int year=0;		//������
int month=0;	//����·�
int day=0;		//�����
int week=0;		//�������
int s=0;		//�����������Ĺ�ʽ����

//===================================================================
//���ú���
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
//���˵�
int exercise_5()
{
	//*****************************************************
	//�������
	int choose;//ѡ����

	//*****************************************************
	printf("�ӭʹ�á������������v6.0��\n");

	//*****************************************************
part1:
	//ִ�к���
	getDate();													//��ȡ����												
	//����������
	if (checkDate()==0)											//������ںϷ���
	{
		printf("���������������,����������!\n");
		goto part1;
	}
	else
	{
		goto part2;
	}

	//*****************************************************
part2:
	s=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400+getDays();
	showCalendar();												//��ӡ����
	printf("The day you choose is :\n");
	printf("%d-%d-%d,",year,month,day);
	printWeek();												//�������
	printf("  The day is %dth in year.",getDays());				//����ڼ���
	
	printf("\n\n");

	//*****************************************************
part3:
	printf("**********************\n");
	printf("*      ��ѡ�����    *\n");
	printf("*1.������һ������    *\n");
	printf("*2.�˳�              *\n");
	printf("*3.�������˵�        *\n");
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
			printf("����!!!������ѡ��\n");
			goto part3;
			break;
		}
	}

	//*****************************************************
part4:
	return 0;
}

//===================================================================
//��ȡ����
int getDate()
{
	//*****************************************************
	//�û���ʾ
	printf("���������year=");
	scanf("%d",&year);
	printf("�������·�month=");
	scanf("%d",&month);
	printf("��������day=");
	scanf("%d",&day);

	//*****************************************************
	return 0;
}

//===================================================================

//������ںϷ���
int checkDate()
{
	//*****************************************************
	int check=0;	//�����ֵ

	//*****************************************************
	//���ú���
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
//�ж��Ƿ��Ƿ�������
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
//��ʾ������������
int showCalendar()
{
	//*****************************************************
	int i;		//������
	int n;		//������

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

//�����������������ڼ�
int getWeek()
{
	return (s%7);
}

//===================================================================

//����������·�һ�������ڼ�
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

//����������������ڼ�
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

//����·�
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

//�����·�����
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
			printf("��������\n");
			return 0;
		}
	}
}
//===================================================================