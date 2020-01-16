#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct
{
	int data[max];
	int length;
}sqlist;

int initlist(sqlist &l)
{
	l.length=0;
	return 1;
}
int printlist(sqlist &l)
{
	for(int i=0;i<l.length;i++)
	{
		printf("%d ",l.data[i]);
	}
	return 1;
}
int listinsert(sqlist &l,int index,int n)
{
	if(index<1 && index>l.length+1)
	{
		return 0;
	}
	for(int i=l.length;i>=index-1;i--)
	{
		l.data[i]=l.data[i-1];
	}
	l.data[index-1]=n;
	l.length++;
	return 1;
}
int listdelete(sqlist &l,int index)
{
	if(index<1 && index>l.length)
	{
		return 0;
	}
	for(int i=index-1;i<l.length-1;i++)
	{
		l.data[i]=l.data[i+1];
	}
	l.length--;
	return 1;
}


void a_union_b(sqlist &a,sqlist b)
{
	int len_a=a.length;
	int len_b=b.length;
	for(int i=0;i<len_b;i++)
	{
		int f=0;
		for(int j=0;j<len_a;j++)
		{
			if(a.data[j]==b.data[i])
			{
				f=1;
			}
		}
		if(f==0)
		{
			listinsert(a,1,b.data[i]);
		}
	}
}

void mergelist(sqlist a,sqlist b,sqlist &c)
{
	int i=0;
	int j=0;
	int k=1;
	while(i<a.length && j<b.length)
	{
		if(a.data[i]<=b.data[j])
		{
			listinsert(c,k,a.data[i]);
			k++;
			i++;
		}
		else
		{
			listinsert(c,k,b.data[j]);
			j++;
			k++;
		}
	}
	while(i<a.length)
	{
		listinsert(c,k,a.data[i]);
		i++;
		k++;
	}
	while(j<b.length)
	{
		listinsert(c,k,b.data[j]);
		j++;
		k++;
	}
}
int main()
{
	sqlist l;
	sqlist q;
	sqlist c;
	initlist(c);
	initlist(q);
	initlist(l);
	listinsert(l,1,1);
	listinsert(l,2,2);
	listinsert(l,3,3);
	listinsert(q,1,4);
	listinsert(q,2,5);
	listinsert(q,3,6);
	mergelist(l,q,c);
	printlist(c);
    system("pause");
    return 0;
}
