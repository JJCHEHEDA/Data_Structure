#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

typedef struct Queue{
    node *front;
    node *button;
};

void initQueue(struct Queue *queue)
{
    queue->front = (struct Node *)malloc(sizeof(struct Node));
    if (queue->front == NULL){
        printf("malloc error!\n");
        return ;
    }
    queue->button = queue->front;
    queue->button->next = NULL;
}

void pushQueue(struct Queue *queue, int val)
{
    struct Node *now = (struct Node *)malloc(sizeof(struct Node));
    now->data = val;
    queue->button->next = now;
    queue->button = now;
}

void printfQueue(struct Queue *queue)
{
    struct Node *now = (struct Node *)malloc(sizeof(struct Node));
    now = queue->front->next;
    while(now != NULL){
        printf("the one of queue is %d\n", now->data);
        now = now->next;
    }
}

int popQueue(struct Queue *queue, int * val)
{
    if (isEmpty(queue)) return 0;
    else{
        struct Node *now = queue->front->next;
        *val = now->data;
        queue->front->next = queue->front->next->next; 
        free(now);
        now = NULL;
        return 1;
    }
}

int isEmpty(struct Queue *queue)
{
    if (queue->front == queue->button) return 1;
    else return 0;
}

void clearQueue(struct Queue *queue)
{
    if (isEmpty(queue)) return ;
    else{
        struct Node *p = queue->front->next;
        struct Node *q = NULL;
        while(p != queue->button){
            q = p->next;
            free(p);
            p = q;
        }
        q = p->next;
        free(p);
        queue->button = queue->front;
        queue->button->next = NULL;
    }
}

int main(int argc, char *argv[])
{
    int num;
    struct Queue queue_one;

    initQueue(&queue_one);
    printfQueue(&queue_one);
    printf("现在输入六个数进队列!\n");
    for (int i=0; i<6; i++)
    {
        scanf("%d", &num);
        pushQueue(&queue_one, num);
    }
    printfQueue(&queue_one);
    if (popQueue(&queue_one, &num)) printf("出队列的元素是%d\n", num);
    else printf("出队列失败!\n");
    clearQueue(&queue_one);
    printfQueue(&queue_one);
    return 0;
}



