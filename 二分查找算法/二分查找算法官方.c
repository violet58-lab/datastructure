#include <stdio.h>
int search(int* num,int left,int right,int target){
    if(left>right) return-1;
    int mid = (left+right)/2;
    if(num[mid]==target) return mid;
    if(num[mid]>target) return search(num,left,mid-1,target);//中间的不要了(+/-1)，直接递归
    else
        return search(num,mid+1,right,target);
}
int main(){
    int a[6]={1,2,3,4,5,6},b;
    scanf("%d",&b);
    printf("%d",search(a,0,6,b));
}