#include <stdio.h>
#define MAX_LEN 1024

int main() {
  /*Read the file.*/

  char ch;
  int char_count = 0, word_count = 0, line_count = 0;
  char file_name[MAX_LEN];
  FILE *fp;

  printf("Enter a file name: ");
  scanf("%s", file_name);

  fp = fopen(file_name, "r");

  if(fp == NULL) {
    printf("Could not open the file %s\n", file_name);
    return 1;
  }

  while ((ch = fgetc(fp)) != EOF) {
    char_count++;

   

      if(ch = '\0' || ch == '\n') 
      line_count++;

  }

  printf("In the file %s:\n", file_name);
  printf("Number of characters: %d.\n", char_count);
  printf("Number of lines: %d.\n", line_count);

  return 0;
}