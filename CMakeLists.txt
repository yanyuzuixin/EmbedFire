cmake_minimum_required(VERSION 3.14.1)

# 设置构建类型，未定义则默认为Debug
# 
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug build.")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message("Release build.")
endif()

# 引用toolchain，可以直接引用，也可以在执行cmake命令时配置
include(cmake/toolchain_arm_gcc.cmake)

set(PROJECT_NAME "hjr_embed_proj")

project(${PROJECT_NAME} C ASM)

set(PROJ_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(VENDOR_PATH ${PROJ_ROOT_PATH}/vendor)
set(STM32_LIB_SRC_PATH ${VENDOR_PATH}/stm32_lib)

set(STM32F4XX_LIB_ROOT ${STM32_LIB_SRC_PATH}/stm32f4/STM32F4xx_DSP_StdPeriph_Lib_V1.8.0)
set(STM32F4XX_LIB_DRIVER ${STM32F4XX_LIB_ROOT}/Libraries/STM32F4xx_StdPeriph_Driver)
set(STM32F4XX_LIB_CMSIS ${STM32F4XX_LIB_ROOT}/Libraries/CMSIS)
set(STM32F4XX_LIB_STARTUP ${STM32F4XX_LIB_CMSIS}/Device/ST/STM32F4xx)

set(STM32F4XX_LIB_INC
    ${STM32F4XX_LIB_DRIVER}/inc
    ${STM32F4XX_LIB_CMSIS}/Include
    ${STM32F4XX_LIB_STARTUP}/Include
    ${STM32_LIB_SRC_PATH}/stm32f4/cfg
)

set(STM32F40_41XXX_LD ${STM32F4XX_LIB_ROOT}/Project/STM32F4xx_StdPeriph_Templates/TrueSTUDIO/STM32F40_41xxx/STM32F417IG_FLASH.ld)

set(STM32F4_COMMON_DEF
    __UVISION_VERSION="526"
    __GCC
    __GCC_VERSION="921"
    STM32F407xx
    STM32F40XX
    USE_STDPERIPH_DRIVER
)

set(STM32F4_COMMON_OPTIONS
    -mcpu=cortex-m4
    -mthumb
    -MD
    -w
    -Os
    -mapcs-frame
    -mapcs-stack-check
    -mthumb-interwork
    -mcpu=cortex-m4
    -mthumb
    -fdata-sections
    -ffunction-sections
)

set(STM32F4_COMMON_LINK_OPTIONS
    -T ${STM32F40_41XXX_LD}
    -mcpu=cortex-m4
    -mthumb
    -mthumb-interwork
    -nostartfiles
    -lm
    -Wl,--gc-sections
)

add_subdirectory(src)
add_subdirectory(vendor)
