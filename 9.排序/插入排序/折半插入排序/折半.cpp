#include<stdio.h>

void zheban(int a[])
{
	int i,j,low,high,mid,temp;
	for(i=1;i<10;i++)
	{
		temp=a[i];
		low=0;
		high=i-1;
		while(low<=high)//折半查找到插入位置high+1 
		{
			mid=(low+high)/2;
			if(a[mid]>temp)
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		for(j=i-1;j>=high+1;j--)
		{
			a[j+1]=a[j];
		}
		a[high+1]=temp;
	}
}

int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	zheban(a);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
