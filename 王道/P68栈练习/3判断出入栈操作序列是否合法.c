//栈初态和终态为空,入栈和出栈次数要一致
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool is_right(char *a){
    int i=0;//i为数组a的下标
    int j=0,k=0;
    while(a[i]!='\0'){
        switch(a[i]){
            case 'I':j++;break;
            case 'O':k++;
        if(k>j)
            return 0;}
        i++;
    }
    if(k!=j)return 0;
    else return 1;
}
int main(){
    char a[1000];
    scanf("%s",&a);
    printf("%d",is_right(a));
}