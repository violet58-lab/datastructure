#include <stdio.h>
#include <stdlib.h>
typedef int E;
struct List{
    E *array;
    int capacity;
    int size;
};
typedef struct List* ArrayList;
_Bool initlist(ArrayList list){
    list->array = malloc(sizeof(E)*10);
    if(list->array==NULL)return 0;
    list->capacity=10;
    list->size=0;
    return 1;
}
_Bool merge(ArrayList A,ArrayList B,ArrayList C){
    if(A->size+B->size>C->capacity)return 0;//判断条件！！！
    int i=0,j=0,k=0;
    while(i<A->size && j<B->size)
        if(A->array[i]<=B->array[j])
            C->array[k++]=A->array[i++];
        else
            C->array[k++]=B->array[j++];
    while(i<A->size)
        C->array[k++]=A->array[i++];
    while(j<B->size)
        C->array[k++]=B->array[j++];
    C->size=k;//一定要写！！！
    return 1;
}
void printlist(ArrayList list){
    for(int i=0;i<list->size;i++){
        printf("%d ",list->array[i]);
    }
    printf("\n");
}
int main(){
    struct List A,B,C;
    if(initlist(&A) && initlist(&B) && initlist(&C)){
        for(int i=0;i<6;i++)
            A.array[i]=i;
        for(int i=0;i<3;i++)
            B.array[i]=i;
        A.size=6;
        B.size=3;
        merge(&A,&B,&C);
        printlist(&C);
    }
}