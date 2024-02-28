// 2��. �������� �Է� �޾� �Ǻ���ġ ���� ����ϰ� ��� ���
// ���� ť�� f(0), f(1)�� ���� �� �־� f(2) ����� �� f(0) ���� �� �� ���� ���� f(b)�� ����

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
        fprintf(stderr, "������ �������\n");
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
        fprintf(stderr, "������ �������\n");
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
    // 1. �������� �Է� ����
    LinkedQueueType queue;
    init(&queue);

    int n;
    printf("�������� �Է��ϼ���: ");
    scanf("%d", &n);

    enqueue(&queue, 0);
    enqueue(&queue, 1);
    //enqueue(&queue, 1);

    // print_queue(&queue);

    // 2. �Ǻ���ġ ���� ��� 
    // F(n) = F(n-1) + F(n-2)
    // 0 1 1 2 3 5 8 13 ...

    // n���� �Ǻ���ġ ���� ���

    element result = 0;
    for (int i = 0; i < n; i++) {
        element before = QueuePeek(&queue);
        result = dequeue(&queue); + dequeue(&queue);
        //dequeue(&queue);
        enqueue(&queue, before);
        enqueue(&queue, result);
        //enqueue(&queue, result);
    }
    

    // 3. ��� ���
    printf("�Ǻ���ġ ���� F(%d)�� %d�Դϴ�.\n", n, result);
    
    
    return 0;
}