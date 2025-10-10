################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/libcpu/arm/cortex-m3/cpuport.c 

S_UPPER_SRCS += \
../rt-thread/libcpu/arm/cortex-m3/context_gcc.S 

OBJS += \
./rt-thread/libcpu/arm/cortex-m3/context_gcc.o \
./rt-thread/libcpu/arm/cortex-m3/cpuport.o 

S_UPPER_DEPS += \
./rt-thread/libcpu/arm/cortex-m3/context_gcc.d 

C_DEPS += \
./rt-thread/libcpu/arm/cortex-m3/cpuport.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/libcpu/arm/cortex-m3/%.o: ../rt-thread/libcpu/arm/cortex-m3/%.S
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -x assembler-with-cpp -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key" -Xassembler -mimplicit-it=thumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
rt-thread/libcpu/arm/cortex-m3/%.o: ../rt-thread/libcpu/arm/cortex-m3/%.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F1 -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\drivers" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\drivers\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\drivers\include\config" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\CMSIS\Device\ST\STM32F1xx\Include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\STM32F1xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\STM32F1xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\applications" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\compilers\common\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\libcpu\arm\cortex-m3" -include"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

