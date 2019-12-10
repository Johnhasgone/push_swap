cmake_minimum_required(VERSION 3.14)
project(push_swap)

set(CMAKE_CXX_STANDARD 14)

add_executable(push_swap push_swap.h instructions.c instructions_2.c
		stack_b_func.c checker.c push_swap_main.c)

add_executable(checker push_swap.h instructions.c instructions_2.c
		checker.c stack_b_func.c checker_main.c stack_a_func.c utils.c utils2.c)

find_library(FT ft libft)
target_link_libraries(push_swap LINK_PUBLIC ${FT})
target_link_libraries(checker LINK_PUBLIC ${FT})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")


