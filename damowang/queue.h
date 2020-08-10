typedef struct queue queue;
int empty(queue* q);
int full(queue* q);
void createQueue(queue* q);
void enq(queue* q, int value);
int deq(queue* q);

