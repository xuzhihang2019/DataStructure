/*�Ӽ�������һ����������a1��a2,...an��
*��д�㷨ʵ�֣�
*��˳��ջ�ṹ�洢�������������
*����ai������-1ʱ����ai��ջ��
*��ai=-1ʱ�����ջ����������ջ��
*Ҫ����Ӧ����ջ�����쳣�����
*��������ʾ��Ϣ��
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct stack
{
	int data[MAXSIZE];
	int top;
} Stack, * pStack;

bool InitStack(pStack s);		/*��ʼ��ջ*/ 
bool push(pStack s, int val);	/*��ջ*/
bool pop(pStack s,int * val);	/*��ջ*/
bool GetTop(pStack s,int *val);
void showstack(pStack s);		/*�������*/

int main()
{
	int len,a,i,top;
	pStack s = (pStack)malloc(sizeof(Stack));
	InitStack(s);				/*��ʼ��ջ*/
	printf("������Ҫ����������ĸ�����");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("�������%d����:",i+1);
		scanf("%d",&a);
		if(a != -1)
		{
			push(s,a);			/*��ai������-1ʱ����ai��ջ*/
		}
		else
		{
			pop(s,&top);
			printf("\nջ��������ջ\n");
			printf("ջ������Ϊ��%d\n\n",top);		/*ai=-1ʱ�����ջ����������ջ*/
		}
	}
	printf("ջ�����Ϊ��\n");
	showstack(s);
	free(s); 
	return 0;
}

bool InitStack(pStack s)
{
	s->top = -1;
	return true;
}

bool push(pStack s, int val)
{
	if(s->top==MAXSIZE-1)
	{
		printf("ջ����\n");
		return false;
	}
	else
	{
		s->top++;
		s->data[s->top] = val;
		return true;
	} 
}

bool pop(pStack s,int * val)/*�ѳ�ջ��Ԫ�ش���val��ָ��ı����У���ջ�ɹ�����true��ʧ�ܷ���false*/
{
	if(s->top==-1)
	{
		printf("ջ��\n");
		return false;
	}
	*val = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(pStack s,int *val)
{
	if(s->top==-1)
	{
		printf("ջ��\n");
		return false;
	}
	else
	{
		*val = s->data[s->top];
		return true;
	}
}

void showstack(pStack s)
{
	int i=0;
	if(s->top==-1)
	{
		printf("ջ��\n");
	}
	else
	{
		while(i<s->top||i==s->top)
		{
			printf("%d  ",s->data[i++]);
		}
		printf("\n");
	}
}
