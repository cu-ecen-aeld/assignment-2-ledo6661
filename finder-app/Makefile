# Compiler and flags
CC ?= $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror

# Target executable
TARGET = writer
SRC = writer.c

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean target
clean:
	rm -f $(TARGET) *.o
