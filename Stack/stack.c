#include "stack.h"

/**
 * Creates a new stack.
 * @param free_data Function to free the data stored in the stack.
 * @return Pointer to the created Stack structure.
 */
Stack *create_stack(void (*free_data)(void *to_free), char* (*to_string)(void *data)) {
    assert(free_data != NULL);
    assert(to_string != NULL);

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;

    stack->free_data = free_data;
    stack->to_string = to_string;

    return stack;
}

/**
 * Inserts an item into the stack.
 * @param stack Pointer to the Stack structure.
 * @param data The data to be inserted.
 */
void push(Stack *stack, void* data) {
    if (data == NULL){
        return;
    }

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
void* pop(Stack *stack) {
    if (is_empty(stack)) {
        return NULL;
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
void* peek(Stack *stack) {
    if (is_empty(stack)) {
        return NULL;
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

    while (!is_empty(stack)) {
        Node *node = stack->top;
        stack->free_data(node->data);
        stack->top = node->next;
        free(node);
    }

    free(stack);
    stack = NULL;
}

/**
 * Returns the number of items in the stack.
 * @param stack Pointer to the Stack structure.
 * @return The number of items in the stack.
 */
int get_size(Stack *stack) {
    return stack == NULL ? 0 : stack->size;
}

/**
 * Removes all items from the stack.
 * @param stack Pointer to the Stack structure.
 */
void clear_stack(Stack *stack) {
    while (!is_empty(stack) > 0) {
        Node *node = stack->top;
        stack->free_data(node->data);
        stack->top = node->next;
        free(node);
    }
    stack->size = 0;
}

/**
 * Converts the stack to a string representation.
 * @param stack Pointer to the Stack structure.
 * @return The string representation of the stack.
 */
char* stack_to_string(Stack *stack) {
    if (is_empty(stack)) {
        return NULL;
    }

    int len = 1;
    char *str = malloc(sizeof(char));
    strcpy(str, "");

    Node *node = stack->top;
    while (node != NULL) {
        char* temp = stack->to_string(node->data);
        len += strlen(temp);

        str = realloc(str, len * sizeof(char));
        strcat(str, temp);
        free(temp);
        node = node->next;
    }

    return str;
}
