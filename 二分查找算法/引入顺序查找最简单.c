#include <stdio.h>
int search(int *num,int numsize,int target){
    for(int i =0;i<numsize;i++)
        if(num[i]==target)
            return i;
    return -1;
}
int main(){
    int a[6]={1,2,3,4,5,6},b=6;
    
    printf("%d",search(a,sizeof(a)/sizeof(int),b));
}