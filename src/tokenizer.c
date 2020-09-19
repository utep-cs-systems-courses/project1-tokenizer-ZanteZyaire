#include <stdio.h>
#include <stdlib.h>

/* Iterates through entire string, keeping
   count of each char visited, up until zero-terminator. */
int string_length(char *string)
{
  int length = 0;

  while (*string) {
    length++;
    string++;
  }
  
  return length;
}

/* Checks if the character is a space character ie.
   space ('  ')
   tab   ('\t') or
   0     ('\0') */
int space_char(char c)
{
  if (c == ' ' || c == '\t' || c == '\0') return 1;
  else return 0;
}

/* Checks for non-space-characters by
   utilizing the space_char function. */
int non_space_char(char c)
{
  return !(space_char(c));
}

/* Determines the start of the next word in str by
   iterating through str until a non-space-character
   is found or returns the zero-terminator of str. */
char *word_start(char *str)
{
  while (*str) {
    if (non_space_char(*str)) return str;
    str++;
  }
  
  return str;
}

/* Determines the length of a word by iterating 
   until a space character is found. */
int word_length(char *word)
{
  int wordLength = 0;

  while (non_space_char(*word)) {
    wordLength++;
    word++;
  }

  return wordLength;
}

/* Returns the zero terminator of a word 
   by returning the pointer that is word length away. */
char *word_terminator(char *word)
{
  return word + word_length(word);
}

/* Counts the number of words in str by retrieveing 
   the start of every word from the previous' word terminator. */
int count_words(char *str)
{
  int count = 0;

  while (*str) {
    str = word_start(word_terminator(str));
    count++;
  }
  
  return count;
}

/* Copies a word of length len from inStr
   then appends a zero-terminator at the end. */
char *copy_str(char *inStr, short len)
{
  char *copiedStr = (char *) malloc(len + 1);

  for (int i = 0; i < len; i++) {
    copiedStr[i] = inStr[i];
  }

  copiedStr[len] = '\0';
  
  return copiedStr;
}

/* Allocates an array of pointers then fills each
   index with a pointer to a copied word in str.
   Appends a zero-terminator at the end. */
char **tokenize(char *str)
{
  char **tokens = malloc((count_words(str) + 1) * sizeof(char *));
  
  int i = 0;
  
  while (*str) {
    str = word_start(str);

    tokens[i++] = copy_str(str, word_length(str));

    str = word_terminator(str);
  }

  tokens[i] = '\0';
  
  return tokens;
}

/* Prints all tokens in order. */
void print_tokens(char **tokens)
{
  int i = 0;
  
  while (tokens[i] != 0)
    printf("tokens[%d] = %s\n", i, tokens[i++]);
}

/* Frees allocated memory of indiviual indexes 
   in the tokens array then frees the array itself. */
void free_tokens(char **tokens)
{
  int i = 0;
  
  while (tokens[i] != 0)
    free(tokens[i++]);

  free(tokens[i]);
  free(tokens);
}
