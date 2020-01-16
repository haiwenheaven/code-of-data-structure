#include<stdio.h>
#include<stdlib.h>
#define maxsize 30

typedef char sstring[maxsize+1];

sstring a={'a','a','c','a','b','a','a','b','a','a','b','c','a','c','a','a','b','c'};
//sstring b={'a','a','b','c','a','c'};
sstring b={'a','a','b','a','b','c'};
void nextj(sstring b,int *next)
{
    next[1]=0;
    int i=1;
    int j=0;
    while(i<b[0])
    {
        if(j==0 || b[i]==b[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }

    }
}
int kmp(sstring a,sstring b)
{
    int next[b[0]+1];
    nextj(b,next);
    int i=1;
    int j=1;
    while(i<=a[0] && j<=b[0])
    {
        if(j==0 || a[i]==b[j])
        {
            j++;
            i++;
        }
        else//a[i]一直不等于b[j]j就一直回退，直到j等于0，i和j都往后移一位
        {
            j=next[j];
        }
    }
    if(j>b[0])
        return i-b[0];
    else
        return 0;
}

int main()
{
    //a[0]=17;
    b[0]=5;
    int next[10];
    nextj(b,next);

    //printf("%d",kmp(a,b));
    system("pause");
    return 0;
}