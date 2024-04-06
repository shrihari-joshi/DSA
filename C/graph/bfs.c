#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef struct graph{
    int v;
    bool adj[MAX][MAX];
}Graph;

Graph* create(int v)
{
    Graph *g = (Graph*) malloc (sizeof(Graph));
    g->v = v;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            g->adj[i][j] = false;
        }
    }
    return g;
}
void add_edge(Graph *g, int v, int w)
{
    g->adj[v][w] = true;
}
void BFS(Graph *g, int s)
{
    bool visited[MAX];
    for(int i=0;i<g->v;i++)
    visited[i] = false;

    int queue[MAX];
    int front=0, rear=0;

    visited[s] = true;
    queue[rear++] = s;

    while(front != rear)
    {
        s = queue[front++];
        printf("%d", s);

        for(int adjacent= 0;adjacent<g->v; adjacent++)
        {
            if(g->adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}
void DFS(Graph *g, bool visited[MAX], int v, int s)
{
    printf("%d",s);
    visited[s] = true;

    for(int i=0;i<v;i++)
    {
        if(g->adj[s][i] && !visited[i])
        DFS(g,visited,v,i);
    }

}
int main()
{
	// Create a graph
	Graph* g = create(4);
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 1, 2);
	add_edge(g, 2, 0);
	add_edge(g, 2, 3);
	add_edge(g, 3, 3);
    bool visited[MAX] = {false};

	printf("Following is Breadth First Traversal "
		"(starting from vertex 0) \n");
	BFS(g, 0);
    printf("\nFollowing is Breadth First Traversal "
		"(starting from vertex 0) \n");
	DFS(g, visited, 4, 0);

	return 0;
}