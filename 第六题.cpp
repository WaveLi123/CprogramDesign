//===================================================================
#include "�γ����.h"

//===================================================================
#define n 20

//===================================================================
int m;

struct staff 
{
	int num;				//����
	char name[20];			//����
	int base;				//��������
	int subsidy;			//�������
	int award;				//�������
	int deduct;				//�۳�����
	int pay;				//ʵ������
}user;

//===================================================================
int first()
{
	FILE *fp1;

	if((fp1=fopen("����.txt","w+"))==NULL)	//fp1����ͨѶ¼�м�¼�ĸ���
	{
		printf("û���ļ�!\n");		
		exit(0);
	}

	fprintf(fp1,"%d",0);					//��ʼ������Ϊ0
	printf("�ļ���ʼ����ɣ�\n");
	
	fclose(fp1);
	
    return 1;
}

//===================================================================
//���Ӽ�¼�ĺ���
void add() 
{
	FILE *fp1;
	FILE *fp2;

    int m;
	int	a;

	m=0;
	a=1;

	if((fp2=fopen("ͨѶ¼.dat","ab"))==NULL)	//׷�ӷ�ʽ��
	{
		printf("û���ļ�!\n");
		
		exit(0);
	}
	
	printf("������Ա����:");
	scanf("%d",&user.num);

	printf("����������:");
	scanf("%s",user.name);
	
	printf("�������������:");
	scanf("%d",&user.base);
	
	printf("�����벹�����:");
	scanf("%d",&user.subsidy);
	
	printf("�����뽱�����:");
	scanf("%d",&user.award);

	printf("������۳����:");
	scanf("%d",&user.deduct);

	user.pay=user.base+user.subsidy+user.award-user.deduct;

	fwrite(&user,sizeof(staff),1,fp2);
	
	fclose(fp2);
	
	if((fp1=fopen("����.txt","r"))==NULL)
	{
		printf("û���ļ�!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);		//ȡ�������е��� 
    fclose(fp1);
    fp1=fopen("����.txt","w");

	m++;						//��¼����һ��

	fprintf(fp1,"%d",m);		//���Ӽ�¼��mд�� 
	fclose(fp1);
}
//===================================================================
//���Ҽ�¼����
void find()
{
	FILE *fp1;
	FILE *fp2;

	int i;
	int num2;					//num2ΪҪ����Ĺ���
	staff q[n];
	
	if((fp1=fopen("����.txt","r"))==0)
	{
		printf("û�д��ļ�!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);		//ȡ��m
	if(m==0)
	{
		printf("û�м�¼�����ܲ��ң�\n");
		
		return;
	}
	
	
	printf("��������Ҫ���ҵĹ��ţ�");
	scanf("%d",&num2);

	if((fp2=fopen("ͨѶ¼.dat","rb"))==NULL)
	{
		printf("û�и��ļ�!\n");
		
		exit(0);
	}

	for(i=0;i<m;i++)
	{ 
		fread(&q[i],sizeof(staff),1,fp2);
		if(num2==q[i].num)	//ƥ�乤�� 
		{
			printf("����: %d\n",q[i].num);
			printf("����: %s\n",q[i].name);
			printf("��������: %d\n",q[i].base);
			printf("��������: %d\n",q[i].subsidy);
			printf("�������: %d\n",q[i].award);
			printf("�۳����: %d\n",q[i].deduct);
			printf("ʵ�����: %d\n",q[i].pay);

			break;			//�ҵ������� 
		}
	}
	if (i==m)
	{
		//���һ��ѭ����ɣ�������Ҳ��� 
		printf("���޴��ˣ�\n");
	}

	fclose(fp1);
	fclose(fp2);
}
//===================================================================
void modify()//�޸ļ�¼���� 
{
	FILE *fp1;
	FILE *fp2;
	int i;
	int k;				//k����Ҫ�޸ĵ�������¼
	
	k=-1;

	int del_num;
	staff q[n];
	
	if((fp1=fopen("����.txt","r"))==0)
	{
		
		printf("�Ҳ����ļ�!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);
	fclose(fp1);			//��ȡm��͹ر� 
	if(m==0)
	{
		printf("û�м�¼���޷�ɾ����\n");
		
		return;
	}
	
	printf("��������Ҫ�޸ļ�¼�Ĺ��ţ�");
	scanf("%d",&del_num);
	
	if((fp2=fopen("ͨѶ¼.dat","rb"))==NULL)
	{
		printf("���޴���!\n");
		
		exit(0);
	}
	
	for(i=0;i<m;i++)
	{
		fread(&q[i],sizeof(staff),1,fp2);
		if(del_num==q[i].num)			//ƥ��Ҫɾ���ļ�¼
		{
			k=i;						//����i����¼��i��ֵ��k
		}
	}

	if(k==-1)							//���һ��ѭ����ɣ�k���ڳ�ֵ0������Ҳ��� 
	{
		printf("�Ҳ���¼��\n");
		return;
	}
	else
	{
		printf("����: %d\n",q[k].num);
		printf("����: %s\n",q[k].name);
		printf("��������: %d\n",q[k].base);
		printf("��������: %d\n",q[k].subsidy);
		printf("�������: %d\n",q[k].award);
		printf("�۳����: %d\n",q[k].deduct);
		printf("ʵ�����: %d\n",q[k].pay);
	}
	fclose(fp2);
	
	printf("������Ա����:");
	scanf("%d",q[k].num);

	printf("����������:");
	scanf("%s",q[k].name);
	
	printf("�������������:");
	scanf("%d",q[k].base);
	
	printf("�����벹�����:");
	scanf("%d",q[k].subsidy);
	
	printf("�����뽱�����:");
	scanf("%d",q[k].award);

	printf("������۳����:");
	scanf("%d",q[k].deduct);
		
	if((fp2=fopen("ͨѶ¼.dat","w"))==NULL)//������д�ķ�ʽ�� 
	{
		printf("�Ҳ����ļ�!\n");
		
		exit(0);
	}
	for(i=0;i<m;i++)
	{
		fwrite(&q[i],sizeof(staff),1,fp2);
	}

	printf("�޸ļ�¼�ɹ���\n");
	
	fclose(fp2);
}
//===================================================================
//ɾ����¼����
void del() 
{
	FILE *fp1;
	FILE *fp2;
	int i;
	int k;						//k����Ҫɾ����������¼
	
	k=-1;

	int del_num;
	staff q[n];
	
	if((fp1=fopen("����.txt","r"))==0)
	{
		
		printf("�Ҳ����ļ�!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);
	fclose(fp1);	//��ȡm��͹ر� 
	if(m==0)
	{
		printf("û�м�¼���޷�ɾ����\n");
		
		return;
	}

	printf("��������Ҫɾ����¼�Ĺ��ţ�");
	scanf("%d",&del_num);

	if((fp2=fopen("ͨѶ¼.dat","rb"))==NULL)
	{
		printf("���޴���!\n");
		
		exit(0);
	}
	
	for(i=0;i<m;i++)
	{
		fread(&q[i],sizeof(staff),1,fp2);
		if(del_num==q[i].num)		//ƥ��Ҫɾ���ļ�¼
		{
			k=i;					//����i����¼��i��ֵ��k
		}
	}
	if(k==-1)						//���һ��ѭ����ɣ�k���ڳ�ֵ0������Ҳ��� 
	{
		printf("�Ҳ�����¼��\n");
		return;
	}

	fclose(fp2);
	if((fp2=fopen("ͨѶ¼.dat","w"))==NULL)	//������д�ķ�ʽ�� 
	{
		printf("�Ҳ����ļ�!\n");
		
		exit(0);
	}

	for(i=0;i<k;i++)
	{
		fwrite(&q[i],sizeof(staff),1,fp2);
	}
	for(i=k+1;i<m;i++)			//iû�е���k����ʵ����ɾ����¼���� 
	{
		fwrite(&q[i],sizeof(staff),1,fp2);
	}
	if((fp1=fopen("����.txt","w"))==NULL)
	{
		printf("�Ҳ����ļ�!");
		
		exit(0);
	}
	m--;				//ɾ����¼��mҪ��1 
	fprintf(fp1,"%d",m);//����д��m
	printf("ɾ����¼�ɹ���\n");
	fclose(fp1);
	fclose(fp2);
}
//===================================================================
void count()
{
	FILE *fp1;
	FILE *fp2;

	int i;

	int sum_base;				//�ܻ�������
	int sum_subsidy;			//�ܲ������
	int sum_award;				//�ܽ������
	int sum_deduct;				//�ܿ۳�����
	int sum_pay;				//��ʵ������

	sum_base=0;
	sum_subsidy=0;
	sum_award=0;
	sum_deduct=0;
	sum_pay=0;

	staff q[n];
	
	if((fp1=fopen("����.txt","r"))==0)
	{
		printf("û�д��ļ�!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);		//ȡ��m
	if(m==0)
	{
		printf("û�м�¼�����ܲ��ң�\n");
		
		return;
	}

	if((fp2=fopen("ͨѶ¼.dat","rb"))==NULL)
	{
		printf("û�и��ļ�!\n");
		
		exit(0);
	}

	for(i=0;i<m;i++)
	{ 
		fread(&q[i],sizeof(staff),1,fp2);
	}

	for (i=0;i<m;i++)
	{
		sum_base += q[i].base;
		sum_subsidy += q[i].subsidy;
		sum_award += q[i].award;
		sum_deduct += q[i].deduct;
		sum_pay +=q[i].pay;
	}

	printf("        �������� �������� ������� �۳���� ʵ������\n");
	printf("�ܺ�:  %7d %7d %7d %7d\n",	sum_base,sum_subsidy,sum_award,sum_deduct,sum_pay);
	printf("ƽ��:  %7d %7d %7d %7d\n",	sum_base/m,sum_subsidy/m,sum_award/m,sum_deduct/m,sum_pay/m);
	printf("����:  %7d",m);

	fclose(fp1);
	fclose(fp2);
}
//===================================================================
//���溯��
void face() 
{
	printf("��*��*��*��*��*���*��*����\n"
		"   ��                         ��\n"
		"   ��     ��һ��ʹ���밴1     ��\n"
		"   ��                         ��\n"
		"   ��     ���Ӽ�¼�밴2       ��\n"
		"   ��                         ��\n"
		"   ��     ���Ҽ�¼�밴3       ��\n"
		"   ��                         ��\n"
		"   ��     �޸ļ�¼�밴4       ��\n"
		"   ��                         ��\n"
		"   ��     ɾ����¼�밴5       ��\n"
		"   ��                         ��\n"
		"   ��     ͳ���밴6           ��\n"
		"   ��                         ��\n"
		"   ��     �˳������밴0       ��\n"
		"   ��                         ��\n"
		"   ��*��*��*��*���*��*��*����\n");
	printf("\n�������ʾѡ����Ҫִ�еĳ���");
}

int exercise_6()
{
	int k;
	int a;

	a=1;
	
	while(a==1)
	{
		system("cls");
		face();
		scanf("%d",&k);
		getchar();	//�̵��س���
		switch(k)
		{  
		case 1:
			{
				system("cls");
				first();
				break;
			}
		case 2:
			{
				system("cls");
				do
				{
					add();
					printf("��������������1������������0\n");
					scanf("%d",&a);
					system("cls");
				} while(a==1);
				break;
			}
		case 3:
			{
				do
				{
					find();
					printf("��������������1������������0\n");
					scanf("%d",&a);
					getchar();		//�̵��س���
					system("cls");
				} while(a==1);
				break;
			}
		case 4:
			{
				do
				{
					modify();
					printf("�����޸�������1������������0\n");
					scanf("%d",&a);
					getchar();		//�̵��س���
					system("cls");
				} while (a==1);
				break;
			}
		case 5:
			{
				do
				{
					del();
					printf("����ɾ��������1������������0\n");
					scanf("%d",&a);
					getchar();		//�̵��س���
					system("cls");
				} while (a==1);
				break;
			}
		case 6:
			{
				system("cls");
				count();
				break;
			}
		}
		printf("����������1������������0\n");
		scanf("%d",&a);
	}
	return 0;
}