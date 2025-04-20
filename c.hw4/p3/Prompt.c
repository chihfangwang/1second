#include <stdio.h>
#include "Prompt.h"

void Prompt_Help() {
    printf("[ %-3s| %-27s]\n", "a.", "Add new contact");
    printf("[ %-3s| %-27s]\n", "d.", "Delete contact");
    printf("[ %-3s| %-27s]\n", "l.", "List all contacts");
    printf("[ %-3s| %-27s]\n", "u.", "Update contact");
    printf("[ %-3s| %-27s]\n", "h.", "Help");
    printf("[ %-3s| %-27s]\n", "q.", "Quit");
}

void Prompt_SingleContact(Contact contact) {
    printf("[ %-15s | %s-%s-%s%5s | %-15s ]\n", 
        contact.name,
        contact.birthdate.year, contact.birthdate.month, contact.birthdate.day, "",
        contact.phone
    );
}

void Prompt_GridTitle() {
    printf("[ %-15s | %-15s | %-15s ]\n", "Name", "Birthdate", "Phone");
}

void Prompt_Hint(const char* hint) {
    printf("===> Hint: %s", hint);
}

void Prompt_SelectedOption(char c) {
    printf("Selected option: (%c)\n", c);
}