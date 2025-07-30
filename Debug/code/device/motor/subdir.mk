################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/device/motor/emm42.c \
../code/device/motor/zfmotor.c 

COMPILED_SRCS += \
./code/device/motor/emm42.src \
./code/device/motor/zfmotor.src 

C_DEPS += \
./code/device/motor/emm42.d \
./code/device/motor/zfmotor.d 

OBJS += \
./code/device/motor/emm42.o \
./code/device/motor/zfmotor.o 


# Each subdirectory must supply rules for building sources it contributes
code/device/motor/%.src: ../code/device/motor/%.c code/device/motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc26xb "-fC:/Users/ZeroHzzzz/Desktop/Seekfree_TC264_Opensource_Library/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/code\/device\/motor\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

code/device/motor/%.o: ./code/device/motor/%.src code/device/motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-code-2f-device-2f-motor

clean-code-2f-device-2f-motor:
	-$(RM) ./code/device/motor/emm42.d ./code/device/motor/emm42.o ./code/device/motor/emm42.src ./code/device/motor/zfmotor.d ./code/device/motor/zfmotor.o ./code/device/motor/zfmotor.src

.PHONY: clean-code-2f-device-2f-motor

