# Makefile for building C files

# Compiler and Linker definitions
CC = gcc
LD = gcc

# Flags for the compiler and linker
CFLAGS = -Wall -g
LDFLAGS =

# Source directories
SRCDIR = src

# Object files
OBJECTS = $(SRCDIR)/main.o

# Executable name
EXECUTABLE = main

# Default target
all: $(EXECUTABLE)

# Link object files into a binary
$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

# Compile C files to object files
$(SRCDIR)/main.o: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(SRCDIR)/*.o $(EXECUTABLE)

# Phony targets
.PHONY: all clean
