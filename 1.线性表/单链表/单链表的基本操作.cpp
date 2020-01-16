#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*linklist;
void creatlinklist(linklist &l,int i)
{
	int x;
	linklist p;
	l=(linklist)malloc(sizeof(lnode));
	l->next=NULL;
	for(int j=0;j<i;j++)
	{
		scanf("%d",&x);
		p=(linklist)malloc(sizeof(lnode));
		p->data=x;
		p->next=l->next;
		l->next=p;
	}
}
void creatlinklist_tail(linklist &l,int n)
{
	l=(linklist)malloc(sizeof(lnode));
	int x;
	linklist s,r;
	r=l;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		s=(linklist)malloc(sizeof(lnode));
		s->data=x;
		r->next=s;
		r=s;
	}
	r->next=NULL;
}
int printlinklist(linklist l)
{
	l=l->next;
	while(l!=NULL)
	{
		printf("%d",l->data);
		l=l->next;
	}
	return 1;
}
void getelement(linklist l,int i,int &e)
{
	int j=1;
	for(;j<=i;j++)
	{
		l=l->next;
		if(l==NULL)
		{
			break;
		}
	}
	if(j-1==i)
	{
		e=l->data;
	}
}
void linklistinsert(linklist &l,int n,int e)
{
	linklist s;
	s=(linklist)malloc(sizeof(lnode));
	s->data=e;
	linklist p;
	p=l;
	for(int i=0;i<n-1;i++)
	{
		p=p->next;
	}
	s->next=p->next;
	p->next=s;
}
void linklistdelete(linklist &l,int n)
{
	linklist p,r;
	p=l;
	for(int i=0;i<n-1;i++)
	{
		p=p->next;
	}
	r=p->next;
	p->next=r->next;
	free(r);
}
int linklistlength(linklist l)
{
	int x=0;
	while(l->next!=NULL)
	{
		l=l->next;
		x++;
	}
	return x;
}
int main()
{
	linklist l;
	creatlinklist(l,5);
	int x=linklistlength(l);
	printf("%d",x);
    system("pause");
	return 0;
}
