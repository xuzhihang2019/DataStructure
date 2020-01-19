#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MaxSize 100
typedef struct DataType
{
	char number[5];    		/*����*/
	char terminal[9];    	/*Ŀ�ĵ�*/
	int price;    			/*�۸�*/
	int count;    			/*ʣ��Ʊ��*/
}DataType;    				/*��Ʊ����*/
typedef struct SequenList
{
	DataType data[MaxSize];	/* �洢��������Ϣ������*/
	int length; 			/*������*/
}SequenList ;  				/*˳���,�洢�����б�*/

/*��������*/
void FCreat(SequenList *L);	/*��ȡ�ļ�,��ȡ��Ʊ��Ϣ,���복����Ϣ�ṹ��*/ 
void SellTicket(SequenList *ticketList,char number[5],int quantity,int money);/*��Ʊ*/ 
void OutPut(SequenList L);	/*���������Ϣ�ṹ��*/
int SearchBin(SequenList st,char number[5]);/*���ֲ���*/ 

int main()
{
	SequenList ticketList;
	char number[5];
	int quantity,money;
	
	while(1)
	{
		printf("\n\n1����Ʊ(Supply)");
		printf("\n2����Ʊ(Sell)");
		printf("\n3����ѯ(Query)");
		printf("\n0���˳�(Quit)");
		printf("\n��ѡ��(Select):");
		switch(getche())
		{	
			case '1':	
				FCreat(&ticketList);
				puts("\n��Ʊ��ɣ�\n");
				break;
			case '2':	
				puts("\n\n��ֱ�����Ҫ����ĳ���  Ʊ��  ���(�Կո����):");
				scanf("%s%d%d",number,&quantity,&money);
				SellTicket(&ticketList, number, quantity, money);	/*������Ʊ*/
				break;
			case '3':
				OutPut(ticketList);/*���в�ѯ*/
				break;
			case '0':
				return;
		}
	}
}

void FCreat(SequenList *L)		/*��ȡ�ļ�,��ȡ��Ʊ��Ϣ*/ 
{
	FILE *fp;    
	int i=1;
	fp=fopen("shepiao_info.txt","r"); 
	if(!fp)
	{
		printf("\n�����ļ��޷���!");
	}	
	else
	{
		L->length=0;
		while(!feof(fp))
		{
			/*���ļ��ж�ȡ��Ʊ��Ϣ�����복����Ϣ�ṹ��*/
			fscanf(fp,"%s%s%d%d\n",L->data[i].number,L->data[i].terminal,&(L->data[i].price),&(L->data[i].count));
			L->length++;
			i++;
		}
	}
}

void OutPut(SequenList L)		/*���������Ϣ�ṹ��*/
{
	int i;
	puts("\n\n��Ʊ��Ϣ��(Tickers List)");
	puts("\n����    Ŀ�ĵ�    �۸�    ʣ��Ʊ��");
	puts("No��Destination    Price    Remainder");
	for(i=1;i<=L.length;i++)
	{
		printf("\n%-7s%-10s%7d%9d",L.data[i].number,L.data[i].terminal,L.data[i].price,L.data[i].count);
	}
}

int SearchBin(SequenList st,char number[5])	/*���ֲ���*/
{  /*ʹ���۰����,��������ұ�st�в��ҹؼ���ֵ����number�ļ�¼,���򷵻ظü�¼��λ�����;û��,�򷵻�����ֵ0��*/
	int low, high, mid;
	low=0,high=st.length-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(number, st.data[mid].number)==0)
		{
			return mid;
		}
		if(strcmp(number, st.data[mid].number)<0)
		{
			high=mid-1;
		}
		if(strcmp(number, st.data[mid].number)>0)
		{
			low=mid+1;
		}
	}
	if(low>high)
	{
		return 0;
	}
}

void SellTicket(SequenList *ticketList,char number[5],int quantity,int money)
{/*��Ʊ,������Ϣ��ΪticketList,�����ĳ���number,��������scount,���money*/
	int cc,rr;
	int mremainder,nremainder;				/*ʣ���ʣ������*/
	int factcount;    						/*ʵ�ʿɹ��������*/
	cc=SearchBin(*ticketList,number);  		/*���ҳ���*/
	if(cc==0)  								/*û�иó���*/
	{
		printf("��Ч���롣�������Ϊ:%d",money);
		return;
	}
	if(ticketList->data[cc].count==0)  		/*ʣ������Ϊ0,������*/
	{
		printf("�ôγ�Ʊ������!���������Ϊ:%d",money);
		return;
	}
	nremainder=ticketList->data[cc].count-quantity ;	/*ʣ������*/
	if(nremainder>=0)   					/*������*/
	{
		factcount=quantity;  				/*��������*/
	}
	else    								/*��������*/
	{
		factcount=ticketList->data[cc].count;   				/*���ɹ��������*/
	}
	mremainder=money-ticketList->data[cc].price*factcount ;		/*ʣ����*/
	if(mremainder<0) 						/*����ʱ������������,����ʱ����๺�������*/
	{
		factcount=(int)(money/ticketList->data[cc].price);    	/*��๺�������*/
	}
	if(factcount>0)
	{
		ticketList->data[cc].count-=factcount;
		mremainder=money-ticketList->data[cc].price*factcount;	/*ʣ����*/
		printf("�ѹ��򣺳���:%s  �г�Ŀ�ĵ�:%s  ����:%d  ����:%d  ���:%d",ticketList->data[cc].number,ticketList->data[cc].terminal,ticketList->data[cc].price,factcount,mremainder);
	}
	else
	{
		printf("��Ч������ʣ���ǮΪ:%d",money);
	}
}

