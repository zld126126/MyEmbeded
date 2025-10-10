################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/finsh/cmd.c \
../rt-thread/components/finsh/msh.c \
../rt-thread/components/finsh/msh_parse.c \
../rt-thread/components/finsh/shell.c 

OBJS += \
./rt-thread/components/finsh/cmd.o \
./rt-thread/components/finsh/msh.o \
./rt-thread/components/finsh/msh_parse.o \
./rt-thread/components/finsh/shell.o 

C_DEPS += \
./rt-thread/components/finsh/cmd.d \
./rt-thread/components/finsh/msh.d \
./rt-thread/components/finsh/msh_parse.d \
./rt-thread/components/finsh/shell.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/finsh/%.o: ../rt-thread/components/finsh/%.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F1 -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\drivers" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\drivers\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\drivers\include\config" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\CMSIS\Device\ST\STM32F1xx\Include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\STM32F1xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\libraries\STM32F1xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\applications" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\compilers\common\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\include" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rt-thread\libcpu\arm\cortex-m3" -include"D:\RT-ThreadStudio\workspace\3-RTT-STM32F103C8T6-Key\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

