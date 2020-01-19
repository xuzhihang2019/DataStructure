#include<stdio.h>
#include<stdlib.h>
#define m 6									/* �Թ���ʵ����  */ 
#define n 8									/*�Թ���ʵ����*/ 
#define STACK_INIT_SIZE 100      			//�洢�ռ��ʼ������
#define STACKINCREMENT 10      				//�洢�ռ��������

typedef struct
{ 
	int x,y,d;    							/*�������꼰����*/ 
} SElemType; 
typedef struct
{     
	SElemType stack[STACK_INIT_SIZE];     
	int top;            
} SeqStack;          						/*����˳��ջ����*/ 
typedef struct
{
	int x,y;   
} Item; 
SElemType XX={-1,-1,-1};
int maze[m+2][n+2]=
{  /*        0,1,2,3,4,5,6,7,8,9      */
	{1,1,1,1,1,1,1,1,1,1},/*0*/
	{1,0,1,1,1,0,1,1,1,1},/*1*/
	{1,1,0,1,0,1,1,1,1,1},/*2*/
	{1,0,1,0,0,0,0,0,1,1},/*3*/
	{1,0,1,1,1,0,1,1,1,1},/*4*/
	{1,1,0,0,1,1,0,0,0,1},/*5*/
	{1,0,1,1,0,0,1,1,0,1},/*6*/
	{1,1,1,1,1,1,1,1,1,1}/*7*/
};
Item move[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
/* 8���ƶ�����*/ 
int Empty_SeqStack(SeqStack *s);					/*����������ջ�Ƿ�Ϊ��*/
void Push_SeqStack(SeqStack *s,SElemType x);		/*����������ѹջ*/
SElemType Gettop_SeqStack(SeqStack *s);				/*����������ջ��ֵ*/
SElemType Pop_SeqStack(SeqStack *s);				/*������������ջ*/
void * OnePath(int maze[m+2][n+2],Item move[8],SeqStack *s);/*��������*/
 
int main()
{
	SElemType temp;
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));  
	if(!s)
	{
		exit(0);
	}
	else
	{
		s->top = -1;
	}
	OnePath(maze,move,s);						/*̽��·��*/ 
	
	if(s->top==-1)								/*ջΪ�գ��Թ��޳�·*/ 
	{
		printf ("���Թ���·��\n");
	}
	else										/*ջ�ǿգ������Թ�·��*/ 
	{ 
		printf ("�Թ�·��Ϊ��\n") ; 
		while(!Empty_SeqStack(s))				/*ջ�ǿ�,��ջ�е�Ԫ�س�ջ����ӡ*/
		{
			temp=Pop_SeqStack(s);
			printf("(%d,%d)-",temp.x,temp.y);
		}
		while(getchar()!='0')
		{
			printf("������0���˳�����");
		}
	}
	return 0;
}

int Empty_SeqStack(SeqStack *s)
{ 
	/*��ջ�ա�Ҫ�󣺿�ջջ��ָ��Ϊ-1,����1,���򷵻�0*/
	if(s->top == -1)
	{
		return 1;
	}
	else
		return 0;
} 
void Push_SeqStack(SeqStack *s,SElemType x)
{ 
	/*��Ԫ��xѹ��ջs�С�Ҫ��ջ��,��ʾջ����Ϣ�������ջ�����򷵻�*/
	if(s->top == STACK_INIT_SIZE-1)
	{
		printf("ջ����");
	}
	else
	{
		s->top++;
		s->stack[s->top] = x;
	}
} 
SElemType Gettop_SeqStack(SeqStack *s) 
{
	/*ȡջ��Ԫ�ء�Ҫ��ջ�ղ��ܳ�ջ,��������ֵXX�����򷵻�ջ��Ԫ��*/
	if(s->top==-1)
	{
		return XX;
	}
	else
	{
		return s->stack[s->top];
	}
} 
SElemType Pop_SeqStack(SeqStack *s)     
{
	/*��ջ, ,�ɹ�ʱ���ض�Ԫ��;���ɹ�ʱ��������*/
	if(Empty_SeqStack(s))
	{
		printf("\n ջΪ�գ�");  
		exit(0);
	} 
	else
	{
		s ->top--;                                  
		return s->stack[s->top+1];
	}
}

void* OnePath(int maze[m+2][n+2],Item move[8],SeqStack *s)
{	/*̽��һ���Թ�·��,�ɹ�ʱ����1,���򷵻�0��̽���ɹ�ʱ,������·���ϵĶ������ջS��*/
	int x,y,d,i,j,dd;
	SElemType temp;
	temp.x=1;    
	temp.y=1;
	temp.d=-1;					/* ��ڵ����꼰����õ�ķ���(��Ϊ-1)��ջ  */ 
	Push_SeqStack(s,temp);		/*temp��ջ*/ 
	maze[temp.x][temp.y]=-1; 
	dd=0;						/*��һ����������*/
	while(!Empty_SeqStack(s))
	{
		temp=Gettop_SeqStack(s);/*ȡջ��Ԫ��*/
		x=temp.x;
		y=temp.y;
		d=dd;
		while(d<8)
		{
			i=x+move[d].x;
			j=y+move[d].y;
			if(maze[i][j]==0)	/*�ҵ���һ����һ�����ж���*/  
			{
				temp.x=i;
				temp.y=j;
				temp.d=d;		/*��һ����һ������temp */
				Push_SeqStack(s,temp);/* ������ջ*/   
				dd=0;			/*���������ʼ��Ϊ��һ������  */   
				maze[i][j]= -1;	/*�����߹���·�������*/   
				if(i==m && j==n)
					return 0;	/*�ҵ��Թ�����,����*/   
				break; 			/*�ҵ���һ���ġ�������֮��,����ʱ������������������  */   
			}
			else
				d=d+1;			/*̽����һ������*/ 
		}
		if(d==8)				/*��·����*/ 
		{
			temp= Pop_SeqStack(s);
			dd=temp.d+1;		/*������һ������һ����������*/ 
		}
	}
	return 0;
}
