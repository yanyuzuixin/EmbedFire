set(SRCS
    main.c
    stm32f4xx_it.c
)
add_library(proj_led_test_main_obj OBJECT ${SRCS})
target_include_directories(proj_led_test_main_obj PRIVATE
    ${STM32F4XX_LIB_INC}
    ../../../hardware/bsp/led
)
target_compile_definitions(proj_led_test_main_obj PRIVATE
    STM32F40_41xxx
)


