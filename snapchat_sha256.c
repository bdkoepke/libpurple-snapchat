#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *snapchat_sha256(const char *string) {
  SHA256_CTX *sha256 = malloc(sizeof(SHA256_CTX));
  SHA256_Init(sha256);
  SHA256_Update(sha256, string, strlen(string));

  unsigned char *digest = malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
  SHA256_Final(digest, sha256);

  const int sizeof_digest_hex = sizeof(char) * (SHA256_DIGEST_LENGTH * 2);
  char *digest_hex = malloc(sizeof_digest_hex + sizeof('\n'));
  int i;
  for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
    sprintf(&digest_hex[i * 2], "%02x", digest[i]);
  free(digest);

  return digest_hex[sizeof_digest_hex] = '\n', digest_hex;
}
