#ifndef SNAPCHAT_REGISTER_H
#define SNAPCHAT_REGISTER_H

#include "snapchat_common.h"

// TODO: this can be abstracted away...
typedef struct snapchat_register_request_t {
  snapchat_request_t request;
  char *const email;
  char *const password;
  unsigned char age;
  char *const birthday;
};

// TODO: hide some of the implementation details here...
typedef struct snapchat_register_response_t {
  snapchat_response_t response;
  char *const email;
  char *const phone_number;
  bool logged;
};

snapchat_register_response_t *snapchat_register(const char *const email,
                                                const char *const password,
                                                unsigned char age,
                                                const char *const birthday);

snapchat_register_repsonse_t *snapchat_registeru(const char *const email,
                                                 const char *const username);

#endif
