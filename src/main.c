#include <stdio.h>
#include <stdio_ext.h>

#define DB_FILE "db.txt"

void read_lines() {
  FILE* f = fopen(DB_FILE, "r");
}

int main() {
  char option;
  do {
    printf("(r) Read the file\n");
    printf("(w) Write in the file\n");
    printf("(q) exit\n");
    if (scanf("%c", &option) != 1) {  // test to avoid unused result warning
      printf("failed to read the option");
    }
    __fpurge(stdin);  // from stdio_ext.h
    printf("\nselected option %s\n\n", &option);
  } while (option != 'q');
}