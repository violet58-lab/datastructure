/*给一个严格升序的数组arr和整数k,
找出数组里第k个缺失的正整数*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//解法一：顺序查找
int findkthpositive(int* arr,int arrsize,int k){
    int i=0,j=1;
    while(i<arrsize){
        if(arr[i]==j){//第一个对了，接着往后
            i++;
        }else{//其实是--k
            if(!--k)return j;//--k为0，说明找到了，返回j
        }
        j++;
    }
    return j+k-1;//遍历完了还没找到，那么就按顺序输出下面的
}//解法二：用二分查找实现
//被跳过的k满足:k=arr[i]-i-1
int findkthpositive(int* arr,int arrsize,int k){
    if(arr[0]>k)return k;//特殊[7,8,9],k=5
    int left=0,right=arrsize;
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]-mid-1>=k) right=mid;
        else left=mid+1;
    }
    return k-(arr[left-1]-(left-1)-1)-arr[left-1];//返回题中给的k与算出来的那个k的差，加上最后一位
}