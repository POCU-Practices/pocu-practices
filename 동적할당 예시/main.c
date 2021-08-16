#include <stdlib.h>

#define LINE_LENGTH (2048)
#define INCREMENT (2)


int main(void)
{
    char** lines; /*포인터 배열 == 이중 포인터*/
    char line[LINE_LENGTH];
    size_t max_lines;
    size_t num_lines;
    size_t i;
    char** tmp;

    max_lines = 0;
    num_lines = 0;
    lines = NULL;


    while (1) {
        if (fgets(line, LINE_LENGTH, stdin) == NULL) {
            clearerr(stdin);
            break;
        }

        if (num_lines == max_lines) {
            tmp = realloc(lines, (max_lines + INCREMENT) * sizeof(char*));

            if (tmp == NULL) {
                fprintf(stderr, "%s\n", "out of memory");
                break;
            }
            lines = tmp;
            max_lines += INCREMENT;
        }
        
        lines[num_lines] = malloc(strlen(line) + 1);
        if (lines[num_lines] == NULL) {
            fprintf(stderr, "%s\n", "out of memory");
            break;
        }
        strcpy(lines[num_lines++], line);
    }

    for (i = 0; i < num_lines; ++i) {
        printf("[%d] %s", i, lines[i]);
    }

    for (i = 0; i < num_lines; ++i) {
        free(lines[i]);
    }

    free(lines);
    return 0;
}



