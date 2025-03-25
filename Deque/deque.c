#include "deque.h"

/**
 * Creates a new deque.
 * @return Pointer to the created Deque structure.
 */
Deque *create_deque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
    return deque;
}

/**
 * Inserts an item at the front of the deque.
 * @param deque Pointer to the Deque structure.
 * @param data The data to be inserted.
 */
void push_front(Deque *deque, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = deque->front;
    node->prev = NULL;
    deque->size++;
    if (deque->front != NULL) {
        deque->front->prev = node;
    } 
    else {
        deque->back = node;
    }
    deque->front = node;
}

/**
 * Inserts an item at the back of the deque.
 * @param deque Pointer to the Deque structure.
 * @param data The data to be inserted.
 */
void push_back(Deque *deque, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = deque->back;
    deque->size++;
    if (deque->back) {
        deque->back->next = node;
    } 
    else {
        deque->front = node;
    }
    deque->back = node;
}

/**
 * Removes and returns the item at the front of the deque.
 * @param deque Pointer to the Deque structure.
 * @return The item at the front of the deque.
 */
int pop_front(Deque *deque) {
    if (is_empty(deque)) {
        fprintf(stderr, "Error: Attempting to pop from empty deque\n");
        exit(1);
    }
    Node *node = deque->front;
    int data = node->data;
    deque->front = node->next;
    deque->size--;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } 
    else {
        deque->back = NULL;
    }
    free(node);
    return data;
}

/**
 * Removes and returns the item at the back of the deque.
 * @param deque Pointer to the Deque structure.
 * @return The item at the back of the deque.
 */
int pop_back(Deque *deque) {
    if (is_empty(deque)) {
        fprintf(stderr, "Error: Attempting to pop from empty deque\n");
        exit(1);
    }
    Node *node = deque->back;
    int data = node->data;
    deque->back = node->prev;
    deque->size--;
    if (deque->back != NULL) {
        deque->back->next = NULL;
    } 
    else {
        deque->front = NULL;
    }
    free(node);
    return data;
}

/**
 * Frees the memory allocated for the deque.
 * @param deque Pointer to the Deque structure to be freed.
 */
int peek_front(Deque *deque) {
    if (is_empty(deque)) {
        fprintf(stderr, "Error: Attempting to peek from empty deque\n");
        exit(1);
    }
    return deque->front->data;
}

/**
 * Returns the item at the back of the deque without removing it.
 * @param deque Pointer to the Deque structure.
 * @return The item at the back of the deque.
 */
int peek_back(Deque *deque) {
    if (deque->back == NULL) {
        fprintf(stderr, "Error: Attempting to peek from empty deque\n");
        exit(1);
    }
    return deque->back->data;
}

/**
 * Checks if the deque is empty.
 * @param deque Pointer to the Deque structure.
 * @return true if the deque is empty, false otherwise.
 */
bool is_empty(Deque *deque) {
    return deque->front == NULL || deque->size == 0;
}