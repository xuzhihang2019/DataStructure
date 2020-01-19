#include<stdio.h>
#include<malloc.h>
typedef struct list 
{
	int Date;					/*������*/
	struct list * next;			/*ָ����*/ 
}List, *PList;

PList create_list();				//��������		
void traverse_list(PList pHead);	//���� 
void insert_list(PList pHead);		//����  

int main()
{
	PList pHead = NULL;
	pHead = create_list();			/*ͷָ�뷵�ظ�pHead*/ 
	printf("����������Ϊ��\n"); 
	traverse_list(pHead);
	insert_list(pHead);
	printf("����������Ϊ��\n");
	traverse_list(pHead);
	return 0;
}

PList create_list()
{
	int len,i,val;
	PList p = NULL;
	PList L = (PList)malloc(sizeof(List));			/*ͷ�ڵ�*/
	p = L;											/*ͷָ��pָ��ͷ�ڵ�L*/
	printf("��������Ҫ���ɵ�����Ľڵ������len = ");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("�������%d���ڵ��ֵ:",i+1);
		scanf("%d",&val);
		PList pNew = (PList)malloc(sizeof(List));	/*forѭ��ÿ�ζ������һ���½ڵ�*/
		pNew->Date = val;							/*���ݴ���ڵ��������*/
		p->next = pNew;								/*�ڵ����*/ 
		pNew->next = NULL;
		p = pNew;									/*ָ��p����ʵ��β�巨*/ 
	}
	return L;
}

void traverse_list(PList pHead)
{
	PList p = pHead->next;							/*ͷ�ڵ㲻�����ݣ����Դ�ͷ�ڵ��һ�ڵ�(�׽ڵ�)��ʼ����*/
	while(p!=NULL)
	{
		printf("%d  ",p->Date);
		p = p->next;
	}
	printf("\n");
}

void insert_list(PList pHead)
{
	int x;
	int i = 0;
	int j = 0;
	PList p = pHead;
	printf("������Ҫ���������");
	scanf("%d",&x);
	while(NULL!=p && x<(p->Date))
	{
		p = p->next;
		++i;
	}
	/*i����Ҫ�����λ�ã��޷�ǰ��*/
	p = pHead;									/*��p�ص�ͷ�ڵ�*/ 
	while(NULL!=p && j<i-1)						/*j=i+1��ֹѭ���������ݲ��뵽j�󣨼�iǰ��*/
	{
		p = p->next;
		++j;
	}
	PList pNew = (PList)malloc(sizeof(List));	/*����������Ҫ�·����ڴ�ռ�*/ 
	pNew->Date = x;
	pNew->next = p->next;						/*�½��ָ��p�ĺ�һ���ڵ�*/
	p->next = pNew;								/*pָ���½ڵ�*/ 
}

