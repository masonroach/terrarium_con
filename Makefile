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
SRCDIR    := src
INCDIR    := inc
OBJDIR    := obj
LIBDIR    := lib
COREDIR   := core
TARGETDIR := bin

# Get info from packages
LIBMAKES := $(shell find $(LIBDIR)/*/Makefile)
$(foreach SUBLIB, $(LIBMAKES), $(eval include $(SUBLIB)))

# Define vpaths
vpath %.c $(SRCDIR) $(COREDIR)/src
vpath %.cpp $(SRCDIR) $(COREDIR)/src
vpath %.o $(OBJDIR)

# Define target
TARGET = $(TARGETDIR)/main

# Find all source files and declare objects
SRC := $(shell find $(SRCDIR) -name [^.]*.c)
SRC += $(shell find $(SRCDIR) -name [^.]*.cpp)
OBJ := $(addprefix $(OBJDIR)/,$(notdir $(SRC)))
OBJ := $(OBJ:.c=.o)
OBJ := $(OBJ:.cpp=.o)

LINKER = $(COREDIR)/tcon_coreapp_linker.ld

# Define include paths
INCLUDES := $(INCDIR) $(COREDIR)/inc
INCFLAGS := $(addprefix -I, $(INCLUDES))

# Linker flags
LDFLAGS = -Wl,-T,$(LINKER),-Map=$(TARGET).map,--cref

# C compiler flags
CFLAGS = $(O_LEVEL) $(INCFLAGS) -Wall -nostartfiles -lnosys -g3 $(LDFLAGS) \
	-mcpu=cortex-m4 --specs=nosys.specs -nodefaultlibs -nostdlib \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wextra

# C++ compiler flags
CPPFLAGS = $(CFLAGS) -fno-exceptions

# Flashing options
FLASH_ADDR := "0x08000000"

# ==============================================================================
# Compiler rules
# ==============================================================================
all: $(TARGET).hex $(TARGET).bin

# Objcopy for binary
$(TARGET).bin: $(TARGET).elf
	$(CP) -O binary $< $@

# Objcopy for hex
$(TARGET).hex: $(TARGET).elf
	$(CP) -O ihex $^ $@

# Compile executable
$(TARGET).elf: $(OBJ)
	@mkdir -p $(@D)
	$(CPP) $(CFLAGS) $^ -o $@

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

