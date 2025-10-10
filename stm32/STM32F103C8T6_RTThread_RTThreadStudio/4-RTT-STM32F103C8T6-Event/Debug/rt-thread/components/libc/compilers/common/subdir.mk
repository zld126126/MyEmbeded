################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/libc/compilers/common/cctype.c \
../rt-thread/components/libc/compilers/common/cstdio.c \
../rt-thread/components/libc/compilers/common/cstdlib.c \
../rt-thread/components/libc/compilers/common/cstring.c \
../rt-thread/components/libc/compilers/common/ctime.c \
../rt-thread/components/libc/compilers/common/cwchar.c 

OBJS += \
./rt-thread/components/libc/compilers/common/cctype.o \
./rt-thread/components/libc/compilers/common/cstdio.o \
./rt-thread/components/libc/compilers/common/cstdlib.o \
./rt-thread/components/libc/compilers/common/cstring.o \
./rt-thread/components/libc/compilers/common/ctime.o \
./rt-thread/components/libc/compilers/common/cwchar.o 

C_DEPS += \
./rt-thread/components/libc/compilers/common/cctype.d \
./rt-thread/components/libc/compilers/common/cstdio.d \
./rt-thread/components/libc/compilers/common/cstdlib.d \
./rt-thread/components/libc/compilers/common/cstring.d \
./rt-thread/components/libc/compilers/common/ctime.d \
./rt-thread/components/libc/compilers/common/cwchar.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/libc/compilers/common/%.o: ../rt-thread/components/libc/compilers/common/%.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F1 -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\drivers" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\drivers\include" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\drivers\include\config" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\libraries\CMSIS\Device\ST\STM32F1xx\Include" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\libraries\STM32F1xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\libraries\STM32F1xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\applications" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\libc\compilers\common\include" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\include" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rt-thread\libcpu\arm\cortex-m3" -include"D:\RT-ThreadStudio\workspace\4-RTT-STM32F103C8T6-Event\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

