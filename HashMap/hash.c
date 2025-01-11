#include "hash.h"

Map* create_map() {
    Map* map = (Map*)malloc(sizeof(Map));
    for (int i = 0; i < HASH_SIZE; i++) {
        map->data[i] = NULL;
    }
    return map;
}

uint32_t hash_int(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

void put(Map* obj, int key, int value) {
    int index = hash_int(key) % HASH_SIZE;
    HashNode* node = obj->data[index];
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = obj->data[index];
    obj->data[index] = newNode;
}

int get(Map* obj, int key) {
    int index = hash_int(key) % HASH_SIZE;
    HashNode* node = obj->data[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    fprintf(stderr, "Key not found: %d\n", key);
    exit(1);
}

int getOrDefault(Map* obj, int key, int defaultValue) {
    int index = hash_int(key) % HASH_SIZE;
    HashNode* node = obj->data[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return defaultValue;
}

void remove_key(Map* obj, int key) {
    int index = hash_int(key) % HASH_SIZE;
    HashNode* node = obj->data[index];
    HashNode* prev = NULL;
    while (node != NULL) {
        if (node->key == key) {
            if (prev == NULL) {
                obj->data[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
    fprintf(stderr, "Key not found: %d\n", key);
    exit(1);
}

bool contains(Map* obj, int key) {
    int index = hash_int(key) % HASH_SIZE;
    HashNode* node = obj->data[index];
    while (node != NULL) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void free_map(Map* obj) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = obj->data[i];
        while (node != NULL) {
            HashNode* next = node->next;
            free(node);
            node = next;
        }
    }
    free(obj);
}