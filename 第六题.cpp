//===================================================================
#include "课程设计.h"

//===================================================================
#define n 20

//===================================================================
int m;

struct staff 
{
	int num;				//工号
	char name[20];			//姓名
	int base;				//基本工资
	int subsidy;			//补贴金额
	int award;				//奖励金额
	int deduct;				//扣除工资
	int pay;				//实发工资
}user;

//===================================================================
int first()
{
	FILE *fp1;

	if((fp1=fopen("备记.txt","w+"))==NULL)	//fp1保存通讯录中记录的个数
	{
		printf("没有文件!\n");		
		exit(0);
	}

	fprintf(fp1,"%d",0);					//初始化数量为0
	printf("文件初始化完成！\n");
	
	fclose(fp1);
	
    return 1;
}

//===================================================================
//增加记录的函数
void add() 
{
	FILE *fp1;
	FILE *fp2;

    int m;
	int	a;

	m=0;
	a=1;

	if((fp2=fopen("通讯录.dat","ab"))==NULL)	//追加方式打开
	{
		printf("没有文件!\n");
		
		exit(0);
	}
	
	printf("请输入员工号:");
	scanf("%d",&user.num);

	printf("请输入姓名:");
	scanf("%s",user.name);
	
	printf("请输入基本工资:");
	scanf("%d",&user.base);
	
	printf("请输入补贴金额:");
	scanf("%d",&user.subsidy);
	
	printf("请输入奖励金额:");
	scanf("%d",&user.award);

	printf("请输入扣除金额:");
	scanf("%d",&user.deduct);

	user.pay=user.base+user.subsidy+user.award-user.deduct;

	fwrite(&user,sizeof(staff),1,fp2);
	
	fclose(fp2);
	
	if((fp1=fopen("备记.txt","r"))==NULL)
	{
		printf("没有文件!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);		//取出备记中的数 
    fclose(fp1);
    fp1=fopen("备记.txt","w");

	m++;						//记录增加一个

	fprintf(fp1,"%d",m);		//增加记录后将m写回 
	fclose(fp1);
}
//===================================================================
//查找记录函数
void find()
{
	FILE *fp1;
	FILE *fp2;

	int i;
	int num2;					//num2为要输入的工号
	staff q[n];
	
	if((fp1=fopen("备记.txt","r"))==0)
	{
		printf("没有此文件!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);		//取出m
	if(m==0)
	{
		printf("没有记录，不能查找！\n");
		
		return;
	}
	
	
	printf("请输入你要查找的工号：");
	scanf("%d",&num2);

	if((fp2=fopen("通讯录.dat","rb"))==NULL)
	{
		printf("没有该文件!\n");
		
		exit(0);
	}

	for(i=0;i<m;i++)
	{ 
		fread(&q[i],sizeof(staff),1,fp2);
		if(num2==q[i].num)	//匹配工号 
		{
			printf("工号: %d\n",q[i].num);
			printf("姓名: %s\n",q[i].name);
			printf("基本工资: %d\n",q[i].base);
			printf("补贴工资: %d\n",q[i].subsidy);
			printf("奖励金额: %d\n",q[i].award);
			printf("扣除金额: %d\n",q[i].deduct);
			printf("实发金额: %d\n",q[i].pay);

			break;			//找到则跳出 
		}
	}
	if (i==m)
	{
		//如果一个循环完成，则输出找不到 
		printf("查无此人！\n");
	}

	fclose(fp1);
	fclose(fp2);
}
//===================================================================
void modify()//修改记录函数 
{
	FILE *fp1;
	FILE *fp2;
	int i;
	int k;				//k就是要修改的那条记录
	
	k=-1;

	int del_num;
	staff q[n];
	
	if((fp1=fopen("备记.txt","r"))==0)
	{
		
		printf("找不到文件!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);
	fclose(fp1);			//读取m后就关闭 
	if(m==0)
	{
		printf("没有记录，无法删除！\n");
		
		return;
	}
	
	printf("请输入你要修改记录的工号：");
	scanf("%d",&del_num);
	
	if((fp2=fopen("通讯录.dat","rb"))==NULL)
	{
		printf("查无此人!\n");
		
		exit(0);
	}
	
	for(i=0;i<m;i++)
	{
		fread(&q[i],sizeof(staff),1,fp2);
		if(del_num==q[i].num)			//匹配要删除的记录
		{
			k=i;						//将第i条记录的i赋值给k
		}
	}

	if(k==-1)							//如果一个循环完成，k等于初值0则输出找不到 
	{
		printf("找不记录！\n");
		return;
	}
	else
	{
		printf("工号: %d\n",q[k].num);
		printf("姓名: %s\n",q[k].name);
		printf("基本工资: %d\n",q[k].base);
		printf("补贴工资: %d\n",q[k].subsidy);
		printf("奖励金额: %d\n",q[k].award);
		printf("扣除金额: %d\n",q[k].deduct);
		printf("实发金额: %d\n",q[k].pay);
	}
	fclose(fp2);
	
	printf("请输入员工号:");
	scanf("%d",q[k].num);

	printf("请输入姓名:");
	scanf("%s",q[k].name);
	
	printf("请输入基本工资:");
	scanf("%d",q[k].base);
	
	printf("请输入补贴金额:");
	scanf("%d",q[k].subsidy);
	
	printf("请输入奖励金额:");
	scanf("%d",q[k].award);

	printf("请输入扣除金额:");
	scanf("%d",q[k].deduct);
		
	if((fp2=fopen("通讯录.dat","w"))==NULL)//重新用写的方式打开 
	{
		printf("找不到文件!\n");
		
		exit(0);
	}
	for(i=0;i<m;i++)
	{
		fwrite(&q[i],sizeof(staff),1,fp2);
	}

	printf("修改记录成功！\n");
	
	fclose(fp2);
}
//===================================================================
//删除记录函数
void del() 
{
	FILE *fp1;
	FILE *fp2;
	int i;
	int k;						//k就是要删除的那条记录
	
	k=-1;

	int del_num;
	staff q[n];
	
	if((fp1=fopen("备记.txt","r"))==0)
	{
		
		printf("找不到文件!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);
	fclose(fp1);	//读取m后就关闭 
	if(m==0)
	{
		printf("没有记录，无法删除！\n");
		
		return;
	}

	printf("请输入你要删除记录的工号：");
	scanf("%d",&del_num);

	if((fp2=fopen("通讯录.dat","rb"))==NULL)
	{
		printf("查无此人!\n");
		
		exit(0);
	}
	
	for(i=0;i<m;i++)
	{
		fread(&q[i],sizeof(staff),1,fp2);
		if(del_num==q[i].num)		//匹配要删除的记录
		{
			k=i;					//将第i条记录的i赋值给k
		}
	}
	if(k==-1)						//如果一个循环完成，k等于初值0则输出找不到 
	{
		printf("找不到记录！\n");
		return;
	}

	fclose(fp2);
	if((fp2=fopen("通讯录.dat","w"))==NULL)	//重新用写的方式打开 
	{
		printf("找不到文件!\n");
		
		exit(0);
	}

	for(i=0;i<k;i++)
	{
		fwrite(&q[i],sizeof(staff),1,fp2);
	}
	for(i=k+1;i<m;i++)			//i没有等于k，就实现了删除记录操作 
	{
		fwrite(&q[i],sizeof(staff),1,fp2);
	}
	if((fp1=fopen("备记.txt","w"))==NULL)
	{
		printf("找不到文件!");
		
		exit(0);
	}
	m--;				//删除记录后m要减1 
	fprintf(fp1,"%d",m);//重新写回m
	printf("删除记录成功！\n");
	fclose(fp1);
	fclose(fp2);
}
//===================================================================
void count()
{
	FILE *fp1;
	FILE *fp2;

	int i;

	int sum_base;				//总基本工资
	int sum_subsidy;			//总补贴金额
	int sum_award;				//总奖励金额
	int sum_deduct;				//总扣除工资
	int sum_pay;				//总实发工资

	sum_base=0;
	sum_subsidy=0;
	sum_award=0;
	sum_deduct=0;
	sum_pay=0;

	staff q[n];
	
	if((fp1=fopen("备记.txt","r"))==0)
	{
		printf("没有此文件!\n");
		
		exit(0);
	}

	fscanf(fp1,"%d",&m);		//取出m
	if(m==0)
	{
		printf("没有记录，不能查找！\n");
		
		return;
	}

	if((fp2=fopen("通讯录.dat","rb"))==NULL)
	{
		printf("没有该文件!\n");
		
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

	printf("        基本工资 补贴工资 奖励金额 扣除金额 实发工资\n");
	printf("总和:  %7d %7d %7d %7d\n",	sum_base,sum_subsidy,sum_award,sum_deduct,sum_pay);
	printf("平均:  %7d %7d %7d %7d\n",	sum_base/m,sum_subsidy/m,sum_award/m,sum_deduct/m,sum_pay/m);
	printf("人数:  %7d",m);

	fclose(fp1);
	fclose(fp2);
}
//===================================================================
//界面函数
void face() 
{
	printf("┏*━*━*━*━*━☆━*━*━┓\n"
		"   ┃                         ┃\n"
		"   ┃     第一次使用请按1     ┃\n"
		"   ┃                         ┃\n"
		"   ┃     增加记录请按2       ┃\n"
		"   ┃                         ┃\n"
		"   ┃     查找记录请按3       ┃\n"
		"   ┃                         ┃\n"
		"   ┃     修改记录请按4       ┃\n"
		"   ┃                         ┃\n"
		"   ┃     删除记录请按5       ┃\n"
		"   ┃                         ┃\n"
		"   ┃     统计请按6           ┃\n"
		"   ┃                         ┃\n"
		"   ┃     退出程序请按0       ┃\n"
		"   ┃                         ┃\n"
		"   ┗*━*━*━*━☆━*━*━*━┛\n");
	printf("\n请根据提示选择你要执行的程序：");
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
		getchar();	//吞掉回车符
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
					printf("继续增加请输入1，否则请输入0\n");
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
					printf("继续查找请输入1，否则请输入0\n");
					scanf("%d",&a);
					getchar();		//吞掉回车符
					system("cls");
				} while(a==1);
				break;
			}
		case 4:
			{
				do
				{
					modify();
					printf("继续修改请输入1，否则请输入0\n");
					scanf("%d",&a);
					getchar();		//吞掉回车符
					system("cls");
				} while (a==1);
				break;
			}
		case 5:
			{
				do
				{
					del();
					printf("继续删除请输入1，否则请输入0\n");
					scanf("%d",&a);
					getchar();		//吞掉回车符
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
		printf("继续请输入1，否则请输入0\n");
		scanf("%d",&a);
	}
	return 0;
}