#include<stdio.h>
#include <stdlib.h>
#define VexNum 20		/*ͼ����ඥ�����*/
#define MAXINT 30000	/*����ֵ*/
typedef char VexType;	/*������������*/
typedef int EdgeType;	/*����������*/

typedef struct
{
	VexType vexs[VexNum];	/*��Ŷ������ݵ�����*/ 
	EdgeType arcs[VexNum][VexNum];	/*��ű����ݵĶ�ά����*/
	int vexnum,arcnum;	/*�������ͱ��� */
}Mgraph;				/*ͼ���ڽӾ����ʾ�ṹ���� */

typedef struct
{
	int adjvex;			/*����U�еĶ���(ʼ��)*/
	int value;			/*����u�ж��㵽��U�е�ĳ���������С����ֵ*/
}InterEdge;

void Min_SpanTree(Mgraph G,int u);	/*��������*/
Mgraph Create_MgraphN();			/*��������*/
int MinValue(InterEdge ee[],int n);	/*��������*/

int main()
{
	Mgraph G;
	G=Create_MgraphN();
	Min_SpanTree(G,0);
	return 0;
}

/*���������Ȩͼ���ڽӾ����㷨*/
Mgraph Create_MgraphN()				
{  
    int i,j,k;
    EdgeType v;						/* �ߵ�Ȩֵ */
    Mgraph G;
    printf("�����붥�������");
    scanf("%d",&G.vexnum);			/*�������*/
    printf("������ߵ�������");
    scanf("%d",&G.arcnum);			/*������*/
    printf("������%d����������ݣ�\n",G.vexnum);
    scanf("%s",G.vexs);				/*�����ַ���ʾ��*/
    /*��ʼ���ߵĶ�ά���������(��ʼ���ߵ�Ȩֵ)*/
    for(i=0;i<VexNum;++i)
    {
		for(j=0;j<VexNum;++j)
		{
			G.arcs[i][j] = MAXINT;	/*���ó�ʼ����ֵΪMAXINT*/
			if(i == j)
			{
				G.arcs[i][j] = 0;			/*���㵽����ľ���ֵΪ0*/
			}
		}           
    }
    
    for(k=0;k<G.arcnum;k++)
    {
		printf("�����%d���������ź��յ����,�ÿո������",k+1);
        scanf("%d %d",&i,&j);		/*�����Ӧ�������ź��յ����*/
	    while(i<1|| i>G.vexnum || j<1 || j>G.vexnum)
	    {
			printf("����ı���ţ�,����������i,j\n");
			scanf("%d %d",&i,&j);
		}
	    printf("������ߵ�Ȩֵ��");
	    getchar();
	    scanf("%d",&v);				/*����ߵ�Ȩֵ*/
	    G.arcs[i-1][j-1] = v;
		G.arcs[j-1][i-1] = v;	/*����ͼ�洢��Ȩֵ,����1�����±�0,����Ҫ��1*/
	}
    return G;
}

/*�Ƚ�����С����ֵ,�����ض�Ӧ�±�*/
int MinValue(InterEdge ee[],int n)
{
    int i,j,k;
    for(j=0;j<n;j++)
    if(ee[j].value>0)
    {
		k=j;
		break;
    }
	for(j=1;j<n;j++)
	{
		if(ee[j].value>0 && ee[j].value<ee[k].value)
		{
			k=j;
		}
	}
    return k;
}

/*��С������������ķ�㷨,��uΪ��ʼ��,�����ڽӾ����ʾ��ͼG����С������,Ȼ�����*/
void Min_SpanTree(Mgraph G,int u)
{
	InterEdge ee[VexNum];
	int  cc=0,pp[VexNum*2];
	int k=0,i,j,s1,in;
	for(i=0;i<G.vexnum;i++)
	{  
		ee[i].adjvex=u;
		ee[i].value=G.arcs[u][i];
	}
	ee[u].value=0;
	for(i=1;i<G.vexnum;i++)			/*����С��������(nһ1)����,nΪ������G.vexnum*/
	{  
		k=MinValue(ee,G.vexnum);
		s1=ee[k].adjvex;			/*��һ��������U��,��һ�����㲻��U�еı���,��(s1,k)��һ��Ȩֵ��С�ı�*/
		ee[k].value=0;				/*������k���뵽U��*/
		pp[cc]=s1;
		cc++;
		pp[cc]=k;
		cc++;			/*����С��������һ����(sl,k)��¼������PP��*/
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[k][j]<ee[j].value)
			{						/*�������·��,�������±�*/
				ee[j].value=G.arcs[k][j];
				ee[j].adjvex=k;
			}
		}
	}
	printf("\n ��С��������:\n");
	for(i=0;i<2*(G.vexnum-1);i=i+2)
	{
		printf("(%2c,%2c);",G.vexs[pp[i]],G.vexs[pp[i+1]]);		/*��С��������ɱ����*/
	}
} 

