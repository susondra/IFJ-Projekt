# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -g

# Source Files
SRC = simulation.c src/generator.c src/dynamic_string.c

# Output Executable
TARGET = simulation

DELETE = output.ifjcode

# Build Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) $(DELETE)
