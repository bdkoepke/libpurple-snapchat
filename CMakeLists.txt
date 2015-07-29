cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(OpenSSL REQUIRED)

include_directories(OPENSSL_INCLUDE_DIR)
link_directories(${OPENSSL_LIBRARIES})
add_definitions()

set(snapchat_SRCS
    snapchat.c
    snapchat_sha256.c
    snapchat_util.c)

add_executable(snapchat ${snapchat_SRCS})

target_link_libraries(snapchat m crypto)
