#include<stdio.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct
{
	Elemtype elem[MAXSIZE];
	int length;
}SxList;
void InitList(SxList *List);		/*�������� ��ʼ��˳���*/
void CreatList(SxList *List);		/*�������� ����˳���*/
void find_List(SxList *List,int val);/*�������� ���� */ 
void show_List(SxList *List);		/*�������� ���˳���*/

int main()
{
	int needFind,i,j,temp;
	SxList List;
	InitList(&List);
	CreatList(&List);
	for(i=0;i<List.length-1;i++)			/*���Ա���Ԫ�ص�������*/
	{
		for(j=0;j<List.length-i-1;j++)
		if(List.elem[j]>List.elem[j+1])
		{
			temp = List.elem[j];
			List.elem[j] = List.elem[j+1];
			List.elem[j+1] = temp;
		}
	}
	printf("��˳���Ϊ��\n");
	show_List(&List);
	printf("\n");
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&needFind);
	find_List(&List,needFind);	
	show_List(&List);			/*���Ҳ�������ٱ���*/
	return 0;
}

void InitList(SxList *List)		/*��ʼ��˳���*/
{
	List->length = 0;
}

void CreatList(SxList *List)	/*����˳���*/
{
	int num,i;
	printf("������Ԫ�ظ���:");
	scanf("%d",&num);
	printf("������%d��Ԫ��\n",num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&List->elem[i]);
		++List->length;
	}
}

void show_List(SxList *List)	/*���˳���*/ 
{
	int i;
	if(0 == List->length)
	{
		printf("������Ϊ�ա�\n");
	}
	else
	{
		for(i=0;i<(List->length);++i)
		{
			printf("%d ",List->elem[i]);
		} 
		printf("\n");
	}
}

void find_List(SxList *List,int val)	/*���� */
{
	int i,temp,j;
	int flag = 0;
	for(i=0;i<List->length;++i)
	{
		if(val==List->elem[i])
		{
			flag = 1;
			temp = List->elem[i];
			List->elem[i] = List->elem[i+1];
			List->elem[i+1] = temp;				/*���ҵ���������Ԫ��λ���ཻ��*/
			printf("�ҵ�!\n");
			printf("�ҵ���������Ԫ��λ���ཻ�������£�\n");
			break;
		}
	}
	if(flag == 0)
	{
		printf("û�ҵ�!\n");
		(List->length)++;
		List->elem[List->length-1] = val;						/*���Ҳ�������������*/
			/*��ʹ����Ԫ���Ե�������*/
		printf("û�ҵ��Ļ����������в�ʹ����Ԫ���Ե����������£�\n");
		for(i=0;i<List->length-1;i++)
		{
			for(j=0;j<List->length-i-1;j++)
			if(List->elem[j]>List->elem[j+1])
			{
				temp = List->elem[j];
				List->elem[j] = List->elem[j+1];
				List->elem[j+1] = temp;
			}
		}
	}
	
}

