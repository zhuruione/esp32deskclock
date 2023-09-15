file(GLOB STRUCTURE "*.c")
idf_component_register(SRCS ${STRUCTURE}
        INCLUDE_DIRS "."
        REQUIRES)
