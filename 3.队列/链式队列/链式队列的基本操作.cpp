#include <stdio.h>
#include <stdlib.h>

typedef struct linknode
{
    int data;
    struct linknode *next;
} linknode, *linklist;

typedef struct
{
    linknode *front, *rear;
} linkqueue;
void init_linkqueue(linkqueue &q)
{
    q.front = q.rear = (linknode *)malloc(sizeof(linknode));
    q.front->next = NULL;
}
void enqueue(linkqueue &q, int x)
{
    linknode *s;
    s = (linknode *)malloc(sizeof(linknode));
    s->data = x;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
}
int dequeue(linkqueue &q)
{
    if (q.front == q.rear)
    {
        return 0;
    }

    else
    {
        linknode *s;
        s = (linknode *)malloc(sizeof(linknode));
        s = q.front;
        int x;
        x = s->next->data;
        q.front = s->next;
        free(s);
        return x;
    }
}
bool isempty(linkqueue q)
{
    if (q.front == q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    linkqueue q;
    init_linkqueue(q);
    enqueue(q, 1);
    int x;
    x = dequeue(q);
    printf("%d\n", x);
    if (isempty(q))
    {
        printf("d");
    }
    system("pause");
    return 0;
}