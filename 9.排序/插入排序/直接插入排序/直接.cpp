#include<stdio.h>

void zhijie(int a[])
{
	int i,j;
	int temp;
	for(i=1;i<10;i++)
	{
		if(a[i]<a[i-1])//ֻ�д������ֵ��Сʱ���б�Ҫȥ�Ƚ� 
		{
			temp=a[i];
			for(j=i-1;a[j]>temp;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}
	}
}


int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	zhijie(a);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);	
	}	
	return 0;
}
