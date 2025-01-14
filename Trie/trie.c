#include "trie.h"

/**
 * Creates a new trie node.
 * @return Pointer to the created TrieNode structure.
 */
TrieNode *create_trie() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

/**
 * Inserts a key into the trie.
 * @param root Pointer to the root of the trie.
 * @param key The key to be inserted.
 */
void insert(TrieNode *root, char *key) {
    TrieNode *node = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = create_trie();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

/**
 * Searches for a key in the trie.
 * @param root Pointer to the root of the trie.
 * @param key The key to search for.
 * @return true if the key is found, false otherwise.
 */
bool search(TrieNode *root, char *key) {
    TrieNode *node = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWord;
}

/**
 * Checks if the trie contains a key with the given prefix.
 * @param root Pointer to the root of the trie.
 * @param prefix The prefix to search for.
 * @return true if the trie contains a key with the given prefix, false otherwise.
 */
bool starts_with(TrieNode *root, char *prefix) {
    TrieNode *node = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return true;
}

/**
 * Frees the memory allocated for the trie.
 * @param root Pointer to the root of the trie to be freed.
 */
void free_trie(TrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}