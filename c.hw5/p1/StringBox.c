#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringBox.h"

char* get_a_string() {
    char* str = (char*)malloc(21 * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    printf("Input a string: ");
    
    scanf(" %20[^\n]", str);
    
    return str;
}

int insertion(char ***strbox, char *str, int str_quantity) {
    if (*strbox == NULL) {
        *strbox = (char**)malloc(sizeof(char*));
    } else {
        *strbox = (char**)realloc(*strbox, (str_quantity + 1) * sizeof(char*));
    }
    
    if (*strbox == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    (*strbox)[str_quantity] = str;
    
    return str_quantity + 1;
}

int list_all(char **strbox, int str_quantity) {
    if (str_quantity == 0) {
        printf("The String Box is empty.\n");
    } else {
        printf("The strings in the box are listed as follows:\n");
        for (int i = 0; i < str_quantity; i++) {
            printf("%d. [%s]\n", i + 1, strbox[i]);
        }
    }
    return 0;
}

int deletion(char ***strbox, int *str_quantity, int index) {
    int real_index = index - 1;
    
    free((*strbox)[real_index]);
    
    for (int i = real_index; i < (*str_quantity) - 1; i++) {
        (*strbox)[i] = (*strbox)[i + 1];
    }
    
    (*str_quantity)--;
    
    if (*str_quantity > 0) {
        *strbox = (char**)realloc(*strbox, (*str_quantity) * sizeof(char*));
        if (*strbox == NULL && *str_quantity > 0) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
    } else {
        free(*strbox);
        *strbox = NULL;
    }
    
    printf("The string at index %d has been deleted.\n", index);
    return 0;
}

int sort_string(char **strbox, int str_quantity) {
    for (int i = 0; i < str_quantity - 1; i++) {
        for (int j = 0; j < str_quantity - i - 1; j++) {
            if (strcmp(strbox[j], strbox[j + 1]) > 0) {
                char *temp = strbox[j];
                strbox[j] = strbox[j + 1];
                strbox[j + 1] = temp;
            }
        }
    }
    return 0;
}
