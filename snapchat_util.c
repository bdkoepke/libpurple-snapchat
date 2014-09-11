#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "snapchat_util.h"

char *concat(const char *const a, const char *const b) {
  char *concat = malloc(sizeof(char) * (strlen(a) + strlen(b)));
  strcpy(concat, a);
  strcat(concat, b);
  return concat;
}

char *int_to_str(int i) {
  char *i_s = malloc(sizeof(char) * ceil(i % 10));
  sprintf(i_s, "%d", i);
  return i_s;
}
