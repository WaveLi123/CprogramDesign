#include "�γ����.h"

//===================================================================
int main()
{
	int choose;
	choose=0;
a:	
	printf("�ӭ���롶�γ���ơ�����һ�ϣ�����\n");
	printf("**************************************\n");
	printf("*1.������ϰ                          *\n");
	printf("*2.���ݴ���                          *\n");
	printf("*3.Ӣ�ĵ��ʴ���                      *\n");
	printf("*4.ѧ���ɼ�����                      *\n");
	printf("*5.��ʾָ�����ڵ�����                *\n");
	printf("*6.���ʹ������                      *\n");
	printf("*7.�˳�                              *\n");
	printf("**************************************\n");
	printf("����������ѡ��");
	scanf("%d",&choose);
	printf("���Ժ�.");
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
			printf("������������������!!");
			goto a;
		}
	}
	return 0;
}