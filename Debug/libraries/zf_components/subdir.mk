################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/zf_components/printf_redirect.c \
../libraries/zf_components/seekfree_assistant.c \
../libraries/zf_components/seekfree_assistant_interface.c 

COMPILED_SRCS += \
./libraries/zf_components/printf_redirect.src \
./libraries/zf_components/seekfree_assistant.src \
./libraries/zf_components/seekfree_assistant_interface.src 

C_DEPS += \
./libraries/zf_components/printf_redirect.d \
./libraries/zf_components/seekfree_assistant.d \
./libraries/zf_components/seekfree_assistant_interface.d 

OBJS += \
./libraries/zf_components/printf_redirect.o \
./libraries/zf_components/seekfree_assistant.o \
./libraries/zf_components/seekfree_assistant_interface.o 


# Each subdirectory must supply rules for building sources it contributes
libraries/zf_components/%.src: ../libraries/zf_components/%.c libraries/zf_components/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc26xb "-fC:/Users/ZeroHzzzz/Desktop/Seekfree_TC264_Opensource_Library/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/libraries\/zf_components\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

libraries/zf_components/%.o: ./libraries/zf_components/%.src libraries/zf_components/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-libraries-2f-zf_components

clean-libraries-2f-zf_components:
	-$(RM) ./libraries/zf_components/printf_redirect.d ./libraries/zf_components/printf_redirect.o ./libraries/zf_components/printf_redirect.src ./libraries/zf_components/seekfree_assistant.d ./libraries/zf_components/seekfree_assistant.o ./libraries/zf_components/seekfree_assistant.src ./libraries/zf_components/seekfree_assistant_interface.d ./libraries/zf_components/seekfree_assistant_interface.o ./libraries/zf_components/seekfree_assistant_interface.src

.PHONY: clean-libraries-2f-zf_components

