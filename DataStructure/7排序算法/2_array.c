/*����ʵ��*/ 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct student		/*ѧ����Ϣ�ṹ��*/ 
{
	int id;
	char name[20];
	int math_score;
	int chinese_score;
	int english_score;
	int total_score;
	int rank;
}xxx;

typedef struct a
{
	xxx elem[100];
}Student;

void sort(Student * stu,int len);

int main()
{
	int len,i;
	Student *stu=(Student *)malloc(sizeof(Student));
	printf("������ѧ��������");
	scanf("%d",&len);
	/*ѧ����Ϣ¼��*/
	for(i=0;i<len;i++)
	{
		printf("�������%d��ѧ����ѧ�ţ�",i+1);
		scanf("%d",&stu->elem[i].id);
		printf("�������%d��ѧ����������",i+1);
		scanf("%s",stu->elem[i].name);
		printf("�������%d��ѧ������ѧ�ɼ���",i+1);
		scanf("%d",&stu->elem[i].math_score);
		printf("�������%d��ѧ�������ĳɼ���",i+1);
		scanf("%d",&stu->elem[i].chinese_score);
		printf("�������%d��ѧ����Ӣ��ɼ���",i+1);
		scanf("%d",&stu->elem[i].english_score);
		stu->elem[i].total_score = stu->elem[i].math_score+stu->elem[i].chinese_score+stu->elem[i].english_score;	/*�ܳɼ�*/
		printf("\n");
	}

	sort(stu,len);
	printf("�����\n");
	printf("ѧ��\t\t����\t��ѧ\t����\tӢ��\t�ܷ�\t����\t\n");
	for(i=0;i<len;i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",stu->elem[i].id,stu->elem[i].name,stu->elem[i].math_score,stu->elem[i].chinese_score,stu->elem[i].english_score,stu->elem[i].total_score,stu->elem[i].rank);
	}
	return 0;
}

void sort(Student * stu,int len)
{
	int i,j;
	xxx temp,t2,t3,t4;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(stu->elem[j].total_score < stu->elem[j+1].total_score)
			{
				temp = stu->elem[j];
				stu->elem[j] = stu->elem[j+1];
				stu->elem[j+1] = temp;
			}
			else if(stu->elem[j].total_score == stu->elem[j+1].total_score)
			{
				if(stu->elem[j].math_score < stu->elem[j+1].math_score)
				{
					t2 = stu->elem[j];
					stu->elem[j] = stu->elem[j+1];
					stu->elem[j+1] = t2;
				}
			}
			else if(stu->elem[j].math_score == stu->elem[j+1].math_score)
			{
				if(stu->elem[j].chinese_score < stu->elem[j+1].chinese_score)
				{
					t3 = stu->elem[j];
					stu->elem[j] = stu->elem[j+1];
					stu->elem[j+1] = t3;
				}
				
			}
			else if(stu->elem[j].chinese_score == stu->elem[j+1].chinese_score)
			{
				if(stu->elem[j].english_score < stu->elem[j+1].english_score)
				{
					t4 = stu->elem[j];
					stu->elem[j] = stu->elem[j+1];
					stu->elem[j+1] = t4;
				}
				
			}
		}
	}
	for(i=0;i<len;i++)
	{
		stu->elem[i].rank=(i+1);
	}
}
