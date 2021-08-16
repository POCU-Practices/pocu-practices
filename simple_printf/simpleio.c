#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "simpleio.h"

static void print_int_recursive(unsigned int val)
{
    if (val == 0) {
        return;
    }

    print_int_recursive(val / 10);
    putchar('0' + val % 10);
}

static void print_int(unsigned int val)
{
    if (val == 0) {
        putchar('0');
        return;
    }

    print_int_recursive(val);
}

void printf_simple(const char* format, ...)
{
    va_list ap;

    va_start(ap, format);
    {
        while (*format != '\0') {
            unsigned int val;
            const char* str;

            switch (*format) {
                case 's':
                    str = va_arg(ap, const char*); /*const char* str = string_value*/
                    while (*str != '\0') {
                        putchar(*str++); 
                    }
                    break;
                case 'c':
                    val = va_arg(ap, unsigned int); /*unsigned int val = char_ASCII_value*/
                    putchar(val);
                    break;
                case 'd':
                    val = va_arg(ap, unsigned int); /*unsigned int val = unsigned_int_value*/
                    print_int(val);
                    break;
                default:
                    putchar(*format); 
                    break; 
            }
            format++;
        } 
    }
    va_end(ap);
}
