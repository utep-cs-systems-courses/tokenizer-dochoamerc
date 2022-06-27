#include <stdio.h>
#include "bst.h"

int main()
{
  bstInsert(&bstRoot, "beforeClear");
  bstPrint(bstRoot);
  bstClear(&bstRoot);
  bstInsert(&bstRoot, "after");
  bstPrint(bstRoot);
}
