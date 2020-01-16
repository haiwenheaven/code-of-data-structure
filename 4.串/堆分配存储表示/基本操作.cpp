#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char *ch;
    int length;
}hstring;
void strassign(hstring &s,char *c)
{
    if(s.ch)//释放s原有的空间
    {
        free(s.ch);
    }
    int n=0;//计算字符串常量的长度
    while(c[n])
    {
        n++;
    }
    s.length=n;
    if(!(s.ch=(char *)malloc(n*sizeof(char))))
    {
        return;
    }
    for(int i=0;i<n;i++)
    {
        s.ch[i]=c[i];
    }
}

void concat(hstring &S,hstring s1,hstring s2)
{
    if(S.ch)
    {
        free(S.ch);
    }
    S.length=s1.length+s2.length;
    S.ch=(char *)malloc(S.length*sizeof(char));
    int i=0;
    for(;i<s1.length;i++)
    {
        S.ch[i]=s1.ch[i];
    }
    for(i=0;i<s2.length;i++)
    {
        S.ch[s1.length+i]=s2.ch[i];
    }
}
void printstr(hstring s)
{
    for(int i=0;i<s.length;i++)
    {
        printf("%c ",s.ch[i]);
    }
}
int main(void)
{
    char c[5]={'f','f','f','f','f'};
    hstring s1;
    hstring s2;
    hstring S;
    strassign(s1,c);
    strassign(s2,c);
    concat(S,s1,s2);
    printstr(S);
    system("pause");
    return 0;
}