################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.c 

OBJS += \
./libraries/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.o 

C_DEPS += \
./libraries/STM32F1xx_HAL_Driver/Src/Legacy/stm32f1xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/STM32F1xx_HAL_Driver/Src/Legacy/%.o: ../libraries/STM32F1xx_HAL_Driver/Src/Legacy/%.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F1 -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\drivers" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\drivers\include" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\drivers\include\config" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\libraries\CMSIS\Device\ST\STM32F1xx\Include" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\libraries\STM32F1xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\libraries\STM32F1xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\applications" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\libc\compilers\common\include" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\include" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rt-thread\libcpu\arm\cortex-m3" -include"D:\RT-ThreadStudio\workspace\2-RTT-STM32F103C8T6-Thread\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

