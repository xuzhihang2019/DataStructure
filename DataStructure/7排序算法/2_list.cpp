///*����ʵ��*/
//#include<stdio.h>
//#include<stdlib.h>
///*����ʵ��*/ 
//#include<malloc.h>
//#include<string.h>
//typedef struct student		/*ѧ����Ϣ�ṹ��*/ 
//{
//	int id;
//	char name[20];
//	float math_score;
//	float chinese_score;
//	float english_score;
//	float total_score;
//	int rank;
//	struct student * next;	/*ָ����*/
//}Student, *pStudent;
//
//pStudent Create_list();
//void sort(pStudent list);
//
//int main()
//{
//	pStudent head = (pStudent)malloc(sizeof(Student));
//	head = Create_list();
//	sort(head);
//	return 0;
//}
//
///*����ѧ����Ϣ����*/
//pStudent Create_list()
//{
//	int i,len;
//	int Tid;
//	char Tname[20];
//	float Tmath_score,Tchinese_score,Tenglish_score;
//
//	pStudent head = (pStudent)malloc(sizeof(Student));
//	if(NULL ==  head)
//	{
//		printf("����ʧ��\n");
//		exit(0);
//	}
//	pStudent pTail;
//	pTail = head;
//	pTail->next = NULL;
//	
//	printf("������ѧ��������");
//	scanf("%d",&len);
//	
//	for(i=0;i<len;i++)
//	{
//		printf("�������%d��ѧ����ѧ�ţ�",i+1);
//		scanf("%d",&Tid);
//		printf("�������%d��ѧ����������",i+1);
//		scanf("%s",Tname);
//		printf("�������%d��ѧ������ѧ�ɼ���",i+1);
//		scanf("%d",&Tmath_score);
//		printf("�������%d��ѧ�������ĳɼ���",i+1);
//		scanf("%d",&Tchinese_score);
//		printf("�������%d��ѧ����Ӣ��ɼ���",i+1);
//		scanf("%d",&Tenglish_score);
//		
//		pStudent pNew = (pStudent)malloc(sizeof(Student));	/*forѭ��ÿ�ζ������һ���ڴ棬�����ʱ�ڵ�pNew*/
//		if(NULL == pNew)
//		{
//			printf("����ʧ��\n");
//			exit(0);
//		}
//		pNew->id = Tid;
//		strcpy(pNew->name, Tname);
//		pNew->math_score = Tmath_score;
//		pNew->chinese_score = Tchinese_score;
//		pNew->english_score = Tenglish_score;
//		pNew->total_score = Tmath_score+Tchinese_score+Tenglish_score;	/*�ܳɼ�*/
//		
//		pTail->next = pNew;
//		pNew->next = NULL;
//		pTail = pNew;
//	}
//	return head; 
//}
//
///*����*/ 
//void sort(pStudent list)
//{
//
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define Path "D:\\dos\\studata.txt"
typedef struct Student{
	char Num[MAX] ; // ���
	int Sumofscore ; // �ɼ��ܺ�
	int Chinese ;
	int Math ;
	int English ;
	int science ;
 
}Stu;
 
int main()
{
 
	int n ,i = 0, j;
	Stu *p[MAX] ; // p ��һ�� ָ������ �����Ǹ�����,ֻ�������ÿһ��Ԫ��
				  // �����洢ָ�� ��
	Stu t ;
	Stu a[MAX] ;  // ����һ���ṹ�����飬ÿһ��Ԫ�ض���һ���ṹ�����
	FILE *fp  ;
	if((fp =fopen(Path,"r"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0 );
	}
 
	while(!feof(fp)) // ֻҪû��ȡ���ļ����,��һֱѭ��
	{
		//
		
		fscanf(fp,"%s %d %d %d %d %d",a[i].Num ,&a[i].Sumofscore ,&a[i].Chinese ,&a[i].Math ,&a[i].English ,&a[i].science);
		// ���ļ��зֱ� ��ȡ �ļ��е� ��һ������ a[i].Num ,�ڶ�����ֵ��a[i].Sumscore ��������
		p[i] = &a[i] ;
		/* p[0] �洢 a[0]�ĵ�ַ ,Ҳ�������ǳ�˵�� p[0] ָ�� a[0]��p[1] = a[1] p[1] �洢 a[1]�ĵ�ַ...
		
		*/
		i++;
	}
	n = i ;
	rewind(fp);// ���ļ�ָ�붨λ���ļ���ͷ ����Ϊһ��ʼ��ȡ�� �ļ�������� ���ļ�ָ���ָ���ļ�ĩβ
/*
	j =  0;
	printf("ѧ��\t�ܷ�\t����\t��ѧ\tӢ��\t����\n"); //  �򵥵�ui����
	while(j<i)
	{
		// ��ʼ���
		printf("%s\t%d\t%d\t%d\t%d\t%d\n",a[j].Num ,a[j].Sumofscore ,a[j].Chinese ,a[j].Math ,a[j].English ,a[j].science);
		j++;
	}*/
 
	//  �ȶ��ֽܷ�������;
	for(i = 0 ;i<n-1 ;i++)
	{
		for(j = 0 ;j<n-1-i ;j++)
		{
			if(p[j]->Sumofscore < p[j+1]->Sumofscore )
			{
				t = a[j] ;
				a[j] = a[j+1 ] ;
				a[j+1] =t ;
			}
		}
	}
 
	/*
    ����ǰ
    ѧ��    �ܷ�    ����    ��ѧ    Ӣ��    ����
	001     505     113     115     112     165
	002     520     105     115     120     180
	003     505     113     117     100     175
	004     515     114     117     120     164
	005     511     120     105     111     175
    ����� (�ִܷӴ�С)
    002     520     105     115     120     180
	004     515     114     117     120     164
	005     511     120     105     111     175
	001     505     113     115     112     165
	003     505     113     117     100     175
	*/
	
	
	for (i = 0 ; i < n-1 ; i++ )
	{
		// �Խṹ���������n-1�ε�����
		if((p[i]->Sumofscore == p[i+1]->Sumofscore ))
		{
			// ��� �ɼ��ܷ����ִ���������
			if((p[i]->Chinese != p[i+1]->Chinese ) &&(p[i]->Chinese < p[i+1]->Chinese) )
			{
				// ����ܷ���Ȳ��� ���Ĳ���� ����ǰ��һλ�����ĳɼ�ҪС�ں���һλ�����ĳɼ�
				// ���������˵�λ�û���
				// t ��һ���м����;
				// ������ð������
				t = a[i] ;
				a[i] = a[i+1];
				a[i+1] = t ;
 
			}
			else if (p[i]->Chinese == p[i+1]->Chinese)
			{
				// ������ĳɼ�Ҳ��� ִ���������
 
				if((p[i]->Math != p[i+1]->Math )&& (p[i]->Math < p[i+1]->Math)  )
				{
					// �����ѧ�ɼ�  ǰһλ����ѧ�ɼ������ں�һλͬѧ����ѧ�ɼ�,����ǰһλ��
					// ��ѧ�ɼ��Ⱥ�һλ����ѧ�ɼ�С ���򻥻�λ��
					t = a[i] ;
					a[i] = a[i+1];
					a[i+1] = t ;
 
				}
				else if (p[i]->Math == p[i]->Math)
				{
					// �����ѧ�ɼ�Ҳһ��ִ������
					if( ( p[i]->English != p[i+1]->Math)&& ( p[i]->English < p[i+1]->Math ) )
					{
						// ����������һ��
						t = a[i] ;
						a[i] = a[i+1];
						a[i+1] = t ;
					}
					else if ( p[i]->English == p[i+1]->English)
					{
 
						if( p[i]->science < p[i+1]->science )
						{
							t = a[i] ;
							a[i] = a[i+1];
							a[i+1] = t ;
						}
 
					}
 
				}
 
			}
 
		}
 
 
	}
 
	j =  0;
	while(j<n)
	{
		printf("%s\n",a[j].Num);
		j++;
	}
 
	return 0 ;
}