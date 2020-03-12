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
	int a;//用来判断菜单选择
	Menu();
	//scanf("%d",&a);	
//	switch(a)
	while(scanf("%d",&a))
	{
		
		if(a==1)
		{
			printf("您选择了1=录入学生"); 			
			Input(stu, currentN);//输入
			Menu();
		}
		else if(a==2)
		{
			printf("您选择了2=显示信息");
			Output(stu, currentN);//输出成绩信息
			Menu();
		}
		else if(a==3)
		{
			printf("您选择了3=排序总评");
			Order(stu, currentN);
			Menu();
		}
		else if(a==4)
		{
			printf("您选择了4=查找学生");
			Search(stu, currentN);
			Menu();
		}
		else if(a==5)
		{	
			printf("您选择了5=插入学生");		
			Input(stu, currentN);
			Menu();
		}
		else if(a==6)
		{
			printf("您选择了6=删除学生");
			Delete(stu, currentN);
			Menu();
		}
		else if(a==7)
		{
		
			printf("您选择了7=统计人数\n");
			printf("成绩区间     100~90    89~80    79~70    69~60     <60\n");		
			Statis(stu, currentN);
			Menu();
		}
		else if(a==0)
		{ 
			printf("退出成功！");
			return 0;
		} 
		else
		{
			printf("输入非法，请重新输入！");			
			Menu();
		}
	}
	return 0;
}
//输入成绩 
void Input(struct Student stu[], int &num)
{
	float score;//学生成绩
	int i=0; //人数
	int NUM_max;
	int str;//用来判断是否继续输入的字符串
	if(num==0)
	{
		while(true)
		{			
				printf("请输入第%d名学生的学号:",i);
				scanf("%s",&stu[i].number); 
				printf("请输入第%d名学生的数学成绩:",i);
				scanf("%f",&stu[i].math);
				printf("请输入第%d名学生的程序设计成绩:",i);
				scanf("%f",&stu[i].project);
				stu[i].sum=stu[i].project+stu[i].math;
				i++;
				if(i==MAX_STUDENT_NUM)
				{
					printf("人数已达到上限，无法再输入！\n");
					break;
				}
				printf("继续输入学生数据 请按1：");
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
			printf("人数已达到人数上限，无法再插入！\n");
		}
		else
		{
			i=num;//当前数组元素个数
			while(true)
			{						
				printf("请输入第%d名学生的学号:",i);
				scanf("%s",&stu[i].number); 
				printf("请输入第%d名学生的数学成绩:",i);
				scanf("%f",&stu[i].math);
				printf("请输入第%d名学生的程序设计成绩:",i);
				scanf("%f",&stu[i].project);
				i++;
				if(i==MAX_STUDENT_NUM)
				{
					printf("人数已达到上限，无法再输入！\n");
					break;
				}
				printf("继续输入学生数据 请按1：");
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
			num=i;//当前数组元素
		}
	}
}
//输出成绩信息 
void Output(struct Student stu[], int num)
{
	if(num!=0)
	{
		printf("成绩信息如下：\n");
		for(int i=0;i<num;i++)
		{
			printf("学号/数学成绩/程序设计成绩/：%s   %.2f   %.2f   \n",stu[i].number,stu[i].math,stu[i].project);
		}
	}
	else
	{
		printf("暂无成绩信息，请选择1=录入学生信息");
	}		
}
//统计人数 
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
//排序 
void Order(struct Student stu[], int num)//总分降序排列 
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
				if(stu[j].sum<stu[j+1].sum)//如果前一个元素小于后一个元素
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
		printf("成绩总分信息如下：\n");
		for(k=0;k<num;k++)
		{
			printf("     %s :%.2f     ",stu[k].number,stu[k].sum);
			
		}
		printf("\n");		
	}
	else
	{
		printf("暂无成绩信息，请选择1=录入学生信息");
	}
}
//查找 
void Search(struct Student stu[], int num)
{
	char name[20];
	int str;//用来判断是否继续输入的字符串
	while(true)
	{
		printf("请输入您要查找的学号：");
		scanf("%s",&name);		
		int flag=0;
		
			for(int i=0;i<num;i++)
			{
				if(strcmp(stu[i].number,name)==0)
				{
					flag++;
					printf("查找到第%d个学生，相符成绩： %f  %f   %f",i,stu[i].math,stu[i].project,stu[i].sum);
				}
			}
			if(flag==0)
			{
				printf("没有该学生信息！");
			}
			printf("继续查找请按1：");
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

//删除 
void Delete(struct Student stu[], int &num)
{
	float score;
	char name[20];
	int str;//用来判断是否继续输入的字符串
	int i;
	while(true)
	{
		printf("请输入您要删除的学生学号：");
		scanf("%s",&name);
		int flag=0;//用来统计删除后剩余的数组元素个数
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
				printf("没有该学生！");	
			}
			else
			{
				printf("是否删除？（1/0）");
		 	scanf("%d",&str); 
			if(str==1)
			{
				for(int j=flag;j<num;j++)
				{
					strcpy(stu[j].number,stu[j+1].number);
					stu[j].math=stu[j+1].math;
					stu[j].project=stu[j+1].project;
					
				}
				num=num-1;//人数减少 
				printf("删除完成\n");
				printf("继续删除其他学生请按y或Y：");
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
//主菜单 
void Menu()
{
	printf("          =================================================\n");
	printf("          =              欢迎使用成绩管理系统             =\n");
	printf("          =           1=录入学生     2=显示信息           =\n");
	printf("          =           3=排序总评     4=查找学生           =\n");
	printf("          =           5=插入学生     6=删除学生           =\n");
	printf("          =           7=统计人数     0=退出               =\n");
	printf("          =================================================\n");
	printf("请选择:");
 
}
