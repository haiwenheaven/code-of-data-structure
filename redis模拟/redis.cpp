#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

//ÿһ�����򼯺϶������νṹ�洢 
typedef struct treenode
{
	int fenshu;
	char *value;
	int valuelength;
	int height;
	struct treenode *left,*right;
	
}treenode,*tree;

//���е����򼯺ϴ���һ������ 
typedef struct sset
{
	char *key;
	int keylength;
	tree t;
	struct sset *next;
}sset,*linkset;


/*�洢key�õ����ݽṹ��Ϊ�˼�ѡ���˵�����*/ 
typedef struct node
{
	char *key;
	int keylength;
	char *value;
	int valuelength;
	struct node *next;
}node,*linklist;

//��һ��ȫ�ֵĹؼ������� 
//�ٽ���һ��ȫ�ֵļ������� 
linklist l;
linkset s;


//������������û���������� 
char mima[6]={'1','2','3','4','5','6'};

//�������û���������� 
char shurudemima[maxsize];

//����������� 
char mingling[maxsize];

//������ָ�ɵ��ʵ��±� 
int fenlixiabiao[maxsize];

//����ĳ��� 
int minglingchangdu;

//���ʵĳ���
int dancichangdu; 

//�����õ��û���������� 
void shoujimingling()
{
	minglingchangdu=0;
	scanf("%c",&mingling[minglingchangdu]);
	
	//��������ֱ���س� 
	while((int)mingling[minglingchangdu] != 10)
	{
		minglingchangdu++;
		scanf("%c",&mingling[minglingchangdu]);
	}
}


//��½ 
void yanzheng()
{
	printf("passwd:");
	int length;
	int flag;
	
	//��֤����ֱ���û�������ȷ 
	while(1)
	{
		length=0;
		scanf("%c",&shurudemima[length]);
		while((int)shurudemima[length] != 10)
		{
			length++;
			scanf("%c",&shurudemima[length]);
		}
		if(length==6)
		{
			flag=0;
			for(int i=0;i<6;i++)
			{
				if(mima[i]!=shurudemima[i])
				{
					flag=1;
				}
			}
			if(flag==0)
			{
				system("cls");
				return;
			}
		}
		system("cls");
		printf("wrong passwd\n");
		printf("try agin:");
	}
}

//���û����������ֳ�һ��һ���ĵ��� 
void fenli()
{
	dancichangdu=0;
	int i;
	for(i=0;i<minglingchangdu;i++)
	{
		
		//����һ���ַ��ǵ�����ʱ������������пո� 
		if((int)mingling[i] != 32)
		{
			if((int)mingling[i]==39)
			{
				fenlixiabiao[dancichangdu]=i;
				dancichangdu++;
				i++;
				while(i<minglingchangdu && (int)mingling[i] != 39)
				{
					i++;
				}
				fenlixiabiao[dancichangdu]=i;
				dancichangdu++;
			}
			else
			{
				fenlixiabiao[dancichangdu]=i;
				dancichangdu++;
				while(i<minglingchangdu && mingling[i]!= ' ')
				{
					i++;
				}
				fenlixiabiao[dancichangdu]=i-1;
				dancichangdu++;
			}
		}
	}
}


//set key value
// ��key�Ѿ�����ʱ����
//��key������ʱ�½�һ�� 
void set()
{
	if(dancichangdu!=6)
	{
		printf("syntax error");
		return;
	}
	if((int)mingling[fenlixiabiao[2]] == 39)
	{
		printf("syntax error");
		return;
	}
	if((int)mingling[fenlixiabiao[4]] != 39 || (int)mingling[fenlixiabiao[5]] != 39 )
	{
		printf("syntax error");
		return;
	}
	int j;
	
	
	//������ظ��ģ��򸲸� 
	j=0;
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist p=l->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;;
				}
			}
			//�ҵ��ظ����� 
			if(flag==0)
			{
				int xindechangdu=fenlixiabiao[5]-fenlixiabiao[4]+1;
				p->valuelength=xindechangdu;
				free(p->value);
				p->value=(char*)malloc(sizeof(char)*xindechangdu);
				for(int i=fenlixiabiao[4];i<=fenlixiabiao[5];i++)
				{
					(p->value)[j]=mingling[i];
					j++;
				}
				printf("ok");
				return;
			}
		}
		p=p->next;
	}
	
	
	//��key��ֵ 
	j=0;
	linklist temp=(linklist)malloc(sizeof(node));
	temp->next=l->next;
	l->next=temp;
	//int jianchang=fenlixiabiao[3]-fenlixiabiao[2]+1;
	temp->keylength=jianchang;
	temp->key=(char*)malloc(sizeof(char)*jianchang);
	for(int i=fenlixiabiao[2];i<=fenlixiabiao[3];i++)
	{
		(temp->key)[j]=mingling[i];
		j++;
	}
	
	
	//��value��ֵ 
	j=0;
	int zhichang=fenlixiabiao[5]-fenlixiabiao[4]+1;
	temp->valuelength=zhichang;
	temp->value=(char*)malloc(sizeof(char)*zhichang);
	for(int i=fenlixiabiao[4];i<=fenlixiabiao[5];i++)
	{
		(temp->value)[j]=mingling[i];
		j++;
	}
	printf("ok");
}


//get key
//�������key��value
// ��������ڣ�����null 
void get()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist p=l->next;
	
	//whileѭ�������Ƿ�������key 
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;;
				}
			}
			
			//�ҵ��ˣ����value 
			if(flag==0)
			{
				for(int i=0;i<p->valuelength;i++)
				{
					printf("%c",(p->value)[i]);
				}
				return;
			}
		}
		p=p->next;
	}
	printf("null");
}


//exists key 
//�ж�һ��key�Ƿ����
//���ڷ���1�������ڷ���0 
void exists()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist p=l->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("(int) 1"); 
				return;
			}
		}
		p=p->next;
	}
	printf("(int) 0");
}


//del key
//ɾ��һ��key
//���ڷ���1����������ڵĻ�����0 
void del()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist qian=l;
	linklist p=l->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;;
				}
			}
			if(flag==0)
			{
				qian->next=p->next;
				free(p);
				printf("(int) 1");
				return;
			}
		}
		p=p->next;
		qian=qian->next;
	}
	printf("(int) 0");
}


//rename oldkey newkey
//��������һ��key������������ж�newkey�Ƿ����
//newkey�����ھ�ֱ�Ӹ�
//newkey ���ھͰ�oldkeyɾ�� 
//��������ڷ��ش��� 
void rename()
{
	if(dancichangdu!=6)
	{
		printf("syntax error");
		return;	
	}
	
	int j;
	int flag;
	int jiujianchang=fenlixiabiao[3]-fenlixiabiao[2]+1;
	int xinjianchang=fenlixiabiao[5]-fenlixiabiao[4]+1;
	
	//�жϾɵ�key�Ƿ����
	linklist qian=l;
	linklist p=l->next;
	linklist q; 
	while(p)
	{
		if(p->keylength==jiujianchang)
		{
			flag=0;
			for(int i=0;i<jiujianchang;i++)
			{
				if((p->key)[i]!=mingling[fenlixiabiao[2]+i])
				{
					flag=1;
					break;
				}
			}
			//�ɵ�key���ڡ�
			//�������ж��µ�key�Ƿ���� 
			//��ʱpΪ��key��ָ��
			//qΪ��key��ָ�� 
			if(flag==0)
			{
				q=l->next;
				while(q)
				{
					if(q->keylength==xinjianchang)
					{
						flag=0;
						for(int i=0;i<xinjianchang;i++)
						{
							if((q->key)[i]!=mingling[fenlixiabiao[4]+i])
							{
								flag=1;
								break;
							}
						}
						//�µ�key���� 
						if(flag==0)
						{
							qian->next=p->next;
							free(p);
							printf("ok");
							return;
						}
					}
					q=q->next;
				}
				//�µ�key������
				//�ɵ�key����ֱ�Ӹ�
				//��֮ǰ�����key�Ƿ���Ϲ淶 
				if((int)mingling[fenlixiabiao[4]]==39)
				{
					printf("syntax error");
					return;
				}
				j=0;
				p->keylength=xinjianchang;
				free(p->key);
				p->key=(char*)malloc(sizeof(char)*xinjianchang);
				for(int i=fenlixiabiao[4];i<=fenlixiabiao[5];i++)
				{
					(p->key)[j]=mingling[i];
					j++;
				}
				printf("ok");
				return;
			}
		}
		p=p->next;
		qian=qian->next;
	}
	
	//�ɵ�key������ 
	printf("(error) no such key"); 
}

//strlen key
//����ָ��key��value����
//û�ҵ�����0 
void strlen()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	//�ҵ����key���������ĳ���
	
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist p=l->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("%d",p->valuelength-2); 
				return;
			}
		}
		p=p->next;
	}
	printf("0");
	 
}


//�����е�key-value���
//���Ϊ�����null 
void all()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
	}
	int i,j;
	linklist p=l->next;
	if(p==NULL)
	{
		printf("null");
		return;	
	} 
	while(p)
	{
		for(i=0;i<p->keylength;i++)
		{
			printf("%c",(p->key)[i]);
		}
		printf("   ");
		for(j=0;j<p->valuelength;j++)
		{
			printf("%c",(p->value)[j]);
		}
		printf("\n");
		p=p->next;
	}
}


//�����е�key���浽�ļ� 
void save()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
		return;
	}
	int i;
	
	//�½�һ���ļ�ָ�� 
	FILE *fpwriter=fopen("stringcache.txt","w");
	
	//�����ʧ�ܱ��� 
	if(fpwriter==NULL)
	{
		printf("can not open file");
		return;
	}
	linklist p=l->next;
	while(p)
	{
		for(i=0;i<p->keylength;i++)
		{
			fprintf(fpwriter,"%c",(p->key)[i]);
		}
		fprintf(fpwriter," ");
		for(i=0;i<p->valuelength;i++)
		{
			fprintf(fpwriter,"%c",(p->value)[i]);
		}
		fprintf(fpwriter,"%c",10);
		p=p->next;
	}
	fclose(fpwriter);
	printf("ok");
}


//���� 
void cls()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
		return;
	}
	system("cls");
}


//���û�û��������ȷ������ʱ 
void wrongstatement()
{
	printf("syntax error");
}


//�˳� 
void tuichu()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
		return;
	}
	exit(0); 
}

//append key value
//���key���ھ���value�ĺ����ֵ
//��������ھ��൱��set 
void append()
{
	if(dancichangdu!=6 || (int)mingling[fenlixiabiao[2]]==39 || (int)mingling[fenlixiabiao[4]]!=39 || (int)mingling[fenlixiabiao[5]]!=39)
	{
		printf("syntax error");
		return;	
	}
	
	int j;
	int o; 
	
	
	//������ҵ��ˣ������ 
	j=0;
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist p=l->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;;
				}
			}
			
			//�ҵ��� 
			if(flag==0)
			{
				int xindechangdu=p->valuelength+fenlixiabiao[5]-fenlixiabiao[4]-1;
			
				
				//�ȴ���һ������ 
				char *xinde=(char*)malloc(sizeof(char)*xindechangdu);
				
				//��ԭ���Ĵ��ȥ 
				for(j=0;j<p->valuelength-1;j++)
				{
					xinde[j]=p->value[j];
				}
				
				//������ļӽ�ȥ
				
				for(o=fenlixiabiao[4]+1;o<=fenlixiabiao[5];o++)
				{
					xinde[j]=mingling[o];
					j++;
				}
				
				//Ȼ���޸����key-value
				 
				p->valuelength=xindechangdu;
				
				free(p->value);
				p->value=xinde; 
				
				printf("ok");
				return;
			}
		}
		p=p->next;
	}
	
	//û���ҵ���ֱ���½�һ��key-value 


	//��key��ֵ 
	j=0;
	linklist temp=(linklist)malloc(sizeof(node));
	temp->next=l->next;
	l->next=temp;
	//int jianchang=fenlixiabiao[3]-fenlixiabiao[2]+1;
	temp->keylength=jianchang;
	temp->key=(char*)malloc(sizeof(char)*jianchang);
	for(int i=fenlixiabiao[2];i<=fenlixiabiao[3];i++)
	{
		(temp->key)[j]=mingling[i];
		j++;
	}
	
	
	//��value��ֵ 
	j=0;
	int zhichang=fenlixiabiao[5]-fenlixiabiao[4]+1;
	temp->valuelength=zhichang;
	temp->value=(char*)malloc(sizeof(char)*zhichang);
	for(int i=fenlixiabiao[4];i<=fenlixiabiao[5];i++)
	{
		(temp->value)[j]=mingling[i];
		j++;
	}
	printf("ok");
}

//�ж�һ��char�Ƿ����ת����int 
//�ܾͷ���1
//���ܾͷ���0 
int isint(char c)
{
	int res;
	if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
	{
		res=1;
	}
	else
	{
		res=0;
	}
	return res;
}


//����������û������������ض���ת����int����
//ֻ������һ�γ���0������ 
//���ж���һ�����Ƿ�������ֵ�Ҫ��
//��������Ϸ��� -1 
//mingling[x]-mingling[y] 
int charzhuanint(int x,int y)
{
	//�ȼ���Ƿ�Ϻ���׼ 
	for(int i=x;i<=y;i++)
	{
		if(isint(mingling[i])==0)
		{
			return -1;
		}
	}
	
	//Ȼ��ʼת�� 
	int quan=1;
	int res=0;
	while(y>=x)
	{
		res+=((int)mingling[y]-48)*quan;
		y--;
		quan*=10;
	}
	return res;
}


//getrange key start end 
//����һ���Ӵ�
// GETRANGE ͨ����֤���ַ�����ֵ��(range)������ʵ���ַ�����ֵ������������Χ��ֵ������

void getrange()
{
	//�������﷨Ҫ�� 
	 if(dancichangdu!=8)
	 {
	 	printf("syntax error");
	 	return;
	 }
	 //�������key 
	int flag;
	int start;
	int end;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linklist p=l->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				start=charzhuanint(fenlixiabiao[4],fenlixiabiao[5]);
				end=charzhuanint(fenlixiabiao[6],fenlixiabiao[7]);
				
				//����Ĳ���0������ 
				 
				if(start==-1 || end==-1)
				{
					printf("syntax error");
					return;	
				}	
				
				//�������0�����������ǲ��������Χ�� 
				
				 if(start>p->valuelength || start>end)
				 {
				 	printf("syntax error");
					return;
				 }
				 for(int i=start;i<=end;i++)
				 {
				 	if(i>=p->valuelength-1)
				 	{
				 		break;
					}
					else
					{
						printf("%c",(p->value)[i]);
					}
				 }
				
				return;
			}
		}
		p=p->next;
	}
	
	printf("no such key");
}


//newlset listname
//������list�Ѿ����ڣ����� 
void newset()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	if((int)mingling[fenlixiabiao[2]]==39)
	{
		printf("syntax error");
		return;
	}
	
	//���ж���û�����list 
	
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linkset p=s->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("already exists"); 
				return;
			}
		}
		p=p->next;
	}
	
	//������ 
	
	linkset temp=(linkset)malloc(sizeof(sset));
	temp->next=s->next;
	s->next=temp;
	temp->key=(char*)malloc(sizeof(char)*jianchang);
	temp->keylength=jianchang;
	temp->t=NULL;
	for(int i=0;i<jianchang;i++)
	{
		(temp->key)[i]=mingling[fenlixiabiao[2]+i];	
	}
	
	printf("ok");
	
}


//dellist listname
//���û�������ͷ���0
 
void dellist()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	
	//
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linkset p=s->next;
	linkset qian=s;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				qian->next=p->next;
				free(p);
				printf("ok");
				return;
			}
		}
		p=p->next;
		qian=qian->next;
	}
	printf("has no this set"); 
}


//alllist
//�����е����򼯺ϵ������г��� 
void alllist()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
		return;	
	}
	if(s->next==NULL)
	{
		printf("null");
		return;
	}
	linkset p=s->next;
	while(p)
	{
		for(int i=0;i<p->keylength;i++)
		{
			printf("%c",(p->key)[i]);
		}
		printf("\n");
		p=p->next;
	}
}


//��������һ�����򼯺� 
void bianli(tree t)
{
	if(t!=NULL)
    {
        bianli(t->left);
        for(int i=1;i<t->valuelength-1;i++)
        {
        	printf("%c",t->value[i]);
		}
		printf("  %d  ",t->fenshu);
		printf("\n");
        bianli(t->right);
    }
}


//�����򼯺��в���һ����� 
void charu(tree &t,tree xin)
{
	if(t==NULL)
	{
		t=xin;
	}
	else if(t!=NULL)
    {
        if(t->fenshu > xin->fenshu)
        {
            charu(t->left,xin);
        }
        else if(t->fenshu < xin->fenshu)
        {
            charu(t->right,xin);
        }
        else if(t->fenshu==xin->fenshu)
        {
            return;
        }
    }
}



//�ҵ�Ҫɾ���ĵ� 
void  FindNode(tree &p,tree &del,tree &father, int e)
{
    while(1)                                                                  
    {
        if(e<p->fenshu)
        { 
            father=p;//ÿ�ζ���¼һ�¸���
            p=p->left;
        }
        else if(e>p->fenshu)
        {
            father=p;
            p=p->right;
        }
        else if(e==p->fenshu)
        {
            del=p;return ;
        }
    }
}


//ɾ��һ����� 
void shanchu(tree p,int fenshu)
{
	if(p==NULL) return ;
    tree root=p;
    tree del=NULL;
    tree father=NULL;
    tree pmark=NULL;
    FindNode(root,del,father,fenshu);
    if(del->left&&del->right)
    {
        pmark=del;//���Ҫɾ���ĵ�
        father=del;
        del=del->left;
        while(del->right)
        {
            father=del;
            del=del->right;
        }
        pmark->fenshu=del->fenshu;
    }
    //������������һ������û�к��ӵ����
    //��ɾ�ڵ� �Ǹ�
    if(father==NULL)//??
    {
        p=del->left?del->left:del->right;
        free(del);
        return ;
    }
    else
    {//������д�ж������ˣ��ߵ���˵������һ������û�к��ӣ�ֻ��Ҫ�ж����ıߵĺ��ӾͿ�
        if(del==father->left)
            father->left=del->left?del->left:del->right;
        else if(del==father->right)
            father->right=del->left?del->left:del->right;
        free(del);
 
    }
}


//��ѯһ����� 
void chaxun(tree t,int x)
{
	
	while(t!=NULL)
    {
        if(x<t->fenshu)
        {
        	t=t->left;
		}
		else if(x>t->fenshu)
		{
			t=t->right;
		}
		else
		{
			for(int i=0;i<t->valuelength;i++)
			{
				printf("%c",t->value[i]);
			}
			return;
		}
    }
    printf("no data");
}

//push listname value number
//����������ͬ��value������������ͬ��number
//���û�����list���½�һ�� 
void push()
{
	//����﷨����
	//1.listname�����С�
	//2.valueһ��Ҫ�С�
	//3.һ��Ҫ��4������ 
	if(dancichangdu!=8)
	{
		printf("syntax error");
		return;	
	}
	if((int)mingling[fenlixiabiao[2]]==39)
	{
		printf("syntax error");
		return;
	}
	if((int)mingling[fenlixiabiao[4]]!=39)
	{
		printf("syntax error");
		return;
	}
	
	//�ҵ����listset
	
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linkset p=s->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
			//�ҵ��ˣ���p->t���в������ 
			if(flag==0)
			{
				int number=charzhuanint(fenlixiabiao[6],fenlixiabiao[7]);
				if(number==-1)
				{
					printf("syntax error");
					return;
				}
				
				//�½�����ʼ��һ������Ա���� 
				tree jiedian=(tree)malloc(sizeof(treenode));
				jiedian->fenshu=number;
				jiedian->valuelength=fenlixiabiao[5]-fenlixiabiao[4]+1;
				jiedian->left=NULL;
				jiedian->right=NULL;
				jiedian->value=(char*)malloc(sizeof(char)*(jiedian->valuelength));
				for(int i=0;i<jiedian->valuelength;i++)
				{
					(jiedian->value)[i]=mingling[fenlixiabiao[4]+i];
				}
				jiedian->height=0;
				charu(p->t,jiedian);
				printf("ok");
				return;
			}
		}
		p=p->next;
	}
	
	
	//û���ҵ� 
	printf("no such set");
	
	
}


// list set
//��һ�����ϵ�����Ԫ�ذ������
 
void list()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	
	if((int)mingling[fenlixiabiao[2]]==39)
	{
		printf("syntax error");
		return;
	}
	
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linkset p=s->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}
 
			if(flag==0)
			{
				if(p->t==NULL)
				{
					return;
				}
				bianli(p->t);
				return;
			}
		}
		p=p->next;
	}
	
	
	//û���ҵ�
	printf("no such set");
	
}

//pop luo fenshu
//ɾ��һ����� 
void pop()
{
	
	if(dancichangdu!=6)
	{
		printf("syntax error");
		return;
	}
	if((int)mingling[fenlixiabiao[2]]==39)
	{
		printf("syntax error");
		return;
	}
	
	
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linkset p=s->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}

			if(flag==0)
			{
				int number=charzhuanint(fenlixiabiao[4],fenlixiabiao[5]);
				if(number==-1)
				{
					printf("syntax error");
					return;
				}
				
				shanchu(p->t,number);
				if(p->t==NULL)
				{
					free(p->t);
				}
				printf("ok");
				return;
			}
		}
		p=p->next;
	}
	
	
	//û���ҵ�
	printf("no such set");
	
}


//search luo 12
//��Ҫ�����һ����� 
void search()
{
	if(dancichangdu!=6)
	{
		printf("syntax error");
		return;
	}
	if((int)mingling[fenlixiabiao[2]]==39)
	{
		printf("syntax error");
		return;
	}
	
	
	int flag;
	int tou=fenlixiabiao[2];
	int wei=fenlixiabiao[3];
	int jianchang=wei-tou+1;
	linkset p=s->next;
	while(p)
	{
		if(p->keylength==jianchang)
		{
			flag=0;
			for(int i=0;i<jianchang;i++)
			{
				if((p->key)[i]!=mingling[tou+i])
				{
					flag=1;
					break;
				}
			}

			if(flag==0)
			{
				int number=charzhuanint(fenlixiabiao[4],fenlixiabiao[5]);
				if(number==-1)
				{
					printf("syntax error");
					return;
				}
				
				chaxun(p->t,number);
				return;
			}
		}
		p=p->next;
	}
	
	
	//û���ҵ�
	printf("no such set");
	
}

//���ݵ�һ�����ʾ���������һ������ 
void diaoyongnagehanshu()
{
	int tou=fenlixiabiao[0];
	int wei=fenlixiabiao[1];
	int cha=wei-tou+1;
	if(dancichangdu==0)//�������Ϊ��ֱ�ӷ��أ� 
	{
		return;
	}
	
	if(cha==3 && mingling[tou]=='s' && mingling[tou+1]=='e' && mingling[tou+2]=='t')
	{
		set();
	}
	else if(cha==3 && mingling[tou]=='g' && mingling[tou+1]=='e' && mingling[tou+2]=='t')
	{
		get();
	}
	
	else if(cha==6 && mingling[tou]=='e' && mingling[tou+1]=='x' && mingling[tou+2]=='i' && mingling[tou+3]=='s' && mingling[tou+4]=='t' && mingling[tou+5]=='s')
	{
		exists();
	}
	else if(cha==3 && mingling[tou]=='d' && mingling[tou+1]=='e' && mingling[tou+2]=='l')
	{
		del();
	}
	else if(cha==6 && mingling[tou]=='r' && mingling[tou+1]=='e' && mingling[tou+2]=='n' && mingling[tou+3]=='a' && mingling[tou+4]=='m' && mingling[tou+5]=='e')
	{
		rename();
	}
	else if(cha==3 && mingling[tou]=='a' && mingling[tou+1]=='l' && mingling[tou+2]=='l')
	{
		all();
	}
	else if(cha==6 && mingling[tou]=='s' && mingling[tou+1]=='t' && mingling[tou+2]=='r' && mingling[tou+3]=='l' && mingling[tou+4]=='e' && mingling[tou+5]=='n')
	{
		strlen();
	}
	else if(cha==4 && mingling[tou]=='s' && mingling[tou+1]=='a' && mingling[tou+2]=='v' && mingling[tou+3]=='e')
	{
		save();
	}
	else if(cha==3 && mingling[tou]=='c' && mingling[tou+1]=='l' && mingling[tou+2]=='s')
	{
		cls();
	}
	else if(cha==4 && mingling[tou]=='e' && mingling[tou+1]=='x' && mingling[tou+2]=='i' && mingling[tou+3]=='t')
	{
		tuichu();
	}
	else if(cha==6 && mingling[tou]=='a' && mingling[tou+1]=='p' && mingling[tou+2]=='p' && mingling[tou+3]=='e' && mingling[tou+4]=='n' && mingling[tou+5]=='d')
	{
		append();
	}
	else if(cha==8 && mingling[tou]=='g' && mingling[tou+1]=='e' && mingling[tou+2]=='t' && mingling[tou+3]=='r' && mingling[tou+4]=='a' && mingling[tou+5]=='n' && mingling[tou+6]=='g' && mingling[tou+7]=='e')
	{
		getrange();
	}
	else if(cha==6 && mingling[tou]=='n' && mingling[tou+1]=='e' && mingling[tou+2]=='w' && mingling[tou+3]=='s' && mingling[tou+4]=='e' && mingling[tou+5]=='t')
	{
		newset();
	}
	else if(cha==7 && mingling[tou]=='d' && mingling[tou+1]=='e' && mingling[tou+2]=='l' && mingling[tou+3]=='l' && mingling[tou+4]=='i' && mingling[tou+5]=='s' && mingling[tou+6]=='t')
	{
		dellist();
	}
	else if(cha==7 && mingling[tou]=='a' && mingling[tou+1]=='l' && mingling[tou+2]=='l' && mingling[tou+3]=='l' && mingling[tou+4]=='i' && mingling[tou+5]=='s' && mingling[tou+6]=='t')
	{
		alllist();
	}
	else if(cha==4 && mingling[tou]=='p' && mingling[tou+1]=='u' && mingling[tou+2]=='s' && mingling[tou+3]=='h')
	{
		push();
	}
	else if(cha==4 && mingling[tou]=='l' && mingling[tou+1]=='i' && mingling[tou+2]=='s' && mingling[tou+3]=='t')
	{
		list();
	}
	else if(cha==3 && mingling[tou]=='p' && mingling[tou+1]=='o' && mingling[tou+2]=='p')
	{
		pop();
	}
	else if(cha==6 && mingling[tou]=='s' && mingling[tou+1]=='e' && mingling[tou+2]=='a' && mingling[tou+3]=='r' && mingling[tou+4]=='c' && mingling[tou+5]=='h')
	{
		search();
	}
	else
	{
		wrongstatement();
	}
}

//��ʼ��key���� 
void initlist()
{
	l=(linklist)malloc(sizeof(node));
	l->next=NULL;
}

//��ʼ���������� 
void initsetlist()
{
	s=(linkset)malloc(sizeof(sset));
	s->next=NULL;
}


//�����exe�ļ��ĵ�һ�����ǰ��ļ��е����ݳ�ʼ����key���� 
void duwenjian()
{
	char v[100];
	int j;
	int i;

	FILE *fp;
	fp = fopen("stringcache.txt", "r");
	
	while(fscanf(fp, "%s", &v) != EOF)
	{
			linklist temp=(linklist)malloc(sizeof(node));
			temp->next=l->next;
			l->next=temp;
			
			j=0;
			while(v[j])
			{
				j++;
			}
			temp->keylength=j;
			temp->key=(char*)malloc(sizeof(char)*j);
			for(i=0;i<j;i++)
			{
				(temp->key)[i]=v[i];
			}
			
			fscanf(fp, "%s", &v);
			j=0;
			while(v[j])
			{
				j++;
			}
			temp->valuelength=j;
			temp->value=(char*)malloc(sizeof(char)*j);
			for(i=0;i<j;i++)
			{
				(temp->value)[i]=v[i];
			}
	}	
	fclose(fp);
}
int main()
{
	//��֤����
	yanzheng();
	
	//�Ѷ����ļ��е����� 
	initlist();
	duwenjian();
	
	initsetlist(); 
	
	//��ӭ���� 
	printf("                                                        _._\n");
	printf("                                                   _.-``__ ''-._\n");
	printf("                                               _.-``    `.  `_.  ''-._\n");
	printf("                                           .-`` .-```.  ```\/    _.,_ ''-._\n");
	printf("                                          (    '      ,       .-`  | `,    )\n");
	printf("                                          |`-._`-...-` __...-.``-._|'` _.-'|\n");
	printf("                                          |    `-._   `._    /     _.-'    |\n");
	printf("                                           `-._    `-._  `-./  _.-'    _.-'\n");
	printf("                                          |`-._`-._    `-.__.-'    _.-'_.-'|\n");
	printf("                                          |    `-._`-._        _.-'_.-'    |\n");
	printf("                                           `-._    `-._`-.__.-'_.-'    _.-'\n");
	printf("                                          |`-._`-._    `-.__.-'    _.-'_.-'|\n");
	printf("                                          |    `-._`-._        _.-'_.-'    |\n");
	printf("                                           `-._    `-._`-.__.-'_.-'    _.-'\n");
	printf("                                               `-._    `-.__.-'    _.-'\n");
	printf("                                                   `-._        _.-'\n");
	printf("                                                       `-.__.-'\n");
	
	//��ʼ�������� 
	while(1)
	{
		printf(">>");
		shoujimingling();
		fenli();
		diaoyongnagehanshu();
		printf("\n");
	}
	return 0;	
} 
 
