#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#include "history.c"

List *history; // History record
int count = 0; // Keeps track of number of history items

/* UI for history of inputed tokens. 
   (Complete with a menu) */
int main()
{
  history = init_history();
    
 menu:
  system("clear");
  printf("\n        -- Menu --          \n");
  printf("\n   (0) Input Strings        \n");
  printf("   (1) View History by Id     \n");
  printf("   (2) View All History       \n");
  printf("   (3) Exit                   \n");
  printf("\n<Select an option by number>\n");
  printf("\n> ");
  
  char option[1];
  fgets(option, 10, stdin);

  // Checks if history is empty
  if (!(history->root->next) && (atoi(option) == 1 || atoi(option) == 2)) {
    printf("\nHistory is empty. (Hit ENTER to try again)\n");
    fgets(option, 10, stdin);
    goto menu;
  }

  // Determines which option was selected from the menu
  switch (atoi(option)) {
  case 0: // Adds history
    system("clear");
    printf("\n(Type 0 to return)\n");
    printf("\nType anything then press ENTER. (Repeat for multiple strings)\n\n");

    char str[50];
    
    while (1) {
      printf("> ");
      fgets(str, 50, stdin);
      
      if (*str == '0') {
	break;
      }
      else {
	add_history(history, str);
        count++;
      }
    }
    
    goto menu;
  case 1: // Gets history by ID
    system("clear");
    printf("\n(Type 0 to return)\n");
    printf("\nType id as 1 or 2 or 3..etc. (Repeat for multiple strings)\n\n");
    
    while (1) {
      char id[1];
      printf("> ");
      fgets(id, 100, stdin);

      if (atoi(id) < 0 || atoi(id) > count) {
	printf("Invalid id. (Hit ENTER to try again)\n");
	fgets(id, 100, stdin);
      }
      else if(atoi(id) == 0) {
	break;
      }
      else {
	char **tokens = tokenize(get_history(history, atoi(id)));
	printf("\n");
	print_tokens(tokens);
	free_tokens(tokens);
      }
    }
    
    goto menu;
  case 2: // Gets all history
    system("clear");
    printf("\n");
    print_history(history);
    printf("\nHit ENTER to return.");
    printf("\n\n> ");
    
    char rand[1];
    fgets(rand, 100, stdin);
    
    goto menu;
  case 3: // Exit option
    system("clear");
    
    break;
  default:
    goto menu;
  }

  free_history(history); // Frees allocated memory from history
  return 0;
}
