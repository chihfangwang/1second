#include <stdio.h>
#include <stdlib.h>

#include "SouvenirShop.h"

void FreeShelf() {
    if (shelf != NULL) {
        free(shelf);
        shelf = NULL;
    }
}

void help() {
    printf("Options:\n");
    printf("[i] - Insert a souvenir\n");
    printf("[r] - Remove a souvenir\n");
    printf("[f] - Find a souvenir\n");
    printf("[l] - List shelf\n");
    printf("[h] - Help\n");
    printf("[s] - Show shelf capacity & filled\n");
    printf("[q] - Quit\n");
}

int main() {
    SouvenirInit();

    char opt = '\0';
    help();
    
    while (opt != 'q') {
        printf("cmd > ");
        scanf(" %c", &opt);
        switch (opt) {
            case 'i':
                SouvenirInsert();
                break;
            case 'r':
                SouvenirRemove();
                break;
            case 'l':
                SouvenirList();
                break;
            case 'f':
                SouvenirFind();
                break;
            case 'h':
                help();
                break;
            case 's':
                SouvenirShowCapacityNFilled();
                break;
            case 'q':
                printf("Bye!\n");
                break;
            default:
                printf("Invalid option\n");
        }
    }
    FreeShelf();
    return 0;
}
