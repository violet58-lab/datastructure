#include <stdio.h>
#include <string.h>
#define MAXLEN 255

typedef struct{
    char ch[MAXLEN+1];//存储串的一维数组。长度为1......255
    int length;//串当前的长度
}SString;

int index(SString s,SString t,int pos){//从pos后面找
    int i=pos,j=1;
    while(i<=s.length && j<=t.length){//i,j都要满足
        if(s.ch[i]==t.ch[j]){++i;++j;}//主串和子串依次匹配下一个字符
        else {i=i-j+2;j=1;}//主串，子串长度回退
    }
    if(j>t.length)return i-t.length;//返回匹配的第一个字符下标
    else return 0;
}
int main(){
    SString s,t;
    strcpy(s.ch + 1, "aaaaaab");
    strcpy(t.ch + 1, "aaab");

    s.length = strlen(s.ch + 1);
    t.length = strlen(t.ch + 1);
    printf("%d",index(s,t,1));
}