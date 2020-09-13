set(SRCS
    port_gpio.c
)
add_library(port_stm32f4_obj OBJECT ${SRCS})
target_include_directories(port_stm32f4_obj PRIVATE ${STM32F4XX_LIB_INC})
target_include_directories(port_stm32f4_obj PRIVATE
    ${COMMON_FILE_PATH}
    ../inc
    ./cfg/port_gpio
)
target_compile_definitions(port_stm32f4_obj PRIVATE ${STM32F4_COMMON_DEF})
target_compile_options(port_stm32f4_obj PRIVATE ${STM32F4_COMMON_OPTIONS})