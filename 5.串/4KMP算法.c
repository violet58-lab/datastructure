#include <stdio.h>
#include <string.h>
#define MAXLEN 255

typedef struct{
    char ch[MAXLEN+1];//存储串的一维数组。下标为1......255
    int length;//串当前的长度
}SString;
void get_next(SString t,int next[]){
    int i=1;//当前正在计算 next 的位置前一个字符
    next[1]=0;//首元素已经赋值了
    int j=0;//当前已经匹配成功的“最长前后缀长度”
    while(i<t.length){//注意不能有等，因为i会先加再用
        if(j==0||t.ch[i]==t.ch[j]){//当前最长前后缀还能不能再加1？
            ++i;++j;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
/*void get_nextval(SString t,int &nextval[]){
    i=1;nextval[1]=0;j=0;
    while(i<t.length){
        if(j==0||t.ch[i]==t.ch[j]){
            ++i;++j;
            if(t.ch[i]!=t.ch[j])nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}*/
int index_kmp(SString s,SString t,int pos,int next[]){//从pos后面找
    int i=pos,j=1;
    while(i<=s.length && j<=t.length){//i,j都要满足
        if(s.ch[i]==t.ch[j]){++i;++j;}//主串和子串依次匹配下一个字符
        else {j=next[j];}//子串长度回退
    }
    if(j>t.length)return i-t.length;//返回匹配的第一个字符下标
    else return 0;
}

int main(){
    SString s,t;
    int next[MAXLEN + 1] = {0};

    strcpy(s.ch + 1, "aaaaaab");
    strcpy(t.ch + 1, "aaab");

    s.length = strlen(s.ch + 1);
    t.length = strlen(t.ch + 1);

    get_next(t, next);
    printf("%d",index_kmp(s,t,1,next));
}