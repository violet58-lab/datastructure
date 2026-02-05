#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int n = (int)strlen(haystack);
    int m = (int)strlen(needle);
    if (m == 0) return 0;

    // lps[i] = needle[0..i] 的最长真前后缀长度
    int lps[10000];              
    lps[0] = 0;
    for (int i = 1, len = 0; i < m; ) {
        if (needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    for (int i = 0, j = 0; i < n; ) {
        if (haystack[i] == needle[j]) {
            i++; j++;
            if (j == m) return i - m;
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i++;         
        }
    }
    return -1;
}