#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef struct bitnode
{
    int data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
typedef struct
{
    bitree data[10];
    int top;
}stack;

void init_stack(stack &s)//初始化栈
{
    s.top = -1;
}
void push(stack &s, bitree t)//入栈
{
    s.top++;
    s.data[s.top] = t;
}
bitree pop(stack &s)//出栈
{
    bitree x;
    x = s.data[s.top];
    s.top--;
    return x;
}
bitree gettop(stack s)//取得栈顶元素
{
    bitree x;
    x = s.data[s.top];
    return x;
}
void createbitree(bitree &t)//先序创建二叉树
{
    char c;
    scanf("%c",&c);
    if(c==' ')
    {
        t=NULL;
    }
    else
    {
        t=(bitree)malloc(sizeof(bitnode));
        t->data=c;
        createbitree(t->lchild);
        createbitree(t->rchild);
    }

}

void preordertraverse(bitree t)//递归先序遍历
{
    if(t!=NULL)
    {
        printf("%d",t->data);
        preordertraverse(t->lchild);
        preordertraverse(t->rchild);
    }
}
void not_recursion_preoder(bitree t)//非递归先序遍历
{
    stack s;
    init_stack(s);
    while(t || s.top!=-1)
    {
        if(t)
        {
            printf("%d",t->data);
            push(s,t);
            t=t->lchild;
        }
        else
        {
            t=pop(s);
            t=t->rchild;
        }
    }
}
void inordertraverse(bitree t)//递归中序遍历
{
    if(t!=NULL)
    {
        inordertraverse(t->lchild);
        printf("%d",t->data);
        inordertraverse(t->rchild);
    }
}
void not_recursion_inoder(bitree t)//非递归中序遍历
{
    stack s;
    init_stack(s);
    while(t || s.top!=-1)
    {
        if(t)
        {
            push(s,t);
            t=t->lchild;
        }
        else
        {
            t=pop(s);
            printf("%d",t->data);
            t=t->rchild;
        }
    }
}
void postordertraverse(bitree t)//递归后序遍历
{
    if(t!=NULL)
    {
        postordertraverse(t->lchild);
        postordertraverse(t->rchild);
        printf("%d",t->data);
    }
}
void not_recursion_postoder(bitree t)//非递归后序遍历
{
    bitree r=NULL;
    r=NULL;
    stack s;
    init_stack(s);
    while(t || s.top!=-1)
    {
        if(t)
        {
            push(s,t);
            t=t->lchild;
        }
        else
        {
            t=gettop(s);
            if(t->rchild!=NULL && t->rchild!=r)
            {
                t=t->rchild;
            }
            else
            {
                t=pop(s);
                printf("%d",t->data);
                r=t;
                t=NULL; 
            }
        }
    }
}
void levelordertraverse(bitree t)
{
    bitree temp[10];
    int front=0;
    int rear=1;
    temp[0]=t;
    while(front<rear)
    {
        printf("%d",temp[front]->data);
        if(temp[front]->lchild)
        {
            temp[rear]=temp[front]->lchild;
            rear++;
        }
        if(temp[front]->rchild)
        {
            temp[rear]=temp[front]->rchild;
            rear++;
        }
        front++;
    }
}
int main()
{
    bitree t;
    createbitree(t);
    preordertraverse(t);
    system("pause");
    return 0;
}
