#include "stats.h"
#include "graph.h"
int numberOfEdges(char name[]) {
	graph* g = (graph*)malloc(sizeof(graph));
	createGraph(g, name);
	int m = g->m;
	removeGraph(g);
	return m;
}
int numberOfVertices(char name[]) {
	graph* g = (graph*)malloc(sizeof(graph));
	createGraph(g, name);
	int n = g->n;
	removeGraph(g);
	return n;
}
float freemanNetworkCentrality(char name[]) {
	graph* g = (graph*)malloc(sizeof(graph));
	createGraph(g, name);
	float fnc;

	removeGraph(g);
	return fnc;
}
float closenessCentrality(char name[]) {
	graph* g = (graph*)malloc(sizeof(graph));
	createGraph(g, name);
	float cc;

	removeGraph(g);
	return cc;
}
