// 2번. 정수값을 입력 받아 피보나치 수열 계산하고 결과 출력
// 원형 큐에 f(0), f(1)의 값이 들어가 있어 f(2) 계산할 때 f(0) 제거 후 그 다음 계산된 f(b)를 넣음

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode* link;
}QueueNode;

typedef struct {
    QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q)
{
    q->front = q->rear = 0;
}
int is_empty(LinkedQueueType* q)
{
    return (q->front == NULL);
}
int is_full(LinkedQueueType* q)
{
    return 0;
}
int enqueue(LinkedQueueType* q, element data)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if (is_empty(q))
    {
        q->front = temp;
        q->rear = temp;

    }
    else
    {
        q->rear->link = temp;
        q->rear = temp;
    }
}

int dequeue(LinkedQueueType* q)
{
    QueueNode* temp = q->front;
    element data;
    if (is_empty(q))
    {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        data = temp->data;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        return data;
    }

}
int QueuePeek(LinkedQueueType* q)
{
    QueueNode* temp = q->front;
    element data;
    if (is_empty(q))
    {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        data = temp->data;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        enqueue(q, data);
        return data;
    }

}
void print_queue(LinkedQueueType* q)
{
    QueueNode* p;
    for (p = q->front; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}
int main(void)
{
    // 1. 정수값을 입력 받음
    LinkedQueueType queue;
    init(&queue);

    int n;
    printf("정수값을 입력하세요: ");
    scanf("%d", &n);

    enqueue(&queue, 0);
    enqueue(&queue, 1);
    //enqueue(&queue, 1);

    // print_queue(&queue);

    // 2. 피보나치 수열 계산 
    // F(n) = F(n-1) + F(n-2)
    // 0 1 1 2 3 5 8 13 ...

    // n까지 피보나치 수열 계산

    element result = 0;
    for (int i = 0; i < n; i++) {
        element before = QueuePeek(&queue);
        result = dequeue(&queue); + dequeue(&queue);
        //dequeue(&queue);
        enqueue(&queue, before);
        enqueue(&queue, result);
        //enqueue(&queue, result);
    }
    

    // 3. 결과 출력
    printf("피보나치 수열 F(%d)은 %d입니다.\n", n, result);
    
    
    return 0;
}