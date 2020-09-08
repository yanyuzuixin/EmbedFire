set(SRCS
    bsp_led.c
)
add_library(bsp_led_obj OBJECT ${SRCS})
target_include_directories(bsp_led_obj PRIVATE ${STM32F4XX_LIB_INC})
target_compile_definitions(bsp_led_obj PRIVATE ${STM32F4_COMMON_DEF})
target_compile_options(bsp_led_obj PRIVATE ${STM32F4_COMMON_OPTIONS})
