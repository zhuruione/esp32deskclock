file(GLOB SPIFLASH "*.c")
idf_component_register(SRCS ${SPIFLASH}
        INCLUDE_DIRS "."
        REQUIRES driver spi_flash)
