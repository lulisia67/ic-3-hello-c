# Makefile for Hello World C Project
# This Makefile follows standard conventions and works with GCC on Linux/WSL

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
DEBUG_FLAGS = -g -DDEBUG_MODE=1
RELEASE_FLAGS = -O2 -DNDEBUG -DDEBUG_MODE=0

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Target executable name
TARGET = $(BUILD_DIR)/hello_world

# Source files (automatically find all .c files in src directory)
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Object files (replace .c with .o and add obj directory prefix)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Include directories for compiler
INCLUDES = -I$(INCLUDE_DIR)

# Default target (what gets built when you just run 'make')
.PHONY: all clean debug release help install

# Default build (debug mode)
all: debug

# Debug build with debugging symbols and debug mode enabled
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build optimized for performance
release: CFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

# Create the target executable by linking object files
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	@echo "Linking $@..."
	$(CC) $(OBJECTS) -o $@
	@echo "Build complete! Executable: $@"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create necessary directories
$(BUILD_DIR):
	@echo "Creating build directory..."
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	@echo "Creating object directory..."
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)
	@echo "Clean complete!"

# Run the program (builds if necessary)
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@echo "=========================================="
	./$(TARGET)

# Install the program to /usr/local/bin (requires sudo)
install: release
	@echo "Installing $(TARGET) to /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/hello_world
	@echo "Installation complete! You can now run 'hello_world' from anywhere."

# Uninstall the program
uninstall:
	@echo "Uninstalling hello_world..."
	sudo rm -f /usr/local/bin/hello_world
	@echo "Uninstall complete!"

# Show help information
help:
	@echo "Hello World C Project Makefile"
	@echo "=============================="
	@echo ""
	@echo "Available targets:"
	@echo "  all      - Build in debug mode (default)"
	@echo "  debug    - Build with debugging symbols and debug mode enabled"
	@echo "  release  - Build optimized for performance"
	@echo "  clean    - Remove all build artifacts"
	@echo "  run      - Build and run the program"
	@echo "  install  - Install to /usr/local/bin (requires sudo)"
	@echo "  uninstall- Remove from /usr/local/bin (requires sudo)"
	@echo "  help     - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make              # Build in debug mode"
	@echo "  make release      # Build optimized version"
	@echo "  make run          # Build and run"
	@echo "  make clean        # Clean build files"
	@echo "  make help         # Show this help"

# Show build information
info:
	@echo "Build Information:"
	@echo "=================="
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"
	@echo "Source Directory: $(SRC_DIR)"
	@echo "Include Directory: $(INCLUDE_DIR)"
	@echo "Build Directory: $(BUILD_DIR)"
	@echo "Target: $(TARGET)"
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
