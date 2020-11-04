#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


const int STRING_COUNT = 2;
const char KEY = 0x1;
char *STRINGS[] = {
    "idmmn!vnsme",
    "idmmn!lnno",
};

char *get_string(unsigned int index) {
    if (index >= STRING_COUNT) {
        return 0;
    }

    char *s = STRINGS[index];
    char *out = malloc(strlen(s) + 1);

    memcpy(out, s, strlen(s) + 1);

    for (unsigned int i = 0; i < strlen(s); i++) {
        out[i] = s[i] ^ KEY;
    }
    out[strlen(s)] = 0;

    return out;
}

int main(int argc, char **argv) {
    printf("%s\n", get_string(0));  // memory leak, sorry
    printf("%s\n", get_string(1));  // memory leak, sorry
    return 0;
}
