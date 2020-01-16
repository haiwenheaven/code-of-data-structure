#include<stdio.h>
//索引表
typedef struct
{
int key;
int address;
}IdxTable;
typedef IdxTable indxtable[3];
//所有节点信息表
typedef struct
{
int key;
}NodeTable;
typedef NodeTable nodetable[18];
//二分查找
int IndxSearch_erfen(indxtable idx,int m,int key1)
{
int left=0,right=m-1,mid;
 
while(left<=right)
{
mid=(left+right)/2;
if(idx[mid].key>=key1&&idx[mid-1].key<key1)
{
return idx[mid].address;
}
else if(idx[mid].key<key1)
left=mid+1;
else if(idx[mid].key>key1)
right=mid-1;
}
}
//顺序查找
int IndxSearch_shunxu(int n,int m,int key1,indxtable idx,nodetable r)
{
//int b=n/m//每块的个数
int b=n/m,i=IndxSearch_erfen(idx,m,key1);
printf("在索引表的起始地址：%d\n",i);
int data_n=i+b;//数据表起始位置到某块终点的长度
while(i<data_n&&r[i].key!=key1)
i++;
if(i>=data_n)
return -1;
else
return i;
}
void main()
{
nodetable r;
int k=38;
indxtable idx;
int a[]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53},i;
//数据表
for(i=0;i<18;i++)
r[i].key=a[i];
//索引表
idx[0].key=22;idx[0].address=0;
idx[1].key=48;idx[1].address=6;
idx[2].key=86;idx[2].address=12;
//查找结果
if((i=IndxSearch_shunxu(18,3,k,idx,r))!=-1)
printf("元素%d的位置是%d\n",k,i);
else
printf("元素%d不在表中",k);
}

