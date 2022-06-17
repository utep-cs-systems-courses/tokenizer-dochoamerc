#include <stdio.h>
#define MAX 100

int main()
{
  char str[MAX];
  printf("> ");
  fgets(str, MAX, stdin);
  printf("%s", str);
}
