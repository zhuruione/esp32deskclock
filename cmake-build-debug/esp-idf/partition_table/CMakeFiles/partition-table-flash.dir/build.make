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

# Utility rule file for partition-table-flash.

# Include any custom commands dependencies for this target.
include esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/progress.make

esp-idf/partition_table/CMakeFiles/partition-table-flash:
	cd /home/zr/app/esp-idf/components/partition_table && /home/zr/.local/share/JetBrains/Toolbox/apps/clion-2/bin/cmake/linux/x64/bin/cmake -D IDF_PATH=/home/zr/app/esp-idf -D "SERIAL_TOOL=python;;/home/zr/app/esp-idf/components/esptool_py/esptool/esptool.py;--chip;esp32" -D "SERIAL_TOOL_ARGS=--before=default_reset;--after=hard_reset;write_flash;@partition-table-flash_args" -D WORKING_DIRECTORY=/home/zr/桌面/esp/espProject/esp_main/cmake-build-debug -P /home/zr/app/esp-idf/components/esptool_py/run_serial_tool.cmake

partition-table-flash: esp-idf/partition_table/CMakeFiles/partition-table-flash
partition-table-flash: esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/build.make
.PHONY : partition-table-flash

# Rule to build all files generated by this target.
esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/build: partition-table-flash
.PHONY : esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/build

esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/clean:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/partition_table && $(CMAKE_COMMAND) -P CMakeFiles/partition-table-flash.dir/cmake_clean.cmake
.PHONY : esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/clean

esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/depend:
	cd /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zr/桌面/esp/espProject/esp_main /home/zr/app/esp-idf/components/partition_table /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/partition_table /home/zr/桌面/esp/espProject/esp_main/cmake-build-debug/esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/depend

