add_subdirectory(main)

set(proj_name proj_led_test_exec)

set(elf_file ${proj_name}.elf)
set(bin_file ${proj_name}.bin)
set(hex_file ${proj_name}.hex)
set(map_file ${proj_name}.map)
set(lss_file ${proj_name}.lss)

add_executable(${elf_file}
    $<TARGET_OBJECTS:port_stm32f4_obj>
    $<TARGET_OBJECTS:bsp_fire407_obj>
    $<TARGET_OBJECTS:module_proj_led_test_obj>
    $<TARGET_OBJECTS:proj_led_test_main_obj>
)
target_link_libraries(${elf_file} PUBLIC stm32f4xx_lib)
target_link_options(${elf_file} PUBLIC ${STM32F4_COMMON_LINK_OPTIONS})
target_link_options(${elf_file} PUBLIC -Wl,-Map=${map_file},--print-memory-usage)

# generate extended listing
add_custom_target(${lss_file} DEPENDS ${elf_file} COMMAND ${ARM_OBJDUMP_EXECUTABLE} -S ${elf_file} > ${lss_file})

# create binary and hex files
add_custom_target(${hex_file} DEPENDS ${elf_file} COMMAND ${ARM_OBJCOPY_EXECUTABLE} -O ihex ${elf_file} ${hex_file})
add_custom_target(${bin_file} DEPENDS ${elf_file} COMMAND ${ARM_OBJCOPY_EXECUTABLE} -O binary ${elf_file} ${bin_file})
add_custom_target(${proj_name} ALL DEPENDS ${bin_file} ${hex_file} ${lss_file})