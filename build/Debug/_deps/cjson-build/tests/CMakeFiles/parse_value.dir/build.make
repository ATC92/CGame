# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Documents\Projects\CGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Documents\Projects\CGame\build\Debug

# Include any dependencies generated for this target.
include _deps/cjson-build/tests/CMakeFiles/parse_value.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/cjson-build/tests/CMakeFiles/parse_value.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/cjson-build/tests/CMakeFiles/parse_value.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/cjson-build/tests/CMakeFiles/parse_value.dir/flags.make

_deps/cjson-build/tests/CMakeFiles/parse_value.dir/codegen:
.PHONY : _deps/cjson-build/tests/CMakeFiles/parse_value.dir/codegen

_deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.obj: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/flags.make
_deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.obj: _deps/cjson-src/tests/parse_value.c
_deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.obj: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Documents\Projects\CGame\build\Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.obj"
	cd /d C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.obj -MF CMakeFiles\parse_value.dir\parse_value.c.obj.d -o CMakeFiles\parse_value.dir\parse_value.c.obj -c C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-src\tests\parse_value.c

_deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/parse_value.dir/parse_value.c.i"
	cd /d C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-src\tests\parse_value.c > CMakeFiles\parse_value.dir\parse_value.c.i

_deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/parse_value.dir/parse_value.c.s"
	cd /d C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-src\tests\parse_value.c -o CMakeFiles\parse_value.dir\parse_value.c.s

# Object files for target parse_value
parse_value_OBJECTS = \
"CMakeFiles/parse_value.dir/parse_value.c.obj"

# External object files for target parse_value
parse_value_EXTERNAL_OBJECTS =

C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/parse_value.c.obj
C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/build.make
C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/libcjson.a
C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/tests/libunity.a
C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/linkLibs.rsp
C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/objects1.rsp
C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe: _deps/cjson-build/tests/CMakeFiles/parse_value.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\user\Documents\Projects\CGame\build\Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable C:\Users\user\Documents\Projects\CGame\bin\debug\parse_value.exe"
	cd /d C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\parse_value.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/cjson-build/tests/CMakeFiles/parse_value.dir/build: C:/Users/user/Documents/Projects/CGame/bin/debug/parse_value.exe
.PHONY : _deps/cjson-build/tests/CMakeFiles/parse_value.dir/build

_deps/cjson-build/tests/CMakeFiles/parse_value.dir/clean:
	cd /d C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests && $(CMAKE_COMMAND) -P CMakeFiles\parse_value.dir\cmake_clean.cmake
.PHONY : _deps/cjson-build/tests/CMakeFiles/parse_value.dir/clean

_deps/cjson-build/tests/CMakeFiles/parse_value.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Documents\Projects\CGame C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-src\tests C:\Users\user\Documents\Projects\CGame\build\Debug C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests C:\Users\user\Documents\Projects\CGame\build\Debug\_deps\cjson-build\tests\CMakeFiles\parse_value.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/cjson-build/tests/CMakeFiles/parse_value.dir/depend

