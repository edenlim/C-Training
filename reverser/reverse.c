#include "stdio.h"
#include <string.h>

void string_reverser(const char *source, char *destination);

int main(void) {
  char user_input[50];
  int str_len;
  printf("Enter a word:\n");
  scanf("%49s", user_input);

  str_len = strlen(user_input);
  printf("The length of the word is: %d\n", str_len);

  char reverse_input[str_len + 1];

  string_reverser(user_input, reverse_input);
  printf("Your reversed word is: %s\n", reverse_input);

  return 0;
}

void string_reverser(const char *user_input, char *reverse_input) {
  int str_len = strlen(user_input);
  for (int i = 0; i < str_len; i++) {
    reverse_input[i] = user_input[str_len - 1 - i];
  }

  reverse_input[str_len] = '\0';
}