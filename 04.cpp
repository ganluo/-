#include "stdio.h"       //标准输入输出
#include "windows.h"    //Sleep()包含在此
#include "string.h"    //字符串操作
#include "conio.h"    //系统输入输出 getch()及getche()函数包含在此  
#define TURE 1
void read();         //从数据文件中读取职工工资数据		
void write();       //向职工工资数据文件中写入记录
void find();       //查询职工工资数据记录
void modify();    //修改职工工资数据记录
void add();      //向职工工资数据文件中增加记录
void del();     //向职工工资数据文件中删除记录
float grsds(float m);    //计算个人所得税
void list();            //浏览职工记录
struct worker          //声明职工工资数据结构体
{
	char workerID[10];     //职工工号
	char name[15];         //姓名
	float gsalary;         //岗位工资
	float xsalary;         //薪级工资
	float zsalary;         //职务津贴
	float jsalary;         //绩效工资
	float sumsalary;       //应发工资
	float personaltax;     //个人所得税
	float realsalary;      //实发工资
};
struct worker zggz[100];      //声明记录职工工资情况的100个元素的结构体数组
int n=-1;                    //声明统计职工人数变量（全局）
void write()                //保存职员信息
{
	FILE *fp;    //声明文件指针
	if(n==-1)   //职工人数为0时
	{
		printf("没有数据可存！按任意键返回主菜单。\n");
		getch();                      //不回显函数，当用户按下某个字符时，函数自动读取，无需按回车（字符不会显示在屏幕上）
		return;
	}
	if((fp=fopen("gz.dat","wb"))!=NULL)            //以二进制方式打开职工工资数据文件并进行判断是否失败
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,fp);   //所有记录一次写入文件
		fclose(fp);                               //关闭文件指针
		printf("\n\n\t%d条职工记录保存完毕！\n",n+1);
	}  
	else                                      //文件打开不成功时
		printf("\t\t无法打开职工工资数据文件！\n");
	printf("\n\t\t按任意键返回主菜单。");
	getch();               //不回显函数
}
void find()               //查询职工工资数据函数
{
	char gonghao[10];    //接收职工工号字符数组
	int i;              //循环变量
	if(n==-1)          //人数为0说明工资记录尚未添加
	{
		printf("\n\n\t\t当前还没有职工工资记录，按任意键返回主菜单。");
		getch();                 //不回显函数
		return;
	}
	printf("\t请输入职工工号：");   //提示信息
	gets(gonghao);                 //从键盘读取数组
	for(i=0;i<=n;i++)             //在职工总数范围内循环查找
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)   //比较并找到
		{
			printf("\n该职工工资情况如下：");
			printf("\n===================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","工号","姓名","岗位工资","薪级工资","职务津贴");
			printf("%-9s%-9s%8s%9s\n","绩效工资","应发工资","个人所得税","实发工资");
			printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
			printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
			printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
			printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
			printf("\n\t\t按任意键返回主菜单。");
			getch();     //不回显函数
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t您所输入的职工工号有误或不存在！");
		printf("按任意键返回主菜单。");
		getch();
		return;
	}
}
void list()    //浏览职工工资数据函数
{
	int i;
	system("cls");      //清屏
	printf("\n\n\t\t\t全体职工工资情况如下：\n");
	printf("\n===================================\n\n");
	printf("%-6s%-6s%-9s%-9s%-9s","工号","姓名","岗位工资","薪级工资","职务津贴");
	printf("%-9s%-9s%8s%9s\n","绩效工资","应发工资","个人所得税","实发工资");
	for(i=0;i<=n;i++)
	{
		printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
		printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
		printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
		printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
	}
	printf("按任意键返回主菜单。");
	getch();
	return;
}
void modify()             //修改职工工资数据函数
{
	char gonghao[10];    //接收职工工号字符数组
	int i;              //循环变量
	if(n==-1)          //人数为0说明工资记录尚未添加
	{
		printf("\n\n\t\t当前还没有职工工资记录，按任意键返回主菜单。");
		getch();
		return;
	}
	printf("\t请输入工号：");//提示信息
	gets(gonghao);          //从键盘读取字符串
	for(i=0;i<=n;i++)      //在职工总数范围内循环查找
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)
		{
			printf("\n\n\t\t\t全体职工工资情况如下：\n");
			printf("\n===================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","工号","姓名","岗位工资","薪级工资","职务津贴");
			printf("%-9s%-9s%8s%9s\n","绩效工资","应发工资","个人所得税","实发工资");
			printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
			printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
			printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
			printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
			printf("\n\t\t请输入该职工新的岗位工资：");
			scanf("%f",&zggz[i].gsalary);
			printf("\n\t\t请输入该职工新的薪级工资：");
			scanf("%f",&zggz[i].xsalary);
			printf("\n\t\t请输入该职工新的职务津贴：");
			scanf("%f",&zggz[i].zsalary);
			printf("\n\t\t请输入该职工新的绩效工资：");
			scanf("%f",&zggz[i].jsalary);
			zggz[i].sumsalary=zggz[i].gsalary+zggz[i].xsalary+zggz[i].zsalary+zggz[i].jsalary;  //计算应发工资
			zggz[i].personaltax=grsds(zggz[i].sumsalary);              //计算个人所得税
			zggz[i].realsalary=zggz[i].sumsalary-zggz[i].personaltax; //计算实发工资
			printf("\n\t\t该职工的应发工资是：%f",zggz[i].sumsalary);
			printf("\n\t\t该职工的个人所得税是：%f",zggz[i].personaltax);
			printf("\n\t\t该职工的实发工资是：%f",zggz[i].realsalary);
			printf("\n\n\t\t该职工工资数据修改成功！按任意键返回主菜单。");
			getch();    //不回显函数
			return;
		}
	}
	printf("\n\t\t您所输入的职工工号有误或不存在！");
	printf("按任意键返回主菜单。");
	getch();     //不回显函数
	return;
}
void add()   //添加职工工资数据函数
{
	printf("\t请输入工号：");
	fflush(stdin);    //请出键盘缓冲区
	gets(zggz[++n].workerID);
	printf("\t\t\t请输入新职工姓名：");
	gets(zggz[n].name);
	printf("\n\t\t请输入该职工新的岗位工资：");
	scanf("%f",&zggz[n].gsalary);
	printf("\n\t\t请输入该职工新的薪级工资：");
	scanf("%f",&zggz[n].xsalary);
	printf("\n\t\t请输入该职工新的职务津贴：");
	scanf("%f",&zggz[n].zsalary);
	printf("\n\t\t请输入该职工新的绩效工资：");
	scanf("%f",&zggz[n].jsalary);
	zggz[n].sumsalary=zggz[n].gsalary+zggz[n].xsalary+zggz[n].zsalary+zggz[n].jsalary;
	zggz[n].personaltax=grsds(zggz[n].sumsalary);   //计算个人所得税
	zggz[n].realsalary=zggz[n].sumsalary-zggz[n].personaltax;
	printf("\t\tt该职工的应发工资是：%f",zggz[n].realsalary);
	printf("\t\tt该职工的个人所得税是：%f",zggz[n].personaltax);
	printf("\t\t\t该职工的实发工资是：%f",zggz[n].realsalary);
	printf("\n\n\t\t\t按任意键返回。");
	getchar();
}
void del()  //删除职工工资数据函数
{
	char gonghao[10];   //接收职工工号字符数组
	int i,j;   //循环变量
	char d;    //接收确认删除字符y/n
	printf("\t请输入待删除职工工号：");
	gets(gonghao);
	for(i=0;i<=n;i++)  //在职工总数范围内循环查找
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)   //比较并找到
		{
			printf("\n\t\t你确认要删除%s号职工工资信息吗（y/n）？",zggz[i].workerID);
			d=getche();
			if(d=='y'||d=='Y')  //确认删除
			{
				if(i==n)  //如果是最后一条记录
					n--;
				else    //不是最后一条记录时
				{
					for(j=i;j<=n;j++)  //从该记录后续记录更新前一条记录
					{
						strcpy(zggz[j].workerID,zggz[j+1].workerID);
						strcpy(zggz[j].name,zggz[j+1].name);
						zggz[j].gsalary=zggz[j+1].gsalary;
						zggz[j].xsalary=zggz[j+1].xsalary;
						zggz[j].zsalary=zggz[j+1].zsalary;
						zggz[j].jsalary=zggz[j+1].jsalary;
						zggz[j].sumsalary=zggz[j+1].sumsalary;
						zggz[j].personaltax=zggz[j+1].personaltax;
						zggz[j].realsalary=zggz[j+1].realsalary;
					}
					n--;
				}
				printf("\n\n\t\t该职工工资数据成功删除！按任意键返回主菜单。");
				getch();
				break;
			}
			else  //未确认删除记录
			{
				printf("\n\n\t\t你选择了不删除该职工记录，按任意键返回主菜单。");
				getch();
				return;
			}
		}
	}
	if(i==n+1)  //未找到指定工号或未删除记录
	{
		printf("\n\t\t本单位无此工号，按任意键返回主菜单。");
		getch();
	}
}
float grsds(float m)   //计算个人所得税
{
	float x;     //当月应纳税所得额
	float y=0;  //当月应纳税额
	int n;
	x=m-2000;
	if(x>0)
		if(x<500)n=1;
		else if(x<2000)n=2;
		else if(x<5000)n=3;
		else if(x<20000)n=4;
		else if(x<40000)n=5;
		else if(x<60000)n=6;
		else if(x<80000)n=7;
		else if(x<100000)n=8;
		else n=9;
		switch(n)    //此处利用case的特点
		{
		case 9:y=(x-1000000)*0.45;x=1000000;
		case 8:y+=(x-80000)*0.40;x=80000;
		case 7:y+=(x-60000)*0.40;x=60000;
		case 6:y+=(x-40000)*0.35;x=40000;
		case 5:y+=(x-20000)*0.30;x=20000;
		case 4:y+=(x-5000)*0.25;x=5000;
		case 3:y+=(x-2000)*0.20;x=2000;
		case 2:y+=(x-500)*0.15;x=500;
		case 1:y+=x*0.05;
		}
		return y;
}
void main()
{
	char ch;
	read();   //从数据文件中读取职工工资数据并初始化职工工资结构体数组
	while(TURE)
	{
	system("cls");//清屏命令
	printf("\n\n\t\t--欢迎使用工资管理系统--\n\n\n");
	printf("\t\t=================================================\n");
	printf("\t\t\t1.查询职员工资记录\n");
	printf("\t\t\t2.修改职员工资记录\n");
	printf("\t\t\t3.添加职员工资记录\n");
	printf("\t\t\t4.删除职员工资记录\n");
	printf("\t\t\t5.保存职员工资记录\n");
	printf("\t\t\t6.浏览职员工资记录\n");
	printf("\t\t\t7.退出\n");
	printf("\t\t=================================================\n");
	printf("\n\t\t你的选择是：");
	ch=getche();  //将读入的字符回显到屏幕上（读入后不管回不回车立即回显）
	switch(ch)
	{
		case'1':find();break;       //查询
		case'2':modify();break;     //修改
		case'3':add();break;        //添加
		case'4':del();break;       //删除
		case'5':write();break;     //保存
		case'6':list();break;      //浏览
		case'7':return;            //退出
		default:printf("\t\t请按任意键返回重新选择（1-7）\n");
		getch();
		}
	}
	return;
}
void read()  //读取职工工资数据函数
{
	FILE *fp;
	if((fp=fopen("gz.dat","rb"))==NULL)     //以二进制方式打开职工工资数据文件并进行判断是否失败
	{
		printf("\n\n\t职工工资数据文件无法打开，或为空！");
		printf("\n\n\t按任意键进入菜单！");
		getch();
		return;
	}
	else    //文件打开成功时
	{
		n++;    //计算结构体数组下标
		while(fread(&zggz[n],sizeof(zggz[n]),1,fp)==1)
			n++;
		fclose(fp);    //关闭文件指针
		printf("\n\n\t职工工资数据读取完毕，共有%d人！\n",n);
		printf("\n\t5秒钟后继续！\n",n);    
		n--;        //计算职工记录总数
		Sleep(5000);//延时5秒钟
	}
}