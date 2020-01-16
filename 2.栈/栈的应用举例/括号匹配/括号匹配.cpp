#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 20

typedef struct
{
    char data[maxsize];
    int top;
} sqstack;

void init_sqstack(sqstack &s)
{
    s.top = -1;
}
void push(sqstack &s, char x)
{
    s.top++;
    s.data[s.top] = x;
}
char pop(sqstack &s)
{
    char x;
    x = s.data[s.top];
    s.top--;
    return x;
}
char gettop(sqstack s)
{
    char x;
    x = s.data[s.top];
    return x;
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
bool match(char *s)
{
    int flag=0;//有没有错
    sqstack stack;
    init_sqstack(stack);
    for(int i=0;i<4;i++)
    {
        switch (s[i])
        {
            case '(':
                push(stack,'(');
                break;
            case '[':
                push(stack,'[');
                break;
            case '{':
                push(stack,'{');
                break;
            case ')':
                if(gettop(stack)=='(')
                {
                    pop(stack);
                }
                else
                {
                    flag=1;
                }
                break;
            case ']':
                if(gettop(stack)=='[')
                {
                    pop(stack);
                }
                else
                {
                    flag=1;
                }
                break;
            case '}':
                if(gettop(stack)=='{')
                {
                    pop(stack);
                }
                else
                {
                    flag=1;
                }
                break;
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    char a[4]={'(','(',')',']'};
    if(match(a))
    {
        printf("yes");
    }
    system("pause");
    return 0;
}