#ifndef SNAPCHAT_LOGIN_H
#define SNAPCHAT_LOGIN_H

typedef struct snapchat_login_request_t {
	const char *const username;
	snapchat_request_t request;
	const char *const password;
}

typedef enum account_type_t {
	PUBLIC = 0;
	PRIVATE = 1;
};

typedef struct snapchat_friend_t {
	const char *const username;
	const char *const display;
	account_type_t type;
};

typedef enum snapchat_id_t {
	TO = 'r';
	FROM = 's';
};

typedef struct snapchat_snaps_t {
	snapchat_id_t id;
	const char *const sender_name;
	const char *const receiver_name;
	int timestamp;
	int sent_timestamp;
	snapchat_media_type_t media_type;
	snapchat_media_state_t media_state;
	// int viewable_time;
};

typedef struct snapchat_friends_t {
	bool can_see_custom_stories;
	snapchat_friend_t friend;
}

#endif
