#include "scan.c";

void main(int argc, char *argv[]) {
  init();
  Infile = fopen(argv[1], "r");
  scanfile();
  exit(0);
}

// List of printable tokens
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

// Loop scanning in all the tokens in the input file.
// Print out details of each token found.
static void scanfile() {
  struct token T;

  while (scan(&T)) {
    printf("Token %s", tokstr[T.token]);
    if (T.token == T_INTLIT)
      printf(", value %d", T.intValue);
    printf("\n");
  }
}