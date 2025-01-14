#include "priority_queue.h"

/* PRIORITY QUEUE FUNCTIONS */
/**
 * Creates a new priority queue.
 * @return Pointer to the created PriorityQueue structure.
 */
PriorityQueue* create_priority_queue(){
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}
/**
 * Swaps two integers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * Maintains the heap property during insertion.
 * @param pq Pointer to the PriorityQueue structure.
 * @param index The index of the item to be heapified.
 */
void heapify_up(PriorityQueue* pq, int index){
    if (index > 0 && pq->items[(index - 1) / 2] > pq->items[index]) {
        // Swap the item with its parent if it is smaller
        swap(&pq->items[(index - 1) / 2], &pq->items[index]);
        // Recursively heapify the parent
        heapify_up(pq, (index - 1) / 2);
    }
}
/**
 * Maintains the heap property during deletion.
 * @param pq Pointer to the PriorityQueue structure.
 * @param index The index of the item to be heapified.
 */
void heapify_down(PriorityQueue* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    // Find the smallest of the current node and its children
    if (left < pq->size && pq->items[left] < pq->items[smallest]){
        smallest = left;
    }

    if (right < pq->size && pq->items[right] < pq->items[smallest]){
        smallest = right;
    }
    // If the smallest node is not the current node, swap them and heapify the child
    if (smallest != index) {
        swap(&pq->items[index], &pq->items[smallest]);
        heapify_down(pq, smallest);
    }
}
/**
 * Inserts an item into the priority queue.
 * @param pq Pointer to the PriorityQueue structure.
 * @param value The value to be inserted.
 * @return true if the insertion was successful, false if the queue is full.
 */
bool enqueue(PriorityQueue* pq, int value){
    if (pq->size == MAX_SIZE) {
        return false;
    }
    pq->items[pq->size++] = value;
    heapify_up(pq, pq->size - 1);
    return true;
}
/**
 * Removes and returns the item at the front of the priority queue.
 * @param pq Pointer to the PriorityQueue structure.
 * @return The item at the front of the priority queue, or -1 if the queue is empty.
 */
int dequeue(PriorityQueue* pq){
    if (isEmpty(pq)){
        fprintf(stderr, "Error: Attempting to dequeue from empty priority queue\n");
        exit(1);
    }
    int item = pq->items[0];
    pq->items[0] = pq->items[--pq->size];
    heapifyDown(pq, 0);
    return item;
}
/**
 * Returns the item at the front of the priority queue without removing it.
 * @param pq Pointer to the PriorityQueue structure.
 * @return The item at the front of the priority queue, or -1 if the queue is empty.
 */
int peek(PriorityQueue* pq){
    if (empty(pq)){
        fprintf(stderr, "Error: Attempting to peek from empty priority queue\n");
        exit(1);
    }
    return pq->items[0];
}
/**
 * Checks if the priority queue is empty.
 * @param pq Pointer to the PriorityQueue structure.
 * @return true if the priority queue is empty, false otherwise.
 */
bool is_empty(PriorityQueue* pq){
    return pq == NULL || pq->size == 0;
}
/**
 * Frees the memory allocated for the priority queue.
 * @param pq Pointer to the PriorityQueue structure to be freed.
 */
void free_priority_queue(PriorityQueue* pq){
    if (pq != NULL){
        free(pq);
        pq = NULL;
    }
}