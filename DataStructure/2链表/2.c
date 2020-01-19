/*
	2���㷨��̣�
	��һ����ͷ���ĵ����� A �ֽ��������ͷ���ĵ����� B �� C��
	���� B ��Ľ��Ϊ A ����ֵС����Ľ�㣬
	�� C ��Ľ��Ϊ A ����ֵ���ڵ�����Ľ��
	������ A ��Ԫ������Ϊ���ͣ�Ҫ�� B��C ������ A ��Ľ�㣩��
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;					/*������*/
	struct node * next;			/*ָ����*/
}Node, *pNode;

pNode create_list();								/*������������������*/
void traverse_list(pNode pHead);					/*������������������*/
void split_list(pNode LA, pNode LB, pNode LC);		/*�����������ֽ�����*/

int main()
{
	pNode LA = (pNode)malloc(sizeof(Node));
	pNode LB = (pNode)malloc(sizeof(Node));
	pNode LC = (pNode)malloc(sizeof(Node));
	LA->next = NULL;
	LB->next = NULL;
	LC->next = NULL;
	LA = create_list();
	printf("������AΪ��\n");
	traverse_list(LA);
	printf("\n\n");
	
	split_list(LA,LB,LC);
	printf("�ֽ�󣬵�����BΪ��\n");
	traverse_list(LB);
	printf("\n");
	printf("�ֽ�󣬵�����CΪ��\n");
	traverse_list(LC);
	printf("\n");
	return 0;
}

pNode create_list()
{
	int len,i,val;
	pNode pHead = (pNode)malloc(sizeof(Node));		/*ͷ�ڵ�*/
	pNode p = (pNode)malloc(sizeof(Node));
	p = pHead;										/*ͷָ��ָ��ͷ�ڵ�*/
	printf("��������Ҫ���ɵ�����Ľڵ������len = ");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("�������%d���ڵ��ֵ:",i+1);
		scanf("%d",&val);
		pNode pNew = (pNode)malloc(sizeof(Node));	/*forѭ��ÿ�ζ������һ���ڴ棬�����ʱ�ڵ�pNew */ 
		pNew->data = val;							/*���ݴ����½ڵ�*/
		p->next = pNew;								/*�½ڵ����*/
		p = p->next;								/*pָ��pNew����ʵ��pָ�������½ڵ�*/ 
		pNew->next = NULL; 
	}
	return pHead;									/*����ͷ�ڵ�*/
}

void traverse_list(pNode pHead)
{
	pNode p = NULL;
	p = pHead->next;								/*ͷ�ڵ㲻�����ݣ����Դ�ͷ�ڵ��һ�ڵ�(�׽ڵ�)��ʼ����*/
	while(p)
	{
		printf("%d  ",p->data);
		p = p->next;								/*p����*/
	}
}

void split_list(pNode LA, pNode LB, pNode LC)
{
	pNode pb = LB;
	pNode pc = LC;
	pNode pa = LA->next;							/*ָ����׽ڵ㿪ʼ����*/
	while(pa!=NULL)
	{												/*����A����pa->data<0ʱ���ͽ�paָ��Ľ����뵽LB�ĺ���*/
		if(pa->data<0)
		{
			pb->next = pa;
			pb = pa;								/*ָ��pb����*/
			pa = pa->next;
			pb->next = NULL;
		}											/*��pa->data>=0ʱ���ͽ�paָ��Ľ����뵽LC�ĺ���*/
		else if(pa->data>0 || pa->data==0)
		{
			pc->next = pa;
			pc = pa;								/*ָ��pc����*/
			pa = pa->next;
			pc->next = NULL;
		}
	}	
}

