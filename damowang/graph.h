typedef struct edge {
	int adjvex;
	int weight;
	struct edge* next;
}edge;
typedef struct graph {
	edge** vexlist;
	int n, m;
}graph;

void createGraph(graph* g, char* fileName);
void removeGraph(graph* g);
