#include <stdio.h>
#include <string.h>
#include "ReverseString.h"

void GetString(char *str) {
    fgets(str, 1024, stdin);
    
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void TrimSpaces(char *str) {
    if (str == NULL) {
        return;
    }
    
    int len = strlen(str);
    if (len == 0) return;
    
    int start = 0;
    while (str[start] == ' ') {
        start++;
    }
    
    if (start == len) {
        str[0] = '\0';
        return;
    }
    
    int end = len - 1;
    while (end >= 0 && str[end] == ' ') {
        end--;
    }
    
    int i;
    for (i = 0; i <= end - start; i++) {
        str[i] = str[start + i];
    }
    str[i] = '\0';
}

void ReverseString(char *str) {
    if (str == NULL) {
        return;
    }
    
    int length = strlen(str);
    int i, j;
    char temp;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    TrimSpaces(str);
}
