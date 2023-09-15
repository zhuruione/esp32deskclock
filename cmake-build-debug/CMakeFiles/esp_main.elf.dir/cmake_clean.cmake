file(REMOVE_RECURSE
  "bootloader/bootloader.bin"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.map"
  "config/sdkconfig.cmake"
  "config/sdkconfig.h"
  "esp_main.bin"
  "esp_main.map"
  "flash_project_args"
  "project_elf_src_esp32.c"
  "CMakeFiles/esp_main.elf.dir/project_elf_src_esp32.c.obj"
  "CMakeFiles/esp_main.elf.dir/project_elf_src_esp32.c.obj.d"
  "esp_main.elf"
  "esp_main.elf.pdb"
  "project_elf_src_esp32.c"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/esp_main.elf.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
