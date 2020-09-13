# add_subdirectory(module_led)

# 
set(SRCS
    ./module_led/module_led.c
)
add_library(module_proj_led_test_obj OBJECT ${SRCS})
target_include_directories(module_proj_led_test_obj PRIVATE ${COMMON_FILE_PATH})
target_include_directories(module_proj_led_test_obj PRIVATE ${HARDWARE_BSP_PATH}/inc)
target_include_directories(module_proj_led_test_obj PRIVATE ./cfg/module_led)
target_include_directories(module_proj_led_test_obj PRIVATE ./inc)
target_compile_options(module_proj_led_test_obj PRIVATE ${STM32F4_COMMON_OPTIONS})