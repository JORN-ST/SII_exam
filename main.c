// Compiled with: gcc -std=c11 -Wall -pthread -lm

#include <stdio.h>
#include <stdbool.h>

#define SAMPLE_SIZE 11

int
GetNext() {
    static int i = 0;
    static int sample_input[SAMPLE_SIZE] =
            { 0xf12, 0xea2, 0x684, 0xfff, 0x217, 0x1f5, 0xf12, 0xea2, 0x684, 0xfff,
              0x1f5
            };

    if (i < SAMPLE_SIZE)
        return sample_input[i++];
    else
        return -1;
}

int main() {
    const int search_sample = 0x1f5;
    int tmp_GetNextRet, i = 0;
    bool found = false;

    do {
        if ((tmp_GetNextRet = GetNext()) == search_sample) {
            found = true;
            printf("[OK]Table value = 0x%x is on position = %d\n", tmp_GetNextRet, i + 1);
        }
    } while (++i < SAMPLE_SIZE);

    if (found == false) {
        fprintf(stderr, "[ERR]Value 0x%x not find in table\n", search_sample);
        return -1;
    }

    return 0;
}