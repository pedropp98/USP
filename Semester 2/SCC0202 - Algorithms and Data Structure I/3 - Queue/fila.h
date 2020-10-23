
typedef struct people{
    char *name;
    int age, health_condition, priority;
}people_t;

typedef struct queue{
    int begin, end, total;
    people_t *elements;
}queue_t;

//Create queue
queue_t *create(int size);

//Checks if queue is empty, returns true if so, false if otherwise
int isempty(queue_t *q);

//Checks if queue is full, returns true if so, false if otherwise
int isfull(queue_t *q);

//Inserts x in the queue rear
int insert(queue_t *q, people_t x);

//Pops x from queue front
int pop(queue_t *q, people_t *x);

//Tells which item is in front of the queue
int front(queue_t *q, people_t *x);

//Frees memory allocked for queue
void destroy(queue_t *q);

