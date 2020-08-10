#define MAXSIZE 100
typedef struct queue {
	int arr[MAXSIZE];
	int head;
	int tail;
}queue;
int empty(queue* q);
int full(queue* q);
void createQueue(queue* q);
void enq(queue* q, int value);
int deq(queue* q);

