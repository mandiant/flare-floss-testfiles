#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// "secret password", with a substitution that leaves 'e', 's', and ' ' alone:
// some characters of the encoded string are already the decoded ones,
// so decoding in place doesn't change every byte of the string.
char buf[] = "sxcrxt passwyrd";

int decode(char *s) {
    for (; *s; s++) {
        if (*s == 'x') {
            *s = 'e';
        } else if (*s == 'y') {
            *s = 'o';
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (decode(buf)) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", buf);
    return 0;
}
