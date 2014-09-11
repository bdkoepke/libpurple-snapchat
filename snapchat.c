#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snapchat.h"
#include "snapchat_sha256.h"
#include "snapchat_util.h"

char *snapchat_request_token(const char *auth_token, int timestamp) {
  const char *const secret = "iEk21fuwZApXlz93750dmW22pw389dPwOk";
  const char *const pattern =
      "0001110111101110001111010101111011010001001110011000110001000110";
  unsigned char *first;
  {
    char *secret_auth_token = concat(secret, auth_token);
    first = snapchat_sha256(secret_auth_token);
    free(secret_auth_token);
  }
  unsigned char *second;
  {
    char *timestamp_s = int_to_str(timestamp);
    char *timestamp_secret = concat(timestamp_s, secret);
    second = snapchat_sha256(timestamp_secret);
    free(timestamp_secret);
    free(timestamp_s);
  }
  char *token;
  {
    int i, pattern_length = strlen(pattern);
    token = malloc(sizeof(char) * pattern_length);
    for (i = 0; i < pattern_length; i++)
      token[i] = pattern[i] == '0' ? first[i] : second[i];
  }
  return token;
}

int main(int argc, char *argv[]) {
  const char *const static_token = "m198sOkJEn37DjqZ32lpRu76xmw288xSQ9";
  char *token = snapchat_request_token(static_token, 1373209025);
  puts(token);
  free(token);
  return 0;
}
