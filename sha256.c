#include <openssl/sha.h>
#include <stdlib.h>
#include <string.h>

unsigned char *snapchat_sha256(const char *string) {
  unsigned char *hash = malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
  SHA256_CTX *sha256 = malloc(sizeof(SHA256_CTX));
  SHA256_Init(sha256);
  SHA256_Update(sha256, string, strlen(string));
  SHA256_Final(hash, sha256);
  return hash;
}
