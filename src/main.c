#include <stdio.h>
#include <stdio_ext.h>

#define DB_FILE "db.txt"

void read_content() {
  FILE* f = fopen(DB_FILE, "r");
  char c = fgetc(f);
  printf("content inside file: %c\n", c);
  fclose(f);
}

void write_content() {
  FILE* f = fopen(DB_FILE, "w");
  fputc('1', f);
  fclose(f);
}

int main() {
  char option;
  do {
    printf("\n");
    printf("(r) Read the file\n");
    printf("(w) Write in the file\n");
    printf("(q) exit\n");
    if (scanf("%c", &option) != 1) {  // test to avoid unused result warning
      printf("failed to read the option");
    }
    __fpurge(stdin);  // from stdio_ext.h

    if (option == 'r') {
      read_content();
    } else if (option == 'w') {
      write_content();
    }

  } while (option != 'q');
}