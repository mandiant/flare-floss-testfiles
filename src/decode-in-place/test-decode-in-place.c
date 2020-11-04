#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


int decode(void *buf, size_t buf_len, unsigned char key) {
    for (unsigned int i = 0; i < buf_len; i++) {
        ((char *)buf)[i] ^= key;
    }
    if (buf_len > 0) {
        ((char *)buf)[buf_len - 1] = 0;
    }
    return 0;
}

int main(int argc, char **argv) {
    char buf[] = "idmmn!vnsme";
    unsigned char key = 0x1;

    if (decode(buf, sizeof(buf), 0x1)) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", buf);
    return 0;
}
