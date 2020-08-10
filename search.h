#include "graph.h"
char* shortestPath(int u, int v, char algorithm[], char name[]);
void DFS(int u, int v, graph* g, int* visited, int* pred);
void BFS(int u, int v, graph* g, int* visited, int* pred);
void Dijkstra(int u, int v, graph* g);
