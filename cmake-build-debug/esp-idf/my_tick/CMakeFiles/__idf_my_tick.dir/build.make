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
include esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/flags.make

esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.obj: esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/flags.make
esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.obj: /home/zr/桌面/esp/espProject/esp_main/components/my_tick/my_tick.c
esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.obj: esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.obj"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.obj -MF CMakeFiles/__idf_my_tick.dir/my_tick.c.obj.d -o CMakeFiles/__idf_my_tick.dir/my_tick.c.obj -c /home/zr/桌面/esp/espProject/esp_main/components/my_tick/my_tick.c

esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_my_tick.dir/my_tick.c.i"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zr/桌面/esp/espProject/esp_main/components/my_tick/my_tick.c > CMakeFiles/__idf_my_tick.dir/my_tick.c.i

esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_my_tick.dir/my_tick.c.s"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zr/桌面/esp/espProject/esp_main/components/my_tick/my_tick.c -o CMakeFiles/__idf_my_tick.dir/my_tick.c.s

# Object files for target __idf_my_tick
__idf_my_tick_OBJECTS = \
"CMakeFiles/__idf_my_tick.dir/my_tick.c.obj"

# External object files for target __idf_my_tick
__idf_my_tick_EXTERNAL_OBJECTS =

esp-idf/my_tick/libmy_tick.a: esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/my_tick.c.obj
esp-idf/my_tick/libmy_tick.a: esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/build.make
esp-idf/my_tick/libmy_tick.a: esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmy_tick.a"
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick && $(CMAKE_COMMAND) -P CMakeFiles/__idf_my_tick.dir/cmake_clean_target.cmake
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_my_tick.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/build: esp-idf/my_tick/libmy_tick.a
.PHONY : esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/build

esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/clean:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick && $(CMAKE_COMMAND) -P CMakeFiles/__idf_my_tick.dir/cmake_clean.cmake
.PHONY : esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/clean

esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/depend:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zr/桌面/esp/espProject/esp_main /home/zr/桌面/esp/espProject/esp_main/components/my_tick /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/my_tick/CMakeFiles/__idf_my_tick.dir/depend

