file(GLOB MYWINDOWS "*.c")
idf_component_register(SRCS ${MYWINDOWS}
        INCLUDE_DIRS "."
        REQUIRES my_windows nvs_flash lvgl client)