#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 128
typedef int K;
typedef int V;

typedef struct LNode{//结点定义
    K key;
    V value;
    struct LNode *next;
}* Node;

typedef struct HashTable{//哈希表
    struct LNode * table;
}* HashTable;

void init(HashTable hashtable){
    hashtable->table = malloc(sizeof(struct LNode)*SIZE);
    for(int i=0;i<SIZE;++i){
        hashtable->table[i].key = -1;
        hashtable->table[i].next = NULL;
    }
}

int hash(unsigned int key){//有负数，负数取模还是负数，将负数转为较大的下标
    return key % SIZE;
}

Node createNode(K key,V value){   //创建结点专用函数
    Node node = malloc(sizeof(struct LNode));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void insert(HashTable hashtable,K key,V value){
    int hashcode = hash(key);
    Node head = &hashtable->table[hashcode];
    while(head->next)
    head = head->next;
    head->next = createNode(key,value);
}

Node find(HashTable hashTable, K key){
    int hashCode = hash(key);
    Node head = hashTable->table + hashCode;
    while (head->next && head->next->key != key)
        head = head->next;
    return head->next;
}

int* result(int i,int j,int *returnSize)
{
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int)*2);
    result[0] = i;
    result[1] = j;
    return result;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct HashTable table;
    init(&table);
    for(int i=0;i<numsSize;++i){
        Node node = find(&table,target-nums[i]);
        if(node)return result(i,node->value,returnSize);
        insert(&table,nums[i],i);
    }
    return NULL;
}