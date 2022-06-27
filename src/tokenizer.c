#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return true;
  return false;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if(c == ' ' || c == '\t')
    return false;
  return true;
}

//made my own string length
int length(char *start)
{
  int count = 0, i = 0;
  while(start[i] != '\0'){
    count++;
    i++;
  }
  return count;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  if(length(str)==0) return 0;
  while(space_char(*str))
    *str++;
  if(*str == '\0') return 0;
  return str;
}
  

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  if(length(word) == 0) return word;
  char *temp = word_start(word);
  if(*temp == 0) return 0;
  while(non_space_char(*temp))
  {
    *temp++;
    if(*temp == '\0') return 0;
  }
  return temp;
}

/* Counts the number of words in the string argument. */
// CANNOT HANDLE TRAILING SPACES
int count_words(char *str)
{
  if(length(str) == 0) return 0;
  int wordCount = 1;
  char *temp = str;
  while((temp = word_terminator(temp)) != NULL) {
    wordCount++;
  }

  return wordCount;
}


/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *newStr = (char*) malloc((len+1) * sizeof(char));
  char c;
  for(int i = 0; i < len; i++)
  {
    *(newStr+i) = *(inStr + i);
  }
 
  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int i=0, wc = count_words(str);
  char **tokens = (char**) malloc( (wc+1) * sizeof(char*) );
  char *temp;

  while(i < wc)
  {
    temp = word_start(str);
    str = word_terminator(temp);
    int wlen;
    if(str != 0) wlen = (str-temp);
    else wlen = length(temp);
    
    tokens[i] = copy_str(temp, wlen);
    i++;
  }

  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0)
  {
    printf("%s\n", tokens[i]);
    i++;
  }
    
}
  

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  free(tokens);
}

#endif
