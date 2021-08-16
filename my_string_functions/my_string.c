#include <stdio.h>

#include "my_string.h"

static char* s_token_ptr = NULL;
static int s_token_count = 0;

char* strcpy(char* dst, const char* src)
{
    char* ret = dst;

    while (*src != '\0') {
        *dst++ = *src++;
    }
    *dst = '\0';

    return ret;
}

char* strncpy(char* dst, const char* src, const size_t count)
{
    char* ret = dst;

    while (*src != '\0' && dst - ret < count) {
        *dst++ = *src++;
    }
    *dst = '\0';

    return ret;
}

size_t my_strlen(const char* str)
{
    const char* first = str;

    while (*str++ != '\0');

    return (size_t)(str - first - 1);
}

int my_strcmp(const char* str1, const char* str2)
{
    while(*str1 != '\0' && *str2 == *str1) {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

int my_strncmp(const char* str1, const char* str2, size_t count) /*only available when both str1 and str2 ends with '\0'!!!*/
{
    const char* ptr1 = str1;

    while (str1 - ptr1 < (int)count && *str1 != '\0' && *str1 == *str2) {
        ++str1;
        ++str2;
    } 

    return *str1 - *str2;    
}

char* strcat(char* dst, const char* src)
{
    char* ret = dst;

    while (*dst != '\0') {
        dst++;
    }

    while (*src != '\0') {
        *dst++ = *src++;
    }

    *dst = '\0';
    return ret;
}

char* strncat(char* dst, const char* src, size_t count)
{
    char* ret = dst;

    while (*dst != '\0') {
        dst++;
    }

    while (*src != '\0' && count > 0) {
        *dst++ = *src++;
        count--;
    }
    *dst = '\0';
    return ret;
}

char* my_strstr(const char* str, const char* substr)
{
    const char* ret = NULL;
    int i;

    for (i = 0; i <= (int)(strlen(str) - strlen(substr)); i++) {
        if (strncmp(str + i, substr, strlen(substr)) == 0) {
            ret = str + i;
            break;
        }    
    }

    return (char*)ret;
}