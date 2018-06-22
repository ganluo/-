#include <stdio.h>
struct worker{

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
/*typedef struct employee
{
char num[10]; //保存职工编号
char name[15]; //保存职工姓名
float jbgz; //保存职工基本工资
float jj; //保存职工奖金
float kk; //保存职工扣款
float yfgz; //保存职工应发工资
float sk; //保存职工税款
float sfgz; //保存职工实发工资
}ZGGZ;*/
int write(zggz a[],int k)//保存职员信息
{
	int j,x;
	char gonghao[10];
	j=x=0;
	while(1)
	{
		printf('请输入职工的工号：（按0返回主菜单）');
		scanf('%s',gonghao);
		strcpy(a[k].workerID,gonghao);
		for(j=0;j<k;j++)
		{
			if(strcmp(a[j].workerID,gonghao)==0)
			{
				printf('已经有工号为%s的员工信息!请重新输入员工号。',str);
				printf('请输入职工的工号：');
				scanf('%s',str);
				strcpy(a[k].workerID,str);
			}
		}
		if(strcmp(a[k].workerID,'0')==0)
			break;
		printf('请输入职工的姓名：');
		scanf('%s',a[k].name);
		printf('请输入职工的岗位工资：');
		scanf('%f',&a[k].gsalary);
		printf('请输入职工的薪级工资：');
		scanf('%f',&a[k].xsalary);
		printf('请输入职工的职务津贴：');
		scanf('%f',&a[k].zsalary);
		printf('请输入职工的绩效工资：');
		scanf('%f',&a[k].jsalary);
		a[k].sumsalary=a[k].gsalary+a[k].xsalary+a[k].zsalary+a[k].jsalary;
		k++;
	}
	return k;
}
int find(zggz a[],int y)   //查询职工工资数据函数
{
	int i;
	int x=0;
	char str[15];
	printf('请输入你要查找的工号或姓名：');
	scanf('%s',str);
	for(i=0;i<y;i++)
		if(!strcmp(str,a[i].workerID)||!strcmp(str,a[i].name))
		{
			printf('员工工号为%s',a[i].workerID);
			printf('员工姓名为%s',a[i].name);
			printf('岗位工资：%f',a[i].gsalary);
			printf('薪级工资：%f',a[i].xsalary);
			printf('职务津贴：%f',a[i].zsalary);
			printf('绩效工资：%f',a[i].jsalary);
			printf('应发工资：%f',a[i].sumsalary);
			printf('个人所得税：%f',a[i].personaltax);
			printf('实发工资：%f',a[i].realsalary);
			x++;
		}
		if(x==0)
		{
			printf('未找到该记录');
			return -1;
		}
}
void list(zggz a[],int n)//浏览职工工资数据函数
{
	int i=0;
	if(n==0)
	{
		printf('Files are empty');
		return;
	}
	do
	{
		printf('员工工号为%s',a[i].workerID);
		printf('员工姓名为%s',a[i].name);
		printf('岗位工资：%f',a[i].gsalary);
		printf('薪级工资：%f',a[i].xsalary);
		printf('职务津贴：%f',a[i].zsalary);
		printf('绩效工资：%f',a[i].jsalary);
		printf('应发工资：%f',a[i].sumsalary);
		printf('个人所得税：%f',a[i].personaltax);
		printf('实发工资：%f',a[i].realsalary);
		i++;
	}while(i<n);
}
void modify(zggz a[],int y)  //修改职工工资数据函数
{
	int i;
	int x=0;
	char str[15];
	printf('请输入你要修改的工号：');
	scanf('%s',str);
	for(i=0;i<y;i++)
		if(!strcmp(str,a[i].workerID)||!strcmp(str,a[i].name))
		{
			printf('请输入修改后职工的姓名：');
			scanf('%s',a[i].name);
			printf('请输入修改后职工的岗位工资：');
			scanf('%f',&a[i].gsalary);
			printf('请输入修改后职工的薪级工资：');
			scanf('%f',&a[i].xsalary);
			printf('请输入修改后职工的职务津贴：');
			scanf('%f',&a[i].zsalary);
			printf('请输入修改后职工的绩效工资：');
			scanf('%f',&a[i].jsalary);
			printf('请输入修改后职工的应发工资：');
			scanf('%f',&a[i].sumsalary);
			printf('请输入修改后职工的个人所得税：');
			scanf('%f',&a[i].personaltax);
			printf('请输入修改后职工的实发工资：');
			scanf('%f',&a[i].realsalary);
			printf('\n修改成功！');
			a[i].sumsalary=a[i].gsalary+a[i].xsalary+a[i].zsalary+a[i].jsalary;
			//a[i].sk=a[i].yfgz*(0.05);
			//a[i].sfgz=a[i].yfgz*(0.95);
			x++;
		}
		if(x==0)
		{
			printf('未找到要修改的工号');
		}
}
int del(zggz a[],int y)  //删除职工工资数据函数
{
	int i=0;
	int x=0;
	char str[15];
	printf('请输入你要删除的编号或姓名：');
	scanf('%s',str);
	printf('\n删除成功！');
	for(i=0;i<y;i++)
		if(!strcmp(str,a[i].workerID)||!strcmp(str,a[i].name))
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
			printf('输入的工号或姓名不存在，请重新输入：');
		}
		return y-x;
}
int add(zggz a[],int y)  //添加职工工资数据函数
{
	int i;
	int x=0;
	char str[15];
	printf('请输入你要插入的工号：');
	scanf('%s',str);
	printf('请输入一条新的记录信息：');
	for(i=0;i<y;i++)
		if(strcmp(str,a[i].workerID)==0)
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
		printf('请输入职工的工号：');
		scanf('%s',a[x].workerID);
		printf('请输入职工的姓名：');
		scanf('%s',a[x].name);
		printf('请输入职工的岗位工资：');
		scanf('%f',&a[x].gsalary);
		printf('请输入职工的薪级工资：');
		scanf('%f',&a[x].xsalary);
		printf('请输入职工的职务津贴：');
		scanf('%f',&a[x].zsalary);
		printf('请输入职工的应发工资：');
		scanf('%f',&a[x].sumsalary);
		printf('请输入职工的个人所得税：');
		scanf('%f',&a[x].xsalary);
		printf('请输入职工的实发工资：');
		scanf('%f',&a[x].realsalary);
		a[x].sumsalary=a[x].gsalary+a[x].xsalary+a[x].zsalary+a[i].jsalary;
		return y+1;
}
void read(zggz a[],int n)  //读取职工工资数据函数
{
	FILE *fp;
	int i;
	if((fp=fopen('gx.txt','wb'))==NULL)
	{
		printf('cannot open file!\n');
		return;
	}
	for(i=0;i<n;i++)
		if(fwrite(&a[i],sizeof(struct worker),1,fp)!=1)
			printf('file write error!\n');
		fclose(fp);
}
void grsds()				//计算个人所得税
{
	if(sumsalary>=100000)
	{
		personaltax=(sumsalary-100000)*0.45+29850;	//20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5
	}
	else if(sumsalary>=80000)
	{
		personaltax=(sumsalary-80000)*0.4+21850;
	})
	}
	else if(sumsalary>=60000)
	{
		personaltax(sumsalary-60000)*0.35+14850;
	}
	else if(sumsalary>=40000)
	{
		personaltax=(sumsalary-40000)*0.3+8850;
	}

	else if(sumsalary>=20000)
	{
		personaltax=(sumsalary-20000)*0.25+3850;
	}
	else if(sumsalary>=5000)
	{
		personaltax=(sumsalary-5000)*0.2+850;
	}
	else if(sumsalary>=2000)
	{
		personaltax=(sumsalary-2000)*0.15+400;
	}
	else if(sumsalary>=500)
	{
		personaltax=(sumsalary-500)*0.1+25;
	}
	else 
	{
		personaltax=sumsalary*0.05;
	}
}

int main()
{
	int selete,c=0;
	int i=0;
	int z=0;
	char q,p,x,s;
	zggz b[100];
	FILE *fp;
	if((fp=fopen('gx.dat','rb'))==NULL)
		printf('Not Found!\n');
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
	while(1)
	{
		scanf('%d',&selete);
		if(selete==0)
		{
			printf('Thank you for your use ( ^_^ ) Bye!\n');
			break;
		}
		switch(selete)
		{
		case 1:c=input(b,c);
			break;
		case 2:
			{
				display(b,c);
				do
				{
					c=del(b,c);
					printf('是否继续删除，是按y，否则请按任意值');
					getchar();
					scanf('%c',&p);
				}while(p=='Y'||p=='y');
				break;
			}
		case 3:
			{
				do
				{
					sear(b,c);
					printf('是否继续查找，是按y，否则请按任意值');
					getchar();
					scanf('%c',&x);
				}while(x=='Y'||x=='y');
				break;
			}
		case 4:
			{
				display(b,c);
				do
				{
					mod(b,c);
					printf('是否继续修改，是按y，否则请按任意值');
					getchar();
					scanf('%c',&q);
				}while(q=='Y'||q=='y');
				break;
			}
		case 5:
			{
				do
				{
					c=insert(b,c);
					printf('是否继续插入，是按y，否则请按任意值');
					getchar();
					scanf('%c',&s);
				}while(s=='Y'||s=='y');
				break;
			}
		case 6:count(b,c);break;
		case 7:display(b,c);sort(b,c);break;
		case 8:save(b,c);break;
		case 9:display(b,c);break;
		default:printf('Please try again');
		}
	}
	return 0;
}
