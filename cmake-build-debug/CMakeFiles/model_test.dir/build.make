# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/model_test.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/model_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/model_test.dir/flags.make

CMakeFiles/model_test.dir/src/model.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/model.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/model.cxx.obj: ../src/model.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/model_test.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\model_test.dir\src\model.cxx.obj -c "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\model.cxx"

CMakeFiles/model_test.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\model.cxx" > CMakeFiles\model_test.dir\src\model.cxx.i

CMakeFiles/model_test.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\model.cxx" -o CMakeFiles\model_test.dir\src\model.cxx.s

CMakeFiles/model_test.dir/src/board.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/board.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/board.cxx.obj: ../src/board.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/model_test.dir/src/board.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\model_test.dir\src\board.cxx.obj -c "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\board.cxx"

CMakeFiles/model_test.dir/src/board.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/board.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\board.cxx" > CMakeFiles\model_test.dir\src\board.cxx.i

CMakeFiles/model_test.dir/src/board.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/board.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\board.cxx" -o CMakeFiles\model_test.dir\src\board.cxx.s

CMakeFiles/model_test.dir/src/brick.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/brick.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/brick.cxx.obj: ../src/brick.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/model_test.dir/src/brick.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\model_test.dir\src\brick.cxx.obj -c "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\brick.cxx"

CMakeFiles/model_test.dir/src/brick.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/brick.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\brick.cxx" > CMakeFiles\model_test.dir\src\brick.cxx.i

CMakeFiles/model_test.dir/src/brick.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/brick.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\brick.cxx" -o CMakeFiles\model_test.dir\src\brick.cxx.s

CMakeFiles/model_test.dir/src/position_set.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/position_set.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/position_set.cxx.obj: ../src/position_set.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/model_test.dir/src/position_set.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\model_test.dir\src\position_set.cxx.obj -c "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\position_set.cxx"

CMakeFiles/model_test.dir/src/position_set.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/position_set.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\position_set.cxx" > CMakeFiles\model_test.dir\src\position_set.cxx.i

CMakeFiles/model_test.dir/src/position_set.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/position_set.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\src\position_set.cxx" -o CMakeFiles\model_test.dir\src\position_set.cxx.s

CMakeFiles/model_test.dir/test/model_test.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/test/model_test.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/test/model_test.cxx.obj: ../test/model_test.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/model_test.dir/test/model_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\model_test.dir\test\model_test.cxx.obj -c "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\test\model_test.cxx"

CMakeFiles/model_test.dir/test/model_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/test/model_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\test\model_test.cxx" > CMakeFiles\model_test.dir\test\model_test.cxx.i

CMakeFiles/model_test.dir/test/model_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/test/model_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\test\model_test.cxx" -o CMakeFiles\model_test.dir\test\model_test.cxx.s

CMakeFiles/model_test.dir/test/brick_test.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/test/brick_test.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/test/brick_test.cxx.obj: ../test/brick_test.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/model_test.dir/test/brick_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\model_test.dir\test\brick_test.cxx.obj -c "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\test\brick_test.cxx"

CMakeFiles/model_test.dir/test/brick_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/test/brick_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\test\brick_test.cxx" > CMakeFiles\model_test.dir\test\brick_test.cxx.i

CMakeFiles/model_test.dir/test/brick_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/test/brick_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\test\brick_test.cxx" -o CMakeFiles\model_test.dir\test\brick_test.cxx.s

# Object files for target model_test
model_test_OBJECTS = \
"CMakeFiles/model_test.dir/src/model.cxx.obj" \
"CMakeFiles/model_test.dir/src/board.cxx.obj" \
"CMakeFiles/model_test.dir/src/brick.cxx.obj" \
"CMakeFiles/model_test.dir/src/position_set.cxx.obj" \
"CMakeFiles/model_test.dir/test/model_test.cxx.obj" \
"CMakeFiles/model_test.dir/test/brick_test.cxx.obj"

# External object files for target model_test
model_test_EXTERNAL_OBJECTS =

model_test.exe: CMakeFiles/model_test.dir/src/model.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/src/board.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/src/brick.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/src/position_set.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/test/model_test.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/test/brick_test.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/build.make
model_test.exe: .cs211/lib/catch/libcatch.a
model_test.exe: .cs211/lib/ge211/src/libge211.a
model_test.exe: C:/MinGW/lib/libSDL2.dll.a
model_test.exe: C:/MinGW/lib/libSDL2_image.dll.a
model_test.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
model_test.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
model_test.exe: CMakeFiles/model_test.dir/linklibs.rsp
model_test.exe: CMakeFiles/model_test.dir/objects1.rsp
model_test.exe: CMakeFiles/model_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable model_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\model_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/model_test.dir/build: model_test.exe
.PHONY : CMakeFiles/model_test.dir/build

CMakeFiles/model_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\model_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/model_test.dir/clean

CMakeFiles/model_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project" "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project" "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug" "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug" "C:\Users\Edward\Desktop\nu 2021 fall\cs 211\final project\final_project\cmake-build-debug\CMakeFiles\model_test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/model_test.dir/depend
