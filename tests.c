#include "hashmap.h"
#include "aiv_unit_test.h"

int tests_succeded = 0;
int tests_failed = 0;
int tests_executed = 0;

TEST(create_hashmap)
{
    struct hashmap *hm = new_hashmap(10);

    ASSERT_THAT(hm != NULL);
    ASSERT_THAT(hm->list != NULL);
    ASSERT_THAT(hm->size == 10);

    free(hm);
}

TEST(add_entry)
{
    struct hashmap *hm = new_hashmap(10);

    int key = 2;
    void *value = (void *)10;
    insert(hm, key, value);

    int pos = hash_key(hm, key);
    struct hashmap_node *temp = hm->list[pos];
    ASSERT_THAT(temp->key == key);
    ASSERT_THAT(temp->value == value);

    free(hm);
}

TEST(add_multiple_entry)
{
    struct hashmap *hm = new_hashmap(10);

    int key = 2;
    void *value = (void *)10;
    insert(hm, key, value);

    int pos = hash_key(hm, key);
    struct hashmap_node *temp = hm->list[pos];
    ASSERT_THAT(temp->key == key);
    ASSERT_THAT(temp->value == value);

    key = 5;
    value = (void *)30;
    insert(hm, key, value);

    pos = hash_key(hm, key);
    temp = hm->list[pos];
    ASSERT_THAT(temp->key == key);
    ASSERT_THAT(temp->value == value);

    free(hm);
}

TEST(replace_value)
{
    struct hashmap *hm = new_hashmap(10);

    int key = 2;
    void *value = (void *)10;
    insert(hm, key, value);

    value = (void *)30;
    insert(hm, key, value);

    int pos = hash_key(hm, key);
    struct hashmap_node *temp = hm->list[pos];
    ASSERT_THAT(temp->key == key);
    ASSERT_THAT(temp->value == value);

    free(hm);
}

TEST(get_value)
{
    struct hashmap *hm = new_hashmap(10);

    int key = 2;
    void *value = (void *)10;
    insert(hm, key, value);

    void *out_value = get_value(hm, key);
    ASSERT_THAT(out_value == value);

    free(hm);
}

int main(int argc, char **argv)
{
    RUN_TEST(create_hashmap);

    RUN_TEST(add_entry);
    RUN_TEST(add_multiple_entry);
    RUN_TEST(replace_value);

    RUN_TEST(get_value);

    PRINT_TEST_RESULTS();
    return 0;
}
