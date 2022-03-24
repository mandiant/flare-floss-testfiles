#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // clang initializes this via dword MOVs
    // hello world XOR 0x11
    char key = 0x11;
    char one[] = {0x79, 0x74, 0x7d, 0x7d, 0x7e, 0x31, 0x66, 0x7e, 0x63, 0x7d, 0x75, 0x00};
    char two[14];

    for (unsigned int i = 0; i < sizeof(one) - 1; i++) {
        ((char *)one)[i] = ((char *)one)[i] ^ key;
    }
    printf("%s\n", one);

    // byte MOVs
    two[0] = 0x76;
    two[1] = 0x7e;
    two[2] = 0x7e;
    two[3] = 0x75;
    two[4] = 0x73;
    two[5] = 0x68;
    two[6] = 0x74;
    two[7] = 0x31;
    two[8] = 0x66;
    two[9] = 0x7e;
    two[10] = 0x63;
    two[11] = 0x7d;
    two[12] = 0x75;
    two[13] = 0x00;

    for (unsigned int i = 0; i < sizeof(two) - 1; i++) {
        ((char *)two)[i] = ((char *)two)[i] ^ key;
    }
    printf("%s\n", two);

    return 0;
}
