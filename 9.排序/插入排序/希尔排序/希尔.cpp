#include<stdio.h>

void xier(int a[])
{
	int dk,i,j,temp;
	for(dk=10/2;dk>=1;dk/=2)//ѡȡ��ͬ�������ֱ����ϣ������ 
	{
		for(int i=dk+1;i<10;i++)//a[i]Ϊ�������������ĵ� 
		{
			if(a[i]<a[i-dk])
			{
				temp=a[i];
				for(j=i-dk;j>=0&&a[j]>temp;j-=dk)//����Ϊdk������-=dk 
				{
					a[j+dk]=a[j];	
				}
				a[j+dk]=temp;	
			}	
		}
	}
}

int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	xier(a);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
