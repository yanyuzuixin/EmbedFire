# add_subdirectory(bsp_led)

set(SRCS
    ./bsp_led/bsp_led.c
)
add_library(bsp_fire407_obj OBJECT ${SRCS})
target_include_directories(bsp_fire407_obj PRIVATE ${COMMON_FILE_PATH})
target_include_directories(bsp_fire407_obj PRIVATE ${PORT_PATH}/inc)
target_include_directories(bsp_fire407_obj PRIVATE ./cfg/bsp_led)
target_include_directories(bsp_fire407_obj PRIVATE ./inc)
# target_compile_definitions(bsp_fire407_obj PRIVATE ${STM32F4_COMMON_DEF})
target_compile_options(bsp_fire407_obj PRIVATE ${STM32F4_COMMON_OPTIONS})