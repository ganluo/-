#include <stdio.h>
struct worker{

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
/*typedef struct employee
{
char num[10]; //����ְ�����
char name[15]; //����ְ������
float jbgz; //����ְ����������
float jj; //����ְ������
float kk; //����ְ���ۿ�
float yfgz; //����ְ��Ӧ������
float sk; //����ְ��˰��
float sfgz; //����ְ��ʵ������
}ZGGZ;*/
int write(zggz a[],int k)//����ְԱ��Ϣ
{
	int j,x;
	char gonghao[10];
	j=x=0;
	while(1)
	{
		printf('������ְ���Ĺ��ţ�����0�������˵���');
		scanf('%s',gonghao);
		strcpy(a[k].workerID,gonghao);
		for(j=0;j<k;j++)
		{
			if(strcmp(a[j].workerID,gonghao)==0)
			{
				printf('�Ѿ��й���Ϊ%s��Ա����Ϣ!����������Ա���š�',str);
				printf('������ְ���Ĺ��ţ�');
				scanf('%s',str);
				strcpy(a[k].workerID,str);
			}
		}
		if(strcmp(a[k].workerID,'0')==0)
			break;
		printf('������ְ����������');
		scanf('%s',a[k].name);
		printf('������ְ���ĸ�λ���ʣ�');
		scanf('%f',&a[k].gsalary);
		printf('������ְ����н�����ʣ�');
		scanf('%f',&a[k].xsalary);
		printf('������ְ����ְ�������');
		scanf('%f',&a[k].zsalary);
		printf('������ְ���ļ�Ч���ʣ�');
		scanf('%f',&a[k].jsalary);
		a[k].sumsalary=a[k].gsalary+a[k].xsalary+a[k].zsalary+a[k].jsalary;
		k++;
	}
	return k;
}
int find(zggz a[],int y)   //��ѯְ���������ݺ���
{
	int i;
	int x=0;
	char str[15];
	printf('��������Ҫ���ҵĹ��Ż�������');
	scanf('%s',str);
	for(i=0;i<y;i++)
		if(!strcmp(str,a[i].workerID)||!strcmp(str,a[i].name))
		{
			printf('Ա������Ϊ%s',a[i].workerID);
			printf('Ա������Ϊ%s',a[i].name);
			printf('��λ���ʣ�%f',a[i].gsalary);
			printf('н�����ʣ�%f',a[i].xsalary);
			printf('ְ�������%f',a[i].zsalary);
			printf('��Ч���ʣ�%f',a[i].jsalary);
			printf('Ӧ�����ʣ�%f',a[i].sumsalary);
			printf('��������˰��%f',a[i].personaltax);
			printf('ʵ�����ʣ�%f',a[i].realsalary);
			x++;
		}
		if(x==0)
		{
			printf('δ�ҵ��ü�¼');
			return -1;
		}
}
void list(zggz a[],int n)//���ְ���������ݺ���
{
	int i=0;
	if(n==0)
	{
		printf('Files are empty');
		return;
	}
	do
	{
		printf('Ա������Ϊ%s',a[i].workerID);
		printf('Ա������Ϊ%s',a[i].name);
		printf('��λ���ʣ�%f',a[i].gsalary);
		printf('н�����ʣ�%f',a[i].xsalary);
		printf('ְ�������%f',a[i].zsalary);
		printf('��Ч���ʣ�%f',a[i].jsalary);
		printf('Ӧ�����ʣ�%f',a[i].sumsalary);
		printf('��������˰��%f',a[i].personaltax);
		printf('ʵ�����ʣ�%f',a[i].realsalary);
		i++;
	}while(i<n);
}
void modify(zggz a[],int y)  //�޸�ְ���������ݺ���
{
	int i;
	int x=0;
	char str[15];
	printf('��������Ҫ�޸ĵĹ��ţ�');
	scanf('%s',str);
	for(i=0;i<y;i++)
		if(!strcmp(str,a[i].workerID)||!strcmp(str,a[i].name))
		{
			printf('�������޸ĺ�ְ����������');
			scanf('%s',a[i].name);
			printf('�������޸ĺ�ְ���ĸ�λ���ʣ�');
			scanf('%f',&a[i].gsalary);
			printf('�������޸ĺ�ְ����н�����ʣ�');
			scanf('%f',&a[i].xsalary);
			printf('�������޸ĺ�ְ����ְ�������');
			scanf('%f',&a[i].zsalary);
			printf('�������޸ĺ�ְ���ļ�Ч���ʣ�');
			scanf('%f',&a[i].jsalary);
			printf('�������޸ĺ�ְ����Ӧ�����ʣ�');
			scanf('%f',&a[i].sumsalary);
			printf('�������޸ĺ�ְ���ĸ�������˰��');
			scanf('%f',&a[i].personaltax);
			printf('�������޸ĺ�ְ����ʵ�����ʣ�');
			scanf('%f',&a[i].realsalary);
			printf('\n�޸ĳɹ���');
			a[i].sumsalary=a[i].gsalary+a[i].xsalary+a[i].zsalary+a[i].jsalary;
			//a[i].sk=a[i].yfgz*(0.05);
			//a[i].sfgz=a[i].yfgz*(0.95);
			x++;
		}
		if(x==0)
		{
			printf('δ�ҵ�Ҫ�޸ĵĹ���');
		}
}
int del(zggz a[],int y)  //ɾ��ְ���������ݺ���
{
	int i=0;
	int x=0;
	char str[15];
	printf('��������Ҫɾ���ı�Ż�������');
	scanf('%s',str);
	printf('\nɾ���ɹ���');
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
			printf('����Ĺ��Ż����������ڣ����������룺');
		}
		return y-x;
}
int add(zggz a[],int y)  //���ְ���������ݺ���
{
	int i;
	int x=0;
	char str[15];
	printf('��������Ҫ����Ĺ��ţ�');
	scanf('%s',str);
	printf('������һ���µļ�¼��Ϣ��');
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
		printf('������ְ���Ĺ��ţ�');
		scanf('%s',a[x].workerID);
		printf('������ְ����������');
		scanf('%s',a[x].name);
		printf('������ְ���ĸ�λ���ʣ�');
		scanf('%f',&a[x].gsalary);
		printf('������ְ����н�����ʣ�');
		scanf('%f',&a[x].xsalary);
		printf('������ְ����ְ�������');
		scanf('%f',&a[x].zsalary);
		printf('������ְ����Ӧ�����ʣ�');
		scanf('%f',&a[x].sumsalary);
		printf('������ְ���ĸ�������˰��');
		scanf('%f',&a[x].xsalary);
		printf('������ְ����ʵ�����ʣ�');
		scanf('%f',&a[x].realsalary);
		a[x].sumsalary=a[x].gsalary+a[x].xsalary+a[x].zsalary+a[i].jsalary;
		return y+1;
}
void read(zggz a[],int n)  //��ȡְ���������ݺ���
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
void grsds()				//�����������˰
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
					printf('�Ƿ����ɾ�����ǰ�y�������밴����ֵ');
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
					printf('�Ƿ�������ң��ǰ�y�������밴����ֵ');
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
					printf('�Ƿ�����޸ģ��ǰ�y�������밴����ֵ');
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
					printf('�Ƿ�������룬�ǰ�y�������밴����ֵ');
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
