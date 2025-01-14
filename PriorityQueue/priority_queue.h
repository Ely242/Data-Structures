#ifndef PQ_H
#define PQ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct {
    int items[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue* create_priority_queue();
void swap(int *a, int *b);
void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq, int index);
bool enqueue(PriorityQueue *pq, int value);
int dequeue(PriorityQueue *pq);
bool is_empty(PriorityQueue *pq);
void free_priority_queue(PriorityQueue *pq);

#endif // PQ_H