#include "queue.h"

int empty(queue* q) {
	return (q->head >= q->tail) ? 1 : 0;
}
int full(queue* q) {
	return (q->tail >= MAXSIZE - 1) ? 1 : 0;
}
void createQueue(queue* q) {
	q->head = 0;
	q->tail = 0;
}
void enq(queue* q, int value) {
	q->arr[q->tail++] = value;
}
int deq(queue* q) {
	return q->arr[q->head++];
}

