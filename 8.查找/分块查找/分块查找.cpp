#include<stdio.h>
//������
typedef struct
{
int key;
int address;
}IdxTable;
typedef IdxTable indxtable[3];
//���нڵ���Ϣ��
typedef struct
{
int key;
}NodeTable;
typedef NodeTable nodetable[18];
//���ֲ���
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
//˳�����
int IndxSearch_shunxu(int n,int m,int key1,indxtable idx,nodetable r)
{
//int b=n/m//ÿ��ĸ���
int b=n/m,i=IndxSearch_erfen(idx,m,key1);
printf("�����������ʼ��ַ��%d\n",i);
int data_n=i+b;//���ݱ���ʼλ�õ�ĳ���յ�ĳ���
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
//���ݱ�
for(i=0;i<18;i++)
r[i].key=a[i];
//������
idx[0].key=22;idx[0].address=0;
idx[1].key=48;idx[1].address=6;
idx[2].key=86;idx[2].address=12;
//���ҽ��
if((i=IndxSearch_shunxu(18,3,k,idx,r))!=-1)
printf("Ԫ��%d��λ����%d\n",k,i);
else
printf("Ԫ��%d���ڱ���",k);
}

