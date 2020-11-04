#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

char one[14];

int main(int argc, char **argv) {
    // byte MOVs
    one[0] = 'g';
    one[1] = 'o';
    one[2] = 'o';
    one[3] = 'd';
    one[4] = 'b';
    one[5] = 'y';
    one[6] = 'e';
    one[7] = ' ';
    one[8] = 'w';
    one[9] = 'o';
    one[10] = 'r';
    one[11] = 'l';
    one[12] = 'd';
    one[13] = 0;

    printf("%s\n", one);

    return 0;
}
