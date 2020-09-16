#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char str[25];
  
  printf("$ ");
  scanf("%s", str);

  printf("%s \n", str);
  return 0;
}
