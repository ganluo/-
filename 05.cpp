#include <stdio.h> //��׼�������
#include <stdlib.h> //��������
#include <windows.h> //Sleep()
#include <string.h> //�ַ�������
#include <conio.h> //ϵͳ�������   
#include <time.h> 
#define TURE 1
void read();
void write();
void find();
void modify();
void add();
void del();
float grsds(float m);
void list();
struct worker
{
	char workerID[10];
	char name[15];//����
	float gsalary;//��λ����
	float xsalary;//н������
	float zsalary;//ְ�����
	float jsalary;//��Ч����
	float sumsalary;//Ӧ������
	float personaltax;//��������˰
	float realsalary;//ʵ������
};
struct worker zggz[100];
int n=-1;

void read()
{
	FILE *fp;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		printf("\n\n\tְ�����������ļ��޷��򿪣���Ϊ�գ�");
		printf("\n\n\t�����������˵���");
		getchar();
		return;
	}
	else
	{
		n++;
		while(fread(&zggz[n],sizeof(zggz[n]),1,fp)==1)
			n++;
		fclose(fp);
		printf("\n\n\tְ���������ݶ�ȡ��ϣ�����%d�ˣ�\n",n);
		printf("\n\t5���Ӻ������\n",n);
		n--;
		Sleep(5000);//��ʱ5����
	}
}
void write()
{
	FILE *fp;
	if(n==-1)
	{
		printf("û�����ݿɴ棡��������������˵���\n");
		getchar();
		return;
	}
	if((fp=fopen("gz.dat","wb"))!=NULL)
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,fp);
		fclose(fp);
		printf("\n\n\t%d��ְ����¼������ϣ�\n",n+1);
	}
	else
		printf("\t\t����ְ�����������ļ���\n");
	printf("\n\t\t��������������˵���");
	getchar();
}
void find()
{
	char gonghao[10];
	int i;
	if(n==-1)
	{
		printf("\n\n\t\t��ǰ��û��ְ�����ʼ�¼����������������˵���");
		getchar();
		return;
	}
	printf("\t������ְ�����ţ�");
	gets(gonghao);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)
		{
			printf("\n��ְ������������£�");
			printf("\n===================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
			printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
			printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
			printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
			printf("\n\t\t��������������˵���");
			getchar();
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t���������ְ����������򲻴��ڣ�");
		printf("��������������˵���");
		getchar();
		return;
	}
}
void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\tȫ��ְ������������£�\n");
	printf("\n===================================\n\n");
	printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
	printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","��������˰","ʵ������");
	for(i=0;i<=n;i++)
	{
		printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
		printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
		printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
		printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
	}
	printf("��������������˵���");
	getchar();
	return;
}
void modify()
{
	char gonghao[10];
	int i;
	if(n==-1)
	{
		printf("\n\n\t\t��ǰ��û��ְ�����ʼ�¼����������������˵���");
		getchar();
		return;
	}
	printf("\t�����빤�ţ�");
	gets(gonghao);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)
		{
			printf("\n\n\t\t\tȫ��ְ������������£�\n");
			printf("\n===================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
			printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
			printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
			printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
			printf("\n\t\t�������ְ���µĸ�λ���ʣ�");
			scanf("%f",&zggz[i].gsalary);
			printf("\n\t\t�������ְ���µ�н�����ʣ�");
			scanf("%f",&zggz[i].xsalary);
			printf("\n\t\t�������ְ���µ�ְ�������");
			scanf("%f",&zggz[i].zsalary);
			printf("\n\t\t�������ְ���µļ�Ч���ʣ�");
			scanf("%f",&zggz[i].jsalary);
			zggz[i].sumsalary=zggz[i].gsalary+zggz[i].xsalary+zggz[i].zsalary+zggz[i].jsalary;
			grsds(zggz[i].sumsalary);
			zggz[i].realsalary=zggz[i].sumsalary-zggz[i].personaltax;
			printf("\n\t\t��ְ����Ӧ�������ǣ�%f",zggz[i].sumsalary);
			printf("\n\t\t��ְ���ĸ�������˰�ǣ�%f",zggz[i].personaltax);
			printf("\n\t\t��ְ����ʵ�������ǣ�%f",zggz[i].realsalary);
			printf("\n\n\t\t��ְ�����������޸ĳɹ�����������������˵���");
			getchar();
			return;
		}
	}
	printf("\n\t\t���������ְ����������򲻴��ڣ�");
	printf("��������������˵���");
	getchar();
	return;
}
void add()
{
	printf("\t�����빤�ţ�");
	fflush(stdin);
	gets(zggz[++n].workerID);
	printf("\t\t\t��������ְ��������");
	gets(zggz[n].name);
	printf("\n\t\t�������ְ���µĸ�λ���ʣ�");
	scanf("%f",&zggz[n].gsalary);
	printf("\n\t\t�������ְ���µ�н�����ʣ�");
	scanf("%f",&zggz[n].xsalary);
	printf("\n\t\t�������ְ���µ�ְ�������");
	scanf("%f",&zggz[n].zsalary);
	printf("\n\t\t�������ְ���µļ�Ч���ʣ�");
	scanf("%f",&zggz[n].jsalary);
	zggz[n].sumsalary=zggz[n].gsalary+zggz[n].xsalary+zggz[n].zsalary+zggz[n].jsalary;
	grsds(zggz[n].sumsalary);
	zggz[n].realsalary=zggz[n].sumsalary-zggz[n].personaltax;
	printf("\t\tt��ְ����Ӧ�������ǣ�%f",zggz[n].realsalary);
	printf("\t\tt��ְ���ĸ�������˰�ǣ�%f",zggz[n].personaltax);
	printf("\t\t\t��ְ����ʵ�������ǣ�%f",zggz[n].realsalary);
	printf("\n\n\t\t\t����������ء�");
	getchar();
}
void del()
{
	char gonghao[10];
	int i,j;
	char d;
	printf("\t�������ɾ��ְ�����ţ�");
	gets(gonghao);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)
		{
			printf("\n\t\t��ȷ��Ҫɾ��%s��ְ��������Ϣ��y/n����",zggz[i].workerID);
			d=getchar();
			if(d=='y'||d=='Y')
			{
				if(i==n)
					n--;
				else
				{
					for(j=i;j<=n;j++)
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
			}
			printf("\n\n\t\t��ְ���������ݳɹ�ɾ������������������˵���");
			getchar();
			break;
		}
		else
		{
			printf("\n\n\t\t��ѡ���˲�ɾ����ְ����¼����������������˵���");
			getchar();
			return;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t����λ�޴˹��ţ���������������˵���");
		getchar();
	}
}
float grsds(float m)
{
	float x;
	float y=0;
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
		switch(n)
		{
		case 9:y=(x-1000000)*(float)0.45;x=1000000;
		case 8:y+=(x-80000)*(float)0.40;x=80000;
		case 7:y+=(x-60000)*(float)0.40;x=60000;
		case 6:y+=(x-40000)*(float)0.35;x=40000;
		case 5:y+=(x-20000)*(float)0.30;x=20000;
		case 4:y+=(x-5000)*(float)0.25;x=5000;
		case 3:y+=(x-2000)*(float)0.20;x=2000;
		case 2:y+=(x-500)*(float)0.15;x=500;
		case 1:y+=x*(float)0.05;
		}
		return y;
}


void main()
{
	char ch;
	while(TURE)
	{
	system("cls");//��������
	printf("\n\n\t\t--��ӭʹ�ù��ʹ���ϵͳ--\n\n\n");
	printf("\t\t=================================================\n");
	printf("\t\t\t1.��ѯְԱ���ʼ�¼\n");
	printf("\t\t\t2.�޸�ְԱ���ʼ�¼\n");
	printf("\t\t\t3.���ְԱ���ʼ�¼\n");
	printf("\t\t\t4.ɾ��ְԱ���ʼ�¼\n");
	printf("\t\t\t5.����ְԱ���ʼ�¼\n");
	printf("\t\t\t6.���ְԱ���ʼ�¼\n");
	printf("\t\t\t7.�˳�\n");
	printf("\t\t=================================================\n");
	printf("\n\t\t���ѡ���ǣ�");
	ch=getchar();
	switch(ch)
	{
		case'1':find();break;//��ѯ
		case'2':modify();break;//�޸�
		case'3':add();break;//���
		case'4':del();break;//ɾ��
		case'5':write();break;//����
		case'6':list();break;//���
		case'7':return;//�˳�
		default:printf("\t\t�밴�������������ѡ��1-7��\n");
		getch();
		}
	}
	return;
}