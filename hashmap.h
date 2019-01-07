#include <stdio.h>
#include <stdlib.h>

struct hashmap_node
{
    int key;
    void *value;
    struct hashmap_node *next;
};

struct hashmap
{
    int size;
    struct hashmap_node **list;
};

struct hashmap *new_hashmap(int size);
int hash_key(struct hashmap *hm, int key);
void insert(struct hashmap *hm, int key, void *value);
void *get_value(struct hashmap *hm, int key);
void remove_value(struct hashmap *hm, int key);