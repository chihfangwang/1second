#include "checkID.h"
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

int formatCheck(char *str) {
    int len = strlen(str);
    if (len != 10) {
        return false;
    }
    
    if (!isupper(str[0])) {
        return false;
    }
    
    for (int i = 1; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    
    return true;
}

int isValid(char *str) {
    int cityCode = 0;
    
    switch (str[0]) {
        case 'A': cityCode = 10; break;
        case 'B': cityCode = 11; break;
        case 'C': cityCode = 12; break;
        case 'D': cityCode = 13; break;
        case 'E': cityCode = 14; break;
        case 'F': cityCode = 15; break;
        case 'G': cityCode = 16; break;
        case 'H': cityCode = 17; break;
        case 'I': cityCode = 34; break;
        case 'J': cityCode = 18; break;
        case 'K': cityCode = 19; break;
        case 'L': cityCode = 20; break;
        case 'M': cityCode = 21; break;
        case 'N': cityCode = 22; break;
        case 'O': cityCode = 35; break;
        case 'P': cityCode = 23; break;
        case 'Q': cityCode = 24; break;
        case 'R': cityCode = 25; break;
        case 'S': cityCode = 26; break;
        case 'T': cityCode = 27; break;
        case 'U': cityCode = 28; break;
        case 'V': cityCode = 29; break;
        case 'W': cityCode = 32; break;
        case 'X': cityCode = 30; break;
        case 'Y': cityCode = 31; break;
        case 'Z': cityCode = 33; break;
        default: return false;
    }
    
    int LD1 = cityCode / 10;
    int LD2 = cityCode % 10;
    
    int D1 = str[1] - '0';
    int D2 = str[2] - '0';
    int D3 = str[3] - '0';
    int D4 = str[4] - '0';
    int D5 = str[5] - '0';
    int D6 = str[6] - '0';
    int D7 = str[7] - '0';
    int D8 = str[8] - '0';
    int D9 = str[9] - '0';
    
    int sum = LD1 * 1 + LD2 * 9 + D1 * 8 + D2 * 7 + D3 * 6 + D4 * 5 + D5 * 4 + D6 * 3 + D7 * 2 + D8 * 1 + D9 * 1;
    
    return (sum % 10 == 0);
}

void strcatHouseholdReg(char *p, char *output) {
    char region[20] = "";
    
    switch (*p) {
        case 'A': strcpy(region, "台北市"); break;
        case 'B': strcpy(region, "台中市"); break;
        case 'C': strcpy(region, "基隆市"); break;
        case 'D': strcpy(region, "台南市"); break;
        case 'E': strcpy(region, "高雄市"); break;
        case 'F': strcpy(region, "新北市"); break;
        case 'G': strcpy(region, "宜蘭縣"); break;
        case 'H': strcpy(region, "桃園市"); break;
        case 'I': strcpy(region, "嘉義市"); break;
        case 'J': strcpy(region, "新竹縣"); break;
        case 'K': strcpy(region, "苗栗縣"); break;
        case 'L': strcpy(region, "台中縣"); break;
        case 'M': strcpy(region, "南投縣"); break;
        case 'N': strcpy(region, "彰化縣"); break;
        case 'O': strcpy(region, "新竹市"); break;
        case 'P': strcpy(region, "雲林縣"); break;
        case 'Q': strcpy(region, "嘉義縣"); break;
        case 'R': strcpy(region, "台南縣"); break;
        case 'S': strcpy(region, "高雄縣"); break;
        case 'T': strcpy(region, "屏東縣"); break;
        case 'U': strcpy(region, "花蓮縣"); break;
        case 'V': strcpy(region, "台東縣"); break;
        case 'W': strcpy(region, "金門縣"); break;
        case 'X': strcpy(region, "澎湖縣"); break;
        case 'Y': strcpy(region, "陽明山管理局"); break;
        case 'Z': strcpy(region, "連江縣"); break;
        default: strcpy(region, "未知區域"); break;
    }
    
    strcat(output, region);
    strcat(output, "\n");
}

char* whichGender(char *p) {
    static char gender[5];
    
    if (*p == '1') {
        strcpy(gender, "男性");
    } else if (*p == '2') {
        strcpy(gender, "女性");
    } else {
        strcpy(gender, "未知");
    }
    
    return gender;
}

char* whichIdentityType(char *p) {
    static char type[50];
    int code = *p - '0';
    
    if (code >= 0 && code <= 5) {
        strcpy(type, "台灣出生的本國國民");
    } else if (code == 6) {
        strcpy(type, "原為外國人之入籍國民");
    } else if (code == 7) {
        strcpy(type, "原無國籍國民");
    } else if (code == 8) {
        strcpy(type, "原為香港或澳門居民的入籍國民");
    } else if (code == 9) {
        strcpy(type, "原為大陸居民的入籍國民");
    } else {
        strcpy(type, "未知身分別");
    }
    
    return type;
}
