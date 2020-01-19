/*1����д��˳������ѭ������QU[n]�в���һ�����x�ĺ���EnQueue��
�ʹӸö�����ɾ��һ�����ĺ���DeQueue��*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}SeQueue;

void initQueue(SeQueue *sq);			/*��ʼ������*/
bool EnQueue(SeQueue *sq,int e);		/*���*/
bool DeQueue(SeQueue *sq,int *e);		/*����*/
void TraverseQueue(SeQueue *sq);				/*������������*/

int main()
{
	int val;
	int delData;
	int len,i,agoData;
	SeQueue *sq=(SeQueue *)malloc(sizeof(SeQueue));
	initQueue(sq);
	printf("������ԭѭ�����еĽڵ������\n");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("ԭѭ�����е�%d���ڵ㣺\n",i+1);
		scanf("%d",&agoData);
		EnQueue(sq, agoData);
	}
	printf("\n");
	
	printf("������Ҫ����Ľڵ�����ݣ�\n");
	scanf("%d",&val);
	EnQueue(sq, val);
	DeQueue(sq, &delData);
	printf("\nɾ���Ľڵ�����Ϊ��%d\n",delData);
	printf("\nѭ�����б�Ϊ�ˣ�\n");
	TraverseQueue(sq);
	printf("\n"); 
	return 0;
}

void initQueue(SeQueue *sq)				/*��ʼ������*/
{
	sq->front = 0;
	sq->rear = 0;
}

bool EnQueue(SeQueue *sq,int e)			/*���*/
{
	if(sq->front==((sq->rear+1)%MAXSIZE))
	{
		printf("��������\n");
		return false;
	}
	else
	{
		sq->data[sq->rear] = e;
		sq->rear = (sq->rear+1)%MAXSIZE;	/*rearָ�����*/
		return true;
	}
}

bool DeQueue(SeQueue *sq,int *e)		/*����*/
{
	if(sq->front==sq->rear)
	{
		printf("����Ϊ��\n");
		return false;
	}
	*e = sq->data[sq->front];			/*�ѳ����е�Ԫ�ش���ָ��e��ָ��ı�����*/
	sq->front=(sq->front+1)%MAXSIZE;	/*frontָ�����*/ 
	return true;
}

void TraverseQueue(SeQueue *sq)
{
	if(sq->front==sq->rear)
	{
		printf("����Ϊ��\n");
	}
	else
	{
		int i;
		i = sq->front;
		while(i != sq->rear)
		{
			printf("%d ",sq->data[i]);
			i = (i+1)%MAXSIZE;				/*i���ƣ���i++*/
		}
	}
	
}


