#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"


void createGraph(graph* g, char* fileName) {
	printf("in create Graph\n");
	// open and read file
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, fileName, "r")) != 0) {
		printf("No such file.");
		return ;
	}
	printf("fp != NULL\n");
	g->vexlist = (edge**)malloc(sizeof(edge*));
	g->vexlist[0] = NULL; //////vexlist[0] is wrong
	int count = 0;
	printf("%d\n", count); 
	int u, v, w;	
	while (fscanf_s(fp, "%d %d %d", &u, &v, &w) != EOF)
	{
		if (v+1 > count || u+1 > count) {
			int temp = count;
			count = (v > u) ? v + 1 : u + 1;
			printf("%d\n", count);
			if ((realloc(g->vexlist, count * sizeof(edge*))) == NULL) {
				printf("内存分配失败。");
				return ;
			}
			printf("%d\n", count);
			for (int i = temp; i < count; i++) {
				g->vexlist[i] = NULL;
			}
			printf("%d\n", count);
		}
		edge* temp = (edge*)malloc(sizeof(edge));
		temp->adjvex = v;
		temp->weight = w;
		temp->next = g->vexlist[u];
		g->vexlist[u] = temp;
		temp = NULL;
		printf("%d\n", count);
	}
	fclose(fp);
	printf("%d", count); //////////////////
	g->n = count;
	int n = count;
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
	for (int i = n-1; i >= 0; i--) {
		edge* now = g->vexlist[i];
		while (now != NULL) {
			edge* temp = now->next;
			free(now);
			now = temp;
		}
		free(&(g->vexlist[i]));
	}
	free(&(g->n));
	free(&(g->m));
}
