# Hello World C Project

A well-organized C hello-world project demonstrating modern C programming practices, build systems, and development workflow integration.

## Project Structure

```
ic-3-hello-c/
├── src/                    # Source code directory
│   └── main.c             # Main application source
├── include/               # Header files directory
│   └── config.h          # Project configuration header
├── build/                # Build output directory (created by make)
│   ├── obj/              # Object files (created by make)
│   └── hello_world       # Final executable (created by make)
├── Makefile              # Build configuration
├── README.md             # This file
└── LICENSE               # Project license
```

## Prerequisites

### WSL Ubuntu 24.04 Setup

1. **Install WSL Ubuntu 24.04** (if not already installed):
   ```bash
   wsl --install -d Ubuntu-24.04
   ```

2. **Update package manager**:
   ```bash
   sudo apt update && sudo apt upgrade -y
   ```

3. **Install essential build tools**:
   ```bash
   sudo apt install -y build-essential gcc make git
   ```

4. **Verify installation**:
   ```bash
   gcc --version
   make --version
   ```

## Build Instructions

### Quick Start

1. **Clone or navigate to the project directory**:
   ```bash
   cd /path/to/ic-3-hello-c
   ```

2. **Build the project**:
   ```bash
   make
   ```

3. **Run the program**:
   ```bash
   make run
   ```

### Build Options

| Command | Description |
|---------|-------------|
| `make` or `make all` | Build in debug mode (default) |
| `make debug` | Build with debugging symbols and debug mode enabled |
| `make release` | Build optimized for performance |
| `make run` | Build and run the program |
| `make clean` | Remove all build artifacts |
| `make help` | Show all available make targets |
| `make info` | Show build configuration information |

### Manual Build (Alternative)

If you prefer to build manually without the Makefile:

```bash
# Create build directory
mkdir -p build/obj

# Compile source to object file
gcc -Wall -Wextra -std=c99 -pedantic -g -Iinclude -c src/main.c -o build/obj/main.o

# Link object file to create executable
gcc build/obj/main.o -o build/hello_world

# Run the program
./build/hello_world
```

## Running the Program

### Basic Execution

```bash
# Build and run in one command
make run

# Or run the executable directly
./build/hello_world
```

### Program Features

The program demonstrates:
- **Header file inclusion** with proper guards
- **Function organization** and documentation
- **Google C/C++ Style** formatting
- **Makefile-based** build system
- **User input handling** with error checking
- **System information** display
- **Debug mode** support

### Example Output

```
========================================
  Hello World C Project
  Version: 1.0.0
========================================
Hello, World!
This is a simple C program demonstrating:
- Header file inclusion with guards
- Function organization and documentation
- Google C/C++ Style formatting
- Makefile-based build system
========================================

System Information:
-------------------
Compiler: GCC 11.4.0
Platform: Linux
Build Mode: Debug
Max Message Length: 256 characters

Enter a custom message (or press Enter for default): 
```

## Cursor.ai Project Configuration

### Project Guidelines and Specifications

Store your project guidelines and specifications in the following locations:

#### 1. `.cursorrules` File (Recommended)
Create a `.cursorrules` file in your project root to define coding standards and project-specific rules:

```bash
# Create .cursorrules file
touch .cursorrules
```

Example `.cursorrules` content:
```
# C/C++ Project Rules for Hello World Project

## Code Style
- Follow Google C/C++ Style Guide
- Use snake_case for variables and functions
- Use UPPER_CASE for constants and macros
- Always include header guards in .h files
- Document all functions with Doxygen-style comments

## Project Structure
- Source files go in src/
- Header files go in include/
- Build artifacts go in build/
- Use Makefile for building

## Best Practices
- Always check return values
- Use const where appropriate
- Initialize variables before use
- Handle errors gracefully
- Use meaningful variable names
```

#### 2. Project Documentation
- **README.md**: Project overview, build instructions, and usage
- **docs/**: Additional documentation (create if needed)
- **CHANGELOG.md**: Version history and changes
- **CONTRIBUTING.md**: Contribution guidelines

#### 3. Configuration Files
- **Makefile**: Build configuration and targets
- **.gitignore**: Version control exclusions
- **config.h**: Project-wide configuration constants

### Cursor.ai Basic Actions for Code Generation

#### 1. **Code Completion**
- **Trigger**: Type code and press `Tab` or `Ctrl+Space`
- **Use case**: Auto-complete function names, variables, and syntax
- **Example**: Type `printf(` and get auto-completion for format strings

#### 2. **Inline Chat**
- **Trigger**: `Ctrl+L` or click chat icon
- **Use case**: Ask questions about code, request explanations, or get help
- **Example**: "Explain this function" or "How do I add error handling?"

#### 3. **Code Generation with Comments**
- **Trigger**: Write a comment describing what you want, then press `Ctrl+K`
- **Use case**: Generate code from natural language descriptions
- **Example**: 
  ```c
  // Function to calculate factorial of a number
  // Press Ctrl+K here to generate the function
  ```

#### 4. **Refactoring**
- **Trigger**: Select code and use `Ctrl+Shift+P` → "Refactor"
- **Use case**: Rename variables, extract functions, optimize code
- **Example**: Select a variable name and rename it across the entire project

#### 5. **Documentation Generation**
- **Trigger**: Place cursor on function and press `Ctrl+K`
- **Use case**: Generate Doxygen-style documentation
- **Example**: 
  ```c
  int calculate_sum(int a, int b) {
      // Place cursor here and press Ctrl+K to generate docs
  }
  ```

#### 6. **Error Fixing**
- **Trigger**: Click on error squiggles or use `Ctrl+.`
- **Use case**: Get suggestions to fix compilation errors
- **Example**: Missing semicolon, undefined variables, type mismatches

#### 7. **Code Explanation**
- **Trigger**: Select code and ask "Explain this code"
- **Use case**: Understand complex code sections
- **Example**: Select a complex algorithm and get a detailed explanation

### Best Practices for Cursor.ai Integration

1. **Use Descriptive Comments**: Write clear comments that describe intent, not implementation
2. **Consistent Naming**: Use consistent naming conventions that Cursor.ai can learn from
3. **Modular Code**: Write small, focused functions that are easier for AI to understand
4. **Error Handling**: Always include proper error handling patterns
5. **Documentation**: Keep documentation up-to-date and comprehensive

## Development Workflow

### 1. Setting Up Development Environment

```bash
# Navigate to project
cd /path/to/ic-3-hello-c

# Build the project
make

# Run tests (if you add them)
make test

# Clean build artifacts
make clean
```

### 2. Adding New Features

1. **Create new source files** in `src/` directory
2. **Add corresponding headers** in `include/` directory
3. **Update Makefile** if needed (usually automatic)
4. **Test your changes**:
   ```bash
   make clean
   make
   make run
   ```

### 3. Code Style Guidelines

This project follows the **Google C/C++ Style Guide**:

- **Naming**: `snake_case` for variables and functions, `UPPER_CASE` for constants
- **Indentation**: 2 spaces (not tabs)
- **Line length**: Maximum 80 characters
- **Comments**: Use `/* */` for block comments, `//` for line comments
- **Header guards**: Always use `#ifndef` guards in header files

### 4. Debugging

```bash
# Build with debug symbols
make debug

# Run with gdb (if installed)
gdb ./build/hello_world

# Use valgrind for memory checking (if installed)
valgrind ./build/hello_world
```

## Troubleshooting

### Common Issues

1. **"make: command not found"**
   ```bash
   sudo apt install build-essential
   ```

2. **"gcc: command not found"**
   ```bash
   sudo apt install gcc
   ```

3. **Permission denied errors**
   ```bash
   chmod +x build/hello_world
   ```

4. **Include file not found**
   - Check that `include/config.h` exists
   - Verify the `-Iinclude` flag in Makefile

### Getting Help

- **Makefile help**: `make help`
- **Build info**: `make info`
- **Clean and rebuild**: `make clean && make`

## Contributing

1. Follow the Google C/C++ Style Guide
2. Add appropriate comments and documentation
3. Test your changes with `make run`
4. Update this README if you add new features

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

**Happy Coding!** 🚀

For questions or issues, please refer to the troubleshooting section or create an issue in the project repository.