#include "list.h"

/**
 * Creates a new linked list.
 * @return Pointer to the created ListNode structure.
 */
ListNode *create_list() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 0;
    head->size = 0;
    head->next = NULL;
    return head;
}

/**
 * Inserts an item into the linked list.
 * @param head Pointer to the head of the linked list.
 * @param data The data to be inserted.
 * @param position The position at which to insert the data.
 */
void insert(ListNode *head, int data, int position) {
    if (position < 0 || position > head->size) {
        fprintf(stderr, "Error: Attempting to insert at invalid index\n");
        exit(1);
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    if (position == 0) {
        node->next = head->next;
        head->next = node;
        head->size++;
        return;
    }
    ListNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    head->size++;
}

/**
 * Removes an item from the linked list.
 * @param head Pointer to the head of the linked list.
 * @param position The position at which to remove the data.
 */
void remove(ListNode *head, int position) {
    if (position < 0 || position >= head->size) {
        fprintf(stderr, "Error: Attempting to remove from invalid index\n");
        exit(1);
    }
    if (position == 0) {
        ListNode *temp = head->next;
        head->next = temp->next;
        free(temp);
        head->size--;
        return;
    }
    ListNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    ListNode *temp = current->next;
    current->next = temp->next;
    free(temp);
    head->size--;
}

/**
 * Checks if the linked list is empty.
 * @param head Pointer to the head of the linked list.
 * @return true if the linked list is empty, false otherwise.
 */
bool is_empty(ListNode *head) {
    return head == NULL || head->size == 0;
}

/**
 * Frees the memory allocated for the linked list.
 * @param head Pointer to the head of the linked list.
 */
void free_list(ListNode *head) {
    ListNode *current = head->next;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}