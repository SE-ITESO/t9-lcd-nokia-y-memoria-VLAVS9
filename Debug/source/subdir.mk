################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/ImageDisplay.c \
../source/LCD_nokia.c \
../source/LCD_nokia_images.c \
../source/Memory.c \
../source/NVIC.c \
../source/PIT.c \
../source/SPI.c \
../source/main.c 

C_DEPS += \
./source/ImageDisplay.d \
./source/LCD_nokia.d \
./source/LCD_nokia_images.d \
./source/Memory.d \
./source/NVIC.d \
./source/PIT.d \
./source/SPI.d \
./source/main.d 

OBJS += \
./source/ImageDisplay.o \
./source/LCD_nokia.o \
./source/LCD_nokia_images.o \
./source/Memory.o \
./source/NVIC.o \
./source/PIT.o \
./source/SPI.o \
./source/main.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/board" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/utilities" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/drivers" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/device" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/component/serial_manager" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/component/lists" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/CMSIS" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/component/uart" -I"/Users/miguelvladimirvargassanchez/Documents/MCUXpressoIDE_11.9.0_2144/PDS/NOKIA/NOKIA_nk/source" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/ImageDisplay.d ./source/ImageDisplay.o ./source/LCD_nokia.d ./source/LCD_nokia.o ./source/LCD_nokia_images.d ./source/LCD_nokia_images.o ./source/Memory.d ./source/Memory.o ./source/NVIC.d ./source/NVIC.o ./source/PIT.d ./source/PIT.o ./source/SPI.d ./source/SPI.o ./source/main.d ./source/main.o

.PHONY: clean-source

