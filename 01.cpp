//ְ�����ʼ�¼��ְ�����š�ְ����������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������9����Ŀ����
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int n=0;
struct worker{

	char workerID[10];//ְ������
	char name[10];//����
	float gsalary;//��λ����
	float xsalary;//н������
	float zsalary;//ְ�����
	float jsalary;//��Ч����
	float sumsalary;//Ӧ������
	float personaltax;//��������˰
	float realsalary;//ʵ������
}zggo[],worker1[2],worker2[2],*p,*q;
void read()
{
	FILE *fp;
	int i=1;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","rt"))==NULL){      //�ļ���ʧ��
		cout<<"Cannot open file strike any key exit!\n";
	    exit(-1);
	}
	fseek(fp,i*sizeof(struct worker),0);//�ƶ��ļ�λ��ָ��
	fread(p,sizeof(struct worker),1,fp);
		cout<<"\n\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\n";
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;//������һ�����˵���Ϣ
		cout<<p->workerID<<"\t"<<p->name<<"\t\t"<<p->gsalary<<
		         "\t\t"<<p->xsalary<<"\t\t"<<p->zsalary<<"\t\t"<<p->jsalary<<endl;//�����ڶ������˵���Ϣ
	fclose(fp);

}
void write()
{
	FILE *fp;
	//float gs,xs,zs,js;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","wt+"))==NULL){        //�ļ���ʧ��
		cout<<"Cannot open file strike any key exit!\n";
		exit(-1);
	}
	for(int i=0;i<2;i++,p++,n++){                       //�ļ��򿪳ɹ�
		cout<<"������������Ϣ�����ţ������ȵȣ���"<<i+1<<"\n";
		cin>>p->workerID; //���빤��
		cin>>p->name;    // ��������
		cin>>p->gsalary; //�����λ����
		cin>>p->xsalary;//����н������
		cin>>p->zsalary;//����ְ�����
		cin>>p->jsalary;//���뼨Ч����
	}
	p=worker1;
	fwrite(p,sizeof(struct worker),2,fp);//д��2�Σ�ÿ�γ�����worker�ֽ���
	rewind(fp);
	fread(q,sizeof(struct worker),2,fp);
/*	cout<<"\n\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\n";
	for(i=0;i<2;i++,q++)
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;*/
	fclose(fp);
}
void find() //��ѯְ����������
{
	char gonghao[10];
	if(n==0)
	{
		cout<<"���ִ���\n";
	}
}
int main()
{
	write();
	read();
	return 0;
}