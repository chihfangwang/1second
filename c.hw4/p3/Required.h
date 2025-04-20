typedef struct {
    char year[5];
    char month[3];
    char day[3];
} Date;

typedef struct {
    char name[16];
    Date birthdate;
    char phone[11];
} Contact;

#define MAX_CONTACTS 5
