# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build

# Include any dependencies generated for this target.
include CMakeFiles/tinyxml2_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tinyxml2_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tinyxml2_static.dir/flags.make

CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.o: CMakeFiles/tinyxml2_static.dir/flags.make
CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.o: /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.o -c /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project/tinyxml2.cpp

CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project/tinyxml2.cpp > CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.i

CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project/tinyxml2.cpp -o CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.s

# Object files for target tinyxml2_static
tinyxml2_static_OBJECTS = \
"CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.o"

# External object files for target tinyxml2_static
tinyxml2_static_EXTERNAL_OBJECTS =

libtinyxml2.a: CMakeFiles/tinyxml2_static.dir/tinyxml2.cpp.o
libtinyxml2.a: CMakeFiles/tinyxml2_static.dir/build.make
libtinyxml2.a: CMakeFiles/tinyxml2_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtinyxml2.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tinyxml2_static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinyxml2_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tinyxml2_static.dir/build: libtinyxml2.a

.PHONY : CMakeFiles/tinyxml2_static.dir/build

CMakeFiles/tinyxml2_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tinyxml2_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tinyxml2_static.dir/clean

CMakeFiles/tinyxml2_static.dir/depend:
	cd /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build /home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/tinyxml2-project-build/CMakeFiles/tinyxml2_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tinyxml2_static.dir/depend
