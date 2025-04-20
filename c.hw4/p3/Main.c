#include <stdio.h>
#include "Contact.h"

Contact contacts[MAX_CONTACTS];

int main() {
    int quit = 0;

    printf("Simple Address Book Program\n");
    Prompt_Help();
    
    while(!quit) {
        char choice = 0;
        printf("Option >> ");
        scanf(" %c", &choice);

        Prompt_SelectedOption(choice);
        switch(choice) {
            case 'a':
                Contact_Add(contacts);
                break;
            case 'd':
                Contact_Delete(contacts);
                break;
            case 'l':
                Contact_List(contacts);
                break;
            case 'u':
                Contact_Update(contacts);
                break;
            case 'h':
                Prompt_Help();
                break;
            case 'q':
                quit = 1;
                break;
            default:
                Prompt_Hint("Invalid option\n");
                break;
        }    
    }
    printf("bye!\n");
    return 0;
}