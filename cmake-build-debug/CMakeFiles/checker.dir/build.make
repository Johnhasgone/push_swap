# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/euvaganov/42/push_swap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/euvaganov/42/push_swap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/checker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checker.dir/flags.make

CMakeFiles/checker.dir/instructions.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/instructions.c.o: ../instructions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/checker.dir/instructions.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/instructions.c.o   -c /Users/euvaganov/42/push_swap/instructions.c

CMakeFiles/checker.dir/instructions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/instructions.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/euvaganov/42/push_swap/instructions.c > CMakeFiles/checker.dir/instructions.c.i

CMakeFiles/checker.dir/instructions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/instructions.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/euvaganov/42/push_swap/instructions.c -o CMakeFiles/checker.dir/instructions.c.s

CMakeFiles/checker.dir/instructions_2.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/instructions_2.c.o: ../instructions_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/checker.dir/instructions_2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/instructions_2.c.o   -c /Users/euvaganov/42/push_swap/instructions_2.c

CMakeFiles/checker.dir/instructions_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/instructions_2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/euvaganov/42/push_swap/instructions_2.c > CMakeFiles/checker.dir/instructions_2.c.i

CMakeFiles/checker.dir/instructions_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/instructions_2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/euvaganov/42/push_swap/instructions_2.c -o CMakeFiles/checker.dir/instructions_2.c.s

CMakeFiles/checker.dir/checker.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/checker.c.o: ../checker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/checker.dir/checker.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/checker.c.o   -c /Users/euvaganov/42/push_swap/checker.c

CMakeFiles/checker.dir/checker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/checker.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/euvaganov/42/push_swap/checker.c > CMakeFiles/checker.dir/checker.c.i

CMakeFiles/checker.dir/checker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/checker.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/euvaganov/42/push_swap/checker.c -o CMakeFiles/checker.dir/checker.c.s

CMakeFiles/checker.dir/push_swap.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/push_swap.c.o: ../push_swap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/checker.dir/push_swap.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/push_swap.c.o   -c /Users/euvaganov/42/push_swap/push_swap.c

CMakeFiles/checker.dir/push_swap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/push_swap.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/euvaganov/42/push_swap/push_swap.c > CMakeFiles/checker.dir/push_swap.c.i

CMakeFiles/checker.dir/push_swap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/push_swap.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/euvaganov/42/push_swap/push_swap.c -o CMakeFiles/checker.dir/push_swap.c.s

CMakeFiles/checker.dir/checker_main.c.o: CMakeFiles/checker.dir/flags.make
CMakeFiles/checker.dir/checker_main.c.o: ../checker_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/checker.dir/checker_main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/checker_main.c.o   -c /Users/euvaganov/42/push_swap/checker_main.c

CMakeFiles/checker.dir/checker_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/checker_main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/euvaganov/42/push_swap/checker_main.c > CMakeFiles/checker.dir/checker_main.c.i

CMakeFiles/checker.dir/checker_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/checker_main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/euvaganov/42/push_swap/checker_main.c -o CMakeFiles/checker.dir/checker_main.c.s

# Object files for target checker
checker_OBJECTS = \
"CMakeFiles/checker.dir/instructions.c.o" \
"CMakeFiles/checker.dir/instructions_2.c.o" \
"CMakeFiles/checker.dir/checker.c.o" \
"CMakeFiles/checker.dir/push_swap.c.o" \
"CMakeFiles/checker.dir/checker_main.c.o"

# External object files for target checker
checker_EXTERNAL_OBJECTS =

checker: CMakeFiles/checker.dir/instructions.c.o
checker: CMakeFiles/checker.dir/instructions_2.c.o
checker: CMakeFiles/checker.dir/checker.c.o
checker: CMakeFiles/checker.dir/push_swap.c.o
checker: CMakeFiles/checker.dir/checker_main.c.o
checker: CMakeFiles/checker.dir/build.make
checker: ../libft/libft.a
checker: CMakeFiles/checker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable checker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checker.dir/build: checker

.PHONY : CMakeFiles/checker.dir/build

CMakeFiles/checker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checker.dir/clean

CMakeFiles/checker.dir/depend:
	cd /Users/euvaganov/42/push_swap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/euvaganov/42/push_swap /Users/euvaganov/42/push_swap /Users/euvaganov/42/push_swap/cmake-build-debug /Users/euvaganov/42/push_swap/cmake-build-debug /Users/euvaganov/42/push_swap/cmake-build-debug/CMakeFiles/checker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checker.dir/depend

