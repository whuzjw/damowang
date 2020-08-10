#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "queue.h"

char* shortestPath(int u, int v, char algorithm[], char fileName[]) {
	// create a graph
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	createGraph(g, fileName);
	// search
	const int n = g->n;
	int* visited = (int*)malloc(n*sizeof(int));
	int* pred = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		visited[i] = 0;
		pred[i] = -1;
	}
	if (algorithm == "DFS") DFS(u, v, g, visited, pred);
	else if (algorithm == "BFS") BFS(u, v, g, visited, pred);
	else if (algorithm == "Dijkstra") Dijkstra(u, v, g);

	int pre = v;
	int arr[1000];
	int count = 0;
	while (pre != u) {
		arr[count++] = pre;
		pre = pred[pre];
	}
	char* path = (char*)malloc(4 * (count + 1) * sizeof(char));
	sprintf(path, "%d", u);
	for (int i = count - 1; i >= 0; i--) {
		sprintf(path, "%s -> %d", path, arr[i]);
	}
	removeGraph(g);
	free(visited);
	free(pred);
	return path;
}
void DFS(int u, int v, graph* g, int* visited, int* pred) {
	visited[u] = 1;
	edge* uEdge = g->vexlist[u];
	while (uEdge != NULL) {
		int k = uEdge->adjvex;
		if (!visited[k]) {
			pred[k] = u;
			DFS(k, v, g, visited, pred);
		}
	}
}
void BFS(int u, int v, graph* g, int* visited, int* pred) {
	queue q;
	createQueue(&q);
	enq(&q, u);
	while (!empty(&q)) {
		int i = deq(&q);
		int flag = 0;
		edge* iEdge = g->vexlist[i];
		while (iEdge != NULL) {
			int iadjvex = iEdge->adjvex;
			if (visited[iadjvex] == 0) {
				if (iEdge->weight == 1) {
					pred[iadjvex] = i;
					visited[iadjvex] = 1;
					if (iadjvex == v) return;
					enq(&q, iadjvex);
				}
				else {
					flag = 1;
				}
				iEdge->weight--;
			}
		}
		if (flag == 1) enq(&q, i);
	}
}
void Dijkstra(int u, int v, graph* g) {

}
