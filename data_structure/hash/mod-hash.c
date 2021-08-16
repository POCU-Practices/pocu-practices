#include <limits.h>

#define TRUE (1)
#define FALSE (0)
#define BUCKET_SIZE (23)

int s_numbers[BUCKET_SIZE];

void init_hashtable(void)
{
    size_t i;

    for (i = 0; i < BUCKET_SIZE; i++) {
        s_numbers[i] = INT_MIN;
    }
}

int has_value(int value)
{
    int i;
    int start_index;

    start_index = value % BUCKET_SIZE;
    if (start_index < 0) {
        start_index += BUCKET_SIZE;
    }

    i = start_index;

    do {
        if (s_numbers[i] == value) {
            return TRUE;
        } else if (s_numbers[i] == INT_MIN) {
            return FALSE; 
            /*단, index가 중복되는 value들 중간에 삭제가 일어나면 삭제된 value 뒤로 위치한 중복된 값들도 FALSE로 출력된다.*/ 
            /*33 52 78 --> 33 INT_MIN 78 : 78은 찾을 수 없다고 나온다.*/
        }

        i = (i + 1) % BUCKET_SIZE;

    } while (i != start_index); /*table entry를 한 바퀴 다 돌고나서 while문을 탈출*/

    return FALSE;
}

int add(int value)
{
    int i;
    int start_index;

    start_index = value % BUCKET_SIZE;
    if (start_index < 0) {
        start_index += BUCKET_SIZE;
    }

    i = start_index;

    do {
        if (s_numbers[i] == value || s_numbers[i] == INT_MIN) {
            s_numbers[i] = value;
            return TRUE;
        }

        i = (i + 1) % BUCKET_SIZE;

    } while (i != start_index);

    return FALSE;
}

int main(void)
{
    init_hashtable();

    add(703);
    add(702);
    add(74);
    add(3);
    add(44);
    add(39);
    add(31);

    return 0;
}