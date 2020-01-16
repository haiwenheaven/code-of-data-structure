#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct
{
    int data;
    int cur;
} component, slinklist[maxsize];
void init(slinklist &s)//将可用的下标串起来 
{
	for(int i=0;i<maxsize-1;i++)
	{
		s[i].cur=i+1;
	}
	s[maxsize-1].cur=0;//最后一个指向0 
}
int malloclist(slinklist &s)//取出第一个可用的下标 
{
	int i=s[0].cur;//s[0]相当于可用下标的头节点，不用于存数据 
	if(i!=0)
	{
		s[0].cur=s[i].cur;
	}
	return i; 
}
void freelist(slinklist &s,int k)//将下标k加入到可用下标链表里 
{
	s[k].cur=s[0].cur;
	s[0].cur=k; 
}
void print(slinklist space,int s)//在space空间中头结点为t的链表 
{
	while(space[s].cur!=0)
	{
		printf("%d",space[space[s].cur].data);
		s=space[s].cur;
	}
}
void deletenode(slinklist &space,int s,int k)//删除space空间以s为头结点的链表的第k个结点 
{
	
}
void insertnode(slinklist &space,int s,int x,int k)//在space空间以s为头结点的链表的第k个位置插入一个结点 
{
	
} 
int main()
{
	int temp;
	int j;
    slinklist space;
    init(space);
    int s=malloclist(space);
    printf("%d\n",s);
    int r=s;
	for(int i=0;i<3;i++)
	{
		scanf("%d",&temp);
		j=malloclist(space);
		space[j].data=temp;
		space[r].cur=j;
		r=j;
	}
	space[r].cur=0;
	
	print(space,s);
	printf("\n%d",s);
    return 0;
}
