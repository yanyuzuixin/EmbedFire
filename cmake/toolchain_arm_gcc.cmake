# 在toolchain脚本中必须要设置的变量，只有当CMAKE_SYSTEM_NAME这个变量被设置了，
# CMake才认为此时正在交叉编译，它会额外设置一个变量CMAKE_CROSSCOMPILING为TRUE。
# CMAKE_SYSTEM_NAME即目标机target所在的操作系统名称，
# 比如ARM或者Linux你就需要写”Linux”,如果Android平台你就写”Android”,
# 如果你的嵌入式平台没有相关OS你即需要写成”Generic”
set(CMAKE_SYSTEM_NAME Generic)

# 这个是可选项，但是在移动开发中很重要，代表目标系统的硬件或者CPU型号，例如ARM，X86 etc
set(CMAKE_SYSTEM_PROCESSOR arm)

# 设置编译器
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)

# 设置编译选项
set(CORE_FLAGS "-mthumb -mthumb-interwork -mcpu=cortex-m4")
set(CORE_FLASS "${CORE_FLASS} -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork")
set(CORE_FLASS "${CORE_FLASS} --specs=nano.specs --specs=nosys.specs")
set(CORE_FLASS "${CORE_FLASS} -fdata-sections -ffunction-sections")

# C编译选项
set(CMAKE_C_FLAGS "${CORE_FLASS} -Wall -Os -mapcs-frame -mapcs-stack-check ")
# 设置全局变量
set(CMAKE_C_FLAGS_DEBUG "" CACHE INTERNAL "c compiler flags: Debug")
set(CMAKE_C_FLAGS_RELEASE "" CACHE INTERNAL "c compiler flags: Release")

set(CMAKE_CXX_FLAGS "${CORE_FLAGS} -fno-rtti -fno-exceptions -fno-builtin -Wall -std=gnu++11 -fdata-sections -ffunction-sections -g -ggdb3" CACHE INTERNAL "cxx compiler flags")
set(CMAKE_CXX_FLAGS_DEBUG "" CACHE INTERNAL "cxx compiler flags: Debug")
set(CMAKE_CXX_FLAGS_RELEASE "" CACHE INTERNAL "cxx compiler flags: Release")

set(CMAKE_ASM_FLAGS "${CORE_FLAGS} -g -ggdb3 -D__USES_CXX" CACHE INTERNAL "asm compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG "" CACHE INTERNAL "asm compiler flags: Debug")
set(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm compiler flags: Release")

# 对FIND_PROGRAM()起作用，有三种取值，NEVER,ONLY,BOTH,
# 第一个表示不在你CMAKE_FIND_ROOT_PATH下进行查找，
# 第二个表示只在这个路径下查找，
# 第三个表示先查找这个路径，再查找全局路径，
# 对于这个变量来说，一般都是调用宿主机的程序，所以一般都设置成NEVER
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# 对FIND_LIBRARY()起作用，表示在链接的时候的库的相关选项，
# 因此这里需要设置成ONLY来保证我们的库是在交叉环境中找的
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

# 对FIND_PATH()和FIND_FILE()起作用，一般来说也是ONLY,
# 如果你想改变，一般也是在相关的FIND命令中增加option来改变局部设置，
# 有NO_CMAKE_FIND_ROOT_PATH,
# ONLY_CMAKE_FIND_ROOT_PATH,
# BOTH_CMAKE_FIND_ROOT_PATH
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# 对find_package()起作用 NEVER,ONLY,BOTH
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# 查找其他可执行程序
find_program(ARM_SIZE_EXECUTABLE arm-none-eabi-size)
find_program(ARM_GDB_EXECUTABLE arm-none-eabi-gdb)
find_program(ARM_OBJCOPY_EXECUTABLE arm-none-eabi-objcopy)
find_program(ARM_OBJDUMP_EXECUTABLE arm-none-eabi-objdump)