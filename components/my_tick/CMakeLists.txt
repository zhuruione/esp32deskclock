file(GLOB MYTICK "*.c")
idf_component_register(SRCS ${MYTICK}
        INCLUDE_DIRS "."
        REQUIRES driver)