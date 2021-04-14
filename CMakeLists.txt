cmake_minimum_required(VERSION 3.19)
project(libc_vector C)

set(CMAKE_C_STANDARD 99)

add_library(libc_vector
		srcs/vector.c
		include/vector.h
		srcs/utils.c include/utils.h main.c)

include_directories(include libft/include)