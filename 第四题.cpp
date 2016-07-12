//===================================================================
#include "�γ����.h"

#define N 100

//===================================================================
//������ú���
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
int n;					//������,ѡ����
int i;					//������
int choose;				//ѡ����

//===================================================================
//�ṹ������
struct student
{
	int No;			//ѧ��
	char name[10];	//����
	char sex;		//�Ա�
	int usual;		//ƽʱ�ɼ�
	int mid;		//���гɼ�
	int final;		//��ĩ�ɼ�
	double total;	//����
}stud[SIZE]={0,0,0,0,0,0,0};

//===================================================================
//����
int exercise_4()
{

part1:
	//����˵�
	printf("**********************************\n");
	printf("*    ѧ���ɼ�����v6.0            *\n");
	printf("*��ѡ����                      *\n");
	printf("*      1.�����ͬѧ              *\n");
	printf("*      2.���Ҳ��޸�              *\n");
	printf("*      3.�������                *\n");
	printf("*      4.������������������ͬѧ*\n");
	printf("*      5.�����ĩ�ɼ���ߵ�Ů��  *\n");
	printf("*      6.�������˵�                *\n");
	printf("**********************************\n");

	//ѡ��
	scanf("%d",&choose);

	switch (choose)
	{
	case 1:
		{
			system("cls");
			n=1;

			//��ȡ����
			for (i=0;i<SIZE,n==1;i++)
			{
				getstudent(i);
				
				printf("�Ƿ������1.�� 2.�˻����˵�");
				scanf("%d",&n);
			}
			system("cls");

			goto part1;
		}
	case 2:
		{
			system("cls");
part2:
			//����
			searchstudent();

			//�޸�
			rework();

			printf("�Ƿ������1.�� 2.�˻����˵�");
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
			printf("����������ѡ��!\n");
			goto part1;
		}
	}

	return 0;
}

//===================================================================
//��ȡ����
void getstudent(int i)
{
	printf("������ѧ��ѧ��������\n");

	//ѧ��
	printf("No.");
	scanf("%d",&stud[i].No);

	//����
	printf("name:");
	scanf("%s",stud[i].name);

	//���������
	srand((unsigned)time(NULL));

	//�Ա�
	stud[i].sex=sex[rand()%2];

	//ƽʱ�ɼ�
	stud[i].usual=rand()%100;

	//���гɼ�
	stud[i].mid=rand()%100;

	//��ĩ�ɼ�
	stud[i].final=rand()%100;

	//����
	stud[i].total=(double)stud[i].usual*0.10+(double)stud[i].mid*0.30+(double)stud[i].final*0.60;
}

//===================================================================
//����ɼ�
void printstudent(int x)
{
	printf("ѧ�ţ�No.%d\n",stud[x].No);
	printf("������%s\n",stud[x].name);
	printf("�ձ�%c\n",stud[x].sex);
	printf("ƽʱ�ɼ���%d\n",stud[x].usual);
	printf("���гɼ���%d\n",stud[x].mid);
	printf("��ĩ�ɼ���%d\n",stud[x].final);
	printf("������%.2f\n\n\n",stud[x].total);
}

//===================================================================
//����ѧ��
void searchstudent()
{
	printf("��������Ҫ���ҵ�ѧ��ѧ��");
	scanf("%d",&choose);
	for (i=0;i<SIZE;i++)
	{
		if (stud[i].No==choose)
		{
			printf("�����ҵļ�¼����\n");
			printstudent(i);
		}
	}
}

//===================================================================
//�޸ļ�¼
void rework()
{
	printf("�������޸ĺ��ƽʱ�ɼ�:");
	scanf("%d",&stud[i].usual);
	printf("�������޸ĺ�����гɼ�:");
	scanf("%d",&stud[i].mid);
	printf("�������޸ĺ����ĩ�ɼ�:");
	scanf("%d",&stud[i].final);
	stud[i].total=stud[i].usual*0.1+stud[i].mid*0.3+stud[i].final*0.6;

	printf("�޸���ϣ����޸ĺ�ļ�¼����:\n");
	printstudent(i);
}

//===================================================================
//�����ɼ��ݼ�����
void decre()
{
	student a={0,0,0,0,0,0,0};		//��ʱ����

	//����
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
//����������
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
//�����ĩ�ɼ���ߵ�Ů��
void finaltopgirl()
{
	student a={0,0,0,0,0,0,0};		//��ʱ����

	//����
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

	//���
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