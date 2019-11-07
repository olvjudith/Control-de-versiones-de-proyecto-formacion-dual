################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/GPIO.c" \
"../src/SPI1.c" \
"../src/S_Configurations.c" \
"../src/WindowLifter.c" \
"../src/WindowLifter_State.c" \
"../src/clocks.c" \
"../src/main.c" \

C_SRCS += \
../src/GPIO.c \
../src/SPI1.c \
../src/S_Configurations.c \
../src/WindowLifter.c \
../src/WindowLifter_State.c \
../src/clocks.c \
../src/main.c \

OBJS_OS_FORMAT += \
./src/GPIO.o \
./src/SPI1.o \
./src/S_Configurations.o \
./src/WindowLifter.o \
./src/WindowLifter_State.o \
./src/clocks.o \
./src/main.o \

C_DEPS_QUOTED += \
"./src/GPIO.d" \
"./src/SPI1.d" \
"./src/S_Configurations.d" \
"./src/WindowLifter.d" \
"./src/WindowLifter_State.d" \
"./src/clocks.d" \
"./src/main.d" \

OBJS += \
./src/GPIO.o \
./src/SPI1.o \
./src/S_Configurations.o \
./src/WindowLifter.o \
./src/WindowLifter_State.o \
./src/clocks.o \
./src/main.o \

OBJS_QUOTED += \
"./src/GPIO.o" \
"./src/SPI1.o" \
"./src/S_Configurations.o" \
"./src/WindowLifter.o" \
"./src/WindowLifter_State.o" \
"./src/clocks.o" \
"./src/main.o" \

C_DEPS += \
./src/GPIO.d \
./src/SPI1.d \
./src/S_Configurations.d \
./src/WindowLifter.d \
./src/WindowLifter_State.d \
./src/clocks.d \
./src/main.d \


# Each subdirectory must supply rules for building sources it contributes
src/GPIO.o: ../src/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/GPIO.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SPI1.o: ../src/SPI1.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/SPI1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/SPI1.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/S_Configurations.o: ../src/S_Configurations.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/S_Configurations.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/S_Configurations.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/WindowLifter.o: ../src/WindowLifter.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/WindowLifter.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/WindowLifter.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/WindowLifter_State.o: ../src/WindowLifter_State.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/WindowLifter_State.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/WindowLifter_State.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/clocks.o: ../src/clocks.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clocks.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/clocks.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


