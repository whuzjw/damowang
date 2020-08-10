#include <malloc.h>
#include <assert.h>
#include "stats.h"
#include "graph.h"


int numberOfEdges(char name[]) {
	printf("in numberOfEdges\n");      /////////////okkk
	graph* g;
	if (( g = (graph*)malloc(sizeof(graph))) == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü¡£");
		return;
	}
	if(g == NULL) 	printf("g != NULL\n");   /////////okkkk
	createGraph(g, name);
	printf("lll");            ////////////wrong!!!!
	int m = g->m;
	removeGraph(g);
	g = NULL;
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
	float fnc = 0;

	removeGraph(g);
	return fnc;
}
float closenessCentrality(char name[]) {
	graph* g = (graph*)malloc(sizeof(graph));
	createGraph(g, name);
	float cc = 0;

	removeGraph(g);
	return cc;
}
