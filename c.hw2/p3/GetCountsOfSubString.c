#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "GetCountsOfSubString.h"

char toLower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

int isSubstringMatch(char* srcstr, int startIndex, char* substr) {
    int i = 0;
    
    while (substr[i] != '\0') {
        if (srcstr[startIndex + i] == '\0' || 
            toLower(srcstr[startIndex + i]) != toLower(substr[i])) {
            return 0;
        }
        i++;
    }
    
    return 1;
}
int GetCountsOfSubString(char* srcstr, char* substr) {
    int count = 0;
    int srcLen = strlen(srcstr);
    int subLen = strlen(substr);
    if (subLen == 0 || srcLen == 0) {
        return 0;
    }
    for (int i = 0; i <= srcLen - subLen; i++) {
        if (isSubstringMatch(srcstr, i, substr)) {
            count++;
        }
    }
    
    return count;
}
