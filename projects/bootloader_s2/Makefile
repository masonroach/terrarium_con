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
LD = $(PREFIX)-ld
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
TARGET = $(TARGETDIR)/boot2

# Add common directories
SRCDIR += $(wildcard $(COMDIR)/src/*/)
INCDIR += $(wildcard $(COMDIR)/inc/*/)

# Find all source files and declare objects
SRC := $(shell find $(SRCDIR) -name [^.]*.c)
SRC += $(shell find $(SRCDIR) -name [^.]*.cpp)

# Define linker
LINKER = tcon_boot2_linker.ld

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
LDFLAGS = -Wl,-T,$(LINKER),-Map=$(TARGET).map,--cref

# C compiler flags
CFLAGS = $(O_LEVEL) $(INCFLAGS) -Wall -nostartfiles -lnosys -g3 $(LDFLAGS) \
	-mcpu=cortex-m4 --specs=nosys.specs -nodefaultlibs -nostdlib \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb

# C++ compiler flags
CPPFLAGS = $(CFLAGS) -fno-exceptions

# Flashing options
FLASH_ADDR := "0x08000000"

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
	$(CC) $(CFLAGS) $^ -o $@

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
# Targets
# ==============================================================================
all: $(TARGET).hex $(TARGET).bin
	@echo Done

# ==============================================================================
# Cleaning
# ==============================================================================
clean:
	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).bin $(OBJDIR)/*.o

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

