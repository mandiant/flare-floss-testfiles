#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // clang initializes this via dword MOVs
    char one[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', 0};
    char two[14];

    printf("%s\n", one);

    // byte MOVs
    two[0] = 'g';
    two[1] = 'o';
    two[2] = 'o';
    two[3] = 'd';
    two[4] = 'b';
    two[5] = 'y';
    two[6] = 'e';
    two[7] = ' ';
    two[8] = 'w';
    two[9] = 'o';
    two[10] = 'r';
    two[11] = 'l';
    two[12] = 'd';
    two[13] = 0;

    printf("%s\n", two);

    return 0;
}
