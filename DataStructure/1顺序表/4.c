#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#define MM 7								/*��Ʊ�к���ĸ���*/
#define NN 36								/*��ѡ���ĸ���*/

typedef int ElemTp;							/*Ԫ������*/
typedef struct
{
	ElemTp elem[MM+1];
	int len;
}VoteTp;									/*��Ʊ�����ṹ��*/

typedef struct
{
	ElemTp elem[NN+1];
	int len;
} SourceTp;									/*��ѡ����ṹ��*/

				/*��������*/ 
void InitializeVote(VoteTp *vote);			/*��ʼ����Ʊ�����*/
void InitializeSource(SourceTp *Source);		/*��ʼ����ѡ����Source���ڱ��з���1��3 6��3 6������������Ϊ36 */
int SeqLocate(VoteTp v,ElemTp x);			/*��˳���v�в���ֵΪx��Ԫ�أ����ظ�Ԫ�ص�λ����ţ�û��ʱ����0*/
void SeqInsertVote(VoteTp *vote,int i,ElemTp x);/*��˳���*vote�ĵ�i������Ԫ��֮ǰ��������Ԫ��x */
void CreateAVote(SourceTp source,VoteTp *vote);  /*����һ�Ų�Ʊvote*/
int RightNum(VoteTp vote,VoteTp answervote); /*�жϲ�Ʊ���н����*/
				/*������*/ 
void InitializeVote(VoteTp *vote)			/*��ʼ����Ʊ�����*/
{
	vote->len=0;
}

void InitializeSource(SourceTp *Source)		/*��ʼ����ѡ����Source���ڱ��з���1��3 6��3 6������������Ϊ36 */
{
 	int i;
 	Source->len=0;
 	for(i=0;i<NN;i++)
 	{
 		Source->elem[i]=i;
		Source->len++;
 	}
}

int SeqLocate(VoteTp v,ElemTp x)			/*��˳���v�в���ֵΪx��Ԫ�أ����ظ�Ԫ�ص�λ����ţ�û��ʱ����0*/
{
	int flag=0;
	int i;
	for(i=0;i<v.len;i++)
	{
		if(v.elem[i]==x)
		{
			flag=1;
			return (i+1);
			break;							/*�ҵ�����ֹѭ��*/
		}
	}
	if(flag==0)
	{
		return 0;
	}
}

void SeqInsertVote(VoteTp *vote,int i,ElemTp x)/* ��˳���*vote�ĵ�i������Ԫ��֮ǰ��������Ԫ��x */
{
	int t;
	for(t = vote->len-1;t>=i-1;--t)
	{
		vote->elem[t+1] = vote->elem[t];
	}
	vote->elem[i-1] = x; 
	(vote->len)++;
}

void CreateAVote(SourceTp source,VoteTp *vote)  /*����һ�Ų�Ʊvote*/
{
	ElemTp k,temp;
	int i;
	InitializeVote(vote); 
	for(i=0;i<MM;i++)
	{
		srand( (unsigned)time( NULL ) );		/*������������ӣ�ÿ�εĲ�Ʊ������ܲ�ͬ*/
		k= rand() % source.len+1;				/*����һ��1��source.len�������k*/
		
		SeqInsertVote(vote,vote->len+1,source.elem[k]);		/*��source.elem[k]���뵽��Ʊ�����vote�� */
		/*����ѡ����source�еĵ�k��Ԫ��ɾ��*/
		/*ɾ���㷨��Source.el em[k]��source.elem[source.len]����������ѡ�����source.1en��1*/
		temp=source.elem[k];
		source.elem[k]=source.elem[source.len];
		source.elem[source.len]=temp;
		source.len=source.len-1;
	}
}

int RightNum(VoteTp vote,VoteTp answervote) /*�жϲ�Ʊ���н����*/
{	/*һ�Ų�Ʊvote���н������answervote��ȣ���������ز¶Եĺ������*/
	int i,k;
	k=0;
	for (i=0;i<MM;i++)
	{
		if(SeqLocate(vote,answervote.elem[i])>0)
		{
			k++;	
		}
	}
	
	return(k);
}

int main()
{ 
	SourceTp source;
 	VoteTp vote;
 	VoteTp answervote;
 	int k,i;
 	InitializeSource(&source); 					/*��ʼ����ѡ����Source������36������������Ϊ36*/		
 	printf("\n �����н�����: "); 
 	CreateAVote(source,&answervote); 			//����һ���н�����
 	for (i=0;i<MM;i++)							/*i�����0��ʼ*/ 
 	{
	 	printf("%3d ",answervote.elem[i]); 		/*������������н�����*/ 
	}	
	while(getchar()!='0')	
	{
		printf("\n ��Ĳ�Ʊ����:\n");
	 	CreateAVote(source,&vote);				/*������Ĳ�Ʊ����*/
	  	for (i=0;i<MM;i++)
	  	{
	  		printf("  %-2d  ",vote.elem[i]);	/*���������Ĳ�Ʊ����*/ 
	  	}	
		printf("\n�ҽ���");
	  	k=RightNum(vote,answervote);			/*�����жϲ�Ʊ���н��������*/
	  	printf("��ϲ������%d λ���֣�����\n",k);
	 	printf("\n ���س�����������0����...");
	}
 	return 0;
}
