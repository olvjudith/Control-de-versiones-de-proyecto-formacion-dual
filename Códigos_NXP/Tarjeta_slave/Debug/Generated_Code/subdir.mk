################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/LPSPI1.c" \
"../Generated_Code/clock.c" \
"../Generated_Code/clockMan1.c" \
"../Generated_Code/gpio.c" \
"../Generated_Code/pin_mux.c" \
"../Generated_Code/timer.c" \
"../Generated_Code/window.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/LPSPI1.c \
../Generated_Code/clock.c \
../Generated_Code/clockMan1.c \
../Generated_Code/gpio.c \
../Generated_Code/pin_mux.c \
../Generated_Code/timer.c \
../Generated_Code/window.c \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu.o \
./Generated_Code/LPSPI1.o \
./Generated_Code/clock.o \
./Generated_Code/clockMan1.o \
./Generated_Code/gpio.o \
./Generated_Code/pin_mux.o \
./Generated_Code/timer.o \
./Generated_Code/window.o \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu.d" \
"./Generated_Code/LPSPI1.d" \
"./Generated_Code/clock.d" \
"./Generated_Code/clockMan1.d" \
"./Generated_Code/gpio.d" \
"./Generated_Code/pin_mux.d" \
"./Generated_Code/timer.d" \
"./Generated_Code/window.d" \

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/LPSPI1.o \
./Generated_Code/clock.o \
./Generated_Code/clockMan1.o \
./Generated_Code/gpio.o \
./Generated_Code/pin_mux.o \
./Generated_Code/timer.o \
./Generated_Code/window.o \

OBJS_QUOTED += \
"./Generated_Code/Cpu.o" \
"./Generated_Code/LPSPI1.o" \
"./Generated_Code/clock.o" \
"./Generated_Code/clockMan1.o" \
"./Generated_Code/gpio.o" \
"./Generated_Code/pin_mux.o" \
"./Generated_Code/timer.o" \
"./Generated_Code/window.o" \

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/LPSPI1.d \
./Generated_Code/clock.d \
./Generated_Code/clockMan1.d \
./Generated_Code/gpio.d \
./Generated_Code/pin_mux.d \
./Generated_Code/timer.d \
./Generated_Code/window.d \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/Cpu.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LPSPI1.o: ../Generated_Code/LPSPI1.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/LPSPI1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/LPSPI1.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/clock.o: ../Generated_Code/clock.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/clock.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/clock.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/clockMan1.o: ../Generated_Code/clockMan1.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/clockMan1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/clockMan1.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/gpio.o: ../Generated_Code/gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/gpio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/gpio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/pin_mux.o: ../Generated_Code/pin_mux.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/pin_mux.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/pin_mux.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/timer.o: ../Generated_Code/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/timer.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/window.o: ../Generated_Code/window.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Generated_Code/window.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Generated_Code/window.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


