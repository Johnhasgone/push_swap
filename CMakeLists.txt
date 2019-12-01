cmake_minimum_required(VERSION 3.14)
project(push_swap)

set(CMAKE_CXX_STANDARD 14)

add_executable(push_swap checker.c push_swap.h instructions.c libft/ft_lstadd_end.c push_swap.c)

find_library(FT ft libft)
target_link_libraries(push_swap LINK_PUBLIC ${FT})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")


