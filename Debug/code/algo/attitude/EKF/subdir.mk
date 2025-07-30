################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/algo/attitude/EKF/QuaternionEKF.c \
../code/algo/attitude/EKF/kalman_filter.c \
../code/algo/attitude/EKF/matrix.c 

COMPILED_SRCS += \
./code/algo/attitude/EKF/QuaternionEKF.src \
./code/algo/attitude/EKF/kalman_filter.src \
./code/algo/attitude/EKF/matrix.src 

C_DEPS += \
./code/algo/attitude/EKF/QuaternionEKF.d \
./code/algo/attitude/EKF/kalman_filter.d \
./code/algo/attitude/EKF/matrix.d 

OBJS += \
./code/algo/attitude/EKF/QuaternionEKF.o \
./code/algo/attitude/EKF/kalman_filter.o \
./code/algo/attitude/EKF/matrix.o 


# Each subdirectory must supply rules for building sources it contributes
code/algo/attitude/EKF/%.src: ../code/algo/attitude/EKF/%.c code/algo/attitude/EKF/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc26xb "-fC:/Users/ZeroHzzzz/Desktop/Seekfree_TC264_Opensource_Library/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/code\/algo\/attitude\/EKF\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

code/algo/attitude/EKF/%.o: ./code/algo/attitude/EKF/%.src code/algo/attitude/EKF/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-code-2f-algo-2f-attitude-2f-EKF

clean-code-2f-algo-2f-attitude-2f-EKF:
	-$(RM) ./code/algo/attitude/EKF/QuaternionEKF.d ./code/algo/attitude/EKF/QuaternionEKF.o ./code/algo/attitude/EKF/QuaternionEKF.src ./code/algo/attitude/EKF/kalman_filter.d ./code/algo/attitude/EKF/kalman_filter.o ./code/algo/attitude/EKF/kalman_filter.src ./code/algo/attitude/EKF/matrix.d ./code/algo/attitude/EKF/matrix.o ./code/algo/attitude/EKF/matrix.src

.PHONY: clean-code-2f-algo-2f-attitude-2f-EKF

