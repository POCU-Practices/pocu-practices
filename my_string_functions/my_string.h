#ifndef MY_STRING
#define MY_STRING

#define TRUE (1)
#define FALSE (0)

int my_strcmp(const char* str1, const char* str2);

int my_strncmp(const char* str1, const char* str2, size_t count);

void my_strcat(char* dest, const char* src);

void my_strncat(char* dest, const char* src, size_t count);

char* my_strstr(const char* str1, const char* str2);

#endif /*MY_STRING*/
