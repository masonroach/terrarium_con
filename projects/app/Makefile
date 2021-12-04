#
# Makefile for STM32WB family
#
# ==============================================================================
# Usage
# ==============================================================================
#
# [make]
# [make all]
#
# [make clean]
#
# [make flash]
#

# ==============================================================================
# Defines
# ==============================================================================

# Define compilers
PREFIX = arm-none-eabi
CC = $(PREFIX)-gcc
CPP = $(PREFIX)-g++
LD = $(PREFIX)-gcc
AS = $(PREFIX)-as
CP = $(PREFIX)-objcopy
OD = $(PREFIX)-objdump

# Optimization
# O0 -> No optimization
# O1, O2, O3 -> Speed optimizations
# Os -> Size optimization
# Og -> Optimize for debugging
O_LEVEL = -O0

# Directories
COMDIR    := ../common
SRCDIR    := src
INCDIR    := inc
OBJDIR    := obj
LIBDIR    := ../../lib
TARGETDIR := ../../bin

# Define target
TARGET = $(TARGETDIR)/app

# Add common directories
SRCDIR += $(wildcard $(COMDIR)/src/*/)
INCDIR += $(wildcard $(COMDIR)/inc/*/)

# Find all source files and declare objects
SRC := $(shell find $(SRCDIR) -name [^.]*.c)
SRC += $(shell find $(SRCDIR) -name [^.]*.cpp)

# Define linker
LINKER = tcon_app_linker.ld

# Define include paths
INCLUDES := $(INCDIR)
INCFLAGS := $(addprefix -I, $(INCLUDES))

# Get info from packages
LIBMAKES := $(shell find $(LIBDIR)/*/Makefile)
$(foreach SUBMAKE, $(LIBMAKES), $(eval include $(SUBMAKE)))

# Define vpaths
vpath %.c $(SRCDIR)
vpath %.cpp $(SRCDIR)
vpath %.s $(SRCDIR)
vpath %.o $(OBJDIR)

# Generate objects
OBJ := $(addprefix $(OBJDIR)/,$(notdir $(SRC)))
OBJ := $(OBJ:.c=.o)
OBJ := $(OBJ:.cpp=.o)
OBJ := $(OBJ:.s=.o)

# Linker flags
LDFLAGS = -Wl,-T$(LINKER),-Map=$(TARGET).map

# Target processor
PROCESSOR = STM32WB30xx

# C compiler flags
CFLAGS = $(O_LEVEL) $(INCFLAGS) -Wall -nostartfiles -lnosys -g3 -std=gnu11 \
	-mcpu=cortex-m4 --specs=nosys.specs -lgcc -D$(PROCESSOR) -DUSE_HAL_DRIVER \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -ffreestanding -fno-builtin \
	-ffunction-sections -fdata-sections

# C++ compiler flags
CPPFLAGS = $(CFLAGS) -fno-exceptions

# ==============================================================================
# Targets
# ==============================================================================
all: $(TARGET).hex $(TARGET).bin
	@echo Done

# ==============================================================================
# Compiler rules
# ==============================================================================
# Objcopy for binary
$(TARGET).bin: $(TARGET).elf
	$(CP) -O binary $< $@

# Objcopy for hex
$(TARGET).hex: $(TARGET).elf
	$(CP) -O ihex $^ $@

# Compile executable
$(TARGET).elf: $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Compile c objects rule
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

# Compile c++ objects rule
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

#Compile s objects rule
$(OBJDIR)/%.o: %.s
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -o $@ $<

# ==============================================================================
# Cleaning
# ==============================================================================
clean:
	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).bin $(TARGET).map $(OBJDIR)/*.o

# ==============================================================================
# Flashing
# ==============================================================================
flash: $(TARGET).hex
	st-flash erase
	st-flash write $(TARGET).bin $(FLASH_ADDR)

# ==============================================================================
# Debugging
# ==============================================================================
debug: flash
	st-util -p 4242 &
	gdb-multiarch $(TARGET).elf -tui -ex "target remote 127.0.0.1:4242"

#debug-gdb:

