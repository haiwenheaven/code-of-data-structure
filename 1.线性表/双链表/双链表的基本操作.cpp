#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode *prior, *next;
} dnode, *dlinklist;

void init_dlinklist(dlinklist &l, int n)
{
    int x;
    dlinklist p;
    l = (dlinklist)malloc(sizeof(dnode));
    l->prior = NULL;
    l->next = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        p = (dlinklist)malloc(sizeof(dnode));
        p->data = x;
        p->next = l->next;
        if (l->next != NULL)
        {
            l->next->prior = p;
        }
        l->next = p;
        p->prior = l;
    }
}
void insert_dlinklist(dlinklist &l, int position, int x)
{
    dlinklist s;
    dlinklist p;
    s = l;
    for (int i = 0; i < position; i++)
    {
        s = s->next;
    }
    p = (dlinklist)malloc(sizeof(dnode));
    p->data = x;
    s->prior->next = p;
    p->prior = s->prior;
    p->next = s;
    s->prior = p;
}
void print_dlinklist(dlinklist l)
{
    l = l->next;
    while (l != NULL)
    {
        printf("%d", l->data);
        l = l->next;
    }
}
void delete_dlinklist(dlinklist &l, int position)
{
    dlinklist s;
    s = l;
    for (int i = 0; i < position; i++)
    {
        s = s->next;
    }
    s->prior->next = s->next;
    s->next->prior = s->prior;
    free(s);
}
int main()
{
    dlinklist l;
    init_dlinklist(l, 5);
    insert_dlinklist(l, 1, 1);
    delete_dlinklist(l, 1);
    print_dlinklist(l);
    system("pause");
    return 0;
}
