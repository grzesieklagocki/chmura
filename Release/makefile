################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TIMER2/subdir.mk
-include PWM/subdir.mk
-include HD44780/subdir.mk
-include ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
chmura.lss \

FLASH_IMAGE += \
chmura.hex \

EEPROM_IMAGE += \
chmura.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: chmura.elf secondary-outputs

# Tool invocations
chmura.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,chmura.map -mmcu=atmega328p -o "chmura.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

chmura.lss: chmura.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S chmura.elf  >"chmura.lss"
	@echo 'Finished building: $@'
	@echo ' '

chmura.hex: chmura.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex chmura.elf  "chmura.hex"
	@echo 'Finished building: $@'
	@echo ' '

chmura.eep: chmura.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex chmura.elf  "chmura.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: chmura.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p chmura.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) chmura.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
