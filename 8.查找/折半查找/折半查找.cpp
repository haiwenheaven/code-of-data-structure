int search(keytype key[],int n,keytype k)
{
 	int low=0,high=n-1,mid;
 	while(low<=high)
 	{
  		mid=(low+high)/2;
  		if(key[mid]==k)
   			return mid;	//���ҳɹ�������mid 
  		if(k>key[mid])
   			low=mid+1;	//�ں�������в��� 
  		else
   			high=mid-1;	//��ǰ�������в��� 
 	}
 	return -1;//����ʧ�ܣ�����-1 
}

