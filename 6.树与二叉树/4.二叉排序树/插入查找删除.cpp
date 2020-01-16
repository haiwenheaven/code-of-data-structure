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
	//有三种情况
	//1.删除结点为叶子结点，则直接删除
	//2.删除的节点只有左子树或者右子树，则删除节点的子树直接代替删除节点
	//3. 删除结点既有左子树又有右子树，则在右子树找中序第一个结点填补
	
	  
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
