#include "pargser.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

enum INDEX_OPTIONS {
    FIND_NEXT = -2,
    NOT_FOUND = -1
};

#ifndef EXIT_AT_ERROR
#define EXIT_AT_ERROR 1
#endif

static uintptr_t pargser_tokenize(const char *str) {

    const char *temp = str;

    while (*temp != '\0' && *temp != '%' && *temp != ';') {
        temp++;
    }

    return (uintptr_t)(temp - str);
}

static int pargser_find(int argc, const char *argv[], const char *arg_name, uintptr_t size) {
    for (int i = 0; i < argc; i++) {
        if (!strncmp(argv[i], arg_name, size)) return i;
    }

    return NOT_FOUND;
}

static void pargser_parse(int argc, const char *argv[], int index, void *ref, const char arg_type) {

    if (arg_type == 'b') {
        *((int*)ref) = index != NOT_FOUND;
        return;
    }

    if (index == NOT_FOUND) return;

    int out_of_bound = index + 1 >= argc;

#if EXIT_AT_ERROR
    if (out_of_bound) exit(EXIT_FAILURE);
#else
    if (out_of_bound) return;
#endif

    if (arg_type == 'i') {
        *((int*)ref) = atoi(argv[index + 1]);
    }

    if (arg_type == 's') {
        *((const char**)ref) = argv[index + 1];
    }

    if (arg_type == 'd') {
        *((double*)ref) = atof(argv[index + 1]);
    }
}

int pargser(int argc, const char *argv[], const char *format, ...) {

    va_list args;
    va_start(args, format);

    int index = FIND_NEXT;

    while (*format) {

        uintptr_t size = pargser_tokenize(format);

        if (size == 0) return 0;

        if (index == FIND_NEXT) {
            index = pargser_find(argc, argv, format, size);
            format += size + 1;
            continue;
        }

        void *ref = va_arg(args, void*);
        const char arg_type = *(format + size - 1);
        pargser_parse(argc, argv, index, ref, arg_type);
        index++;

        if (*(format + size) == ';') index = FIND_NEXT;
        format += size + 1;
    }

    return 0;
}