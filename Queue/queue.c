#include "queue.h"

/**
 * Creates a new queue.
 * @return Pointer to the created Queue structure.
 */
Queue* create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

/**
 * Checks if the queue is empty.
 * @param queue Pointer to the Queue structure.
 * @return True if the queue is empty, false otherwise.
 */
bool is_empty(Queue *queue) {
    return queue == NULL || queue->size == 0;
}

/**
 * Inserts an item into the queue.
 * @param queue Pointer to the Queue structure.
 * @param data The data to be inserted.
 */
void enqueue(Queue *queue, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (empty(queue)) {
        queue->front = node;
    } 
    else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->size++;
}

/**
 * Removes and returns the item at the front of the queue.
 * @param queue Pointer to the Queue structure.
 * @return The item at the front of the queue.
 */
int dequeue(Queue *queue) {
    if (empty(queue)) {
        fprintf(stderr, "Error: Attempting to dequeue from empty queue\n");
        exit(1);
    }
    Node *node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

/**
 * Returns the item at the front of the queue without removing it.
 * @param queue Pointer to the Queue structure.
 * @return The item at the front of the queue.
 */
int peek(Queue *queue) {
    if (empty(queue)) {
        fprintf(stderr, "Error: Attempting to peek from empty queue\n");
        exit(1);
    }
    return queue->front->data;
}

/**
 * Frees the memory allocated for the queue.
 * @param queue Pointer to the Queue structure to be freed.
 */
void free_queue(Queue *queue) {
    while (!empty(queue)) {
        Node *node = queue->front;
        queue->front = node->next;
        free(node);
        queue->size--;
    }
    free(queue);
    queue = NULL;
}