#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void* data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* create_queue();
bool is_empty(Queue *queue);
void enqueue(Queue *queue, void* data);
void* dequeue(Queue *queue);
int peek(Queue *queue);
void free_queue(Queue *queue);

#endif // QUEUE_H