#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SouvenirShop.h"

Souvenir *shelf = NULL; // 宣告全域變數
int size = 0;          // 已儲存的商品數量
int capacity = 0;      // 目前所配置的空間大小

// 初始化紀念品商店
void SouvenirInit() {
    // 依照 MIN_SOUVENIRS 常數的值，動態配置記憶體空間
    capacity = MIN_SOUVENIRS;
    shelf = (Souvenir *)malloc(capacity * sizeof(Souvenir));
    size = 0;
}

// 檢查特定ID的商品是否已存在
int findSouvenirIndex(int id) {
    for (int i = 0; i < size; i++) {
        if (shelf[i].id == id) {
            return i;
        }
    }
    return -1; // 未找到
}

// 新增商品
void SouvenirInsert() {
    int id;
    float price;
    char type;
    
    // 檢查是否需要擴展空間
    if (size >= capacity) {
        printf("Expanding for insufficient capacity!\n");
        capacity *= 2;
        shelf = (Souvenir *)realloc(shelf, capacity * sizeof(Souvenir));
    }
    
    // 輸入ID
    printf("ID? ");
    scanf("%d", &id);
    
    // 檢查ID是否重複
    if (findSouvenirIndex(id) != -1) {
        printf("ID %d exists\n", id);
        return;
    }
    
    // 輸入價格
    printf("Price? ");
    scanf("%f", &price);
    
    // 輸入商品類型
    printf("Type [(b)ook, (k)eychain, (t)-shirt]? ");
    scanf(" %c", &type);
    
    // 建立新商品結構體
    Souvenir newSouvenir;
    newSouvenir.id = id;
    newSouvenir.price = price;
    
    // 根據商品類型輸入詳細資料
    switch (type) {
        case 'b': // 書本
            newSouvenir.type = book;
            printf("Author? ");
            scanf(" %[^\n]", newSouvenir.attribute.author);
            break;
            
        case 'k': // 鑰匙圈
            newSouvenir.type = keychain;
            printf("Material [(c)opper, (s)teel, (w)oods, (p)lastic]? ");
            char material;
            scanf(" %c", &material);
            
            // 檢查材質是否有效
            if (material != 'c' && material != 's' && material != 'w' && material != 'p') {
                printf("Invalid material\n");
                return;
            }
            newSouvenir.attribute.material = (KeychainMaterial)material;
            break;
            
        case 't': // T恤
            newSouvenir.type = t_shirt;
            printf("Size (XS, S, M, L, XL, XXL)? ");
            char sizeStr[4];
            scanf("%s", sizeStr);
            
            TShirtSize tsize;
            if (strcmp(sizeStr, "XS") == 0) {
                tsize = XS;
            } else if (strcmp(sizeStr, "S") == 0) {
                tsize = S;
            } else if (strcmp(sizeStr, "M") == 0) {
                tsize = M;
            } else if (strcmp(sizeStr, "L") == 0) {
                tsize = L;
            } else if (strcmp(sizeStr, "XL") == 0) {
                tsize = XL;
            } else if (strcmp(sizeStr, "XXL") == 0) {
                tsize = XXL;
            } else {
                printf("Invalid T-shirt size\n");
                return;
            }
            newSouvenir.attribute.size = tsize;
            break;
            
        default:
            printf("Invalid type\n");
            return;
    }
    
    // 將新商品加入到 shelf 中
    shelf[size] = newSouvenir;
    size++;
    printf("Souvenir added\n");
}

// 移除商品
void SouvenirRemove() {
    int id;
    printf("ID? ");
    scanf("%d", &id);
    
    // 搜尋要刪除的商品
    int index = findSouvenirIndex(id);
    if (index == -1) {
        printf("ID %d not found\n", id);
        return;
    }
    
    // 調整陣列，移除該商品
    for (int i = index; i < size - 1; i++) {
        shelf[i] = shelf[i + 1];
    }
    size--;
    
    // 檢查是否需要縮減空間
    if (size < capacity / 2 && capacity > MIN_SOUVENIRS) {
        printf("Shrinking for excessive capacity!\n");
        capacity /= 2;
        shelf = (Souvenir *)realloc(shelf, capacity * sizeof(Souvenir));
    }
    
    printf("Souvenir removed\n");
}

// 列出所有商品
void SouvenirList() {
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

// 尋找特定ID的商品
void SouvenirFind() {
    int id;
    printf("ID? ");
    scanf("%d", &id);
    
    int index = findSouvenirIndex(id);
    if (index == -1) {
        printf("ID %d not found\n", id);
        return;
    }
    
    // 顯示找到的商品資訊
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

// 顯示架子的容量和已填充數量
void SouvenirShowCapacityNFilled() {
    printf("Shelf capacity: %d\n", capacity);
    printf("Souvenirs filled: %d\n", size);
}
