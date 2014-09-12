#ifndef SNAPCHAT_COMMON_H
#define SNAPCHAT_COMMON_H

typedef struct snapchat_request {
  char *const username;
  char *const request_token;
  int timestamp;
};

typedef struct snapchat_responses {
  bool logged;
};

typedef enum snapchat_media_types {
  IMAGE = 0,
  VIDEO = 1,
  VIDEO_NOAUDIO = 2,
  FRIEND_REQUEST = 3,
  FRIEND_REQUEST_IMAGE = 4,
  FRIEND_REQUEST_VIDEO = 5,
  FRIEND_REQUEST_VIDEO_NOAUDIO = 6
};

typedef enum snapchat_media_states {
  NONE = -1,
  SENT = 0,
  DELIVERED = 1,
  VIEWED = 2,
  SCREENSHOT = 3
};

const char *const snapchat_fallback_build_version = "3.0.2";

// Snapchat/4.1.01 (Nexus 4; Android 18; gzip)
const char *const snapchat_user_agent_format =
    "Snapchat/%s (%s; Android %s; gzip)";

unsigned char *snapchat_encrypt_snaps(const unsigned char *const media,
                                      size_t media_length);
unsigned char *snapchat_decrypt_snaps(const unsigned char *const ciphertext);

unsigned char *snapchat_encrypt_stories(const unsigned char *const story,
                                        const unsigned char *const key,
                                        const unsigned char *const iv);
unsigned char *snapchat_decrypt_stories(const unsigned char *const ciphertext,
                                        const unsigned char *const key,
                                        const unsigned char *const iv);

unsigned char *snapchat_gunzip(const unsigned char *const compressed,
                               size_t compressed_length);

#endif
