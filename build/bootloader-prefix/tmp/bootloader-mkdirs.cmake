# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/zr/app/esp-idf/components/bootloader/subproject"
  "/home/zr/桌面/espProject/esp_main/build/bootloader"
  "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix"
  "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix/tmp"
  "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix/src/bootloader-stamp"
  "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix/src"
  "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/zr/桌面/espProject/esp_main/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
