#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX 100

typedef struct node 
{
	char name[10];									/*��ż����Ա����*/
	struct node *lchild, *rchild;
}BTree;												/*�������ṹ�����Ͷ���*/
 

BTree *q[MAX];										/*ȫ�ֱ������洢����Ԫ�صĶ���*/
BTree *CreatBtree();								/*�������������������� */
void ScanLevel(BTree *bt);							/*���������������˳�������������� */
int FindAncestry(BTree *bt,char *ch);				/*����������������*/ 

int main()
{
	BTree *head;
	int ch;
	char cname[10];
	while(1)
	{
 		printf("��ѡ�����²�����\n");
	    printf ("һһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһ\n");
	    printf("1��������һ�����������\n");
	    printf("2���������������������\n");
	    printf("3�������ĳ����Ա���������ȳ�Ա\n");
	    printf("4������������\n");
	    printf ("һһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһһ\n");
	    printf("��ѡ��(1--4)��");
	    scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case 1:
				head=CreatBtree(); 					/*�������������*/
				printf("\n��������������ɹ���\n");
				printf("\n�밴������������˵�...");
				getchar();
				break;
			case 2:
				printf("�������������������\n");
				ScanLevel(head);					/*��������������*/
				printf("\n�밴������������˵�...");
				break;
			case 3: 
				printf("\n������Ҫ�����ĸ���Ա�����ȣ�\n");
		        scanf("%s",cname);
				getchar();
		    	FindAncestry(head,cname);
				printf("\n�밴������������˵�...");
		        break;
			case 4:
				exit(0);
		}
		getchar();
	}
	return 0;
}

/*���˳�򴴽����������*/
BTree * CreatBtree()
{
	char ch1[10];
	int front,rear;									/*���ö�ͷ�Ͷ�βָ�룬���ö���Ϊ��*/
	int flag=0;										/*��ͷָ��front�ƶ����жϱ�־*/ 
	BTree *root,*s;
	front=1,rear=0;									/*front������ָ�򸸽���±��*/ 
	root=NULL;
	printf("�밴���˳����������Ա��������ȱ������@��������Ϊ$ \n");
	scanf("%s",ch1);								/* �����һ�������Ա���� */
	while(strcmp(ch1,"$"))							/*���ǽ�����ʱ�ظ�ѭ�� */
	{	
		s=NULL;
		if(strcmp(ch1, "@"))
		{
			s = (BTree *)malloc(sizeof(BTree));		/*���ǿս��ʱ�������½��*/
			strcpy(s->name, ch1);
			s->lchild = NULL;
			s->rchild = NULL;
		}
    	rear++;
		q[rear]=s;									/*���½���ַ���*/  
		if(rear==1)									/*����ĵ�һ�����Ϊ����� */
		{
			root=s;
		}
		else										/*��������㣬�����벻��s�Ͳ��ؿ�����ô�ҽ��s*/
		{
			if(q[front] && s)						/*���Ӻ�˫�׽�㲻�ǿս��  */
			{
				if(rear%2==0)						/*rearΪż�����½�������� */
				{
					q[front]->lchild = s;			/*rearΪż�����½����q[front]����*/
				}
 				else
				{
                    q[front]->rchild = s;			/*rearΪ�������½����q[front]�Һ��� */
					front++;  						/*���*q[front]�����Һ��Ӵ�����ϣ��ý����ӣ��ı丸�����±�front*/
					flag=0;
				}
			}
			else
			{
				flag++;      						 /*��ӵĽ��Ϊ��ʱ�����Һ��Ӵ����꣬�ý����ӣ�frontָ������*/
	        	if(flag==2)
				{
					front++;
					flag=0;
				}
			}
		}
	scanf("%s",ch1);								/*������һ���ַ� */
	}
	return root;									/*���ظ�����ַ */
}

/*�����˳�������������� */
void ScanLevel(BTree *bt)
{
	int front=0,rear=0; 							/*��ʼ�����е�ͷ��βָ�� */
	if(bt!=NULL)
	{
		rear++;
		q[rear]=bt;									/*��bt��ָ��Ľ����� */
	}
	while(front!=rear)								/*���зǿ� */
	{
		front++;
		bt=q[front];								/*��ͷ������ */
		printf ("%s    ",bt->name);					/*����ý������� */
		if(bt->lchild!=NULL)
		{
			rear++;
			q[rear] = bt->lchild;					/*�����ӽ����� */ 
		}
		if(bt->rchild!=NULL)
		{
			rear++;
			q[rear] = bt->rchild;					/*���Һ��ӽ����� */
		}
	}
	printf("\n");
}

/*��������Ϊ*ch�Ľ�㡣���У�����ý����������ȳ�Ա��������1����û�У�����0*/
int FindAncestry(BTree *t,char *ch)
{													
	int flagl=0,flag2=0;   							/*����������־���� */
	int cond;
	if(t==NULL||(t->lchild==NULL&&t->rchild==NULL)) /*���н����������l*/
	{
		return 0;
	}
	cond=(t->lchild!=NULL)&&(strcmp(t->lchild->name,ch)==0);	/*���������ҽ��*/
	cond=cond ||((t->rchild!=NULL)&&(strcmp(t->rchild->name,ch)==0));	/*���Һ��������ҽ��*/
	if(cond)										/*���ӻ��Һ��������ҽ�� */
	{
		printf("%s,",t->name);
		return 1;   								/*�ҵ����ȣ�����1ֵ*/
	}
	else
	{	
		flagl=FindAncestry(t->lchild,ch);			/*���������ϲ��ң�������ֵ����flag1*/
		flag2=FindAncestry(t->rchild,ch);			/*���������ϲ��ң�������ֵ����flag2*/
		if(flagl || flag2)   						/*���������������������н�� */
		{
			printf("%s,",t->name);
			return 1;								/*�����ж������ģ�����1ֵ */
		}
		else
		{
			return 0;
		}
	}
	printf("\n");
}

