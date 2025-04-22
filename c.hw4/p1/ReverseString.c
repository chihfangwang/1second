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
    
    // 移除頭部空格
    int start = 0;
    while (str[start] == ' ') {
        start++;
    }
    
    // 如果全是空格
    if (start == len) {
        str[0] = '\0';
        return;
    }
    
    // 移除尾部空格
    int end = len - 1;
    while (end >= 0 && str[end] == ' ') {
        end--;
    }
    
    // 移動字符串
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
    
    // 先反轉字串
    int length = strlen(str);
    int i, j;
    char temp;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    // 移除頭尾空格，保留中間空格
    TrimSpaces(str);
}
