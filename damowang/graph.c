#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct edge {
	int adjvex;
	int weight;
	struct edge* next;
}edge;
typedef struct graph {
	edge** vexlist;
	int n, m;
}graph;

void createGraph(graph* g, char* fileName) {
	// open and read file
	FILE* fp;
	if ((fp = fopen(fileName, "r")) == NULL) {
		printf("No such file.");
		return ;
	}
	if ((g->vexlist = (edge**)malloc(sizeof(edge*))) == NULL) {
		printf("内存分配失败。");
		return;
	}
	g->vexlist[0] = NULL;
	int u, v, w;
	while (fscanf(fp, "%d %d %d", &u, &v, &w) != EOF)
	{
		if (v+1 > sizeof(g->vexlist) / sizeof(edge*)) {
			size_t temp = sizeof(g->vexlist) / sizeof(edge*);
			if ((realloc(g->vexlist, (v + 1) * sizeof(edge*))) == NULL) {
				printf("内存分配失败。");
				return ;
			}
			for (int i = temp; i < v + 1; i++) {
				g->vexlist[i] = NULL;
			}
		}
		edge* temp = g->vexlist[u];
		g->vexlist[u] = (edge*)malloc(sizeof(edge));
		g->vexlist[u]->adjvex = v;
		g->vexlist[u]->weight = w;
		g->vexlist[u]->next = temp;
	}
	fclose(fp);
	g->n = sizeof(g->vexlist) / sizeof(edge*);
	int n = g->n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		edge* temp = g->vexlist[i];
		while (temp != NULL) {
			m++;
			temp = temp->next;
		}
	}
	g->m = m;
}
// 不知对不对
void removeGraph(graph* g) {
	int n = g->n;
	for (int i = 0; i < n; i++) {
		edge* prev = g->vexlist[i];
		edge* now = g->vexlist[i]->next;
		while (now != NULL) {
			free(prev);   // 指哪free哪，prev指向g->vexlist[i]
			prev = now;
			now = now->next;
		}
	}
	free(g);
}
