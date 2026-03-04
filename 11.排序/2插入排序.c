#include <stdio.h>

void InsertSort(int arr[],int size){
    for(int i=1;i<size;++i){//轮数
        int tmp = arr[i],j = i;
        while(j>0 && arr[j-1] > tmp){//只要j大于0，并且前一个大于当前插入的元素
            arr[j] = arr[j-1];//后移一位
            j--;
        }
        arr[j] = tmp;
    }
}

int main(){
    int arr[]={3,5,7,2,9,0,6,1,8,4};

    InsertSort(arr,10);

    for(int i=0;i<10;++i)
        printf("%d ",arr[i]);
}