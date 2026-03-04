#include <stdio.h>

void SelectSort(int arr[],int size){
    for(int i=0;i<size-1;++i){//轮数
        int min = i;
        for(int j=i;j<size;++j)
            if(arr[j] < arr[min])min = j;
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort1(int arr[],int size){//选择排序优化，小的往左走，大的往右走
    int left = 0,right = size - 1;//确定出已经排好的边界
    while(left<right){
        int min = left,max = right;
        for(int i=left;i<=right;i++){//同时找最大的和最小的
            if(arr[i]<arr[min])min = i;
            if(arr[i]>arr[max])max = i;
        }
        swap(&arr[max],&arr[right]);//先把最大的换到右边
        //大的换到右边之后，游客热能被换出来的是最小的，所以判断一下
        //如果遍历发现最小的就是当前右边排序的第一个元素
        //所以要把min改为换出来的位置
        if(min == right)min = max;
        swap(&arr[min],&arr[left]);
        left++;
        right--;
    }
}

int main(){
    int arr[]={3,5,7,2,9,0,6,1,8,4};

    SelectSort1(arr,10);

    for(int i=0;i<10;++i)
        printf("%d ",arr[i]);
}