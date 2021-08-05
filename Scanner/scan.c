#include "data.h";
#include "defs.h";
#include "decl.h";

// Get the next character form the input file
static int next(void) {
    int c;
    if (Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fget(Infile);
    if ('\n' == c){
        Line++;
    }
    return c;
}

// Put back unwanted characters
static void putback(int c){
    Putback = c;
}


// Skip white space and newlines, that the compiller don't need to deal with
static int skip(void){
    int c;
    c = next();
    
    while (' ' == c || '\t' == c || '\n' == c || 'r' == c || '\f' == c){
        c = next();
    }
    return (c);
}


int scan(struct token *t){
  int c;
  // Skip the white spaces
  c = skip();

  switch (c)
  {
  case EOF:
    return (0);
  case '+':
    t -> token = T_PLUS;
  case '-':
    t -> token = T_MINUS;
  case '*':
    t -> token = T_STAR;
  case '/':
    t -> token = T_SLASH;
  default:
    if (isdigit(c)){
      t -> intValue = scanint(c);
      t -> token = T_INTLIT;
      break;
    }

    printf("Unrecognised character %c on line %d\n", c, Line);
    exit(1);
  }
  return (1);
}


// Scan and return an integer literal
// value from the input file. Store
// the value as a string in Text.
static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return val;
}

// Return the position of character c
// in string s, or -1 if c not found
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}