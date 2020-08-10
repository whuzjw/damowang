#include <stdio.h>
#include <stdlib.h>
struct edge;
int read(char name[], int* n, int* m, edge** Adj);
int numberOfEdges(char name[]);
int numberOfVertices(char name[]);
int freemanNetworkCentrality(char name[]);
int closenessCentrality(char name[]);
