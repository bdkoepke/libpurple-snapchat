#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sha256.h"
#include "snapchat.h"

unsigned char *snapchat_request_token(const char *auth_token, int timestamp) {
	const char * const secret = "iEk21fuwZApXlz93750dmW22pw389dPwOk";
	const char * const pattern = "0001110111101110001111010101111011010001001110011000110001000110";
	unsigned char *first;
	{
		// removing 1 because '\n' is counted twice
		char *secret_auth_token = malloc(strlen(secret) + strlen(auth_token) - 1);
		strcpy(secret_auth_token, secret);
		strcat(secret_auth_token, auth_token);
		first = snapchat_sha256(secret_auth_token);
		free(secret_auth_token);
	}
	unsigned char *second;
	{
		char *timestamp_secret = malloc(sizeof(char) * (ceil(timestamp % 10) + strlen(secret)));
		sprintf(timestamp_secret, "%d", timestamp);
		strcat(timestamp_secret, secret);
		second = snapchat_sha256(timestamp_secret);
		free(timestamp_secret);
	}
	size_t pattern_length = strlen(pattern);
	unsigned char *token = malloc(sizeof(char) * pattern_length);
	int i;
	for (i = 0; i < pattern_length; i++)
		token[i] = pattern[i] == '0' ? first[i] : second[i];
	return token;
}

int main() {
	unsigned char *token = snapchat_request_token("m198sOkJEn37DjqZ32lpRu76xmw288xSQ9", 1373209025);

	printf("%d\n", strlen(token));

	int i;
	for (i = 0; i < strlen(token); i++)
		printf("%d", token[i]);
	printf("\n");
}
