# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /home/ariely122/.cache/JetBrains/RemoteDev/dist/8883b3744bbaf_CLion-251.23774.112/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/ariely122/.cache/JetBrains/RemoteDev/dist/8883b3744bbaf_CLion-251.23774.112/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ariely122/CPP_EX1_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ariely122/CPP_EX1_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proj1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proj1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj1.dir/flags.make

CMakeFiles/proj1.dir/codegen:
.PHONY : CMakeFiles/proj1.dir/codegen

CMakeFiles/proj1.dir/Algorithms.cpp.o: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/Algorithms.cpp.o: /home/ariely122/CPP_EX1_1/Algorithms.cpp
CMakeFiles/proj1.dir/Algorithms.cpp.o: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj1.dir/Algorithms.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/Algorithms.cpp.o -MF CMakeFiles/proj1.dir/Algorithms.cpp.o.d -o CMakeFiles/proj1.dir/Algorithms.cpp.o -c /home/ariely122/CPP_EX1_1/Algorithms.cpp

CMakeFiles/proj1.dir/Algorithms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/Algorithms.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ariely122/CPP_EX1_1/Algorithms.cpp > CMakeFiles/proj1.dir/Algorithms.cpp.i

CMakeFiles/proj1.dir/Algorithms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/Algorithms.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ariely122/CPP_EX1_1/Algorithms.cpp -o CMakeFiles/proj1.dir/Algorithms.cpp.s

CMakeFiles/proj1.dir/Graph.cpp.o: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/Graph.cpp.o: /home/ariely122/CPP_EX1_1/Graph.cpp
CMakeFiles/proj1.dir/Graph.cpp.o: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proj1.dir/Graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/Graph.cpp.o -MF CMakeFiles/proj1.dir/Graph.cpp.o.d -o CMakeFiles/proj1.dir/Graph.cpp.o -c /home/ariely122/CPP_EX1_1/Graph.cpp

CMakeFiles/proj1.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ariely122/CPP_EX1_1/Graph.cpp > CMakeFiles/proj1.dir/Graph.cpp.i

CMakeFiles/proj1.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ariely122/CPP_EX1_1/Graph.cpp -o CMakeFiles/proj1.dir/Graph.cpp.s

CMakeFiles/proj1.dir/main.cpp.o: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/main.cpp.o: /home/ariely122/CPP_EX1_1/main.cpp
CMakeFiles/proj1.dir/main.cpp.o: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/proj1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/main.cpp.o -MF CMakeFiles/proj1.dir/main.cpp.o.d -o CMakeFiles/proj1.dir/main.cpp.o -c /home/ariely122/CPP_EX1_1/main.cpp

CMakeFiles/proj1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ariely122/CPP_EX1_1/main.cpp > CMakeFiles/proj1.dir/main.cpp.i

CMakeFiles/proj1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ariely122/CPP_EX1_1/main.cpp -o CMakeFiles/proj1.dir/main.cpp.s

CMakeFiles/proj1.dir/tests.cpp.o: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/tests.cpp.o: /home/ariely122/CPP_EX1_1/tests.cpp
CMakeFiles/proj1.dir/tests.cpp.o: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/proj1.dir/tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/tests.cpp.o -MF CMakeFiles/proj1.dir/tests.cpp.o.d -o CMakeFiles/proj1.dir/tests.cpp.o -c /home/ariely122/CPP_EX1_1/tests.cpp

CMakeFiles/proj1.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ariely122/CPP_EX1_1/tests.cpp > CMakeFiles/proj1.dir/tests.cpp.i

CMakeFiles/proj1.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ariely122/CPP_EX1_1/tests.cpp -o CMakeFiles/proj1.dir/tests.cpp.s

CMakeFiles/proj1.dir/Queue.cpp.o: CMakeFiles/proj1.dir/flags.make
CMakeFiles/proj1.dir/Queue.cpp.o: /home/ariely122/CPP_EX1_1/Queue.cpp
CMakeFiles/proj1.dir/Queue.cpp.o: CMakeFiles/proj1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/proj1.dir/Queue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj1.dir/Queue.cpp.o -MF CMakeFiles/proj1.dir/Queue.cpp.o.d -o CMakeFiles/proj1.dir/Queue.cpp.o -c /home/ariely122/CPP_EX1_1/Queue.cpp

CMakeFiles/proj1.dir/Queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj1.dir/Queue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ariely122/CPP_EX1_1/Queue.cpp > CMakeFiles/proj1.dir/Queue.cpp.i

CMakeFiles/proj1.dir/Queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj1.dir/Queue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ariely122/CPP_EX1_1/Queue.cpp -o CMakeFiles/proj1.dir/Queue.cpp.s

# Object files for target proj1
proj1_OBJECTS = \
"CMakeFiles/proj1.dir/Algorithms.cpp.o" \
"CMakeFiles/proj1.dir/Graph.cpp.o" \
"CMakeFiles/proj1.dir/main.cpp.o" \
"CMakeFiles/proj1.dir/tests.cpp.o" \
"CMakeFiles/proj1.dir/Queue.cpp.o"

# External object files for target proj1
proj1_EXTERNAL_OBJECTS =

proj1: CMakeFiles/proj1.dir/Algorithms.cpp.o
proj1: CMakeFiles/proj1.dir/Graph.cpp.o
proj1: CMakeFiles/proj1.dir/main.cpp.o
proj1: CMakeFiles/proj1.dir/tests.cpp.o
proj1: CMakeFiles/proj1.dir/Queue.cpp.o
proj1: CMakeFiles/proj1.dir/build.make
proj1: CMakeFiles/proj1.dir/compiler_depend.ts
proj1: CMakeFiles/proj1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable proj1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj1.dir/build: proj1
.PHONY : CMakeFiles/proj1.dir/build

CMakeFiles/proj1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj1.dir/clean

CMakeFiles/proj1.dir/depend:
	cd /home/ariely122/CPP_EX1_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ariely122/CPP_EX1_1 /home/ariely122/CPP_EX1_1 /home/ariely122/CPP_EX1_1/cmake-build-debug /home/ariely122/CPP_EX1_1/cmake-build-debug /home/ariely122/CPP_EX1_1/cmake-build-debug/CMakeFiles/proj1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/proj1.dir/depend

