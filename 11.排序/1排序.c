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

void quickSort(int arr[],int start,int end){//快速排序，很重要
    if(start>=end)return;
    int left=start,right=end,pivot=arr[left];
    while(left<right){
        while(left<right && arr[right]>=pivot)right--;
        arr[left] = arr[right];//遇到比基准小的，丢到左边去
        while(left<right && arr[left]<=pivot)left++;
        arr[right] = arr[left];//遇到比基准大的，丢到右边去
    }
    arr[left] = pivot;//相遇的位置就是存放基准的位置了
    quickSort(arr,start,left-1);
    quickSort(arr,right+1,end);
}

void dualPivotquickSort(int arr[],int start,int end){//双轴快速排序
    if(start>=end)return;
    if(arr[start]>arr[end])//如果两个基准顺序反了，要换一下
        swap(&arr[start],&arr[end]);
    int pivot1 = arr[start],pivot2 = arr[end];//定义两个基准
    int left = start,right = end,mid = left + 1;
    while(mid<right){
        if(arr[mid]<pivot1)swap(&arr[++left],&arr[mid++]);
        else if(arr[mid]<=pivot2)++mid;
        else{
            while(arr[--right]>=pivot2 &&right > mid);
            if(mid >= right)break;
            swap(&arr[mid],&arr[right]);
        }
    }
    swap(&arr[start],&arr[left]);
    swap(&arr[end],&arr[right]);
    dualPivotquickSort(arr,start,left-1);
    dualPivotquickSort(arr,left+1,right-1);
    dualPivotquickSort(arr,right+1,end);
}

int main(){
    int arr[]={3,5,7,2,9,0,6,1,8,4};

    // bubbleSort(arr,9);
    // insertSort1(arr,9);
    // selectSort(arr,9);
    // selectSort1(arr,9);
    //quickSort(arr,0,9);
    dualPivotquickSort(arr,0,9);

    for(int i=0;i<10;++i)
        printf("%d ",arr[i]);
}