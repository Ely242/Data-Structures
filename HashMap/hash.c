#include "hash.h"

/**
 * Creates a new map.
 * @return Pointer to the created Map structure.
 */
Map* create_map() {
    Map* map = (Map*)malloc(sizeof(Map));
    for (int i = 0; i < HASH_SIZE; i++) {
        map->data[i] = NULL;
    }
    return map;
}

/**
 * Hash function for integers.
 * @param x The integer to be hashed.
 * @return The hash value of the integer.
 */
uint32_t hash_int(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

/**
 * Inserts a key-value pair into the map.
 * @param obj Pointer to the Map structure.
 * @param key The key to be inserted.
 * @param value The value to be inserted.
 */
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

/**
 * Returns the value associated with the given key.
 * @param obj Pointer to the Map structure.
 * @param key The key to search for.
 * @return The value associated with the key.
 */
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

/**
 * Returns the value associated with the given key, or a default value if the key is not found.
 * @param obj Pointer to the Map structure.
 * @param key The key to search for.
 * @param defaultValue The default value to return if the key is not found.
 * @return The value associated with the key, or the default value if the key is not found.
 */
int get_or_default(Map* obj, int key, int defaultValue) {
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

/**
 * Checks if the map contains the given key.
 * @param obj Pointer to the Map structure.
 * @param key The key to search for.
 * @return true if the key is found, false otherwise.
 */
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

/**
 * Removes the key-value pair with the given key from the map.
 * @param obj Pointer to the Map structure.
 * @param key The key to be removed.
 */
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

/**
 * Checks if the map contains the given key.
 * @param obj Pointer to the Map structure.
 * @param key The key to search for.
 * @return true if the key is found, false otherwise.
 */
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

/**
 * Frees the memory allocated for the map.
 * @param obj Pointer to the Map structure to be freed.
 */
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