/**
 * @file config.h
 * @brief Configuration header file for the Hello World C project
 * 
 * This header file contains project-wide configuration constants and macros.
 * It uses include guards to prevent multiple inclusion of the same header.
 * 
 * @author Your Name
 * @date 2025
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Include standard C library headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Project version information */
#define PROJECT_NAME "Hello World C Project"
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0

/* Build configuration */
#ifndef DEBUG_MODE
    #define DEBUG_MODE 1  /* Set to 0 for release builds */
#endif

/* Application settings */
#define MAX_MESSAGE_LENGTH 256
#define DEFAULT_GREETING "Hello, World!"

/* Compiler-specific macros */
#ifdef __GNUC__
    #define COMPILER_GCC 1
#else
    #define COMPILER_GCC 0
#endif

/* Platform detection */
#ifdef _WIN32
    #define PLATFORM_WINDOWS 1
#elif defined(__linux__)
    #define PLATFORM_LINUX 1
#elif defined(__APPLE__)
    #define PLATFORM_MACOS 1
#else
    #define PLATFORM_UNKNOWN 1
#endif

/* Debug macros */
#if DEBUG_MODE
    #define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) ((void)0)
#endif

/* Function attribute macros for better code generation */
#define UNUSED_PARAM(x) ((void)(x))

/* Error codes */
typedef enum {
    ERROR_NONE = 0,
    ERROR_INVALID_INPUT = -1,
    ERROR_MEMORY_ALLOCATION = -2,
    ERROR_FILE_NOT_FOUND = -3
} error_code_t;

#endif /* CONFIG_H */
