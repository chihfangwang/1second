#define MIN_SOUVENIRS 2

typedef enum {
    book        = 'b',
    keychain    = 'k',
    t_shirt     = 't'
} Type;

typedef enum { 
    copper  = 'c', 
    steel   = 's', 
    woods   = 'w',
    plastic = 'p'
} KeychainMaterial;

typedef enum { XS, S, M, L, XL, XXL } TShirtSize;

typedef struct {
    int id;
    float price;
    Type type;
    union {
        char author[20]; // For book
        KeychainMaterial material; // For keychain
        TShirtSize size; // For t-shirt
    } attribute;
} Souvenir;

extern Souvenir *shelf;
extern int filled;      // number of souvenirs
extern int capacity;    // capacity of the shelf