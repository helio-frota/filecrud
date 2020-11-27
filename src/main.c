#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>

#define DB_FILE "db.txt"
#define CSI "\x1b["
#define RESET "0m"
#define GREEN "32m"
#define MAGENTA "35m"

/**
 * Reads the content of the db.txt file.
 *
 * @name read_content
 * @returns {void} void
 */
void read_content() {
  FILE* f = fopen(DB_FILE, "r");
  char c = fgetc(f);
  printf("%s%s", CSI, MAGENTA);
  printf("content inside file: %c\n", c);
  printf("%s%s", CSI, RESET);
  fclose(f);
}

/**
 * Writes '1' to the db.txt file
 * and prints out message about it.
 * @name write_content
 * @returns {void} void
 */
void write_content() {
  FILE* f = fopen(DB_FILE, "w");
  // easy and well explained here https://www.youtube.com/watch?v=oXEDMNXzuo4
  srand(time(NULL));
  int zero_or_one = rand() % 2;
  printf("%s%s", CSI, MAGENTA);
  printf("writing %d in db.txt\n", zero_or_one);
  printf("%s%s", CSI, RESET);
  fputc('0' + zero_or_one, f);  // adding 0 to the int we get the ASCII value
  fclose(f);
}

/**
 * Prints the menu to stdout.
 *
 * This function uses system("clear") call from stdlib.h.
 *
 * This function uses some ANSI escape codes.
 * @name print_menu
 * @returns {void} void
 */
void print_menu() {
  int result = system("clear");  // from stdlib.h
  if (result != 0) {
    printf("error trying to clear the screen");
  }
  printf("%s%s", CSI, GREEN);
  printf("\n");
  printf("(r) Read the file\n");
  printf("(w) Write in the file\n");
  printf("(q) exit\n");
  printf("%s%s", CSI, RESET);
}

/**
 * This is the main function.
 * @name main
 * @returns {int} int
 */
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
    } else if (option == 'q') {
      break;
    } else {
      print_menu();
    }

  } while (option != 'q');
}