#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct
{
    int data;
    int cur;
} component, slinklist[maxsize];
void init(slinklist &s)//�����õ��±괮���� 
{
	for(int i=0;i<maxsize-1;i++)
	{
		s[i].cur=i+1;
	}
	s[maxsize-1].cur=0;//���һ��ָ��0 
}
int malloclist(slinklist &s)//ȡ����һ�����õ��±� 
{
	int i=s[0].cur;//s[0]�൱�ڿ����±��ͷ�ڵ㣬�����ڴ����� 
	if(i!=0)
	{
		s[0].cur=s[i].cur;
	}
	return i; 
}
void freelist(slinklist &s,int k)//���±�k���뵽�����±������� 
{
	s[k].cur=s[0].cur;
	s[0].cur=k; 
}
void print(slinklist space,int s)//��space�ռ���ͷ���Ϊt������ 
{
	while(space[s].cur!=0)
	{
		printf("%d",space[space[s].cur].data);
		s=space[s].cur;
	}
}
void deletenode(slinklist &space,int s,int k)//ɾ��space�ռ���sΪͷ��������ĵ�k����� 
{
	
}
void insertnode(slinklist &space,int s,int x,int k)//��space�ռ���sΪͷ��������ĵ�k��λ�ò���һ����� 
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
