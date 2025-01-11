#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define HASH_SIZE 10007

typedef struct {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* data[HASH_SIZE];
} Map;

Map* create_map();
void put(Map* obj, int key, int value);
int get(Map* obj, int key);
int getOrDefault(Map* obj, int key, int defaultValue);
void remove_key(Map* obj, int key);
bool contains(Map* obj, int key);
void free_map(Map* obj);

#endif // HASH_H