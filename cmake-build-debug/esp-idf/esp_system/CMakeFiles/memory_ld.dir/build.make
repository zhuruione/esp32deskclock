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

# Utility rule file for memory_ld.

# Include any custom commands dependencies for this target.
include esp-idf/esp_system/CMakeFiles/memory_ld.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/esp_system/CMakeFiles/memory_ld.dir/progress.make

esp-idf/esp_system/CMakeFiles/memory_ld: esp-idf/esp_system/ld/memory.ld

esp-idf/esp_system/ld/memory.ld: /home/zr/app/esp-idf/components/esp_system/ld/esp32/memory.ld.in
esp-idf/esp_system/ld/memory.ld: config/sdkconfig.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating memory.ld linker script..."
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/esp_system && /home/zr/.espressif/tools/xtensa-esp32-elf/esp-2022r1-11.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc -C -P -x c -E -o /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/esp_system/ld/memory.ld -I /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/config -I /home/zr/app/esp-idf/components/esp_system/ld /home/zr/app/esp-idf/components/esp_system/ld/esp32/memory.ld.in

memory_ld: esp-idf/esp_system/CMakeFiles/memory_ld
memory_ld: esp-idf/esp_system/ld/memory.ld
memory_ld: esp-idf/esp_system/CMakeFiles/memory_ld.dir/build.make
.PHONY : memory_ld

# Rule to build all files generated by this target.
esp-idf/esp_system/CMakeFiles/memory_ld.dir/build: memory_ld
.PHONY : esp-idf/esp_system/CMakeFiles/memory_ld.dir/build

esp-idf/esp_system/CMakeFiles/memory_ld.dir/clean:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/esp_system && $(CMAKE_COMMAND) -P CMakeFiles/memory_ld.dir/cmake_clean.cmake
.PHONY : esp-idf/esp_system/CMakeFiles/memory_ld.dir/clean

esp-idf/esp_system/CMakeFiles/memory_ld.dir/depend:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zr/桌面/esp/espProject/esp_main /home/zr/app/esp-idf/components/esp_system /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/esp_system /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/esp_system/CMakeFiles/memory_ld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/esp_system/CMakeFiles/memory_ld.dir/depend

