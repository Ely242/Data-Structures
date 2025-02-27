#include "queue.h"

/**
 * Creates a new queue.
 * @return Pointer to the created Queue structure.
 */
Queue* create_queue(void (*free_data)(void*), char* (*to_string)(void*)) {
    assert(free_data != NULL);
    assert(to_string != NULL);

    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    queue->to_string = to_string;
    queue->free_data = free_data;
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
void enqueue(Queue *queue, void* data) {
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
void* dequeue(Queue *queue) {
    if (empty(queue)) {
        return NULL;
    }
    Node *node = queue->front;
    void* data = node->data;
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
void* peek(Queue *queue) {
    if (empty(queue)) {
        return NULL;
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
        queue->free_data(node->data);
        queue->front = node->next;

        free(node);
        queue->size--;
    }
    free(queue);
    queue = NULL;
}

/**
 * Prints the contents of the queue.
 * @param queue Pointer to the Queue structure.
 * @param print_data Function pointer to print the data.
 */
char* queue_to_string(Queue *queue) {
    Node *node = queue->front;
    char *str = (char*)malloc(sizeof(char));
    int len = 1;
    strcpy(str, "");

    while (node != NULL) {
        char *data_str = queue->to_string(node->data);
        len += strlen(data_str);
        str = (char*)realloc(str, len * sizeof(char));

        strcat(str, data_str);
        node = node->next;
        free(data_str);
    }

    return str; // returned string must be freed by the caller
}

/**
 * Clears the queue. Results in an empty queue.
 * @param queue Pointer to the Queue structure.
 */
void clear_queue(Queue *queue) {
    while (!empty(queue)) {
        Node *node = queue->front;
        queue->free_data(node->data);
        queue->front = node->next;

        free(node);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

/**
 * Returns the size of the queue.
 * @param queue Pointer to the Queue structure.
 * @return The size of the queue.
 */
int get_size(Queue *queue) {
    return queue == NULL ? 0 : queue->size;
}