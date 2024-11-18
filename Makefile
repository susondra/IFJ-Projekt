# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -g

# Source Files
SRC = simulation.c generator.c dynamic_string.c

# Output Executable
TARGET = simulation

# Build Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
