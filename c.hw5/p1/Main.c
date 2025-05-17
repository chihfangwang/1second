#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringBox.h"
#define true 1
#define false 0

int help_prompt(){
    printf("You can use the following commands:\n");
    printf("--------------------------------------------\n");
    printf("[insert] or [add] - Insert a new string\n");
    printf("[list] or [ls]    - List all strings\n");
    printf("[delete] or [rm]  - Delete a string\n");
    printf("[sort]            - Sort the strings\n");
    printf("[status]          - Show the current number of strings\n");
    printf("[help]            - Show this help message\n");
    printf("[quit] or [exit]  - Exit the String Box\n");
    return 0;
}

int welcome_prompt(){
    printf("Welcome to the String Box!\n");
    help_prompt();
    return 0;
}

int main(){
    int quit = false;
    int index = 0;
    char **strbox = NULL;
    int str_quantity = 0;
    int strbox_size = 0;
    int unreleased_count = 0;
    char *temp = NULL;
    char *cmd = malloc(10*sizeof(char));
    welcome_prompt();
    while(!quit){
        printf("--------------------------------------------\n");
        printf(">> "); // input prompt
        scanf(" %10[^\n]", cmd); // get command within 10 char

        if(!strcmp(cmd, "insert") || !strcmp(cmd, "add")){
            temp = get_a_string();
            str_quantity = insertion(&strbox, temp, str_quantity);
            printf("The string [%s] has been stored.\n", temp);
        } else if(!strcmp(cmd, "list") || !strcmp(cmd, "ls")){
            list_all(strbox, str_quantity);
        } else if(!strcmp(cmd, "delete") || !strcmp(cmd, "rm")){
            if(str_quantity == 0){
                printf("The String Box is empty. Nothing to delete.\n");
                continue;
            }
            list_all(strbox, str_quantity);
            printf("Please enter the index of the string to delete(\'0\' for cancellation): ");
            scanf(" %d", &index);
            if(index == 0){
                printf("Deletion cancelled.\n");
                continue;
            } else if (index > str_quantity || index < 0){
                printf("Invalid index. Operation failed.\n");
                continue;
            } else {
                deletion(&strbox, &str_quantity, index);
            }
        } else if(!strcmp(cmd, "sort")){
            if(str_quantity == 0){
                printf("The String Box is empty. Nothing to sort.\n");
                continue;
            } else if(str_quantity == 1){
                printf("There is only one string in the box. Nothing to sort.\n");
                continue;
            }
            sort_string(strbox, str_quantity);
            printf("Sorting . . . Done!\n");
        } else if(!strcmp(cmd, "status")){
            (str_quantity == 0) ? printf("The String Box is empty.\n") : 
            (str_quantity == 1) ? printf("There is 1 string in the box.\n") :
            printf("There are %d strings in the box.\n", str_quantity);
        } else if(!strcmp(cmd, "help")){
            help_prompt();
        } else if(!strcmp(cmd, "quit") || !strcmp(cmd, "exit")){
            for(int i = 0; i < str_quantity; i++){
                if(strbox[i] != NULL){
                    unreleased_count++;
                    free(strbox[i]);
                    strbox[i] = NULL;
                }
            }
            free(strbox);
            printf("String quantity: %d, Unreleased space quantity: %d\n", str_quantity, unreleased_count);
            printf("The String Box is terminated. Bye!\n");
            quit = true;
        } else {
            printf("Unknown command: [%s]\nEnter \"help\" for instructions.\n", cmd);
        }
    }
    free(cmd);
    return 0;
}