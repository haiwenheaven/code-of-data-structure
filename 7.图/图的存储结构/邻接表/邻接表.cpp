#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef struct arcnode
{
	int pos;//这段弧指向的那个结点在图的结点数组中的位置
	int weight;
	struct arcnode *next;
}arcnode,*arc;
typedef struct
{
	char data; 
	arc firstarc;
}node;
typedef struct
{
	node nodes[maxsize];
	int nodenum;
	int arcnum;
}graph;

void init(graph &g)
{
	g.arcnum=0;
	g.nodenum=0;
}
int locate(graph g,char c)
{
	int index;
	for(int i=0;i<g.nodenum;i++)
	{
		if(g.nodes[i].data==c)
		{
			index=i;
			break;
		}
	}
	return index;	
} 
void print(graph g)
{
	for(int i=0;i<g.nodenum;i++)
	{
		printf("%c",g.nodes[i].data);
	}
}
void creategraph(graph &g)
{
	printf("结点数:");
	scanf("%d",&g.nodenum);
	getchar();
	for(int i=0;i<g.nodenum;i++)
	{
		printf("第%d个结点的值：",i);
		scanf("%c",&g.nodes[i].data);
		getchar();
	}
	printf("边数:");
	scanf("%d",&g.arcnum);
	getchar();
	for(int i=0) 
}
void bfs(graph g)
{
	int visit[maxsize]={0};
	
}
void dfs(graph g)
{
	
}
void mintree(graph g)
{
	
}
int main()
{
    graph g;
    init(g);
    creategraph(g);
    print(g);
    return 0;
}
