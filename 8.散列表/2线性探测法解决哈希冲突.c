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
    int hashcode = hash(element->key),count = 0;
    while(hashtable->table[hashcode]){//发现哈希冲突，继续寻找
        hashcode = hash(element->key + ++count);
    }
    hashtable->table[hashcode] = element;
}

bool find(HashTable hashtable,int key){
    int hashcode = hash(key),count = 0;
    const int startindex = hashcode;//记录起始位置，转一圈回来了的停
    do{
        if(hashtable->table[hashcode]->key == key)return 1;//如果找到就返回1
        hashcode = hash(key+ ++count);
    }while(hashcode != startindex && hashtable->table[hashcode]);//没找到继续找
    return 0;
}

Element create(int key){
    Element element = malloc(sizeof(struct Element));
    element->key = key;
    return element;
}

int main(){
    struct HashTable table;
    init(&table);

    for(int i=1;i<=9;++i)
        insert(&table,create(i*9));
    for(int i=0;i<9;++i)
        printf("%d ",table.table[i]->key);
}