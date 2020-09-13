set(COMMON_FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(HARDWARE_BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/hardware/bsp)
set(MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/module)

add_subdirectory(hardware)
add_subdirectory(module)
add_subdirectory(proj)
# add_subdirectory(rtos)