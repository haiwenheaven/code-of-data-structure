#include <stdio.h>
#include <stdlib.h>

#define maxsize 50
typedef struct{
	int data[maxsize];
	int front;
	int rear;
}queue;

void init_queue(queue &q)
{
	q.front=q.rear=0;
}

bool isempty(queue q)
{
	if(q.rear==q.front)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isfull(queue q)
{
	if((q.rear+1)%maxsize==q.front)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enqueue(queue &q,int x)
{
	if(!isfull(q))
	{
		q.data[q.rear]=x;
		q.rear=(q.rear+1)%maxsize;
	}
	else
	{
		printf("the queue is full");
	}
}
int dequeue(queue &q)
{
	int x;
	if(q.rear==q.front)
	{
		return 0;
	}
	else
	{
		x=q.data[q.front];
		q.front=(q.front+1)%maxsize;
	}
	return x;
}
int main()
{
	queue q;
	init_queue(q);
	for(int i=0;i<51;i++)
	{
		enqueue(q,i);
	}
	enqueue(q,1);
	int x;
	x=dequeue(q);
	printf("%d",x);
    system("pause");
	return 0;
}