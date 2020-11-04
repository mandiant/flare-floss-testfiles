#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


int xor(char *buf, size_t buf_len, unsigned char key) {
    for (unsigned int i = 0; i < buf_len; i++) {
        buf[i] = buf[i] ^ key;
    }
    if (buf_len > 0) {
        buf[buf_len - 1] = 0;
    }
    return 0;
}


int main(int argc, char **argv) {
    char s[] = "idmmn!vnsme";

    if (xor(s, sizeof(s), 0x1)) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", s);
    if (xor(s, sizeof(s), 0x1)) {
        perror("failed to reencode.\n");
        return -1;
    }
    return 0;
}
