#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int data;
    int size;
    struct ListNode *next;
} ListNode;

ListNode *create_list();
// Position parameter should be 0-indexed
void insert(ListNode *head, int data, int position); // add at a specific position
void remove(ListNode *head, int position); // remove at a specific position
bool is_empty(ListNode *head);
void free_list(ListNode *head);

#endif // LIST_H