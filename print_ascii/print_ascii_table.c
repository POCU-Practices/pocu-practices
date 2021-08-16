#include <stdio.h>

#include "print_ascii_table.h"

void print_ascii_table(void)
{
    const int MIN_ASCII = 32;
    const int MAX_ASCII = 126;
    const int NUM_CHARS = MAX_ASCII - MIN_ASCII + 1;
    const int NUM_COLS = 3;
    const int NUM_ROWS = (NUM_CHARS + NUM_COLS - 1) / NUM_COLS; /*(NUM_CHARS % NUM_COLS)개의 문자도 포함하기 위해서 최대 나머지 개수(NUM_COLS - 1)만큼 NUM_CHAR에 추가하고 나눈다.*/

    int r;
    int ch;

    printf("DEC HEX  CHAR\tDEC HEX  CHAR\tDEC HEX  CHAR\n"); /*table header*/
    
    for (r = 0; r < NUM_ROWS - 1; r++) {
        ch = MIN_ASCII + r;
        printf("%03d %#X  %c\t", ch, ch, ch);

        ch += NUM_ROWS;
        printf("%03d %#X  %c\t", ch, ch, ch);

        ch += NUM_ROWS;
        printf("%03d %#X  %c\n", ch, ch, ch);
    }

    /*last row is not fully occupied!*/
    for (ch = MIN_ASCII + r; ch <= MAX_ASCII; ch += NUM_ROWS) {
        printf("%03d %#X  %c\t", ch, ch, ch);
    }
}
