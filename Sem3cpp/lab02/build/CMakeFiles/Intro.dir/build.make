# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stud2021/1sieklinski/Inf3/lab02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud2021/1sieklinski/Inf3/lab02/build

# Include any dependencies generated for this target.
include CMakeFiles/Intro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Intro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Intro.dir/flags.make

CMakeFiles/Intro.dir/Main.cpp.o: CMakeFiles/Intro.dir/flags.make
CMakeFiles/Intro.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stud2021/1sieklinski/Inf3/lab02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Intro.dir/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intro.dir/Main.cpp.o -c /home/stud2021/1sieklinski/Inf3/lab02/Main.cpp

CMakeFiles/Intro.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intro.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stud2021/1sieklinski/Inf3/lab02/Main.cpp > CMakeFiles/Intro.dir/Main.cpp.i

CMakeFiles/Intro.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intro.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stud2021/1sieklinski/Inf3/lab02/Main.cpp -o CMakeFiles/Intro.dir/Main.cpp.s

CMakeFiles/Intro.dir/src/StudentList.cpp.o: CMakeFiles/Intro.dir/flags.make
CMakeFiles/Intro.dir/src/StudentList.cpp.o: ../src/StudentList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stud2021/1sieklinski/Inf3/lab02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Intro.dir/src/StudentList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Intro.dir/src/StudentList.cpp.o -c /home/stud2021/1sieklinski/Inf3/lab02/src/StudentList.cpp

CMakeFiles/Intro.dir/src/StudentList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Intro.dir/src/StudentList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stud2021/1sieklinski/Inf3/lab02/src/StudentList.cpp > CMakeFiles/Intro.dir/src/StudentList.cpp.i

CMakeFiles/Intro.dir/src/StudentList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Intro.dir/src/StudentList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stud2021/1sieklinski/Inf3/lab02/src/StudentList.cpp -o CMakeFiles/Intro.dir/src/StudentList.cpp.s

# Object files for target Intro
Intro_OBJECTS = \
"CMakeFiles/Intro.dir/Main.cpp.o" \
"CMakeFiles/Intro.dir/src/StudentList.cpp.o"

# External object files for target Intro
Intro_EXTERNAL_OBJECTS =

Intro: CMakeFiles/Intro.dir/Main.cpp.o
Intro: CMakeFiles/Intro.dir/src/StudentList.cpp.o
Intro: CMakeFiles/Intro.dir/build.make
Intro: CMakeFiles/Intro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stud2021/1sieklinski/Inf3/lab02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Intro"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Intro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Intro.dir/build: Intro

.PHONY : CMakeFiles/Intro.dir/build

CMakeFiles/Intro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Intro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Intro.dir/clean

CMakeFiles/Intro.dir/depend:
	cd /home/stud2021/1sieklinski/Inf3/lab02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud2021/1sieklinski/Inf3/lab02 /home/stud2021/1sieklinski/Inf3/lab02 /home/stud2021/1sieklinski/Inf3/lab02/build /home/stud2021/1sieklinski/Inf3/lab02/build /home/stud2021/1sieklinski/Inf3/lab02/build/CMakeFiles/Intro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Intro.dir/depend
