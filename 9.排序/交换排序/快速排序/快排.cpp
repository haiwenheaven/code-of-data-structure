#include<stdio.h>

int partition(int a[],int low,int high)//每次都以第一个元素为枢轴进行交换排序，并返回中间那个元素的下标 
{
	int biaogan=a[low];
	while(low<high)
	{
		while(low<high && a[high]>=biaogan)
		{
			high--;
		}
		a[low]=a[high];
		while(low<high && a[low]<=biaogan)
		{
			low++;
		}
		a[high]=a[low];
	}
	a[low]=biaogan;
	return low;//low便是一次快排的枢轴的下标 
} 
void qsort(int a[],int low,int high)//对序列进行一次快速排序之后在对递归对两边的序列排序，直到low>=high 
{
	int p=partition(a,low,high);
	if(low<high)
	{
		qsort(a,p+1,high);
		qsort(a,low,p-1);
	}
}

int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	qsort(a,0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
