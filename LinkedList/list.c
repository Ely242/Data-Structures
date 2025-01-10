#include "list.h"

ListNode *create_list() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 0;
    head->size = 0;
    head->next = NULL;
    return head;
}

void insert(ListNode *head, int data, int position) {
    if (position < 0 || position > head->size) {
        return;
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

void remove(ListNode *head, int position) {
    if (position < 0 || position >= head->size) {
        return;
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

bool empty(ListNode *head) {
    return head->size == 0;
}

void free_list(ListNode *head) {
    ListNode *current = head->next;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}