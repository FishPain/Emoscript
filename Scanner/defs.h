#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Token structure
struct token {
    int token;
    int intValue;
};


// When the token is INTLIT (Integer Literal), 
// the intValue will hold the int value scanned.
// Tokens
enum {
    T_PLUS,
    T_MINUS,
    T_STAR, 
    T_SLASH,
    T_INTLIT
};

