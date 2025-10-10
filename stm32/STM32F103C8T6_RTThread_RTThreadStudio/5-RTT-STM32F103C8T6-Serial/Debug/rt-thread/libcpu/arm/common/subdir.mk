################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/libcpu/arm/common/backtrace.c \
../rt-thread/libcpu/arm/common/div0.c \
../rt-thread/libcpu/arm/common/showmem.c 

OBJS += \
./rt-thread/libcpu/arm/common/backtrace.o \
./rt-thread/libcpu/arm/common/div0.o \
./rt-thread/libcpu/arm/common/showmem.o 

C_DEPS += \
./rt-thread/libcpu/arm/common/backtrace.d \
./rt-thread/libcpu/arm/common/div0.d \
./rt-thread/libcpu/arm/common/showmem.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/libcpu/arm/common/%.o: ../rt-thread/libcpu/arm/common/%.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F1 -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\drivers" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\drivers\include" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\drivers\include\config" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\libraries\CMSIS\Device\ST\STM32F1xx\Include" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\libraries\STM32F1xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\libraries\STM32F1xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\applications" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\libc\compilers\common\include" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\include" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rt-thread\libcpu\arm\cortex-m3" -include"D:\RT-ThreadStudio\workspace\5-RTT-STM32F103C8T6-Serial\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

