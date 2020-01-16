#include<stdio.h>
#include<iostream>
#include<malloc.h>
#define maxSize 1000
int visit[maxSize];
using namespace std;
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode; 
 
typedef struct{
	int data;
	ArcNode *firstarc;
}Vnode; 
 
typedef struct{
	Vnode adjlist[maxSize];
	int n, e;
}AGraph;
 
AGraph *graph;
void  insertNode(ArcNode *node, ArcNode *newNode){
	ArcNode *p = node;
	while(p->nextarc != NULL){
		p = p->nextarc;
	}
	p->nextarc = newNode;	
}
 
void create(){
	graph = (AGraph*)malloc(sizeof(AGraph));
	cout << "输入顶点的数目: " << endl;
	cin >> graph->n;
	cout << "输入图中边的数目: " << endl;
	cin >> graph->e;
	int u = -1, v = -1, weight = -1;
	for(int i = 0; i < graph->n; i++){
		graph->adjlist[i].firstarc = NULL;
	}
	
	ArcNode *node; 
	for(int i = 0; i < graph->e; i++){
		cin >> u >> v >> weight;
		node = (ArcNode *)malloc(sizeof(ArcNode));
		node->adjvex = v; 
		node->info = weight;
		node->nextarc = NULL;
		graph->adjlist[u].data = u;
		if(graph->adjlist[u].firstarc == NULL){
			graph->adjlist[u].firstarc = node; 
		}else{
			insertNode(graph->adjlist[u].firstarc, node); 
		}	
	} 
}
 
//深度优先遍历
void dfs(AGraph *G, int v){
	ArcNode *p;
	visit[v] = 1;
	cout << v << " ";
	p = G->adjlist[v].firstarc;
	while(p != NULL){
		if(visit[p->adjvex] == 0){
			dfs(G, p->adjvex);
		}
		p = p->nextarc;	
	}
} 
 
int main(void){
	create();
	dfs(graph, 0);
	return 0;
}

