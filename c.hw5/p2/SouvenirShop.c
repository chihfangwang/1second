#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SouvenirShop.h"

Souvenir *shelf = NULL;
int size = 0;         
int capacity = 0;    

void SouvenirInit() {
    capacity = MIN_SOUVENIRS;
    shelf = (Souvenir *)malloc(capacity * sizeof(Souvenir));
    if (shelf == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    size = 0;
}

int findSouvenirIndex(int id) {
    for (int i = 0; i < size; i++) {
        if (shelf[i].id == id) {
            return i;
        }
    }
    return -1;
}

void SouvenirInsert() {
    if (size >= capacity) {
        printf("Expanding for insufficient capacity!\n");
        capacity *= 2;
        shelf = (Souvenir *)realloc(shelf, capacity * sizeof(Souvenir));
        if (shelf == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    
    Souvenir newItem;
    
    printf("ID? ");
    scanf("%d", &newItem.id);
    
    if (findSouvenirIndex(newItem.id) != -1) {
        printf("ID %d exists\n", newItem.id);
        return;
    }
    
    printf("Price? ");
    scanf("%f", &newItem.price);
    
    char type;
    printf("Type [(b)ook, (k)eychain, (t)-shirt]? ");
    scanf(" %c", &type);
    
    switch (type) {
        case 'b': 
            newItem.type = book;
            printf("Author? ");
            scanf(" %19[^\n]", newItem.attribute.author);
            break;
        case 'k': 
            newItem.type = keychain;
            printf("Material [(c)opper, (s)teel, (w)oods, (p)lastic]? ");
            scanf(" %c", &type);
            
            switch (type) {
                case 'c':
                    newItem.attribute.material = copper;
                    break;
                case 's':
                    newItem.attribute.material = steel;
                    break;
                case 'w':
                    newItem.attribute.material = woods;
                    break;
                case 'p':
                    newItem.attribute.material = plastic;
                    break;
                default:
                    printf("Invalid material\n");
                    return;
            }
            break;
        case 't':
            newItem.type = t_shirt;
            printf("Size (XS, S, M, L, XL, XXL)? ");
            char size[4];
            scanf(" %3s", size);
            
            if (strcmp(size, "XS") == 0) {
                newItem.attribute.size = XS;
            } else if (strcmp(size, "S") == 0) {
                newItem.attribute.size = S;
            } else if (strcmp(size, "M") == 0) {
                newItem.attribute.size = M;
            } else if (strcmp(size, "L") == 0) {
                newItem.attribute.size = L;
            } else if (strcmp(size, "XL") == 0) {
                newItem.attribute.size = XL;
            } else if (strcmp(size, "XXL") == 0) {
                newItem.attribute.size = XXL;
            } else {
                printf("Invalid T-shirt size\n");
                return;
            }
            break;
        default:
            printf("Invalid type\n");
            return;
    }
    
    shelf[size] = newItem;
    size++;
    printf("Souvenir added\n");
}

void SouvenirRemove() {
    int id;
    printf("ID? ");
    scanf("%d", &id);
    
    int index = findSouvenirIndex(id);
    
    if (index == -1) {
        printf("ID %d not found\n", id);
        return;
    }
    
    for (int i = index; i < size - 1; i++) {
        shelf[i] = shelf[i + 1];
    }
    size--;
    
    if (size * 2 <= capacity && capacity > MIN_SOUVENIRS) {
        printf("Shrinking for excessive capacity!\n");
        capacity /= 2;
        shelf = (Souvenir *)realloc(shelf, capacity * sizeof(Souvenir));
        if (shelf == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    
    printf("Souvenir removed\n");
}

void SouvenirList() {
    if (size == 0) {
        printf("The shelf is empty\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("[ID: %d][Price: $%.2f]", shelf[i].id, shelf[i].price);
        
        switch (shelf[i].type) {
            case book:
                printf("[Type: Book, Author: %s]\n", shelf[i].attribute.author);
                break;
            case keychain:
                printf("[Type: Keychain, Material: ");
                switch (shelf[i].attribute.material) {
                    case copper:
                        printf("Copper");
                        break;
                    case steel:
                        printf("Steel");
                        break;
                    case woods:
                        printf("Woods");
                        break;
                    case plastic:
                        printf("Plastic");
                        break;
                }
                printf("]\n");
                break;
            case t_shirt:
                printf("[Type: T-Shirt, Size: ");
                switch (shelf[i].attribute.size) {
                    case XS:
                        printf("XS");
                        break;
                    case S:
                        printf("S");
                        break;
                    case M:
                        printf("M");
                        break;
                    case L:
                        printf("L");
                        break;
                    case XL:
                        printf("XL");
                        break;
                    case XXL:
                        printf("XXL");
                        break;
                }
                printf("]\n");
                break;
        }
    }
}

void SouvenirFind() {
    int id;
    printf("ID? ");
    scanf("%d", &id);
    
    int index = findSouvenirIndex(id);
    
    if (index == -1) {
        printf("ID %d not found\n", id);
        return;
    }
    
    printf("[ID: %d][Price: $%.2f]", shelf[index].id, shelf[index].price);
    
    switch (shelf[index].type) {
        case book:
            printf("[Type: Book, Author: %s]\n", shelf[index].attribute.author);
            break;
        case keychain:
            printf("[Type: Keychain, Material: ");
            switch (shelf[index].attribute.material) {
                case copper:
                    printf("Copper");
                    break;
                case steel:
                    printf("Steel");
                    break;
                case woods:
                    printf("Woods");
                    break;
                case plastic:
                    printf("Plastic");
                    break;
            }
            printf("]\n");
            break;
        case t_shirt:
            printf("[Type: T-Shirt, Size: ");
            switch (shelf[index].attribute.size) {
                case XS:
                    printf("XS");
                    break;
                case S:
                    printf("S");
                    break;
                case M:
                    printf("M");
                    break;
                case L:
                    printf("L");
                    break;
                case XL:
                    printf("XL");
                    break;
                case XXL:
                    printf("XXL");
                    break;
            }
            printf("]\n");
            break;
    }
}

void SouvenirShowCapacityNFilled() {
    printf("Shelf capacity: %d\n", capacity);
    printf("Souvenirs filled: %d\n", size);
}
