/*
	1����дһ���������ö��ֲ����㷨��һ��������в��ҹؼ���Ϊx�Ľ��
	�������ڣ������һ��Ԫ��x�������ֱ�������ԡ�
*/
#include<stdio.h>
int main()
{
	int i,flag=0,index,j,n,k,t,low,high,mid;
	int a[50];
	/*������ʼ���ݱ�*/ 
	printf("������������Ԫ�ظ���:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	/*ԭ��������*/
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("������Ҫ���ҵ����ݣ�");
	scanf("%d",&k);
	/*���ֲ���*/
	low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])
		{
			printf("\n�ҵ��ýڵ㣬�±�Ϊ��%d",mid);
			break;
		}
		if(k<a[mid])
		{
			high=mid-1;
		}
		if(k>a[mid])
		{
			low=mid+1;
		}
	}
	/*�Ҳ���*/ 
	if(low>high)
	{
		printf("\n�ýڵ㲻����\n");
		/*�ҵ������λ��*/
		for(i=0;i<n;i++)
		{
			if(k<a[i])
			{
				flag=1;
				index=i;
				break;
			}
		}
		if(flag==0)/*���������ԭ���ݶ���*/
		{
			a[n]=k;
		}
		else
		{
			/*����λ�ú����������*/
			for(i=n-1;i>=index;--i)	/*����Ӻ���ǰ����*/
			{
				a[i+1]=a[i];		/*�Ӻ���ǰ��ÿ��������*/ 
			}
			/*����*/
			a[index]=k; 
		}
		printf("����x������Ϊ��\n");
		for(i=0;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}

