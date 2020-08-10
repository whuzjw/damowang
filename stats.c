#include <stats.h>

struct edge{
	int vertex;
	int weight;
};
struct edge** read(char name[], int* n, int* m){
	FILE* fp = fopen(name, "r");
	if(fp == NULL){
		return NULL;
	}
	fscanf(fp, "%d %d", n, m);
	struct edge** Adj = (edge**)malloc(n*sizeof(edge*));
	int vertex1, vertex2, weight;
	for(int i = 0; i < *m; i++){
		fscanf(fp, "%d, %d, %d", &vertex1, &vertex2, &weight);
		///////////////////////////////////////////////////
	}
	return Adj;
}
int numberOfEdges(char name[]){
	int n, m;	
	edge* Adj[n];
}
int numberOfVertices(char name[]){

}
int freemanNetworkCentrality(char name[]){

}
int closenessCentrality(char name[]){

}
