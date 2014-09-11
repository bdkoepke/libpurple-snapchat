snapchat:
	gcc snapchat.c snapchat_util.c snapchat_sha256.c -lssl -lcrypto -o snapchat -Wno-deprecated-declarations

clean:
	rm snapchat
