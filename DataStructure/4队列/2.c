#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<malloc.h>
typedef int DataType; 		
#define MAXNUM 20 			/*���������Ԫ�ظ���*/
#define ERROR 1

typedef struct LQNode
{
	DataType info;
	struct LQNode *next;
}LQNode; 					/*���е�Ԫ������*/

typedef struct
{ 
	LQNode *rear,*front; 	/*��β����ͷָ��*/
}LinkQueue;					/*��������*/

LinkQueue *LQueueCreateEmpty();/*����ն���*/
bool LQueueIsEmpty(LinkQueue *LQ);/*�жӿպ���*/
void LQueueEnQueue(LinkQueue *LQ,DataType x);/*���*/
void LQueueDeQueue(LinkQueue *LQ,DataType *x);/*����:����ͷԪ�س��ӣ�����x���ض�ͷԪ����Ϣ*/
DataType LQueueFront(LinkQueue *LQ);
void MyEnQueue(LinkQueue *ql,LinkQueue *q2,DataType d,int priority);
DataType MyDeQueue(LinkQueue *ql,LinkQueue *q2);

int main()
{
	LinkQueue *q1;			/*���ȼ��͵Ĳ��˶���*/
	LinkQueue *q2;			/*���ȼ��ߵĲ��˶���*/
 	int menu;				/*�洢�û�ѡ��Ĳ˵����*/
 	int priority;			/*���˿��������ȼ���*/
 	DataType id;			/*���ղ��˵���ҽԺ���Ⱥ���ȡ������*/
	DataType e;				/*���˿��������ȼ���*/
	int n=0;
	q1=LQueueCreateEmpty();
	q2=LQueueCreateEmpty();
 	id=1;
	printf("****************��ӭ�����Ŷӿ���ģ��ϵͳ*******\n");
	printf("*********1���µĲ�����������к��� ********\n");
	printf("*********2��ҽ���������ȼ���Ϊ��������*****\n");
	printf("*********3���˳�ϵͳ **********************\n");
	printf("**********************************************\n");
	while(1)
	{
		printf("\nһһһһһһһһһһһһһһһһһһһһһһһһһһһһһ\n");
		printf("******�밴�˵����ѡ����Ӧ�Ĳ���(ϵͳֻ������ֵ������):******\n");
		scanf("%d",&menu);
		while(menu>3||menu<1)
		{ 					/*��������ʽ����Ϊ��*/
			printf("\n��������밴�˵��������:");
			scanf("%d",&menu);
		}
		switch(menu)
		{
			case 1: 		/*������µĲ��ˣ���������*/
				printf("�����벡�˵����ȼ���(��ģ��ϵͳֻ�����������ȼ���1��2(2����))\n");
	 			scanf("%d",&priority);
	 			if(1==priority || 2==priority) 	/*��������������ȷ*/
	 			{
	 				printf("***�ò��˵�IDΪ��%d***\n",id);
			 		MyEnQueue(q1,q2,id,priority);		/*�������ȼ�ѡ���Ӧ�������*/
	 				id++;
	 			}
				else 		/*�����������Ĳ���ȷ, ֱ������1��2Ϊֹ*/
	 				printf("\n�����벡�˵����ȼ���(��ģ��ϵͳֻ�����������ȼ���1��2)\n");
	 			break;
 			case 2: 		/*����в��˳�Ժ*/
 				e = MyDeQueue(q1,q2);	
 				if(-1!=e) 	/*������в�Ϊ��*/
 					printf("***��ǰ�����εĲ��˵�IDΪ��%d***\n",e);
 				else 		/*�������Ϊ��*/
 					printf("***�޲��ˣ�����Ϊ��***\n");
 				break;
 			case 3: exit(0);
 		}
	}
	return 0;
}


LinkQueue *LQueueCreateEmpty() /*��ʼ���ն�*/
{
	LinkQueue *q=(LinkQueue *)malloc(sizeof(LinkQueue));
	LQNode *p = (LQNode *)malloc(sizeof(LQNode));
	p->next = NULL;
	q->front = p;
	q->rear = q->front;
	return q;
}

bool LQueueIsEmpty(LinkQueue *LQ) /*�жӿպ���*/
{
	if(LQ->front==LQ->rear)
	{
		return true;
	}
	else
		return false;
}

void LQueueEnQueue(LinkQueue *LQ,DataType x) /*���*/
{
	LQNode *p = (LQNode *)malloc(sizeof(LQNode));
	if(p == NULL)
	{
		printf("�ڴ����ʧ��\n");
	}
	else
	{
		p->info = x;
		p->next = NULL;
		LQ->rear->next = p;
		LQ->rear = p;
	}
}

void LQueueDeQueue(LinkQueue *LQ,DataType *x)/*����:����ͷԪ�س��ӣ�����x���ض�ͷԪ����Ϣ*/
{
	LQNode * p = (LQNode *)malloc(sizeof(LQNode));
	if(LQ->front->next == LQ->rear)
	{
		LQ->front = LQ->rear;
		*x = LQ->rear->info;
	}
	else
	{
		p = LQ->front->next;
		LQ->front->next = p->next;
		*x = p->info;
		free(p); 
	}
}

DataType LQueueFront(LinkQueue *LQ) /*����ͷԪ��*/
{
	if(LQ->front==LQ->rear)
	{
		printf("����Ϊ��\n");
	}
	return LQ->front->info;
}

void MyEnQueue(LinkQueue *q1,LinkQueue *q2,DataType d,int priority)
{
	if(priority==2)
		LQueueEnQueue(q2,d); 
	else
		LQueueEnQueue(q1,d);
}

DataType MyDeQueue(LinkQueue *q1,LinkQueue *q2)
{
	DataType e;
	if(!LQueueIsEmpty(q2))
		LQueueDeQueue(q2,&e);
	else
		if(!LQueueIsEmpty(q1))
			LQueueDeQueue(q1,&e);
		else return -ERROR;
	return e;
}

