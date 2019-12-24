# push_swap
Summary: This project sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. Data sorting made using QUICKSORT algorithm.

General instructions:

1. Two executable files: checker and push_swap
2. libft is in the project
3. Makefile compiles the libft library and the project
4. No global variables
5. Handling all the errors
6. No memory leaks
7. author file
. Within mandatory part the next functions are allowed: 
  - write
  - read
  - malloc
  - free
  - exit
  
  
Important points to remember:

1. there are two stacks: a and b. 
  - a contains a random number of either positive or negative numbers without any duplicates.
  - b is empty.
2. The goal is to sort numbers in stack a in ascending order.
3. To do this we have the following operations:
  - sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  - sb : swap b - list_swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  - ss : sa and sb at the same time.
  - pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  - rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  - rr : ra and rb at the same time.
  - rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
  - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
  - rrr : rra and rrb at the same time.
  
Project contains of two programs: checker and push_swap. 

# Checker program:
  
  
    - gets a list of integers as an argument, the first argument should be at the top of the stack.
    - array of strings is converted to list of ints. lst_pushback should be used so the first string should appear at the begining of the list.
    - than Checker waits and reads instructions on the standart input 
    - if no arguments is given, checker stops and displays nothing. 
    - In case of error, checker must display Error followed by a ’\n’ on the STANDART ERROR.
      ERRORS include for example: 
      - some arguments are not integers, 
      - some arguments are bigger than an integer, 
      - there are duplicates, 
      - an instruction don’t exist and/or is incorrectly formatted.
  
 # Push_swap program:
  
  
    - gets a list of integers as an argument, the first argument should be at the top of the stack.
    - push_swap sorts stack a in ascending order using stack b.
    - push_swap prints on the standard output list of commands that sorts numbers in stack a.
    - In case of error, push_swap must display Error followed by a ’\n’ on the STANDART ERROR.
      ERRORS include for example: 
      - some arguments are not integers, 
      - some arguments are bigger than an integer, 
      - there are duplicates.
      
What the algo does:
1. finds pivot (median) to divide all the numbers with biggest number of iteration in stack a in two parts. All the numbers less than pivot are sent to stack b with increasing a number of iteration by 1. All the numbers bigger than pivot are sent to the bottom of the stack a. At the first time the number of iteration of all the numbers in stack a are zero.
2. step 1 is repeated until the stack a is sorted or has only 3 numbers (which now are the biggest ones and could be sorted without using stack b).
3. actions from step 1 are made to numbers with the biggest iteration num in stack b.
4. all the numbers with biggest iteration number in stack b moved from bottom to top.
5. steps 1-4 repeated until the stack b is empty and stack a is sorted.

  
  

