#include <stdio.h>
#include <string.h>
#define MAXLEN 255

typedef struct{
    char ch[MAXLEN+1];//存储串的一维数组。长度为1......255
    int length;//串当前的长度
}SString;

void get_nextval(SString t,int nextval[]){
    int i=1;nextval[1]=0;int j=0;
    while(i<t.length){
        if(j==0||t.ch[i]==t.ch[j]){
            ++i;++j;
            if(t.ch[i]!=t.ch[j])nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}
int index_kmp(SString s,SString t,int pos,int nextval[]){//从pos后面找
    int i=pos,j=1;
    while(i<=s.length && j<=t.length){//i,j都要满足
        if(j==0 || s.ch[i]==t.ch[j]){++i;++j;}//主串和子串依次匹配下一个字符
        else {j=nextval[j];}//主串，子串长度回退
    }
    if(j>t.length)return i-t.length;//返回匹配的第一个字符下标
    else return 0;
}

int main(){
    SString s,t;
    int nextval[MAXLEN + 1] = {0};

    strcpy(s.ch + 1, "aaaaaab");
    strcpy(t.ch + 1, "aaab");

    s.length = strlen(s.ch + 1);
    t.length = strlen(t.ch + 1);

    get_nextval(t, nextval);
    printf("%d",index_kmp(s,t,1,nextval));
}