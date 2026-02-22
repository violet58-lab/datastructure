#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

typedef struct LNode{//结点定义
    int key;
    struct LNode *next;
}* Node;

typedef struct HashTable{//哈希表
    struct LNode * table;//这个数组专门保存头结点
}* HashTable;

void init(HashTable hashtable){
    hashtable->table = malloc(sizeof(struct LNode)*SIZE);
    for(int i=0;i<SIZE;++i){
        hashtable->table[i].key = -1;
        hashtable->table[i].next = NULL;
    }
}

int hash(int key){   //哈希函数
    return key % SIZE;
}

Node createNode(int key){   //创建结点专用函数
    Node node = malloc(sizeof(struct LNode));
    node->key = key;
    node->next = NULL;
    return node;
}

void insert(HashTable hashtable,int key){
    int hashcode = hash(key);
    Node head = &hashtable->table[hashcode];
    while(head->next)//找插入位置
    head = head->next;
    head->next = createNode(key);
}

bool find(HashTable hashTable, int key){
    int hashCode = hash(key);
    Node head = hashTable->table + hashCode;//与上文2种写法
    while (head->next && head->key != key)   //直到最后或是找到为止
        head = head->next;
    return head->key == key;   //直接返回是否找到
}

int main(){
    struct HashTable table;    //创建哈希表
    init(&table);

    insert(&table, 10);
    insert(&table, 19);
    insert(&table, 20);

    printf("%d\n", find(&table, 20));
    printf("%d\n", find(&table, 17));
    printf("%d\n", find(&table, 19));
}