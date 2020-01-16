#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

typedef char sstring[maxsize+1];

sstring a={'a','a','b','a','b','c','a','b','c','a','c','b','a','b'};
sstring b={'a','a','b','c','a','c'};

int index(sstring a,sstring b)
{
    int j;
    for(int i=1;i<a[0]-b[0]+2;i++)
    {
        j=1;
        while(1)
        {
            if(j>b[0])
            {
                return i;
            }
            else
            {
                if(a[i+j-1]!=b[j])
                {
                    break;
                }
            }
            j++;
        }

    }
    return 0;
}
int main()
{
    a[0]=13;
    b[0]=5;
    int x=index(a,b);
    printf("%d",x);
    system("pause");
    return 0;
}