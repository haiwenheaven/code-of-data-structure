#include <stdio.h>
#include <stdlib.h>

#define maxsize 20

typedef struct
{
    int data[maxsize];
    int top;
} sqstack;

void init_sqstack(sqstack &s)//初始化栈
{
    s.top = -1;
}
void push(sqstack &s, int x)//入栈
{
    s.top++;
    s.data[s.top] = x;
}
void pop(sqstack &s, int &x)//出栈
{
    x = s.data[s.top];
    s.top--;
}
void gettop(sqstack s, int &x)//取得栈顶元素
{
    x = s.data[s.top];
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        i++;
        printf("%d\n", i);
    }
    system("pause");
    return 0;
}
