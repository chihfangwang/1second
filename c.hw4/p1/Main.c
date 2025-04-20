#include <stdio.h>

#include "ReverseString.h"

int main() {
    char str[1025];

    printf("Enter a string: ");

    GetString(str);
    ReverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}