#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int coef;
    int exp;
    struct lnode *next;
} lnode, *linklist;

void creat_polynomial(linklist &l, int n) //Î²²å·¨
{
    l = (linklist)malloc(sizeof(lnode));
    int x;
    int y;
    linklist s, r;
    r = l;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        s = (linklist)malloc(sizeof(lnode));
        s->coef = x;
        s->exp = y;
        r->next = s;
        r = s; //rÎªÎ²Ö¸Õë
    }
    r->next = NULL;
}
void print_polynomial(linklist l) //Êä³ö¶àÏîÊ½
{
    l = l->next;
    while (l != NULL)
    {
        if (l->next == NULL)
        {
            printf("%dx^%d", l->coef, l->exp);
        }
        else
        {
            printf("%dx^%d+", l->coef, l->exp);
        }
        l = l->next;
    }
}
void addition_polynomial(linklist &a, linklist b) //°Ñ¶àÏîÊ½b¼Óµ½¶àÏîÊ½a
{
    linklist temp;
    temp = a;
    //prior_temp=a;
    b = b->next;
    while (temp->next != NULL && b != NULL)
    {
        if (temp->next->exp == b->exp)
        {
            temp->next->coef += b->coef;
            b = b->next;
            temp = temp->next;
        }
        else if (temp->next->exp > b->exp)
        {
            b->next = temp->next;
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
        else if (temp->exp < b->exp)
        {
            temp = temp->next;
        }
    }
    if (b != NULL)
    {
        temp->next = b;
    }
}
void multiplication_polynomial(linklist &a, linklist &b)
{
}
int main()
{
    linklist a;
    linklist b;
    printf("creat polynomial a:\n");
    creat_polynomial(a, 1);
    printf("creat polynomial b:\n");
    creat_polynomial(b, 2);
    multiplication_polynomial(a, b);
    printf("after addion:\n");
    print_polynomial(a);
    //print_polynomial(b);
    system("pause");
    return 0;
}
