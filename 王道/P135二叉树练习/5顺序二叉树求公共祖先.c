#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct TreeList{
    E * array;
    int capacity;
};
typedef struct TreeList * TList;

E ComAncestor(TList T,int i,int j){
    if(T->array[i] != '#' && T->array[j] != '#'){
        while(i != j){
            if(i > j)i=i/2;
            else j=j/2;
        }
        return T->array[i];
    }return -1;
}
int main(){
    struct TreeList TreeList;
    TreeList.array=malloc(sizeof(E)*16);
    TreeList.capacity=16;
    TreeList.array[0] = -1;
    for (int k = 1; k <= 15; k++) TreeList.array[k] = k;   // 值=下标，方便观察
    printf("%d",ComAncestor(&TreeList,2,3));
}