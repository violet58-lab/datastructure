#include <stdio.h>

#define MAXLEN 255
typedef struct Chunk{
    char ch[MAXLEN];
    struct Chunk *next;
}Chunk;

typedef struct {
    Chunk *head,*tail;
    int curlen;
}LString;