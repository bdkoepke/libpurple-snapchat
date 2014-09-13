cmake_minimum_required(VERSION 2.8)

set(MATH_LINK_FLAGS
    "-lm")
set(SSL_LINK_FLAGS
    "-lssl -lcrypto")
set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} ${SSL_LINK_FLAGS} ${MATH_LINK_FLAGS}")

set(snapchat_SRCS
    snapchat.c
    snapchat_sha256.c
    snapchat_util.c)

add_executable(snapchat ${snapchat_SRCS})

target_link_libraries(snapchat)
