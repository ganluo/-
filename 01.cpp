//职工工资记录由职工工号、职工姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税和实发工资9个项目构成
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int n=0;
struct worker{

	char workerID[10];//职工工号
	char name[10];//姓名
	float gsalary;//岗位工资
	float xsalary;//薪级工资
	float zsalary;//职务津贴
	float jsalary;//绩效工资
	float sumsalary;//应发工资
	float personaltax;//个人所得税
	float realsalary;//实发工资
}zggo[],worker1[2],worker2[2],*p,*q;
void read()
{
	FILE *fp;
	int i=1;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","rt"))==NULL){      //文件打开失败
		cout<<"Cannot open file strike any key exit!\n";
	    exit(-1);
	}
	fseek(fp,i*sizeof(struct worker),0);//移动文件位置指针
	fread(p,sizeof(struct worker),1,fp);
		cout<<"\n\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\n";
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;//读出第一个工人的信息
		cout<<p->workerID<<"\t"<<p->name<<"\t\t"<<p->gsalary<<
		         "\t\t"<<p->xsalary<<"\t\t"<<p->zsalary<<"\t\t"<<p->jsalary<<endl;//读出第二个工人的信息
	fclose(fp);

}
void write()
{
	FILE *fp;
	//float gs,xs,zs,js;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","wt+"))==NULL){        //文件打开失败
		cout<<"Cannot open file strike any key exit!\n";
		exit(-1);
	}
	for(int i=0;i<2;i++,p++,n++){                       //文件打开成功
		cout<<"输入两个人信息（工号，姓名等等）："<<i+1<<"\n";
		cin>>p->workerID; //输入工号
		cin>>p->name;    // 输入姓名
		cin>>p->gsalary; //输入岗位工资
		cin>>p->xsalary;//输入薪级工资
		cin>>p->zsalary;//输入职务津贴
		cin>>p->jsalary;//输入绩效工资
	}
	p=worker1;
	fwrite(p,sizeof(struct worker),2,fp);//写入2次，每次长度是worker字节数
	rewind(fp);
	fread(q,sizeof(struct worker),2,fp);
/*	cout<<"\n\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\n";
	for(i=0;i<2;i++,q++)
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;*/
	fclose(fp);
}
void find() //查询职工工资数据
{
	char gonghao[10];
	if(n==0)
	{
		cout<<"出现错误！\n";
	}
}
int main()
{
	write();
	read();
	return 0;
}