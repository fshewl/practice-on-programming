#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *s = "10 90";

  int i = atoi(s);

  char *next = strchr(s, ' ');

  int j = atoi(next);

  printf("%d\n", i);
  printf("%d\n", j);
  
}
