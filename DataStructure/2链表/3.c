#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;								/*������*/
	struct Node * next;						/*ָ����*/
}Node, *pNode;

pNode CreateList();							/*������������������*/
void RiseSort(pNode head);					/*��������������*/
void Simplification(pNode head);			/*����������ȥ����ͬ�ļ���Ԫ��*/
pNode CreateAgg();
void InsertNode(pNode head,int num);
pNode MergeAgg(pNode A,pNode B); 			/*�������������������ϵĲ���*/ 
pNode MutualAgg(pNode A,pNode B); 			/*�������������������ϵĽ���*/
void PrintList(pNode head);					/*������������������*/
void freeheap(pNode head);					/*�����������ͷŽڵ�*/

int main() 
{
    pNode A, B, C, D;
    printf("�������� A:\n");
    A = CreateAgg();
    printf("\n�������� B:\n");
    B = CreateAgg();
    printf("\n����A��Ԫ����:\n");
    PrintList(A);
    printf("\n����B��Ԫ����:\n");
    PrintList(B);
    C = MutualAgg(A,B);
    printf("\nA��B�Ľ���Ϊ:\n");
    PrintList(C);
    D = MergeAgg(A,B);
	printf("\nA��B�Ĳ���Ϊ:\n");
    PrintList(D);
    /*****�ͷ��ڴ�*****/
    freeheap(A);
    freeheap(B);
    freeheap(C);
    freeheap(D);
    printf("\n");
    return 0;
}

pNode CreateList() 
{ 
    pNode head, p;
    int i,n,val;
    head = p = (pNode)malloc(sizeof(Node)); 
    head->data = 0;
    printf("������ڵ�����,�� 0 Ϊ������־\n");
    do 
	{
        p->next = (pNode)malloc(sizeof(Node));
        scanf("%d",&val);
        p->next->data = val;
        p = p->next;
    }while(val != 0);
    p->next = head;
    return head;
}
 
void RiseSort(pNode head) 
{ 
    pNode p, s, pt; 
    p = head;
    s = p->next;
    while(p->next != head) 
	{
        while(s->next != head) 
		{
            if(p->next->data > s->next->data) 
			{
                pt = p->next;
                p->next = s->next;
                s->next = p->next->next;
                p->next->next = pt;
            }
            else s = s->next;
        }
        p = p->next;
        s = p->next;
    }
}

void Simplification(pNode head) 
{ 
    pNode p, q, s;
    p = head->next;
    q = p->next;
    while(q != head) 
	{
        if(p->data == q->data) 
		{
            p->next = q->next;
            s = q;
            q = q->next;
            free(s);
        }
        else 
		{
            p = p->next;
            q = q->next;
        }
    }
}

pNode CreateAgg() 
{
    pNode head;
    head = CreateList();
    RiseSort(head);						/*����*/ 
    Simplification(head);				/*ȥ����ͬ�ļ���Ԫ��*/ 
    return head;
}
 
void InsertNode(pNode head,int num) 
{
    pNode t, p = head;
    while(p->next != head) 
	{
        if(p->next->data == num) return; 
        if(p->next->data < num) p = p->next;
        else 
		{
            t = (pNode)malloc(sizeof(Node));
            t->data = num;
            t->next = p->next;
            p->next = t;
            return;
        }
    }
    t =(pNode)malloc(sizeof(Node));
    t->data = num;
    p->next = t; 
    t->next = head;     // ����������β�Ĵ���
}
 
pNode MergeAgg(pNode A,pNode B) /*�������������������ϵĲ���*/ 
{
    pNode head, pa, pb, pc, qc;
    head = pc = (pNode)malloc(sizeof(Node));
    pa = A->next;
    while(pa != A) 
	{
        qc = (pNode)malloc(sizeof(Node));
        qc->data = pa->data;
        pc->next = qc;
        pc = qc;
        pa = pa->next;
    }
    pc->next = head;
    pb = B->next;
    while(pb != B) 
	{
        InsertNode(head,pb->data);
        pb = pb->next;
    }
    return head;
}
 
pNode MutualAgg(pNode A,pNode B) /*�������������������ϵĽ���*/
{
    pNode C, pa, pb, pc, qc;
    C = pc = (pNode)malloc(sizeof(Node));
    pc->data = 0;
    pa = A->next;
    pb = B;
    while(pa != A) 
	{
        pb = B->next;
        while(pb != B) 
		{
            if(pb->data == pa->data) 
			{
                qc = (pNode)malloc(sizeof(Node));
                qc->data = pb->data;
                pc->next = qc;
                pc = qc;
            }
            pb = pb->next;
        }
        pa = pa->next;
    }
    pc->next = C;
    return C;
}

void PrintList(pNode head)
{
	pNode p = NULL;
	p = head->next;								/*ͷ�ڵ㲻�����ݣ����Դ�ͷ�ڵ��һ�ڵ�(�׽ڵ�)��ʼ����*/
	while(p != head)
	{
		printf("%d  ",p->data);
		p = p->next;								/*p����*/
	}
	printf("\n");
}

void freeheap(pNode head) 
{
    pNode p, q;
    p = head;
    q = p->next;
    while(q != head) 
	{
        p = q;
        q = p->next;
        free(p);
    }
    free(head);
}
 
