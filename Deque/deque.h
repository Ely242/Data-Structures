#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *back;
    int size;
} Deque;

Deque *create_deque();
void push_front(Deque *deque, int data);
void push_back(Deque *deque, int data);
int pop_front(Deque *deque);
int pop_back(Deque *deque);
int peek_front(Deque *deque);
int peek_back(Deque *deque);
bool is_empty(Deque *deque);
void free_deque(Deque *deque);

#endif // DEQUE_H