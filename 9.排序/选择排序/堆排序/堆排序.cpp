#include<stdio.h>

void adjustdown(int a[],int k,int len)//k位置的元素往下调整，长度为len 大顶堆 
{
	int i;
	a[0]=a[k];
	for(i=2*k;i<=len;i*=2)
	{
		if(i<len && a[i]<a[i+1])
		{
			i++;
		}
		if(a[i]<=a[0])
		{
			break;
		}
		else
		{
			a[k]=a[i];
			k=i;
		}
	}
	a[k]=a[0];
}
void adjustup()
{
	
}
void heapsort(int a[])
{
	for(int i=5;i>0;i--)
	{
		adjustdown(a,i,10);
	}
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[1]);
		a[1]=a[10-i];
		adjustdown(a,1,10-i-1);
	}
}
 
int main()
{
	int a[11]={0,6,5,2,9,6,5,20,3,4,7};
	heapsort(a);
	return 0;
}
