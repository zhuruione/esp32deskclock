file(GLOB MYWIFI "*.c")
idf_component_register(SRCS ${MYWIFI}
        INCLUDE_DIRS "."
        REQUIRES esp_wifi nvs_flash)