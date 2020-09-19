#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"

int main()
{
  char str[40];
  printf("$ ");
  fgets(str, 100, stdin);
  
  char **tokens = tokenize(str);

  printf("%s \n", str);
  printf("-- Tokens --\n");
  print_tokens(tokens);
  free_tokens(tokens);
  return 0;
}
