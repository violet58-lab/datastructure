#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
    int i = 0, j = 0;
    int length1 = strlen(haystack);
    int length2 = strlen(needle);

    int nextval[10000] = {0};

    int a = 0;
    int b = -1;
    nextval[0] = -1;

    while (a < length2-1) {
        if (b == -1 || needle[a] == needle[b]) {
            ++a;
            ++b;
            if(needle[a]!=needle[b])nextval[a] = b;
            else nextval[a]=nextval[b];
        } else {
            b = nextval[b];
        }
    }

    while (i < length1 && j < length2) {
        if (j==-1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            j = nextval[j];
        }
    }

    if (j > length2-1) return i - length2;
    return -1;
}