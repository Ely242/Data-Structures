#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct Node {
    void* data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
    void (*free_data)(void*);
    char* (*to_string)(void*);
} Queue;

Queue* create_queue(void (*free_data)(void*), char* (*to_string)(void*));
bool is_empty(Queue *queue);
int get_size(Queue *queue);
void enqueue(Queue *queue, void* data);
void* dequeue(Queue *queue);
void* peek(Queue *queue);
void free_queue(Queue *queue);
char* queue_to_string(Queue *queue);
void clear_queue(Queue *queue);

#endif // QUEUE_H
