#include <stdio.h>

#include "error_handler.h"

void simple_stderr_print(const char* msg);
int run(void);

int main(void)
{
    int success;

    success = run();

    register_error_handler(default_error_handler);
    if (run() == FALSE) {
        success = FALSE;
    }

    register_error_handler(simple_stderr_print);
    if (run() == FALSE) {
        success = FALSE;
    }

    return success ? 0 : 1;
}

int run(void)
{
    int numerator;
    int denominator;

    while (TRUE) {
        printf("enter numerator : ");
        if (scanf("%d", &numerator) == 1) {
            break; 
        }
    }

    while (TRUE) {
        printf("enter denominator : ");
        if (scanf("%d", &denominator) == 1) {
            break;
        }
    }

    if (denominator == 0) {
        log_error("cannot divide by zero");
        return FALSE;
    }

    printf("%d / %d = %.2f\n", numerator, denominator, numerator / (float)denominator);

    return TRUE;
}

void simple_stderr_print(const char* msg) /*라이브러가 아닌 간단히 구현한 callback*/
{
    fputs(msg, stderr); 
/*callback 함수의 인자로 단순한 문자열이 아닌 enum형 데이터를 전달하여 발생한 오류의 종류를 구분할 수 있고*/
/*switch 문 하나 넣어서 그에 따라 오류에 대처하는 코드를 작성할 수 있다.*/
}
