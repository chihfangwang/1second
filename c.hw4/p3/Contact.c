#include <stdio.h>
#include <string.h>
#include "Contact.h"

// 初始化通訊錄
void initialize(Contact contacts[]) {
    static int initialized = 0;
    if (!initialized) {
        for (int i = 0; i < MAX_CONTACTS; i++) {
            contacts[i].name[0] = '\0';
        }
        initialized = 1;
    }
}

// 檢查通訊錄是否為空
int isEmpty(Contact contacts[]) {
    initialize(contacts);
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (contacts[i].name[0] != '\0') {
            return 0; // 不為空
        }
    }
    return 1; // 為空
}

// 查找空位
int findEmptySlot(Contact contacts[]) {
    initialize(contacts);
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (contacts[i].name[0] == '\0') {
            return i;
        }
    }
    return -1; // 沒有空位
}

// 根據姓名查找聯絡人
int findContactByName(Contact contacts[], const char* name) {
    initialize(contacts);
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (contacts[i].name[0] != '\0' && strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // 未找到
}

// 添加新聯絡人
void Contact_Add(Contact contacts[]) {
    initialize(contacts);
    int emptySlot = findEmptySlot(contacts);
    
    if (emptySlot == -1) {
        Prompt_Hint("Address book is full\n");
        return;
    }
    
    Contact newContact;
    memset(&newContact, 0, sizeof(Contact));
    
    printf("Enter name: ");
    scanf("%15s", newContact.name);
    
    // 檢查是否已存在該姓名
    if (findContactByName(contacts, newContact.name) != -1) {
        Prompt_Hint("Contact already exists\n");
        return;
    }
    
    printf("Enter birthdate (YYYY MM DD): ");
    scanf("%4s %2s %2s", 
          newContact.birthdate.year, 
          newContact.birthdate.month, 
          newContact.birthdate.day);
    
    printf("Enter phone number: ");
    scanf("%10s", newContact.phone);
    
    // 添加到通訊錄
    contacts[emptySlot] = newContact;
    Prompt_Hint("Contact added successfully\n");
}

// 刪除聯絡人
void Contact_Delete(Contact contacts[]) {
    initialize(contacts);
    if (isEmpty(contacts)) {
        Prompt_Hint("List is empty\n");
        return;
    }
    
    char name[16];
    printf("Enter name to delete: ");
    scanf("%15s", name);
    
    int index = findContactByName(contacts, name);
    
    if (index == -1) {
        Prompt_Hint("Contact not found\n");
        return;
    }
    
    // 清空該聯絡人資料
    memset(&contacts[index], 0, sizeof(Contact));
    Prompt_Hint("Contact deleted successfully\n");
}

// 列出所有聯絡人
void Contact_List(Contact contacts[]) {
    initialize(contacts);
    if (isEmpty(contacts)) {
        Prompt_Hint("No records were found\n");
        return;
    }
    
    Prompt_GridTitle();
    
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (contacts[i].name[0] != '\0') {
            Prompt_SingleContact(contacts[i]);
        }
    }
}

// 更新聯絡人資訊
void Contact_Update(Contact contacts[]) {
    initialize(contacts);
    if (isEmpty(contacts)) {
        Prompt_Hint("List is empty\n");
        return;
    }
    
    char name[16];
    printf("Enter name to update: ");
    scanf("%15s", name);
    
    int index = findContactByName(contacts, name);
    
    if (index == -1) {
        Prompt_Hint("Contact not found\n");
        return;
    }
    
    printf("Enter new birthdate (YYYY MM DD): ");
    scanf("%4s %2s %2s", 
          contacts[index].birthdate.year, 
          contacts[index].birthdate.month, 
          contacts[index].birthdate.day);
    
    printf("Enter new phone number: ");
    scanf("%10s", contacts[index].phone);
    
    Prompt_Hint("Contact updated successfully\n");
}
