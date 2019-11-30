# push_swap
Summary: This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimised data sorting.

General instructions:

1. Two executable files: checker and push_swap
2. libft should be in the project
3. Makefile must compile the libft library and the project
4. No global variables
5. Handling all the errors
6. No memory leaks
7. SUBMIT AUTHOR FILE!!
8. author file
9. Within mandatory part the next functions are allowed: 
  - write
  - read
  - malloc
  - free
  - exit

Important points to remember:

1. there are two stacks: a and b. 
  - a contains a random number of either positive or negative numbers without any duplicates.
  - b is empty.
2. The goal is to sort in ascending order numbers in stack a.
3. To do this you have the following operations at your disposal:
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
  
  4. Two programms have to be made for sorting and checking: checker and push_swap
  
  # Checker program:
  
  
    - gets a list of integers as an argument, the first argument should be at the top of the stack.
    - array of strings should be convert to list of ints. lst_pushback should be used so the first string should appear at the begining of the list.
    - than Checker waits and reads instructions on the standart input 
    - if no arguments is given, checker stops and displays nothing. 
    - In case of error, checker must display Error followed by a ’\n’ on the STANDART ERROR.
      ERRORS include for example: 
      - some arguments are not integers, 
      - some arguments are bigger than an integer, 
      - there are duplicates, 
      - an instruction don’t exist and/or is incorrectly formatted.

