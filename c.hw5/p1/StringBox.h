#ifndef STRINGBOX_H
#define STRINGBOX_H

char* get_a_string();

int insertion(char ***strbox, char *str, int str_quantity);

int list_all(char **strbox, int str_quantity);

int deletion(char ***strbox, int *str_quantity, int index);

int sort_string(char **strbox, int str_quantity);

#endif 
