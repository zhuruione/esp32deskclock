# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/zr/.local/share/JetBrains/Toolbox/apps/clion-2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/zr/.local/share/JetBrains/Toolbox/apps/clion-2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zr/桌面/esp/espProject/esp_main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug

# Include any dependencies generated for this target.
include esp-idf/client/CMakeFiles/__idf_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/client/CMakeFiles/__idf_client.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/client/CMakeFiles/__idf_client.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/client/CMakeFiles/__idf_client.dir/flags.make

esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.obj: esp-idf/client/CMakeFiles/__idf_client.dir/flags.make
esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.obj: /home/zr/桌面/esp/espProject/esp_main/components/client/gettime.c
esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.obj: esp-idf/client/CMakeFiles/__idf_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.obj"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.obj -MF CMakeFiles/__idf_client.dir/gettime.c.obj.d -o CMakeFiles/__idf_client.dir/gettime.c.obj -c /home/zr/桌面/esp/espProject/esp_main/components/client/gettime.c

esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_client.dir/gettime.c.i"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zr/桌面/esp/espProject/esp_main/components/client/gettime.c > CMakeFiles/__idf_client.dir/gettime.c.i

esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_client.dir/gettime.c.s"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zr/桌面/esp/espProject/esp_main/components/client/gettime.c -o CMakeFiles/__idf_client.dir/gettime.c.s

# Object files for target __idf_client
__idf_client_OBJECTS = \
"CMakeFiles/__idf_client.dir/gettime.c.obj"

# External object files for target __idf_client
__idf_client_EXTERNAL_OBJECTS =

esp-idf/client/libclient.a: esp-idf/client/CMakeFiles/__idf_client.dir/gettime.c.obj
esp-idf/client/libclient.a: esp-idf/client/CMakeFiles/__idf_client.dir/build.make
esp-idf/client/libclient.a: esp-idf/client/CMakeFiles/__idf_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libclient.a"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client && $(CMAKE_COMMAND) -P CMakeFiles/__idf_client.dir/cmake_clean_target.cmake
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/client/CMakeFiles/__idf_client.dir/build: esp-idf/client/libclient.a
.PHONY : esp-idf/client/CMakeFiles/__idf_client.dir/build

esp-idf/client/CMakeFiles/__idf_client.dir/clean:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client && $(CMAKE_COMMAND) -P CMakeFiles/__idf_client.dir/cmake_clean.cmake
.PHONY : esp-idf/client/CMakeFiles/__idf_client.dir/clean

esp-idf/client/CMakeFiles/__idf_client.dir/depend:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zr/桌面/esp/espProject/esp_main /home/zr/桌面/esp/espProject/esp_main/components/client /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/client/CMakeFiles/__idf_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/client/CMakeFiles/__idf_client.dir/depend

