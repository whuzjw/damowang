#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stats.h>

int main(int argc, char** argv) {
	if (argc == 1) return 0;
	else if (argc == 2) {
		if (argv[1] == "-h") {
			printf("Help menu.\n");
		}
	}
	else if (argc == 5){
		if (argv[1] == "-g") {
			char* fp = argv[2];
			if (argv[3] == "-s") {
				char* statsParam = argv[4];
				if (statsParam == "edges") {
					printf("%d", numberOfEdges(fp));
				}
				else if (statsParam == "vertices") {
					printf("%d", numberOfVertices(fp));
				}
				else if (statsParam == "freeman") {
					printf("%d", freemanNetworkCentrality(fp));
				}
				else if (statsParam == "closeness") {
					printf("%d", closenessCentrality(fp));
				}
			}
		}
	}
	else if (argc == 8) {
		if (argv[1] == "-g") {
			if (argv[3] == "-sp") {
				char* algorithm = argv[4];
				int u, v;
				if (argv[5] == "-u") {
					u = atoi(argv[6]);   // atoi() 转字符串为数值
				}
				if (argv[7] == "-v") {
					v = atoi(argv[8]);
				}
				int* sp = shortestPath(u, v, algorithm);
				int length = sizeof(sp) / sizeof(sp[0]);
				printf("%d", sp[0]);
				for (int i = 1; i < length; i++) {
					printf(" -> %d", sp[i]);
				}
			}
		}
	}
}
