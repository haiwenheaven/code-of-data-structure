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

bool isempty(queue &q)
{
	if(q.front==q.rear)
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
	q.data[q.rear]=x;
	q.rear++;
}
int dequeue(queue &q)
{
	int x=q.data[q.front];
	q.front++;
	return x;
}
int main()
{
	int x;
	queue q;
	init_queue(q);
	enqueue(q,1);
	enqueue(q,2);
	x=dequeue(q);
	printf("%d",x);
    system("pause");
	return 0;
}