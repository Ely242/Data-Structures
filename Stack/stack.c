#include "stack.h"

Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, void *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void *pop(Stack *stack) {
    if (stack->size == 0) {
        return NULL;
    }
    Node *node = stack->top;
    void *data = node->data;
    stack->top = node->next;
    free(node);
    stack->size--;
    return data;
}

void *peek(Stack *stack) {
    return stack->size == 0 ? NULL : stack->top->data;
}

bool empty(Stack *stack) {
    return stack->size == 0;
}

void freeStack(Stack *stack) {
    while (stack->size > 0) {
        Node *node = stack->top;
        stack->top = node->next;
        free(node);
        stack->size--;
    }
    free(stack);
    stack = NULL;
}