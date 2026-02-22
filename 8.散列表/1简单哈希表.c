#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

typedef struct Element{//定义
    int key;
}*Element;

typedef struct HashTable{
    Element * table;
}* HashTable;

void init(HashTable hashtable){//初始化
    hashtable->table = malloc(sizeof(Element)*SIZE);
    for(int i=0;i<SIZE;++i)
        hashtable->table[i] = NULL;
}

int hash(int key){//哈希函数
    return key % SIZE;
}

void insert(HashTable hashtable,Element element){//插入函数 
    int hashcode = hash(element->key); 
    hashtable->table[hashcode] = element; 
}

bool find(HashTable hashtable,int key){ 
    int hashcode = hash(key); 
    if(hashtable->table[hashcode] == NULL)return 0; 
    return hashtable->table[hashcode]->key == key; 
}

Element create(int key){
    Element element = malloc(sizeof(struct Element));
    element->key = key;
    return element;
}

int main(){
    struct HashTable table;
    init(&table);

    insert(&table,create(10));
    insert(&table,create(7)); 
    insert(&table,create(19)); 
    insert(&table,create(23)); 
    
    printf("%d\n",find(&table,11)); 
    printf("%d",find(&table,23));
}