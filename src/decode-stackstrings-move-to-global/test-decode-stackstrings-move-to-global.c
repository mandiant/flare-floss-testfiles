#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

char global[14];

void load_stackstring() {
    char one[14];
    // byte MOVs
    one[0] = 'l';
    one[1] = 'o';
    one[2] = 'a';
    one[3] = 'd';
    one[4] = 'e';
    one[5] = 'd';
    one[6] = ' ';
    one[7] = 'w';
    one[8] = 'o';
    one[9] = 'r';
    one[10] = 'l';
    one[11] = 'd';
    one[12] = '!';
    one[13] = 0;

    int i = 0;
    while (one[i]) {
        global[i] = one[i];
        i++;
    }
}

int main(int argc, char **argv) {
    load_stackstring();

    printf("%s\n", global);

    return 0;
}
