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
CMAKE_SOURCE_DIR = /home/stud2021/1sieklinski/Inf4/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud2021/1sieklinski/Inf4/lab2/build

# Utility rule file for clean-cmake-files.

# Include the progress variables for this target.
include CMakeFiles/clean-cmake-files.dir/progress.make

CMakeFiles/clean-cmake-files:
	/usr/bin/cmake -P clean-all.cmake

clean-cmake-files: CMakeFiles/clean-cmake-files
clean-cmake-files: CMakeFiles/clean-cmake-files.dir/build.make

.PHONY : clean-cmake-files

# Rule to build all files generated by this target.
CMakeFiles/clean-cmake-files.dir/build: clean-cmake-files

.PHONY : CMakeFiles/clean-cmake-files.dir/build

CMakeFiles/clean-cmake-files.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clean-cmake-files.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clean-cmake-files.dir/clean

CMakeFiles/clean-cmake-files.dir/depend:
	cd /home/stud2021/1sieklinski/Inf4/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud2021/1sieklinski/Inf4/lab2 /home/stud2021/1sieklinski/Inf4/lab2 /home/stud2021/1sieklinski/Inf4/lab2/build /home/stud2021/1sieklinski/Inf4/lab2/build /home/stud2021/1sieklinski/Inf4/lab2/build/CMakeFiles/clean-cmake-files.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clean-cmake-files.dir/depend

