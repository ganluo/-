#include <stdio.h> //标准输入输出
#include <stdlib.h> //处理杂乱
#include <windows.h> //Sleep()
#include <string.h> //字符串操作
#include <conio.h> //系统输入输出   
#include <time.h> 
#define TURE 1
typedef struct worker{

	char workerID[10];//职工工号
	char name[15];//姓名
	float gsalary;//岗位工资
	float xsalary;//薪级工资
	float zsalary;//职务津贴
	float jsalary;//绩效工资
	float sumsalary;//应发工资
	float personaltax;//个人所得税
	float realsalary;//实发工资
}zggz;
void grsds(zggz a[],int i)				//计算个人所得税
{
	if(a[i].sumsalary>=100000)
	{
		a[i].personaltax=(a[i].sumsalary-100000)*(float)0.45+29850;	//20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5
	}
	else if(a[i].sumsalary>=80000.0)
	{
     	a[i].personaltax=(a[i].sumsalary-80000)*(float)0.4+21850;
	}
   	else if(a[i].sumsalary>=60000)
	{
    	a[i].personaltax=(a[i].sumsalary-60000)*(float)0.35+14850;
	}
    else if(a[i].sumsalary>=40000)
	{
	    a[i].personaltax=(a[i].sumsalary-40000)*(float)0.3+8850;
	}
   	else if(a[i].sumsalary>=20000)
	{
	   	a[i].personaltax=(a[i].sumsalary-20000)*(float)0.25+3850;
	}
   	else if(a[i].sumsalary>=5000)
	{
	   	a[i].personaltax=(a[i].sumsalary-5000)*(float)0.2+850;
	}
    else if(a[i].sumsalary>=2000)
	{
	   	a[i].personaltax=(a[i].sumsalary-2000)*(float)0.15+400;
	}
    else if(a[i].sumsalary>=500)
	{
    	a[i].personaltax=(a[i].sumsalary-500)*(float)0.1+25;
	}
   else 
	{
	   	a[i].personaltax=a[i].sumsalary*(float)0.05;
	}
}
int read(zggz a[],int n)   //读取职工工资数据函数
{
	FILE *fp;
	int i;
	if((fp=fopen("gz.txt","rb"))==NULL)//以二进制方式打开职工工资数据文件并进行判断是否失败
	{
		printf("\n\n\t职工工资数据文件无法打开，或为空！\n");
		printf("\n\t\t按任意键返回主菜单！\n");
		getchar();
		return 0;
	}
	else  //文件打开成功时
	{
		for(i=0;i<n;i++)
			if(fread(&a[i],sizeof(struct worker),1,fp)==1)
				printf("file write error!\n");
			fclose(fp);
			printf("\n\t5秒钟后继续！\n",i);
			i--;
			Sleep(5000);//延时5秒钟
			return 0;
	}
}
int write(zggz a[],int k)   //保存职员信息
{
	FILE *fp;
	int j,x;
	char gonghao[10];
	j=x=0;
	if(x==-1)
	{
		printf("\n\t\t按任意键返回主菜单！");
		getchar();
		return 0;
	}
	
	if((fp=fopen("gz.dat","wb"))!=NULL)
	{
		fwrite(&a[j],sizeof(struct worker),j+1,fp);
		while(1)
	{
		printf("请输入职工的工号：");
		scanf("%s",gonghao);
		strcpy(a[k].workerID,gonghao);
		for(j=0;j<k;j++)
		{
			if(strcmp(a[j].workerID,gonghao)==0)
			{
				printf("已经有工号为%s的员工信息!请重新输入员工号。\n",gonghao);
				printf("请输入职工的工号：");
				scanf("%s",gonghao);
				strcpy(a[k].workerID,gonghao);
			}
		}
		if(strcmp(a[k].workerID,"0")==0)
			break;
		printf("请输入职工的姓名：");
		scanf("%s",a[k].name);
		printf("请输入职工的岗位工资：");
		scanf("%f",&a[k].gsalary);
		printf("请输入职工的薪级工资：");
		scanf("%f",&a[k].xsalary);
		printf("请输入职工的职务津贴：");
		scanf("%f",&a[k].zsalary);
		printf("请输入职工的绩效工资：");
		scanf("%f",&a[k].jsalary);
		a[k].sumsalary=a[k].gsalary+a[k].xsalary+a[k].zsalary+a[k].jsalary;
		k++;
	}
		fclose(fp);
	    printf("\n\n\t\t%d条职工记录保存完毕！\n",j+1);
	}
	else
	{
		printf("\t\t无法打开职工工资数据文件！\n");
		printf("\n\t\t按任意键返回主菜单！");
		getchar();
	}

	
	return k;
}
int find(zggz a[],int y)  //查询职工工资数据函数
{
	int i;
	int x=0;
	char gonghao[15];
	printf("请输入你要查找的工号或姓名：");
	scanf("%s",gonghao);
	for(i=0;i<y;i++)
		if(!strcmp(gonghao,a[i].workerID)||!strcmp(gonghao,a[i].name))
		{
			printf("\n该职工工资情况如下：");
			printf("\n=============================\n\n");
			printf("员工工号为%s",a[i].workerID);
			printf("员工姓名为%s",a[i].name);
			printf("岗位工资：%f",a[i].gsalary);
			printf("薪级工资：%f",a[i].xsalary);
			printf("职务津贴：%f",a[i].zsalary);
			printf("绩效工资：%f",a[i].jsalary);
			printf("应发工资：%f",a[i].sumsalary);
			printf("个人所得税：%f",a[i].personaltax);
			printf("实发工资：%f",a[i].realsalary);
			x++;
		}
		if(x==0)
		{
			printf("\n未找到该记录！");
			return -1;
		}
		printf("\n\t\t按任意键返回主菜单！");
		getchar();
		return 0;
}
int list(zggz a[],int n)   //浏览职工工资数据函数
{
	int i=0;
	printf("\n\n\t\t\t全体职工工资情况如下：\n");
	printf("\t\t\t=============================\n\n");
	if(n==0)
	{
		printf("Files are empty");
		return 0;
	}
	do
	{
		printf("员工工号为%s",a[i].workerID);
		printf("员工姓名为%s",a[i].name);
		printf("岗位工资：%f",a[i].gsalary);
		printf("薪级工资：%f",a[i].xsalary);
		printf("职务津贴：%f",a[i].zsalary);
		printf("绩效工资：%f",a[i].jsalary);
		printf("应发工资：%f",a[i].sumsalary);
		printf("个人所得税：%f",a[i].personaltax);
		printf("实发工资：%f",a[i].realsalary);
		i++;
	}while(i<n);
	Sleep(5000);
	printf("\n\t\t按任意键返回主菜单！");
	getchar();
}
void modify(zggz a[],int y) //修改职工工资数据函数
{
	int i;
	int x=0;
	char gonghao[15];
	printf("请输入你要修改的工号：");
	scanf("%s",gonghao);
	for(i=0;i<y;i++)
		if(!strcmp(gonghao,a[i].workerID)||!strcmp(gonghao,a[i].name))
		{
			printf("请输入修改后职工的姓名：");
			scanf("%s",a[i].name);
			printf("请输入修改后职工的岗位工资：");
			scanf("%f",&a[i].gsalary);
			printf("请输入修改后职工的薪级工资：");
			scanf("%f",&a[i].xsalary);
			printf("请输入修改后职工的职务津贴：");
			scanf("%f",&a[i].zsalary);
			printf("请输入修改后职工的绩效工资：");
			scanf("%f",&a[i].jsalary);
			printf("请输入修改后职工的应发工资为：%f",a[i].sumsalary=a[i].gsalary+a[i].xsalary+a[i].zsalary+a[i].jsalary);
			grsds(a,i);
			printf("请输入修改后职工的个人所得税为：%f",a[i].personaltax);
			printf("请输入修改后职工的实发工资为：%f",a[i].realsalary);
			printf("\n修改成功！");
			x++;
		}
		if(x==0)
		{
			printf("未找到要修改的工号");
		}
		printf("\n\t\t按任意键返回主菜单！");
	    getchar();
}
int del(zggz a[],int y)  //删除职工工资数据函数
{
	int i=0;
	int x=0;
	char gonghao[15];
	printf("请输入你要删除的编号或姓名：");
	scanf("%s",gonghao);
	printf("\n删除成功！");
	for(i=0;i<y;i++)
		if(!strcmp(gonghao,a[i].workerID)||!strcmp(gonghao,a[i].name))
		{
			while(i<y)
			{
				strcpy(a[i].workerID,a[i+1].workerID);
				strcpy(a[i].name,a[i+1].name);
				a[i].gsalary=a[i+1].gsalary;
				a[i].xsalary=a[i+1].xsalary;
				a[i].zsalary=a[i+1].zsalary;
				a[i].jsalary=a[i+1].jsalary;
				a[i].sumsalary=a[i+1].sumsalary;
				a[i].personaltax=a[i+1].personaltax;
				a[i].realsalary=a[i+1].realsalary;
				i++;
			}
			x++;
		}
		if(x==0)
		{
			printf("\n输入的工号或姓名不存在，请重新输入：");
		}
		return y-x;
}
int add(zggz a[],int y)  //添加职工工资数据函数
{
	int i;
	int x=0;
	char gonghao[15];
	printf("\t请输入你要插入的工号：");
	scanf("%s",gonghao);
	fflush(stdin);
	printf("\t请输入一条新的记录信息：");
	for(i=0;i<y;i++)
		if(strcmp(gonghao,a[i].workerID)==0)
		{
			x=i;
			for(i=y;i>x+1;i--)
			{
				a[i].gsalary=a[i-1].gsalary;
				a[i].xsalary=a[i-1].xsalary;
				a[i].zsalary=a[i-1].zsalary;
				a[i].jsalary=a[i-1].jsalary;
				a[i].sumsalary=a[i-1].sumsalary;
				a[i].personaltax=a[i-1].personaltax;
				a[i].realsalary=a[i-1].realsalary;
				strcpy(a[i].name,a[i-1].name);
				strcpy(a[i].workerID,a[i-1].workerID);
			}
		}
		x++;
		printf("请输入职工的工号：");
		scanf("%s",a[x].workerID);
		printf("请输入职工的姓名：");
		scanf("%s",a[x].name);
		printf("请输入职工的岗位工资：");
		scanf("%f",&a[x].gsalary);
		printf("请输入职工的薪级工资：");
		scanf("%f",&a[x].xsalary);
		printf("请输入职工的职务津贴：");
		scanf("%f",&a[x].zsalary);
		printf("请输入职工的绩效工资：");
		scanf("%f",&a[x].jsalary);
		printf("则职工的应发工资为：%f\n",a[x].sumsalary=a[x].gsalary+a[x].xsalary+a[x].zsalary+a[x].jsalary);
		grsds(a,x);
		printf("则职工的个人所得税为：%f\n",a[x].xsalary);
		printf("则职工的实发工资为：%f\n",a[x].realsalary=a[x].sumsalary-a[x].personaltax);
		return y+1;
}


int main()
{
	char ch;
	while(TURE)
	{
	system("cls");//清屏命令
	printf("\n\n\t\t--欢迎使用工资管理系统--\n\n\n");
	printf("\t\t=================================================\n");
	printf("\t\t\t1.读取职员工资记录\n");
	printf("\t\t\t2.查询职员工资记录\n");
	printf("\t\t\t3.修改职员工资记录\n");
	printf("\t\t\t4.添加职员工资记录\n");
	printf("\t\t\t5.删除职员工资记录\n");
	printf("\t\t\t6.保存职员工资记录\n");
	printf("\t\t\t7.浏览职员记录\n");
	printf("\t\t\t8.退出\n");
	printf("\t\t=================================================\n");
	printf("\n\t\t你的选择是：");
	ch=getchar();
	int c=0;
	int i=0;
	int z=0;
	zggz b[100];
	FILE *fp;
	if((fp=fopen("gx.dat","rb"))==NULL)
		printf("Not Found!");
	else
	{
		do
		{
			fread(&b[i],sizeof(struct worker),1,fp);
			i++;
		}while(!feof(fp));
		fclose(fp);
		c=i-1;
	}
	switch(ch)
	{
	case'1':read(b,c);break;//读取
	case'2':find(b,c);break;//查询
	case'3':modify(b,c);break;//修改
	case'4':add(b,c);break;//添加
	case'5':del(b,c);break;//删除
	case'6':write(b,c);break;//保存
	case'7':list(b,c);break;//浏览
	case'8':return 0;//退出
	default:printf("\t\t请按任意键返回重新选择（1-7）\n");
	getch();
	}
	}
	return 0;
}
