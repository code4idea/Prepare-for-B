//기수 정렬은 낮은 자리수부터 정렬해가는 알고리즘. 따라서, 자리수가 고정되어 있어야 효율적
// Queue 가 필요
#define MAX_SIZE 1000

typedef struct queue{
  int data[MAX_SIZE];
  int front;
  int end;
}Queue;

void initQueue(Queue q){
  q.front = 0;
  q.end = -1;
}

void enQueue(Queue q, int num){
  
}
