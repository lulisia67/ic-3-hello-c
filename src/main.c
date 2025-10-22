/**
 * @file main.c
 * @brief Main entry point for the Hello World C project
 * 
 * This file contains the main function and demonstrates basic C programming
 * concepts including header inclusion, function calls, and program structure.
 * 
 * @author Your Name
 * @date 2025
 */

/* Include project configuration header first */
#include "config.h"

/* Forward declarations for functions defined in this file */
static void PrintWelcomeMessage(void);
static void PrintSystemInfo(void);
static int ProcessUserInput(void);

/**
 * @brief Main entry point of the program
 * 
 * The main function is the entry point for all C programs. It receives
 * command line arguments and returns an integer status code.
 * 
 * @param argc Number of command line arguments (including program name)
 * @param argv Array of strings containing command line arguments
 * @return int Program exit status (0 for success, non-zero for error)
 */
int main(int argc, char* argv[]) {
    /* Suppress unused parameter warnings in release builds */
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);
    
    /* Print debug information if in debug mode */
    DEBUG_PRINT("Starting %s v%d.%d.%d", PROJECT_NAME, 
                VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    
    /* Display welcome message */
    PrintWelcomeMessage();
    
    /* Display system information */
    PrintSystemInfo();
    
    /* Process user input and handle any errors */
    int result = ProcessUserInput();
    if (result != ERROR_NONE) {
        fprintf(stderr, "Error occurred: %d\n", result);
        return EXIT_FAILURE;
    }
    
    /* Print success message and exit */
    printf("\nProgram completed successfully!\n");
    DEBUG_PRINT("%s", "Program exiting normally");
    
    return EXIT_SUCCESS;
}

/**
 * @brief Prints a welcome message to the user
 * 
 * This function demonstrates basic string output and uses the
 * DEFAULT_GREETING constant defined in config.h.
 */
static void PrintWelcomeMessage(void) {
    printf("========================================\n");
    printf("  %s\n", PROJECT_NAME);
    printf("  Version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    printf("========================================\n");
    printf("%s\n", DEFAULT_GREETING);
    printf("This is a simple C program demonstrating:\n");
    printf("- Header file inclusion with guards\n");
    printf("- Function organization and documentation\n");
    printf("- Google C/C++ Style formatting\n");
    printf("- Makefile-based build system\n");
    printf("========================================\n\n");
}

/**
 * @brief Prints system and compiler information
 * 
 * This function displays information about the compilation environment
 * and target platform using preprocessor macros.
 */
static void PrintSystemInfo(void) {
    printf("System Information:\n");
    printf("-------------------\n");
    
    /* Display compiler information */
    if (COMPILER_GCC) {
        printf("Compiler: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    } else {
        printf("Compiler: Unknown\n");
    }
    
    /* Display platform information */
    printf("Platform: ");
#if PLATFORM_WINDOWS
    printf("Windows\n");
#elif PLATFORM_LINUX
    printf("Linux\n");
#elif PLATFORM_MACOS
    printf("macOS\n");
#else
    printf("Unknown\n");
#endif
    
    /* Display build configuration */
    printf("Build Mode: %s\n", DEBUG_MODE ? "Debug" : "Release");
    printf("Max Message Length: %d characters\n", MAX_MESSAGE_LENGTH);
    printf("\n");
}

/**
 * @brief Processes user input and demonstrates error handling
 * 
 * This function shows how to handle user input and demonstrates
 * basic error handling patterns in C.
 * 
 * @return int Error code (ERROR_NONE on success, error code on failure)
 */
static int ProcessUserInput(void) {
    char user_message[MAX_MESSAGE_LENGTH];
    
    printf("Enter a custom message (or press Enter for default): ");
    
    /* Read user input with bounds checking */
    if (fgets(user_message, sizeof(user_message), stdin) == NULL) {
        fprintf(stderr, "Error reading user input\n");
        return ERROR_INVALID_INPUT;
    }
    
    /* Remove trailing newline character */
    size_t len = strlen(user_message);
    if (len > 0 && user_message[len - 1] == '\n') {
        user_message[len - 1] = '\0';
    }
    
    /* Display the message or default if empty */
    if (strlen(user_message) == 0) {
        printf("Using default message: %s\n", DEFAULT_GREETING);
    } else {
        printf("Your custom message: %s\n", user_message);
    }
    
    DEBUG_PRINT("%s", "User input processed successfully");
    return ERROR_NONE;
}
