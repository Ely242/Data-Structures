#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node {
    void* data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
    void (*free_data)(void *to_free);
    char* (*to_string)(void *data);
} Stack;

Stack* create_stack(void (*free_data)(void *to_free), char* (*to_string)(void *data));
bool is_empty(Stack *stack);
void push(Stack *stack, void* data);
int get_size(Stack *stack);
void* pop(Stack *stack);
void* peek(Stack *stack);
void free_stack(Stack *stack);
void clear_stack(Stack *stack);
char* stack_to_string(Stack *stack);

#endif // STACK_H