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
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->size++;
}

void* dequeue(Queue *queue) {
    if (empty(queue)) {
        return NULL;
    }
    Node *node = queue->front;
    void *data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

void* peek(Queue *queue) {
    return empty(queue) ? NULL : queue->front->data;
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