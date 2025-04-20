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
}
