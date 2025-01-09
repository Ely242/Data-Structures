#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* create_queue();
bool empty(Queue *queue);
void enqueue(Queue *queue, void *data);
void* dequeue(Queue *queue);
void* peek(Queue *queue);
void freeQueue(Queue *queue);

#endif // QUEUE_H