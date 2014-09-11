#ifndef SNAPCHAT_EXCEPTION_H
#define SNAPCHAT_EXCEPTION_H

typedef struct snapchat_exception_t {
	const char *const message;
	bool logged;
};

#endif
