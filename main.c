#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
  char str[MAX];
  printf("> ");
  fgets(str, MAX, stdin);
  printf("%s", str);

  
}
