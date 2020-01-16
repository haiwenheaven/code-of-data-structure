#include<stdio.h>
#include<stdlib.h>

int mingroup(int a,int b)
{
    int min;
    if(a>b)
    {
        min=b;
    }
    if(a<b)
    {
        min=a;
    }
    if(a==b)
    {
        min=a;
    }
    return min;
}
int countBinarySubstrings(char* s) {
    int count=0;
    int length=0;
    int j=0;
    int group[1000000000000000];
    int temp;
    int min;
    while(s[length])
    {
        length++;
    }
    for(int i=0;i<length;i++)
    {
        temp=1;
        for(;temp<length-i;temp++)
        {
            if(s[i]!=s[i+temp])
            {
                break;
            }
        }
        i=i+temp-1;
        group[j]=temp;
        j++;
    }
    for(int i=0;i<j-1;i++)
    {
        min=mingroup(group[i],group[i+1]);
        if(min==1)
        {
            count+=1;
        }
        else if(min>1)
        {
            count=count+min;
        }
    }
    return count;
}
int main()
{
    char c[10]={''}
    system("pause");
    return 0;
}