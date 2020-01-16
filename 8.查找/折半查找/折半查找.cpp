int search(keytype key[],int n,keytype k)
{
 	int low=0,high=n-1,mid;
 	while(low<=high)
 	{
  		mid=(low+high)/2;
  		if(key[mid]==k)
   			return mid;	//查找成功，返回mid 
  		if(k>key[mid])
   			low=mid+1;	//在后半序列中查找 
  		else
   			high=mid-1;	//在前半序列中查找 
 	}
 	return -1;//查找失败，返回-1 
}

