#include <stdio.h>
#include <string.h>

#define BUFFER_LENGTH (32)

static size_t s_buffer_index = 0u;/*첫 번째 비어있는 위치*/
static char s_buffer[BUFFER_LENGTH];

void buffered_print(const char* src)
{
    size_t num_left;
    const char* p = src; /*src 내의 포인터*/

    num_left = strlen(src);/*복사할 남은 문자의 개수, null 제외하고*/

    while (num_left > 0) { /*버퍼가 비워져도 복사할 문자의 개수가 남으면 그대로 전역변수 s_buffer에 추가된다.*/

        size_t copy_count = BUFFER_LENGTH - s_buffer_index - 1; /*buffer에 null 제외하고 남은 공간 크기*/
        const int buffer_empty = (s_buffer_index == 0);

        if (num_left < copy_count) {
            copy_count = num_left;
        }

        s_buffer_index += copy_count;
        num_left -= copy_count;

        if (buffer_empty) {
            strncpy(s_buffer, p, copy_count);
            s_buffer[s_buffer_index] = '\0'; /*num_left >> copy_count인 경우 s_buffer 마지막에 null을 추가해야 하므로*/
        } else {
            strncat(s_buffer, p, copy_count); /*null이 자동으로 마지막에 추가된다.*/
        }

        p += copy_count;

        if (s_buffer_index == BUFFER_LENGTH - 1) { /*s_buffer_index가 마지막 null에 위치하는 경우*/
            printf("%s\n", s_buffer);
            s_buffer_index = 0;
        }
    }
}
