#include <stdio.h>
#include <stdlib.h>

#define maxsize 20

typedef struct
{
    int data[maxsize];
    int top;
} sqstack;

void init_sqstack(sqstack &s)
{
    s.top = -1;
}
void push(sqstack &s, int x)
{
    s.top++;
    s.data[s.top] = x;
}
void pop(sqstack &s, int &x)
{
    x = s.data[s.top];
    s.top--;
}
void gettop(sqstack s, int &x)
{
    x = s.data[s.top];
}
bool isempty(sqstack s)
{
    if(s.top==-1)
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
    sqstack s;
    init_sqstack(s);
    int x = 100;
    while(x!=0)
    {
        push(s,x%2);
        x=x/2;
    }
    int e;
    while(!isempty(s))
    {
        pop(s,e);
        printf("%d",e);
    }
    system("pause");
    return 0;
}