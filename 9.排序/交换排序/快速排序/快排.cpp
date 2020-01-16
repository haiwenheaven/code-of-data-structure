#include<stdio.h>

int partition(int a[],int low,int high)//ÿ�ζ��Ե�һ��Ԫ��Ϊ������н������򣬲������м��Ǹ�Ԫ�ص��±� 
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
	return low;//low����һ�ο��ŵ�������±� 
} 
void qsort(int a[],int low,int high)//�����н���һ�ο�������֮���ڶԵݹ�����ߵ���������ֱ��low>=high 
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
