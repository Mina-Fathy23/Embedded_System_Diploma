################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/STM32_F103C6_EXTI_drivers.c \
../STM32_F103C6_Drivers/STM32_F103C6_GPIO_drivers.c \
../STM32_F103C6_Drivers/STM32_F103C6_RCC_drivers.c \
../STM32_F103C6_Drivers/STM32_F103C6_USART_drivers.c 

OBJS += \
./STM32_F103C6_Drivers/STM32_F103C6_EXTI_drivers.o \
./STM32_F103C6_Drivers/STM32_F103C6_GPIO_drivers.o \
./STM32_F103C6_Drivers/STM32_F103C6_RCC_drivers.o \
./STM32_F103C6_Drivers/STM32_F103C6_USART_drivers.o 

C_DEPS += \
./STM32_F103C6_Drivers/STM32_F103C6_EXTI_drivers.d \
./STM32_F103C6_Drivers/STM32_F103C6_GPIO_drivers.d \
./STM32_F103C6_Drivers/STM32_F103C6_RCC_drivers.d \
./STM32_F103C6_Drivers/STM32_F103C6_USART_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/STM32_F103C6_EXTI_drivers.o: ../STM32_F103C6_Drivers/STM32_F103C6_EXTI_drivers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Seven_Segmant_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/inc" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103C6_EXTI_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103C6_GPIO_drivers.o: ../STM32_F103C6_Drivers/STM32_F103C6_GPIO_drivers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Seven_Segmant_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/inc" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103C6_GPIO_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103C6_RCC_drivers.o: ../STM32_F103C6_Drivers/STM32_F103C6_RCC_drivers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Seven_Segmant_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/inc" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103C6_RCC_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103C6_USART_drivers.o: ../STM32_F103C6_Drivers/STM32_F103C6_USART_drivers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/Seven_Segmant_Driver" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/inc" -I"D:/Mina/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103C6_USART_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

