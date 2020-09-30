set(STM32F4_DEVICE STM32F40_41xxx)

set(STM32F4XX_LIB_SRCS
    ${STM32F4XX_LIB_DRIVER}/src/misc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_adc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_can.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_cec.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_crc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_cryp.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_cryp_aes.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_cryp_des.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_cryp_tdes.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_dac.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_dbgmcu.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_dcmi.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_dma.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_dma2d.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_dsi.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_exti.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_flash.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_flash_ramfunc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_fmpi2c.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_gpio.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_hash.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_hash_md5.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_hash_sha1.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_i2c.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_iwdg.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_lptim.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_ltdc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_pwr.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_qspi.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_rcc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_rng.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_rtc.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_sai.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_sdio.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_spdifrx.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_spi.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_syscfg.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_tim.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_usart.c
    ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_wwdg.c
)

# FMC/FSMC only defined for some F4 families
if (STM32F4_DEVICE STREQUAL STM32F427_437xx OR 
    STM32F4_DEVICE STREQUAL STM32F429_439xx OR 
    STM32F4_DEVICE STREQUAL STM32F446xx OR 
    STM32F4_DEVICE STREQUAL STM32F469_479xx)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_fmc.c
    )
else()
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_DRIVER}/src/stm32f4xx_fsmc.c
    )
endif()

set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
    ${STM32F4XX_LIB_STARTUP}/Source/Templates/system_stm32f4xx.c
)

if (STM32F4_DEVICE STREQUAL STM32F40XX)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_STARTUP}/Source/Templates/gcc_ride7/startup_stm32f40xx.s
    )
elseif (STM32F4_DEVICE STREQUAL STM32F401X)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_STARTUP}/Source/Templates/gcc_ride7/startup_stm32f401xx.s
    )
elseif (STM32F4_DEVICE STREQUAL STM32F40_41xxx)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_STARTUP}/Source/Templates/gcc_ride7/startup_stm32f40_41xxx.s
    )
elseif (STM32F4_DEVICE STREQUAL STM32F427_437xx)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_STARTUP}/Source/Templates/gcc_ride7/startup_stm32f427_437xx.s
    )
elseif (STM32F4_DEVICE STREQUAL STM32F427x)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_STARTUP}/Source/Templates/gcc_ride7/startup_stm32f427x.s
    )
elseif (STM32F4_DEVICE STREQUAL STM32F429_439xx)
    set(STM32F4XX_LIB_SRCS ${STM32F4XX_LIB_SRCS}
        ${STM32F4XX_LIB_STARTUP}/Source/Templates/gcc_ride7/startup_stm32f429_439xx.s
    )
endif()

add_library(stm32f4xx_lib ${STM32F4XX_LIB_SRCS})
target_include_directories(stm32f4xx_lib PUBLIC 
    ${STM32F4XX_LIB_INC}
    ./cfg
)

target_compile_definitions(stm32f4xx_lib PRIVATE ${STM32F4_COMMON_DEF})
target_compile_options(stm32f4xx_lib PRIVATE ${STM32F4_COMMON_OPTIONS})
