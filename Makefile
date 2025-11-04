# Project name
TARGET = main

# Source files
SRC = main.cpp

# Compiler
CC = g++

# Use pkg-config to get compiler and linker flags
PKGS = raylib

CFLAGS = -Wall -Wextra -O2 $(shell pkg-config --cflags $(PKGS))
LDFLAGS = $(shell pkg-config --libs $(PKGS))

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (not real files)
.PHONY: all clean
