file(GLOB CLIENT "*.c")
idf_component_register(SRCS ${CLIENT}
        INCLUDE_DIRS "."
        REQUIRES my_wifi)
