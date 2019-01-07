#include "hashmap.h"

struct hashmap *new_hashmap(int size)
{
    struct hashmap *hm = (struct hashmap *)malloc(sizeof(struct hashmap));
    hm->size = size;
    hm->list = (struct hashmap_node **)malloc(sizeof(struct hashmap_node *) * size);

    for (int i = 0; i < size; i++)
    {
        hm->list[i] = NULL;
    }

    return hm;
}

int hash_key(struct hashmap *hm, int key)
{
    if (key < 0)
    {
        return -(key % hm->size);
    }
    return (key % hm->size);
}

void insert(struct hashmap *hm, int key, void *value)
{
    int pos = hash_key(hm, key);
    struct hashmap_node *list = hm->list[pos];
    struct hashmap_node *newNode = (struct hashmap_node *)malloc(sizeof(struct hashmap_node));
    struct hashmap_node *temp = list;

    while (temp)
    {
        if (temp->key == key)
        {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = list;
    hm->list[pos] = newNode;
}

void *get_value(struct hashmap *hm, int key)
{
    int pos = hash_key(hm, key);
    struct hashmap_node *list = hm->list[pos];
    struct hashmap_node *temp = list;
    while (temp)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

void remove_value(struct hashmap *hm, int key)
{
    int pos = hash_key(hm, key);
    struct hashmap_node *list = hm->list[pos];
    struct hashmap_node *previous = list;

    if (previous->next == NULL)
    {
        if (previous->key == key)
        {
            previous = NULL;
        }
        return;
    }

    struct hashmap_node *current = previous->next;

    while (current)
    {
        if (current->key == key)
        {
            previous->next = current->next;
            free(current);
            current = NULL;
        }
    }
}