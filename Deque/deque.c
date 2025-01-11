#include "deque.h"

Deque *create_deque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
    return deque;
}

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

int pop_front(Deque *deque) {
    if (deque->front == NULL) {
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

int pop_back(Deque *deque) {
    if (deque->back == NULL) {
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

int peek_front(Deque *deque) {
    if (deque->front == NULL) {
        fprintf(stderr, "Error: Attempting to peek from empty deque\n");
        exit(1);
    }
    return deque->front->data;
}

int peek_back(Deque *deque) {
    if (deque->back == NULL) {
        fprintf(stderr, "Error: Attempting to peek from empty deque\n");
        exit(1);
    }
    return deque->back->data;
}

bool is_empty(Deque *deque) {
    return deque->front == NULL || deque->size == 0;
}