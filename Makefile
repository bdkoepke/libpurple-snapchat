snapchat:
	gcc snapchat.c sha256.c -lssl -lcrypto -o snapchat -Wno-deprecated-declarations
