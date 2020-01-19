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
void inversion_List(SxList *List);	/*�������� ���� */ 
void show_List(SxList *List);		/*�������� ���˳���*/

int main()
{
	SxList List;
	InitList(&List);
	CreatList(&List);
	printf("��˳���Ϊ��\n");
	show_List(&List);
	printf("\n");
	printf("���ú�Ϊ��\n");
	inversion_List(&List); 
	show_List(&List);			/*���ú��ٱ���*/
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

void inversion_List(SxList *List)	/*���� */
{
	int t, i=0;
	int j=List->length-1;
	/*�����еĿ�ʼ�����ĩԪ�ؽڵ㻥��*/
	while(i<j)
	{
		t = List->elem[i];
		List->elem[i] = List->elem[j];
		List->elem[j] = t;
		++i;
		--j;
	}
}
