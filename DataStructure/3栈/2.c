#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

typedef struct stack
{
	int data[MAXSIZE];
	int top;
} Stack, * Seqstack;

bool InitStack(Seqstack s);		/*��ʼ��ջ*/ 
bool push(Seqstack s, int val);	/*��ջ*/
bool pop(Seqstack s,int * val);	/*��ջ*/
bool GetTop(Seqstack s,int *val);
void showstack(Seqstack s);		/*�������*/
bool SeqstackEmpty(Seqstack s);

int main()
{
	int len,b,i,top,num,a[100];
	int n=0; 
	Seqstack s = (Seqstack)malloc(sizeof(Stack));
	InitStack(s);				/*��ʼ��ջ*/
	printf("������Ҫ����������ĸ�����");
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		printf("�������%d����:",i+1);
		scanf("%d",&b);
		push(s,b);
	}
	printf("ջΪ��\n");
	showstack(s);
	printf("\n");
	
	while(!SeqstackEmpty(s))	/*ջ��Ϊ�գ��ͳ�ջ����ջ���ݷ�������a��*/
	{
		pop(s,&num);
		a[n] = num;
		n++;
	}
	for(i=0;i<n;i++)
	{
		push(s,a[i]);		/*����a����ջ*/ 
	}
	
	printf("�������㷨��ջΪ��\n");
	showstack(s);
	printf("\n");
	free(s); 
	return 0;
}

bool InitStack(Seqstack s)
{
	s->top = -1;
	return true;
}

bool push(Seqstack s, int val)
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

bool pop(Seqstack s,int * val)/*�ѳ�ջ��Ԫ�ش���val��ָ��ı����У���ջ�ɹ�����true��ʧ�ܷ���false*/
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

bool GetTop(Seqstack s,int *val)
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

void showstack(Seqstack s)
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

bool SeqstackEmpty(Seqstack s)
{
	if(s->top==-1)
	{
		return true;
	}
	else
		return false;
}
