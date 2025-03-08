#include "IsPalindrome.h"
#include <ctype.h>
#include <string.h>

int IsPalindrome(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    int len = strlen(str);
    char clean[257]; 
    int cleanIndex = 0;
    
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            clean[cleanIndex++] = toupper(str[i]);
        }
    }
    clean[cleanIndex] = '\0'; 
    
    if (cleanIndex == 0) {
        return 0;
    }
    
    int left = 0;
    int right = cleanIndex - 1;
    
    while (left < right) {
        if (clean[left] != clean[right]) {
            return 0;
        }
        left++;
        right--;
    }
    
    return 1; 
}
