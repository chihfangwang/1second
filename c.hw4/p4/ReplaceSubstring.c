#include "ReplaceSubstring.h"
#include <string.h>

void ReplaceSubstring(char article[], const char to_replace[], const char replacement[]) {
    char result[2049] = "";
    char *position;
    char *current = article;
    int to_replace_len = strlen(to_replace);
    int replacement_len = strlen(replacement);
    
    if (to_replace_len == 0) {
        return;
    }

    while ((position = strstr(current, to_replace)) != NULL) {
        strncat(result, current, position - current);
        
        strcat(result, replacement);
        
        current = position + to_replace_len;
    }
    
    strcat(result, current);
    
    strcpy(article, result);
}
