int Sequential_Search(int *a,int n,int key)
{
    int i;
    a[0]=key; //����a[0]Ϊ�ؼ���ֵ����Ϊ�ڱ�
    i=n;      //ѭ��������β����ʼ
    while(a[i]!=key) 
    {
        i--;
    }
    return i;//����0��˵������ʧ��
}
