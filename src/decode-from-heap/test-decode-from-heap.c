#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


int decode(void *out_buf, size_t out_len, const void *in_buf, size_t in_len, unsigned char key) {
    for (unsigned int i = 0; i < in_len; i++) {
        ((char *)out_buf)[i] = ((char *)in_buf)[i] ^ key;
    }
    if (in_len > 0) {
        ((char *)out_buf)[in_len - 1] = 0;
    }
    return 0;
}


int main(int argc, char **argv) {
    char in1[] = "idmmn!vnsme";
    char *in2 = malloc(sizeof(in1));
    if (in2 == NULL) {
        perror("failed to malloc.\n");
        return -1;
    }
    memcpy(in2, in1, sizeof(in1));

    char out[12] = { 0 };
    unsigned char key = 0x1;

    if (decode(out, sizeof(out), in2, sizeof(in1), 0x1)) {
        perror("failed to decode.\n");
        return -1;
    }
    printf("%s\n", out);
    return 0;
}
