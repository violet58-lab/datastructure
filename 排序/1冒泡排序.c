#include <stdio.h>

void bubbleSort(int arr[],int size){//优化版（就是加了flag）
    for(int i=0;i<size-1;++i){//轮数
        int flag = 1;
        for(int j=0;j<size-1-i;++j){
            if(arr[j]>arr[j+1]){
                flag = 0;
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if(flag)break;
    }
}

int main(){
    int arr[]={3,5,7,2,9,0,6,1,8,4};

    bubbleSort(arr,10);

    for(int i=0;i<10;++i)
        printf("%d ",arr[i]);
}