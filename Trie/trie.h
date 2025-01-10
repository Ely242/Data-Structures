#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode *create_trie();
void insert(TrieNode *root, char *key);
bool search(TrieNode *root, char *key);
bool starts_with(TrieNode *root, char *prefix);
void free_trie(TrieNode *root);

#endif // TRIE_H