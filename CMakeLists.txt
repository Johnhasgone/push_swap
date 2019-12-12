cmake_minimum_required(VERSION 3.14)
project(push_swap)

set(CMAKE_CXX_STANDARD 14)

add_executable(push_swap push_swap.h instructions_1.c instructions_2.c
		checker.c push_swap_main.c push_swap_func.c utils_1.c utils_2.c
		utils_3.c)

add_executable(checker push_swap.h instructions_1.c instructions_2.c
		checker.c checker_main.c push_swap_func.c utils_1.c utils_2.c
		utils_3.c libft/ft_lst_check_add_end.c)

find_library(FT ft libft)
target_link_libraries(push_swap LINK_PUBLIC ${FT})
target_link_libraries(checker LINK_PUBLIC ${FT})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")


