#include <stdio.h> //��׼�������
#include <stdlib.h> //��������
#include <windows.h> //Sleep()
#include <string.h> //�ַ�������
#include <conio.h> //ϵͳ�������   
#include <time.h> 
#define TURE 1
typedef struct worker{

	char workerID[10];//ְ������
	char name[15];//����
	float gsalary;//��λ����
	float xsalary;//н������
	float zsalary;//ְ�����
	float jsalary;//��Ч����
	float sumsalary;//Ӧ������
	float personaltax;//��������˰
	float realsalary;//ʵ������
}zggz;
void grsds(zggz a[],int i)				//�����������˰
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
int read(zggz a[],int n)   //��ȡְ���������ݺ���
{
	FILE *fp;
	int i;
	if((fp=fopen("gz.txt","rb"))==NULL)//�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
		printf("\n\n\tְ�����������ļ��޷��򿪣���Ϊ�գ�\n");
		printf("\n\t\t��������������˵���\n");
		getchar();
		return 0;
	}
	else  //�ļ��򿪳ɹ�ʱ
	{
		for(i=0;i<n;i++)
			if(fread(&a[i],sizeof(struct worker),1,fp)==1)
				printf("file write error!\n");
			fclose(fp);
			printf("\n\t5���Ӻ������\n",i);
			i--;
			Sleep(5000);//��ʱ5����
			return 0;
	}
}
int write(zggz a[],int k)   //����ְԱ��Ϣ
{
	FILE *fp;
	int j,x;
	char gonghao[10];
	j=x=0;
	if(x==-1)
	{
		printf("\n\t\t��������������˵���");
		getchar();
		return 0;
	}
	
	if((fp=fopen("gz.dat","wb"))!=NULL)
	{
		fwrite(&a[j],sizeof(struct worker),j+1,fp);
		while(1)
	{
		printf("������ְ���Ĺ��ţ�");
		scanf("%s",gonghao);
		strcpy(a[k].workerID,gonghao);
		for(j=0;j<k;j++)
		{
			if(strcmp(a[j].workerID,gonghao)==0)
			{
				printf("�Ѿ��й���Ϊ%s��Ա����Ϣ!����������Ա���š�\n",gonghao);
				printf("������ְ���Ĺ��ţ�");
				scanf("%s",gonghao);
				strcpy(a[k].workerID,gonghao);
			}
		}
		if(strcmp(a[k].workerID,"0")==0)
			break;
		printf("������ְ����������");
		scanf("%s",a[k].name);
		printf("������ְ���ĸ�λ���ʣ�");
		scanf("%f",&a[k].gsalary);
		printf("������ְ����н�����ʣ�");
		scanf("%f",&a[k].xsalary);
		printf("������ְ����ְ�������");
		scanf("%f",&a[k].zsalary);
		printf("������ְ���ļ�Ч���ʣ�");
		scanf("%f",&a[k].jsalary);
		a[k].sumsalary=a[k].gsalary+a[k].xsalary+a[k].zsalary+a[k].jsalary;
		k++;
	}
		fclose(fp);
	    printf("\n\n\t\t%d��ְ����¼������ϣ�\n",j+1);
	}
	else
	{
		printf("\t\t�޷���ְ�����������ļ���\n");
		printf("\n\t\t��������������˵���");
		getchar();
	}

	
	return k;
}
int find(zggz a[],int y)  //��ѯְ���������ݺ���
{
	int i;
	int x=0;
	char gonghao[15];
	printf("��������Ҫ���ҵĹ��Ż�������");
	scanf("%s",gonghao);
	for(i=0;i<y;i++)
		if(!strcmp(gonghao,a[i].workerID)||!strcmp(gonghao,a[i].name))
		{
			printf("\n��ְ������������£�");
			printf("\n=============================\n\n");
			printf("Ա������Ϊ%s",a[i].workerID);
			printf("Ա������Ϊ%s",a[i].name);
			printf("��λ���ʣ�%f",a[i].gsalary);
			printf("н�����ʣ�%f",a[i].xsalary);
			printf("ְ�������%f",a[i].zsalary);
			printf("��Ч���ʣ�%f",a[i].jsalary);
			printf("Ӧ�����ʣ�%f",a[i].sumsalary);
			printf("��������˰��%f",a[i].personaltax);
			printf("ʵ�����ʣ�%f",a[i].realsalary);
			x++;
		}
		if(x==0)
		{
			printf("\nδ�ҵ��ü�¼��");
			return -1;
		}
		printf("\n\t\t��������������˵���");
		getchar();
		return 0;
}
int list(zggz a[],int n)   //���ְ���������ݺ���
{
	int i=0;
	printf("\n\n\t\t\tȫ��ְ������������£�\n");
	printf("\t\t\t=============================\n\n");
	if(n==0)
	{
		printf("Files are empty");
		return 0;
	}
	do
	{
		printf("Ա������Ϊ%s",a[i].workerID);
		printf("Ա������Ϊ%s",a[i].name);
		printf("��λ���ʣ�%f",a[i].gsalary);
		printf("н�����ʣ�%f",a[i].xsalary);
		printf("ְ�������%f",a[i].zsalary);
		printf("��Ч���ʣ�%f",a[i].jsalary);
		printf("Ӧ�����ʣ�%f",a[i].sumsalary);
		printf("��������˰��%f",a[i].personaltax);
		printf("ʵ�����ʣ�%f",a[i].realsalary);
		i++;
	}while(i<n);
	Sleep(5000);
	printf("\n\t\t��������������˵���");
	getchar();
}
void modify(zggz a[],int y) //�޸�ְ���������ݺ���
{
	int i;
	int x=0;
	char gonghao[15];
	printf("��������Ҫ�޸ĵĹ��ţ�");
	scanf("%s",gonghao);
	for(i=0;i<y;i++)
		if(!strcmp(gonghao,a[i].workerID)||!strcmp(gonghao,a[i].name))
		{
			printf("�������޸ĺ�ְ����������");
			scanf("%s",a[i].name);
			printf("�������޸ĺ�ְ���ĸ�λ���ʣ�");
			scanf("%f",&a[i].gsalary);
			printf("�������޸ĺ�ְ����н�����ʣ�");
			scanf("%f",&a[i].xsalary);
			printf("�������޸ĺ�ְ����ְ�������");
			scanf("%f",&a[i].zsalary);
			printf("�������޸ĺ�ְ���ļ�Ч���ʣ�");
			scanf("%f",&a[i].jsalary);
			printf("�������޸ĺ�ְ����Ӧ������Ϊ��%f",a[i].sumsalary=a[i].gsalary+a[i].xsalary+a[i].zsalary+a[i].jsalary);
			grsds(a,i);
			printf("�������޸ĺ�ְ���ĸ�������˰Ϊ��%f",a[i].personaltax);
			printf("�������޸ĺ�ְ����ʵ������Ϊ��%f",a[i].realsalary);
			printf("\n�޸ĳɹ���");
			x++;
		}
		if(x==0)
		{
			printf("δ�ҵ�Ҫ�޸ĵĹ���");
		}
		printf("\n\t\t��������������˵���");
	    getchar();
}
int del(zggz a[],int y)  //ɾ��ְ���������ݺ���
{
	int i=0;
	int x=0;
	char gonghao[15];
	printf("��������Ҫɾ���ı�Ż�������");
	scanf("%s",gonghao);
	printf("\nɾ���ɹ���");
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
			printf("\n����Ĺ��Ż����������ڣ����������룺");
		}
		return y-x;
}
int add(zggz a[],int y)  //���ְ���������ݺ���
{
	int i;
	int x=0;
	char gonghao[15];
	printf("\t��������Ҫ����Ĺ��ţ�");
	scanf("%s",gonghao);
	fflush(stdin);
	printf("\t������һ���µļ�¼��Ϣ��");
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
		printf("������ְ���Ĺ��ţ�");
		scanf("%s",a[x].workerID);
		printf("������ְ����������");
		scanf("%s",a[x].name);
		printf("������ְ���ĸ�λ���ʣ�");
		scanf("%f",&a[x].gsalary);
		printf("������ְ����н�����ʣ�");
		scanf("%f",&a[x].xsalary);
		printf("������ְ����ְ�������");
		scanf("%f",&a[x].zsalary);
		printf("������ְ���ļ�Ч���ʣ�");
		scanf("%f",&a[x].jsalary);
		printf("��ְ����Ӧ������Ϊ��%f\n",a[x].sumsalary=a[x].gsalary+a[x].xsalary+a[x].zsalary+a[x].jsalary);
		grsds(a,x);
		printf("��ְ���ĸ�������˰Ϊ��%f\n",a[x].xsalary);
		printf("��ְ����ʵ������Ϊ��%f\n",a[x].realsalary=a[x].sumsalary-a[x].personaltax);
		return y+1;
}


int main()
{
	char ch;
	while(TURE)
	{
	system("cls");//��������
	printf("\n\n\t\t--��ӭʹ�ù��ʹ���ϵͳ--\n\n\n");
	printf("\t\t=================================================\n");
	printf("\t\t\t1.��ȡְԱ���ʼ�¼\n");
	printf("\t\t\t2.��ѯְԱ���ʼ�¼\n");
	printf("\t\t\t3.�޸�ְԱ���ʼ�¼\n");
	printf("\t\t\t4.���ְԱ���ʼ�¼\n");
	printf("\t\t\t5.ɾ��ְԱ���ʼ�¼\n");
	printf("\t\t\t6.����ְԱ���ʼ�¼\n");
	printf("\t\t\t7.���ְԱ��¼\n");
	printf("\t\t\t8.�˳�\n");
	printf("\t\t=================================================\n");
	printf("\n\t\t���ѡ���ǣ�");
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
	case'1':read(b,c);break;//��ȡ
	case'2':find(b,c);break;//��ѯ
	case'3':modify(b,c);break;//�޸�
	case'4':add(b,c);break;//���
	case'5':del(b,c);break;//ɾ��
	case'6':write(b,c);break;//����
	case'7':list(b,c);break;//���
	case'8':return 0;//�˳�
	default:printf("\t\t�밴�������������ѡ��1-7��\n");
	getch();
	}
	}
	return 0;
}
