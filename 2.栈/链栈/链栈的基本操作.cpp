#include<stdlib.h>
#include <stdio.h>

typedef struct linknode
{
	int data;
	struct linknode *next;
}*linkstack;
void init(linkstack &s)
{
	s=(linkstack)malloc(sizeof(linknode));
	s->next=NULL;
}
void push(linkstack &s,int x)
{
	linkstack temp;
	temp=(linkstack)malloc(sizeof(linknode));
	temp->data=x;
	temp->next=s->next;
	s->next=temp;
}
void pop(linkstack &s,int &x)
{
	x=s->next->data;
	linkstack temp;
	temp=s->next;
	s->next=s->next->next;
	free(temp);
}
void gettop(linkstack s,int &x)
{
	x=s->next->data;
}
int main(int argc, char const *argv[])
{
	linkstack s;
	init(s);
	push(s,1);
	push(s,5);
	int x;
	pop(s,x);
	printf("%d\n",x);
    system("pause");
	return 0;
}