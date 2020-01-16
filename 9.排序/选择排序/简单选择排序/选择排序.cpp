#include<stdio.h>

void xuanze(int a[])
{
	int xiabiao,i,j,temp;
	for(i=0;i<10;i++)
	{		
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[i])
			{
				xiabiao=j;
			}
		}
		if(xiabiao!=i)
		{
			temp=a[i];
			a[i]=a[xiabiao];
			a[xiabiao]=temp;
		}
	}
}
int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	xuanze(a);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
