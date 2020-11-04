#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


int decode(void *out_buf, size_t out_len, const void *in_buf, size_t in_len, unsigned char key) {
    if (out_len != in_len) {
        return -1;
    }

    for (unsigned int i = 0; i < out_len; i++) {
        ((char *)out_buf)[i] = ((char *)in_buf)[i] ^ key;
    }
    if (out_len > 0) {
        ((char *)out_buf)[out_len - 1] = 0;
    }

    return 0;
}

char in[] = "idmmn!vnsme";
char out[12] = { 0 };

int main(int argc, char **argv) {
    unsigned char key = 0x1;

    if (decode(out, sizeof(out), in, sizeof(in), 0x1)) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", out);
    return 0;
}
