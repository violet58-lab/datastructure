#include <stdio.h>

#define MAXLEN 255

typedef struct{
    char ch[MAXLEN+1];//存储串的一维数组
    int length;//串当前的长度
}SString;