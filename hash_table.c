#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for a linked list node
struct node {
  char *key;
  char *value;
  struct node *next;
};

// structure for a hash table
struct hash_table {
  int size;
  struct node **buckets;
};

// hash function
unsigned long djb2_hash(char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c; // hash * 33 + c
  }
  return hash;
}

// create a new node
struct node *create_node(char *key, char *value) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->key = key;
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

// create a new hash table
struct hash_table *create_hash_table(int size) {
  struct hash_table *ht =
      (struct hash_table *)malloc(sizeof(struct hash_table));
  ht->size = size;
  ht->buckets = (struct node **)malloc(sizeof(struct node *) * size);
  for (int i = 0; i < size; i++) {
    ht->buckets[i] = NULL;
  }
  return ht;
}

// insert a key-value pair into the hash table
void insert(struct hash_table *ht, char *key, char *value) {
  unsigned long hash_value = djb2_hash(key) % ht->size;
  struct node *node = ht->buckets[hash_value];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      node->value = value;
      return;
    }
    node = node->next;
  }
  struct node *new_node = create_node(key, value);
  new_node->next = ht->buckets[hash_value];
  ht->buckets[hash_value] = new_node;
}

// get a value by key from the hash table
char *get(struct hash_table *ht, char *key) {
  unsigned long hash_value = djb2_hash(key) % ht->size;
  struct node *node = ht->buckets[hash_value];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }
  return NULL;
}

// delete a key-value pair from the hash table
void delete (struct hash_table *ht, char *key) {
  unsigned long hash_value = djb2_hash(key) % ht->size;
  struct node *prev_node = NULL;
  struct node *node = ht->buckets[hash_value];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      if (prev_node == NULL) {
        ht->buckets[hash_value] = node->next;
      } else {
        prev_node->next = node->next;
      }
      free(node);
      return;
    }
    prev_node = node;
    node = node->next;
  }
}
int main() {
  struct hash_table *ht = create_hash_table(100);
  insert(ht, "key1", "value1");
  insert(ht, "key2", "value2");
  char *val = get(ht, "key1");
  printf("Value for key1: %s\n", val);
  delete (ht, "key1");
  val = get(ht, "key1");
  if (val == NULL) {
    printf("Key1 is not in hash table.\n");
  }
  return 0;
}
