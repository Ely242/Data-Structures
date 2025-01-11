#include "queue.h"

Queue* create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool empty(Queue *queue) {
    return queue == NULL || queue->size == 0;
}

void enqueue(Queue *queue, void *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (empty(queue)) {
        queue->front = node;
    } 
    else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (empty(queue)) {
        fprintf(stderr, "Error: Attempting to dequeue from empty queue\n");
        exit(1);
    }
    Node *node = queue->front;
    void *data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

int peek(Queue *queue) {
    if (empty(queue)) {
        fprintf(stderr, "Error: Attempting to peek from empty queue\n");
        exit(1);
    }
    return queue->front->data;
}

void freeQueue(Queue *queue) {
    while (!empty(queue)) {
        Node *node = queue->front;
        queue->front = node->next;
        free(node);
        queue->size--;
    }
    free(queue);
    queue = NULL;
}