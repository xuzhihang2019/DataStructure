/*
	��������ͼ���ڽӾ���洢�������������ʽ����
	����ͼ���Դ�Ȩ�򲻴�Ȩ��Ҫ��ֱ��д�ڽӾ����������;������������ʵ�֡�
*/
#include<stdio.h>
#define MAXSIZE 100		/*ͼ����󶥵����*/
typedef char HeadType;	/*������������*/
typedef int EdgeType;	/*����������*/
typedef struct
{
	HeadType head[MAXSIZE];	/*��Ŷ������ݵ�����*/
	EdgeType edges[MAXSIZE][MAXSIZE]; 	/*��ű����ݵĶ�ά����*/
	int headNum;			/*������*/
	int edgeNum;			/*����*/
}Graph; 

Graph CreateGraph();			/*�����������ڽӾ���������*/
void PrintGraph(Graph g);		/*���������������������*/

int main()
{
	Graph g;
	g = CreateGraph();			/*�����ڽӾ���*/
	PrintGraph(g);				/*����ڽӾ���*/
	return 0;
}

Graph CreateGraph()
{
	int i,j,k;
    Graph g;
    printf("�����붥�������");
    scanf("%d",&g.headNum);			/*�������*/
    printf("������ߵ�������");
    scanf("%d",&g.edgeNum);			/*������*/
    printf("������%d����������ݣ�\n",g.headNum);
    scanf("%s",g.head);				/*�����ַ���ʾ��*/
    /*��ʼ���ߵĶ�ά���������(��ʼ���ߵ�Ȩֵ)*/
    for(i=0;i<MAXSIZE;++i)
    {
		for(j=0;j<MAXSIZE;++j)
		{
			if(i != j)
			{
				g.edges[i][j] = 0;
			}
			else
			{
				g.edges[i][i] = 0;			/*���㵽����ľ���ֵΪ0*/
			}
		}           
    }
    
    for(k=0;k<g.edgeNum;k++)
    {
		printf("�����%d���������ź��յ����,�ÿո������",k+1);
        scanf("%d %d",&i,&j);		/*�����Ӧ�������ź��յ����*/
	    while(i<1|| i>g.headNum || j<1 || j>g.headNum)
	    {
			printf("����ı���ţ�,����������i,j\n");
			scanf("%d %d",&i,&j);
		}
	    getchar();
	    g.edges[i-1][j-1] = 1;
		g.edges[j-1][i-1] = 1;
	}
    return g;
}

void PrintGraph(Graph g)
{
	int i,j;
	printf("\n�����������£�\n");
	printf("%s\n",g.head);
	printf("\n�ڽӾ������£�\n");
	for(i=0;i<g.headNum;i++)
	{
		for(j=0;j<g.headNum;j++) 
		{
			printf("%5d",g.edges[i][j]);
		}
		printf("\n");
	}
}

