#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "stats.h"

int main(int argc, char** argv) {
	if (argc == 2) {
		if (argv[1] == "-h") {
			printf("Help menu.\n");
		}
	}
	else if (argc == 5){
		if (argv[1] == "-g") {
			char* fileName = argv[2];
			if (argv[3] == "-s") {
				char* statsParam = argv[4];
				if (statsParam == "edges") {
					printf("%d", numberOfEdges(fileName));
				}
				else if (statsParam == "vertices") {
					printf("%d", numberOfVertices(fileName));
				}
				else if (statsParam == "freeman") {
					printf("%f", freemanNetworkCentrality(fileName));
				}
				else if (statsParam == "closeness") {
					printf("%f", closenessCentrality(fileName));
				}
			}
		}
	}
	else if (argc == 8) {
		if (argv[1] == "-g") {
			char* fileName = argv[2];
			if (argv[3] == "-sp") {
				char* algorithm = argv[4];
				int u, v;
				if (argv[5] == "-u") {
					u = atoi(argv[6]);   // atoi() 转字符串为数值
				}
				if (argv[7] == "-v") {
					v = atoi(argv[8]);
				}
				char* sp = shortestPath(u, v, algorithm, fileName);  
				printf("%s", sp);
				free(sp);  // 这样应该可以
			}
		}
	}

	return 0;
}
