#include<stdio.h>
#include<stdlib.h>

#define maxsize 100
typedef struct
{
	int node[maxsize];
	int arc[maxsize][maxsize];
	int nodenum;
	int arcnum;
}graph;


int main()
{
    graph g;
    system("pause");
    return 0;
}
