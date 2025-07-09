#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007

// 链表节点结构
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

HashNode* hash_table[HASH_SIZE];

// 哈希函数
int hash_func(int key) {
    return key % HASH_SIZE;
}

// 初始化哈希表
void hash_init() {
    memset(hash_table, 0, sizeof(hash_table));
}

// 插入元素
void hash_insert(int key, int value) {
    int index = hash_func(key);
    HashNode* node = hash_table[index];
    
    // 检查是否已存在相同key
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    
    // 创建新节点并插入链表头部
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

// 查找元素
int hash_search(int key) {
    int index = hash_func(key);
    HashNode* node = hash_table[index];
    
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    
    return -1; // 未找到
}

// 删除元素
void hash_delete(int key) {
    int index = hash_func(key);
    HashNode* node = hash_table[index];
    HashNode* prev = NULL;
    
    while (node != NULL) {
        if (node->key == key) {
            if (prev == NULL) {
                hash_table[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

// 释放哈希表内存
void hash_free() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hash_table[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

// 测试函数
void test_separate_chaining() {
    hash_init();
    
    hash_insert(1, 100);
    hash_insert(2, 200);
    hash_insert(10008, 300); // 测试冲突
    
    printf("Search 1: %d\n", hash_search(1));
    printf("Search 2: %d\n", hash_search(2));
    printf("Search 10008: %d\n", hash_search(10008));
    
    hash_delete(2);
    printf("After delete, search 2: %d\n", hash_search(2));
    
    hash_free();
}

int main() {
    test_separate_chaining();
    return 0;
}
