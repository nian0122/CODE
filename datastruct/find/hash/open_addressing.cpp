#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007
#define DELETED -1

typedef struct {
    int key;
    int value;
} HashItem;

HashItem hash_table[HASH_SIZE];

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
    int start = index;
    
    while (hash_table[index].key != 0 && hash_table[index].key != DELETED) {
        if (hash_table[index].key == key) {
            hash_table[index].value = value;
            return;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }
    
    hash_table[index].key = key;
    hash_table[index].value = value;
}

// 查找元素
int hash_search(int key) {
    int index = hash_func(key);
    int start = index;
    
    while (hash_table[index].key != 0) {
        if (hash_table[index].key == key) {
            return hash_table[index].value;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) {
            break;
        }
    }
    
    return -1; // 未找到
}

// 删除元素
void hash_delete(int key) {
    int index = hash_func(key);
    int start = index;
    
    while (hash_table[index].key != 0) {
        if (hash_table[index].key == key) {
            hash_table[index].key = DELETED;
            return;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == start) {
            break;
        }
    }
}

// 测试函数
void test_open_addressing() {
    hash_init();
    
    hash_insert(1, 100);
    hash_insert(2, 200);
    hash_insert(10008, 300); // 测试冲突
    
    printf("Search 1: %d\n", hash_search(1));
    printf("Search 2: %d\n", hash_search(2));
    printf("Search 10008: %d\n", hash_search(10008));
    
    hash_delete(2);
    printf("After delete, search 2: %d\n", hash_search(2));
}

int main() {
    test_open_addressing();
    return 0;
}
