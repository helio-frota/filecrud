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

void print_menu() {
  printf("\n");
  printf("(r) Read the file\n");
  printf("(w) Write in the file\n");
  printf("(q) exit\n");
}

int main() {
  char option;
  print_menu();
  do {
    if (scanf("%c", &option) != 1) {  // test to avoid unused result warning
      printf("failed to read the option");
    }
    __fpurge(stdin);  // from stdio_ext.h

    if (option == 'r') {
      read_content();
    } else if (option == 'w') {
      write_content();
    } else {
      print_menu();
    }

  } while (option != 'q');
}