#include<stdio.h>
#include<stdlib.h>

typedef struct bitnode{
    int val;
    struct bitnode *left,*right;
}bitnode,*bitree;

void insert(bitree &bst,int x)
{
    if(bst==NULL)
    {
        bst=(bitree)malloc(sizeof(bitnode));
        bst->val=x;
        bst->left=bst->right=NULL;
    }
    else if(bst!=NULL)
    {
        if(bst->val > x)
        {
            insert(bst->left,x);
        }
        else if(bst->val < x)
        {
            insert(bst->right,x);
        }
        else if(bst->val==x)
        {
            return;
        }
    }
}
bitree search(bitree bst,int x)
{
    while(bst!=NULL)
    {
        if(x<bst->val)
        {
        	bst=bst->left;
		}
		else if(x>bst->val)
		{
			bst=bst->right;
		}
		else
		{
			return bst;
		}
    }
    return NULL;
}
void deletenode(bitree &bst,int x)
{
	//���������
	//1.ɾ�����ΪҶ�ӽ�㣬��ֱ��ɾ��
	//2.ɾ���Ľڵ�ֻ����������������������ɾ���ڵ������ֱ�Ӵ���ɾ���ڵ�
	//3. ɾ�������������������������������������������һ������
	
	  
}
void inordertraverse(bitree t)
{
    if(t!=NULL)
    {
        inordertraverse(t->left);
        printf("%d ",t->val);
        inordertraverse(t->right);
    }
}
int main()
{
    int data[10]={5,3,6,2,4,8,1,7,9,10};
    bitree bst;
    bst=NULL;
    for(int i=0;i<10;i++)
    {
        insert(bst,data[i]);
    }
    inordertraverse(bst);
    printf("\n");
    deletenode(bst,9);
	inordertraverse(bst); 
    system("pause");
    return 0;
}
