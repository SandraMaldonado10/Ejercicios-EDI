################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FechaYHora.cpp \
../src/Informe.cpp \
../src/Medico.cpp \
../src/PilaInformes.cpp \
../src/PruebasEnsayoClinico.cpp \
../src/ensayoclinico.cpp \
../src/paciente.cpp \
../src/prog_principal.cpp \
../src/timer.cpp 

CPP_DEPS += \
./src/FechaYHora.d \
./src/Informe.d \
./src/Medico.d \
./src/PilaInformes.d \
./src/PruebasEnsayoClinico.d \
./src/ensayoclinico.d \
./src/paciente.d \
./src/prog_principal.d \
./src/timer.d 

OBJS += \
./src/FechaYHora.o \
./src/Informe.o \
./src/Medico.o \
./src/PilaInformes.o \
./src/PruebasEnsayoClinico.o \
./src/ensayoclinico.o \
./src/paciente.o \
./src/prog_principal.o \
./src/timer.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/FechaYHora.d ./src/FechaYHora.o ./src/Informe.d ./src/Informe.o ./src/Medico.d ./src/Medico.o ./src/PilaInformes.d ./src/PilaInformes.o ./src/PruebasEnsayoClinico.d ./src/PruebasEnsayoClinico.o ./src/ensayoclinico.d ./src/ensayoclinico.o ./src/paciente.d ./src/paciente.o ./src/prog_principal.d ./src/prog_principal.o ./src/timer.d ./src/timer.o

.PHONY: clean-src

