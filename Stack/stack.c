#include "stack.h"

/**
 * Creates a new stack.
 * @return Pointer to the created Stack structure.
 */
Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

/**
 * Inserts an item into the stack.
 * @param stack Pointer to the Stack structure.
 * @param data The data to be inserted.
 */
void push(Stack *stack, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

/**
 * Removes and returns the item at the top of the stack.
 * @param stack Pointer to the Stack structure.
 * @return The item at the top of the stack.
 */
int pop(Stack *stack) {
    if (empty(stack)) {
        fprintf(stderr, "Error: Attempting to pop from empty stack\n");
        exit(1);
    }
    Node *node = stack->top;
    void *data = node->data;
    stack->top = node->next;
    free(node);
    stack->size--;
    return data;
}

/**
 * Returns the item at the top of the stack without removing it.
 * @param stack Pointer to the Stack structure.
 * @return The item at the top of the stack.
 */
int peek(Stack *stack) {
    if (empty(stack)) {
        fprintf(stderr, "Error: Attempting to peek from empty stack\n");
        exit(1);
    }
    return stack->top->data;
}

/**
 * Checks if the stack is empty.
 * @param stack Pointer to the Stack structure.
 * @return true if the stack is empty, false otherwise.
 */
bool is_empty(Stack *stack) {
    return stack == NULL || stack->size == 0;
}

/**
 * Frees the memory allocated for the stack.
 * @param stack Pointer to the Stack structure to be freed.
 */
void free_stack(Stack *stack) {
    while (!empty(stack) > 0) {
        Node *node = stack->top;
        stack->top = node->next;
        free(node);
        stack->size--;
    }
    free(stack);
    stack = NULL;
}