#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

const int MAX_STUDENT_NUM=5;

struct Student
{
	//long int num;
	char number[20];
	float math;
	float project;
	float sum;	
	
};

void Input(struct Student stu[], int &num);
void Output(struct Student stu[], int num);
void Statis(struct Student stu[], int num);
void Order(struct Student stu[], int num);
void Search(struct Student stu[], int num);
void Delete(struct Student stu[], int &num);
void Menu();
int main()
{
	int currentN=0;
	struct Student stu[MAX_STUDENT_NUM];
	int a;//�����жϲ˵�ѡ��
	Menu();
	//scanf("%d",&a);	
//	switch(a)
	while(scanf("%d",&a))
	{
		
		if(a==1)
		{
			printf("��ѡ����1=¼��ѧ��"); 			
			Input(stu, currentN);//����
			Menu();
		}
		else if(a==2)
		{
			printf("��ѡ����2=��ʾ��Ϣ");
			Output(stu, currentN);//����ɼ���Ϣ
			Menu();
		}
		else if(a==3)
		{
			printf("��ѡ����3=��������");
			Order(stu, currentN);
			Menu();
		}
		else if(a==4)
		{
			printf("��ѡ����4=����ѧ��");
			Search(stu, currentN);
			Menu();
		}
		else if(a==5)
		{	
			printf("��ѡ����5=����ѧ��");		
			Input(stu, currentN);
			Menu();
		}
		else if(a==6)
		{
			printf("��ѡ����6=ɾ��ѧ��");
			Delete(stu, currentN);
			Menu();
		}
		else if(a==7)
		{
		
			printf("��ѡ����7=ͳ������\n");
			printf("�ɼ�����     100~90    89~80    79~70    69~60     <60\n");		
			Statis(stu, currentN);
			Menu();
		}
		else if(a==0)
		{ 
			printf("�˳��ɹ���");
			return 0;
		} 
		else
		{
			printf("����Ƿ������������룡");			
			Menu();
		}
	}
	return 0;
}
//����ɼ� 
void Input(struct Student stu[], int &num)
{
	float score;//ѧ���ɼ�
	int i=0; //����
	int NUM_max;
	int str;//�����ж��Ƿ����������ַ���
	if(num==0)
	{
		while(true)
		{			
				printf("�������%d��ѧ����ѧ��:",i);
				scanf("%s",&stu[i].number); 
				printf("�������%d��ѧ������ѧ�ɼ�:",i);
				scanf("%f",&stu[i].math);
				printf("�������%d��ѧ���ĳ�����Ƴɼ�:",i);
				scanf("%f",&stu[i].project);
				stu[i].sum=stu[i].project+stu[i].math;
				i++;
				if(i==MAX_STUDENT_NUM)
				{
					printf("�����Ѵﵽ���ޣ��޷������룡\n");
					break;
				}
				printf("��������ѧ������ �밴1��");
				scanf("%d",&str);
				if(str==1)
				{
					continue;
				}
				else
				{
					break;
				}			
		}
		num=i;
	}
	else
	{
		if(num==MAX_STUDENT_NUM)
		{
			printf("�����Ѵﵽ�������ޣ��޷��ٲ��룡\n");
		}
		else
		{
			i=num;//��ǰ����Ԫ�ظ���
			while(true)
			{						
				printf("�������%d��ѧ����ѧ��:",i);
				scanf("%s",&stu[i].number); 
				printf("�������%d��ѧ������ѧ�ɼ�:",i);
				scanf("%f",&stu[i].math);
				printf("�������%d��ѧ���ĳ�����Ƴɼ�:",i);
				scanf("%f",&stu[i].project);
				i++;
				if(i==MAX_STUDENT_NUM)
				{
					printf("�����Ѵﵽ���ޣ��޷������룡\n");
					break;
				}
				printf("��������ѧ������ �밴1��");
				scanf("%d",&str);
				if(str==1)
				{
					continue;
				}
				else
				{
					break;
				}	
			}
			num=i;//��ǰ����Ԫ��
		}
	}
}
//����ɼ���Ϣ 
void Output(struct Student stu[], int num)
{
	if(num!=0)
	{
		printf("�ɼ���Ϣ���£�\n");
		for(int i=0;i<num;i++)
		{
			printf("ѧ��/��ѧ�ɼ�/������Ƴɼ�/��%s   %.2f   %.2f   \n",stu[i].number,stu[i].math,stu[i].project);
		}
	}
	else
	{
		printf("���޳ɼ���Ϣ����ѡ��1=¼��ѧ����Ϣ");
	}		
}
//ͳ������ 
void Statis(struct Student stu[], int num)
{
	int	i,a[5]={0},b[5]={0};
	for(i=0;i<num;i++)
	{
		if(stu[i].math>=90 && stu[i].math<=100)
		{
			a[0] +=1;
		}
		else if(stu[i].math>=80 && stu[i].math<90)
		{
			a[1] +=1;
		}
		else if(stu[i].math>=70 && stu[i].math<80)
		{
			a[2] +=1;
		}
		else if(stu[i].math>=60 && stu[i].math<70)
		{
			a[3] +=1;
		}
		else
		{
			a[4] +=1;
		}
	}
	for(i=0;i<num;i++)
	{
		if(stu[i].project>=90 && stu[i].project<=100)
		{
			b[0] +=1;
		}
		else if(stu[i].project>=80 && stu[i].project<90)
		{
			b[1] +=1;
		}
		else if(stu[i].project>=70 && stu[i].project<80)
		{
			b[2] +=1;
		}
		else if(stu[i].project>=60 && stu[i].project<70)
		{
			b[3] +=1;
		}
		else
		{
			b[4] +=1;
		}
	}
	printf("       ");
	for(i=0;i<5;i++)
	{
		printf("     %d     ",a[i]);
		
		
	}
	printf("\n");
	printf("       ");
	for(i=0;i<5;i++)
	{		
		printf("     %d     ",b[i]);
	}
	printf("\n");

}
//���� 
void Order(struct Student stu[], int num)//�ֽܷ������� 
{
	if(num!=0)
	{
		int i,j,k;
		float temp=0;
		char var[20];
		for(i=0;i<num;i++)
		{
			for(j=0;j<num-i-1;j++)
			{
				if(stu[j].sum<stu[j+1].sum)//���ǰһ��Ԫ��С�ں�һ��Ԫ��
				{
					temp = stu[j].sum;
					stu[j].sum =stu[j+1].sum;
					stu[j+1].sum = temp;
					
					temp = stu[j].math;
					stu[j].math =stu[j+1].math;
					stu[j+1].math = temp;
					temp = stu[j].project;
					stu[j].project =stu[j+1].project;
					stu[j+1].project = temp;
					
					strcpy(var,stu[j].number);
                    strcpy(stu[j].number,stu[j+1].number);
                    strcpy(stu[j+1].number,var);
					
				}
			}
		}
		printf("�ɼ��ܷ���Ϣ���£�\n");
		for(k=0;k<num;k++)
		{
			printf("     %s :%.2f     ",stu[k].number,stu[k].sum);
			
		}
		printf("\n");		
	}
	else
	{
		printf("���޳ɼ���Ϣ����ѡ��1=¼��ѧ����Ϣ");
	}
}
//���� 
void Search(struct Student stu[], int num)
{
	char name[20];
	int str;//�����ж��Ƿ����������ַ���
	while(true)
	{
		printf("��������Ҫ���ҵ�ѧ�ţ�");
		scanf("%s",&name);		
		int flag=0;
		
			for(int i=0;i<num;i++)
			{
				if(strcmp(stu[i].number,name)==0)
				{
					flag++;
					printf("���ҵ���%d��ѧ��������ɼ��� %f  %f   %f",i,stu[i].math,stu[i].project,stu[i].sum);
				}
			}
			if(flag==0)
			{
				printf("û�и�ѧ����Ϣ��");
			}
			printf("���������밴1��");
			scanf("%d",&str);
			//cin>>str;
			if(str==1)
			{
				continue;
			}
			else
			{
				break;
			}
		
		
	}
}	

//ɾ�� 
void Delete(struct Student stu[], int &num)
{
	float score;
	char name[20];
	int str;//�����ж��Ƿ����������ַ���
	int i;
	while(true)
	{
		printf("��������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%s",&name);
		int flag=0;//����ͳ��ɾ����ʣ�������Ԫ�ظ���
		//float a[100];
		
		
			for(i=0;i<num;i++)
			{
				if(strcmp(stu[i].number,name)==0)
				{
					flag=i;
					break;
				}				
			}
			
			if (flag==num)
			{			
				printf("û�и�ѧ����");	
			}
			else
			{
				printf("�Ƿ�ɾ������1/0��");
		 	scanf("%d",&str); 
			if(str==1)
			{
				for(int j=flag;j<num;j++)
				{
					strcpy(stu[j].number,stu[j+1].number);
					stu[j].math=stu[j+1].math;
					stu[j].project=stu[j+1].project;
					
				}
				num=num-1;//�������� 
				printf("ɾ�����\n");
				printf("����ɾ������ѧ���밴y��Y��");
				scanf("%d",&str);
				if(str==1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}		
			}
						
								
	}
}
//���˵� 
void Menu()
{
	printf("          =================================================\n");
	printf("          =              ��ӭʹ�óɼ�����ϵͳ             =\n");
	printf("          =           1=¼��ѧ��     2=��ʾ��Ϣ           =\n");
	printf("          =           3=��������     4=����ѧ��           =\n");
	printf("          =           5=����ѧ��     6=ɾ��ѧ��           =\n");
	printf("          =           7=ͳ������     0=�˳�               =\n");
	printf("          =================================================\n");
	printf("��ѡ��:");
 
}
