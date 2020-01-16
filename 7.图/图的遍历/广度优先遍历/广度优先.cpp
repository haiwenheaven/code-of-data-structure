#include <stdio.h>  
#include <stdlib.h>  
#define  MaxVertices 100
#define MAX_VERTEX_NUM 20
typedef struct node{   //�߱� 
   int adjvex;
   node* next;  
}EdgeNode;    
typedef struct{     //�����  
   int vertex;  
   EdgeNode* edgenext;  
}VertexNode;  
typedef VertexNode AdjList[MaxVertices];  
typedef struct{   
    AdjList adjlist;  
    int n,e;  
}AdjMatrix; 
typedef struct Qnode{       //���ӽ�������
    int data;
    struct Qnode *next;
}Qnode,*QueuePtr;
typedef struct{         //����ָ������
   QueuePtr front;
   QueuePtr rear;
}LinkQueue;
int visited[MAX_VERTEX_NUM]; 
void InitQueue(LinkQueue *Q)//��ʼ������ 
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(Qnode));
    if(!Q->front) 
        exit(1); //�洢����ʧ��
    Q->front->next=NULL;
 }
void EnQueue(LinkQueue *Q,int e)//��� 
{ 
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(Qnode));
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
}
int QueueEmpty(LinkQueue *Q)//�ж϶ӿ� 
{
    return(Q->front==Q->rear? 1:0);
}
void DeQueue(LinkQueue *Q,int &e)//���� 
{ 
    QueuePtr p;
    if(QueueEmpty(Q))
    {
        printf("\n Queue is free!");
        exit(1);
    }//if
    p=Q->front->next;
    e=p->data;
    Q->front->next=p->next;
    if(Q->front->next==NULL) Q->rear=Q->front;
        free(p);

}
void CreateGraph(AdjMatrix* G)//����ͼ  
{  
    int i,j,k,w,v;  
    EdgeNode *s;  
    printf("���붥�����ͱ������м��Կո�ֿ�����");  
    scanf("%d%d",&G->n,&G->e);  

    printf("���������\n"); 
    for (i=0;i<G->n;i++)  
    {  
        //fflush(stdin);  
        //��� stream ָ������������ stdin������ô fflush ��������Ϊ�ǲ�ȷ���ġ�
        //�ʶ�ʹ�� fflush(stdin) �ǲ���ȷ�ġ�
        getchar(); 
        printf("�������%d���������Ϣ:",i+1);
        G->adjlist[i].vertex=getchar();
        G->adjlist[i].edgenext=NULL;  
    }  
    //ǰ�巨 
    printf("�����߱�\n");  
    for (k=0;k<G->e;k++)  
    {  
       printf("���������ӵĶ�����ţ�");  
       scanf("%d%d",&i,&j);  
       //����ֱ�������Ľ��б���(�������롰0 1��ʱ����0��Ӧ�ı߱��б���1) 
       i-=1;j-=1; 
       s=(EdgeNode*)malloc(sizeof(EdgeNode));  
       s->adjvex=j;//�߱�ֵ 
       s->next=G->adjlist[i].edgenext;  
       G->adjlist[i].edgenext=s;  
       //���ڼ�������Ľ��б���(�������롰0 1��ʱ����1��Ӧ�ı߱��б���0)
       s=(EdgeNode*)malloc(sizeof(EdgeNode));  
       s->adjvex=i;  
       s->next=G->adjlist[j].edgenext;  
       G->adjlist[j].edgenext=s;  
    }  
}   
void DispGraph(AdjMatrix *G)//����ͼ 
{
    int i;
    for (i=0;i<G->n;i++)  
    {  
        printf("%d->",i+1);  
        while(1)  
        {             
            if(G->adjlist[i].edgenext==NULL)
            {
                printf("^");
                break;  
            }
            printf("%d->",G->adjlist[i].edgenext->adjvex+1);  
            G->adjlist[i].edgenext=G->adjlist[i].edgenext->next;  

        }  
        printf("\n");  
    }  
}
void BFSTraverse(AdjMatrix *G)//����������� 
{
    LinkQueue Q;
    for(int v=0;v<G->n;++v) 
        visited[v]=false;
    InitQueue(&Q);

    printf("�����������˳��");
    for(int v=0;v<G->n;++v)
    {
        if(!visited[v])
        {
            EnQueue(&Q,v);//���ڽӱ�Ķ���Ԫ����� 
            while(!QueueEmpty(&Q))
            {
                int u;      
                DeQueue(&Q,u);
                if(!visited[u]) 
                {
                    visited[u]=true;
                    printf("->%c",G->adjlist[u].vertex);//visitһ��
                } 
                //�Ըö���Ԫ�صı߹�ϵ���б������������ 
                for(EdgeNode *w=G->adjlist[u].edgenext;w;w=w->next)
                    if(!visited[w->adjvex]) 
                        EnQueue(&Q,w->adjvex);
            }
            printf("\n\n"); 
        }
    }
}
int main()  
{  
    //freopen("1.txt","r",stdin);
    AdjMatrix* G= (AdjMatrix*)malloc(sizeof(AdjMatrix));  
    CreateGraph(G);
    BFSTraverse(G);  
    DispGraph(G); 
}  

