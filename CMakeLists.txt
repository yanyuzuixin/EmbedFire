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

project(${PROJECT_NAME} C CXX ASM)

set(PROJ_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include(src)
include(vendor)
