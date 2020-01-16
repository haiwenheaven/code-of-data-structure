#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

//每一个有序集合都用树形结构存储 
typedef struct treenode
{
	int fenshu;
	char *value;
	int valuelength;
	int height;
	struct treenode *left,*right;
	
}treenode,*tree;

//所有的有序集合串成一个链表 
typedef struct sset
{
	char *key;
	int keylength;
	tree t;
	struct sset *next;
}sset,*linkset;


/*存储key用的数据结构，为了简单选择了单链表*/ 
typedef struct node
{
	char *key;
	int keylength;
	char *value;
	int valuelength;
	struct node *next;
}node,*linklist;

//建一个全局的关键字链表 
//再建立一个全局的集合链表 
linklist l;
linkset s;


//用来存密码和用户输入的密码 
char mima[6]={'1','2','3','4','5','6'};

//用来存用户输入的密码 
char shurudemima[maxsize];

//存命令的数组 
char mingling[maxsize];

//把命令分割成单词的下标 
int fenlixiabiao[maxsize];

//命令的长度 
int minglingchangdu;

//单词的长度
int dancichangdu; 

//用来得到用户输入的命令 
void shoujimingling()
{
	minglingchangdu=0;
	scanf("%c",&mingling[minglingchangdu]);
	
	//接受输入直到回车 
	while((int)mingling[minglingchangdu] != 10)
	{
		minglingchangdu++;
		scanf("%c",&mingling[minglingchangdu]);
	}
}


//登陆 
void yanzheng()
{
	printf("passwd:");
	int length;
	int flag;
	
	//验证密码直到用户输入正确 
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

//把用户输入的命令分成一个一个的单词 
void fenli()
{
	dancichangdu=0;
	int i;
	for(i=0;i<minglingchangdu;i++)
	{
		
		//当第一个字符是单引号时里面可以允许有空格 
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
// 当key已经存在时覆盖
//当key不存在时新建一个 
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
	
	
	//如果有重复的，则覆盖 
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
			//找到重复的了 
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
	
	
	//对key赋值 
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
	
	
	//对value赋值 
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
//返回这个key的value
// 如果不存在，返回null 
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
	
	//while循环查找是否存在这个key 
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
			
			//找到了，输出value 
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
//判断一个key是否存在
//存在返回1，不存在返回0 
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
//删除一个key
//存在返回1，如果不存在的话返回0 
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
//重新命名一个key，如果存在再判断newkey是否存在
//newkey不存在就直接改
//newkey 存在就把oldkey删除 
//如果不存在返回错误 
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
	
	//判断旧的key是否存在
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
			//旧的key存在。
			//接下来判断新的key是否存在 
			//此时p为旧key的指针
			//q为新key的指针 
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
						//新的key存在 
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
				//新的key不存在
				//旧的key可以直接改
				//改之前检查新key是否符合规范 
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
	
	//旧的key不存在 
	printf("(error) no such key"); 
}

//strlen key
//返回指定key的value长度
//没找到返回0 
void strlen()
{
	if(dancichangdu!=4)
	{
		printf("syntax error");
		return;
	}
	//找到这个key并返回他的长度
	
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


//把所有的key-value输出
//如果为空输出null 
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


//将所有的key保存到文件 
void save()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
		return;
	}
	int i;
	
	//新建一个文件指针 
	FILE *fpwriter=fopen("stringcache.txt","w");
	
	//如果打开失败报错 
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


//清屏 
void cls()
{
	if(dancichangdu!=2)
	{
		printf("syntax error");
		return;
	}
	system("cls");
}


//当用户没有输入正确的命令时 
void wrongstatement()
{
	printf("syntax error");
}


//退出 
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
//如果key存在就在value的后面加值
//如果不存在就相当于set 
void append()
{
	if(dancichangdu!=6 || (int)mingling[fenlixiabiao[2]]==39 || (int)mingling[fenlixiabiao[4]]!=39 || (int)mingling[fenlixiabiao[5]]!=39)
	{
		printf("syntax error");
		return;	
	}
	
	int j;
	int o; 
	
	
	//如果有找到了，则添加 
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
			
			//找到了 
			if(flag==0)
			{
				int xindechangdu=p->valuelength+fenlixiabiao[5]-fenlixiabiao[4]-1;
			
				
				//先创建一个数组 
				char *xinde=(char*)malloc(sizeof(char)*xindechangdu);
				
				//把原来的存进去 
				for(j=0;j<p->valuelength-1;j++)
				{
					xinde[j]=p->value[j];
				}
				
				//把输入的加进去
				
				for(o=fenlixiabiao[4]+1;o<=fenlixiabiao[5];o++)
				{
					xinde[j]=mingling[o];
					j++;
				}
				
				//然后修改这个key-value
				 
				p->valuelength=xindechangdu;
				
				free(p->value);
				p->value=xinde; 
				
				printf("ok");
				return;
			}
		}
		p=p->next;
	}
	
	//没有找到，直接新建一个key-value 


	//对key赋值 
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
	
	
	//对value赋值 
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

//判断一个char是否可以转化成int 
//能就返回1
//不能就返回0 
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


//这个函数把用户输入的命令的特定端转化成int类型
//只允许这一段出现0和正数 
//先判断这一段中是否符合数字的要求
//如果不符合返回 -1 
//mingling[x]-mingling[y] 
int charzhuanint(int x,int y)
{
	//先检查是否合乎标准 
	for(int i=x;i<=y;i++)
	{
		if(isint(mingling[i])==0)
		{
			return -1;
		}
	}
	
	//然后开始转换 
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
//返回一个子串
// GETRANGE 通过保证子字符串的值域(range)不超过实际字符串的值域来处理超出范围的值域请求。

void getrange()
{
	//不满足语法要求 
	 if(dancichangdu!=8)
	 {
	 	printf("syntax error");
	 	return;
	 }
	 //查找这个key 
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
				
				//输出的不是0和正数 
				 
				if(start==-1 || end==-1)
				{
					printf("syntax error");
					return;	
				}	
				
				//输入的是0和正数，但是不在这个范围内 
				
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
//如何这个list已经存在，报错 
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
	
	//先判断有没有这个list 
	
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
	
	//不存在 
	
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
//如果没有这个表就返回0
 
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
//把所有的有序集合的名字列出来 
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


//用来遍历一个有序集合 
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


//往有序集合中插入一个结点 
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



//找到要删除的点 
void  FindNode(tree &p,tree &del,tree &father, int e)
{
    while(1)                                                                  
    {
        if(e<p->fenshu)
        { 
            father=p;//每次都记录一下父亲
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


//删除一个结点 
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
        pmark=del;//标记要删除的点
        father=del;
        del=del->left;
        while(del->right)
        {
            father=del;
            del=del->right;
        }
        pmark->fenshu=del->fenshu;
    }
    //接下来分析有一个或者没有孩子的情况
    //被删节点 是根
    if(father==NULL)//??
    {
        p=del->left?del->left:del->right;
        free(del);
        return ;
    }
    else
    {//不用在写判断条件了，走到这说明就是一个或者没有孩子，只需要判断是哪边的孩子就可
        if(del==father->left)
            father->left=del->left?del->left:del->right;
        else if(del==father->right)
            father->right=del->left?del->left:del->right;
        free(del);
 
    }
}


//查询一个结点 
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
//不允许有相同的value，但允许有相同的number
//如果没有这个list就新建一个 
void push()
{
	//检查语法错误
	//1.listname不能有‘
	//2.value一定要有’
	//3.一定要有4个单词 
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
	
	//找到这个listset
	
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
			//找到了，对p->t进行插入操作 
			if(flag==0)
			{
				int number=charzhuanint(fenlixiabiao[6],fenlixiabiao[7]);
				if(number==-1)
				{
					printf("syntax error");
					return;
				}
				
				//新建并初始化一个结点以便插入 
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
	
	
	//没有找到 
	printf("no such set");
	
	
}


// list set
//把一个集合的所有元素按序输出
 
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
	
	
	//没有找到
	printf("no such set");
	
}

//pop luo fenshu
//删除一个结点 
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
	
	
	//没有找到
	printf("no such set");
	
}


//search luo 12
//按要求查找一个结点 
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
	
	
	//没有找到
	printf("no such set");
	
}

//根据第一个单词决定调用哪一个函数 
void diaoyongnagehanshu()
{
	int tou=fenlixiabiao[0];
	int wei=fenlixiabiao[1];
	int cha=wei-tou+1;
	if(dancichangdu==0)//如果命令为空直接返回； 
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

//初始化key链表 
void initlist()
{
	l=(linklist)malloc(sizeof(node));
	l->next=NULL;
}

//初始化集合链表 
void initsetlist()
{
	s=(linkset)malloc(sizeof(sset));
	s->next=NULL;
}


//打开这个exe文件的第一步就是把文件中的数据初始化到key链表 
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
	//验证密码
	yanzheng();
	
	//把读入文件中的数据 
	initlist();
	duwenjian();
	
	initsetlist(); 
	
	//欢迎界面 
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
	
	//开始接受命令 
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
 
