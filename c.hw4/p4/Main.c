#include <stdio.h>

#include "ReplaceSubstring.h"

int main() {
    char article[2049], to_replace[16], replacement[16];

    scanf(" %2048[^\n]", article);
    scanf(" %16s", to_replace);
    scanf(" %16s", replacement);

    ReplaceSubstring(article, to_replace, replacement);

    printf("%s\n", article);

    return 0;
}