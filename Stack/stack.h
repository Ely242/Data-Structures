#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
} Stack;

Stack* create_stack();
bool empty(Stack *stack);
void push(Stack *stack, void *data);
void* pop(Stack *stack);
void* peek(Stack *stack);
void freeStack(Stack *stack);

#endif // STACK_H