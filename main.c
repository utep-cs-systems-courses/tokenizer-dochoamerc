//#ifndef _TOKENIZER_
//#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#include "src/tokenizer.h"
#include "src/history.h"
#define MAX 100

int main()
{
  List* list = init_history();
  char str[MAX];
  char *s = str;
    
  while(1)
  {
    printf("> ");
    fgets(str, MAX, stdin);
    if(*s == '0') break;
    printf("You entered: %s\n", str);
    
    printf("\nTokenizing\n",0);
    char **tokens = tokenize(s);
    int last = count_words(s);
    printf("Print last token: %s\n", tokens[last-1]);
    printf("Print all tokens:\n",0);
    print_tokens(tokens);
    
    add_history(list, str);

  }

  while(1){
    
    printf("\nHistory\n");
    printf("Enter history id you'd like to see again:\n>",0);
    int c;
    scanf("%d", &c);
    printf("ID %d: %s\n", c, get_history(list, c));
    if(c == 0) break;
  }
  
  printf("All history:\n",0);
  print_history(list);

}
