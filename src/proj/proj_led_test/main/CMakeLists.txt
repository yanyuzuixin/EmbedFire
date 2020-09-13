set(SRCS
    main.c
    # bsp_usart.c
    # stm32f4xx_it.c
    # isr.c
)
add_library(proj_led_test_main_obj OBJECT ${SRCS})
target_include_directories(proj_led_test_main_obj PRIVATE
    ${MODULE_PATH}/inc
)
target_compile_definitions(proj_led_test_main_obj PRIVATE ${STM32F4_COMMON_DEF})
target_compile_options(proj_led_test_main_obj PRIVATE ${STM32F4_COMMON_OPTIONS})


