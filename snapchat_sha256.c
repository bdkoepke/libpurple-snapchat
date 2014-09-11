#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *snapchat_sha256(const char *string) {
  unsigned char *hash = malloc(sizeof(unsigned char) * SHA256_DIGEST_LENGTH);
  SHA256_CTX *sha256 = malloc(sizeof(SHA256_CTX));
  SHA256_Init(sha256);
  SHA256_Update(sha256, string, strlen(string));
  SHA256_Final(hash, sha256);

	const int sizeof_hash_hex = sizeof(char) * (SHA256_DIGEST_LENGTH * 2);
	char *hash_hex = malloc(sizeof_hash_hex + sizeof('\n'));
	hash_hex[sizeof_hash_hex] = '\n';
	int i;
	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		sprintf(&hash_hex[i * 2], "%02x", hash[i]);
  return hash_hex;
}
