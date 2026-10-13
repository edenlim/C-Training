#include "stdio.h"
#include "string.h"

int main(void) {
  char input[100];
  printf("Enter your text:\n");

  fgets(input, sizeof(input), stdin);
  printf("Chhose your mode:\n");
  // -- Reverse, length, parrot, one at a time
  printf("%s", input);

  return 0;
}