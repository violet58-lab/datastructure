#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int i = 0, j = 0;
    int length1 = strlen(haystack);
    int length2 = strlen(needle);

    int next[10000] = {0};

    int a = 0;
    int b = -1;
    next[0] = -1;

    while (a < length2-1) {
        if (b == -1 || needle[a] == needle[b]) {
            ++a;
            ++b;
            next[a] = b;
        } else {
            b = next[b];
        }
    }

    while (i < length1 && j < length2) {
        if (j==-1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    if (j > length2-1) return i - length2;//或j>=length2
    return -1;
}